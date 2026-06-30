import 'dart:convert';
import 'dart:io';

import 'package:crypto/crypto.dart';
import 'package:path/path.dart';
import 'package:path_provider/path_provider.dart';
import 'package:sqflite/sqflite.dart';

import '../models/contact.dart';
import '../models/recording.dart';
import '../models/user.dart';
import 'cloud_sync.dart';

/// DatabaseHelper concentra acesso ao SQLite local.
///
/// Analogia: este arquivo é o "bibliotecário" do app — quem sabe onde cada
/// ficha está guardada (users, contacts, recordings). Toda escrita também
/// envia uma cópia para o `CloudSync` (carteiro para a nuvem), mas a fonte
/// de verdade do dia-a-dia é o SQLite local.
class DatabaseHelper {
  DatabaseHelper._privateConstructor();

  static final DatabaseHelper instance = DatabaseHelper._privateConstructor();
  static Database? _database;

  /// Usado como fallback em telas que ainda não conhecem o usuário logado.
  static const int defaultUserId = 1;

  Future<Database> get database async {
    if (_database != null) return _database!;
    _database = await _initDatabase();
    return _database!;
  }

  Future<Database> _initDatabase() async {
    Directory documentsDirectory = await getApplicationDocumentsDirectory();
    final String path = join(documentsDirectory.path, 'guara.db');
    return await openDatabase(
      path,
      version: 1,
      onCreate: _onCreate,
    );
  }

  Future<void> _onCreate(Database db, int version) async {
    await db.execute('''
      CREATE TABLE users(
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        email TEXT NOT NULL UNIQUE,
        password TEXT NOT NULL,
        dateCreated TEXT NOT NULL
      )
    ''');

    await db.execute('''
      CREATE TABLE contacts(
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        userId INTEGER NOT NULL,
        name TEXT NOT NULL,
        relationship TEXT NOT NULL,
        phoneNumber TEXT NOT NULL,
        dateCreated TEXT NOT NULL,
        FOREIGN KEY(userId) REFERENCES users(id)
      )
    ''');

    await db.execute('''
      CREATE TABLE recordings(
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        userId INTEGER NOT NULL,
        date TEXT NOT NULL,
        path TEXT NOT NULL,
        FOREIGN KEY(userId) REFERENCES users(id)
      )
    ''');

    // Usuário admin padrão (senha "1234" em hash sha256).
    await db.insert('users', {
      'name': 'Admin',
      'email': 'admin@guara.com',
      'password': hashPassword('1234'),
      'dateCreated': DateTime.now().toIso8601String(),
    });
  }

  // ---------- AUTH ----------

  /// Hash leve para não armazenar senha em texto claro.
  /// Atende ao schema (Varchar(255)) e melhora a segurança.
  static String hashPassword(String raw) {
    final bytes = utf8.encode(raw);
    return sha256.convert(bytes).toString();
  }

  /// Tenta autenticar com email/senha. Retorna o User ou null.
  Future<User?> authenticate(String email, String password) async {
    final db = await database;
    final maps = await db.query(
      'users',
      where: 'email = ? AND password = ?',
      whereArgs: [email.trim().toLowerCase(), hashPassword(password)],
      limit: 1,
    );
    if (maps.isEmpty) return null;
    return User.fromMap(maps.first);
  }

  Future<User?> getUserByEmail(String email) async {
    final db = await database;
    final maps = await db.query(
      'users',
      where: 'email = ?',
      whereArgs: [email.trim().toLowerCase()],
      limit: 1,
    );
    if (maps.isEmpty) return null;
    return User.fromMap(maps.first);
  }

  // ---------- USERS ----------

  /// Insere usuário garantindo email único, senha em hash e replicando
  /// para a nuvem (silencioso se offline / não configurado).
  Future<int> insertUser(User user) async {
    final db = await database;
    final normalized = User(
      id: user.id,
      name: user.name.trim(),
      email: user.email.trim().toLowerCase(),
      password: hashPassword(user.password),
      dateCreated: user.dateCreated,
    );
    final id = await db.insert('users', normalized.toMap());
    // Replica para a nuvem com o id recém-gerado.
    await CloudSync.instance.upsertUser(
      User(
        id: id,
        name: normalized.name,
        email: normalized.email,
        password: normalized.password,
        dateCreated: normalized.dateCreated,
      ),
    );
    return id;
  }

  Future<User?> getUser(int id) async {
    final db = await database;
    final maps = await db.query('users', where: 'id = ?', whereArgs: [id]);
    if (maps.isEmpty) return null;
    return User.fromMap(maps.first);
  }

  // ---------- CONTACTS ----------

  Future<int> insertContact(Contact contact) async {
    final db = await database;
    final id = await db.insert('contacts', contact.toMap());
    final replicated = Contact(
      id: id,
      userId: contact.userId,
      name: contact.name,
      relationship: contact.relationship,
      phoneNumber: contact.phoneNumber,
      dateCreated: contact.dateCreated,
    );
    await CloudSync.instance.upsertContact(replicated);
    return id;
  }

  Future<int> updateContact(Contact contact) async {
    final db = await database;
    final rows = await db.update(
      'contacts',
      contact.toMap(),
      where: 'id = ?',
      whereArgs: [contact.id],
    );
    await CloudSync.instance.upsertContact(contact);
    return rows;
  }

  Future<int> deleteContact(int id) async {
    final db = await database;
    final existing = await db.query('contacts', where: 'id = ?', whereArgs: [id], limit: 1);
    final rows = await db.delete('contacts', where: 'id = ?', whereArgs: [id]);
    if (existing.isNotEmpty) {
      final c = Contact.fromMap(existing.first);
      await CloudSync.instance.deleteContact(userId: c.userId, contactId: id);
    }
    return rows;
  }

  Future<List<Contact>> getAllContacts({int? userId}) async {
    final db = await database;
    final maps = userId == null
        ? await db.query('contacts', orderBy: 'dateCreated DESC')
        : await db.query(
            'contacts',
            where: 'userId = ?',
            whereArgs: [userId],
            orderBy: 'dateCreated DESC',
          );
    return maps.map((map) => Contact.fromMap(map)).toList();
  }

  // ---------- RECORDINGS ----------

  Future<int> insertRecording(Recording recording) async {
    final db = await database;
    final id = await db.insert('recordings', recording.toMap());
    final replicated = Recording(
      id: id,
      userId: recording.userId,
      date: recording.date,
      path: recording.path,
    );
    await CloudSync.instance.upsertRecording(replicated);
    return id;
  }

  Future<int> updateRecording(Recording recording) async {
    final db = await database;
    final rows = await db.update(
      'recordings',
      recording.toMap(),
      where: 'id = ?',
      whereArgs: [recording.id],
    );
    await CloudSync.instance.upsertRecording(recording);
    return rows;
  }

  Future<int> deleteRecording(int id) async {
    final db = await database;
    final existing = await db.query('recordings', where: 'id = ?', whereArgs: [id], limit: 1);
    final rows = await db.delete('recordings', where: 'id = ?', whereArgs: [id]);
    if (existing.isNotEmpty) {
      final r = Recording.fromMap(existing.first);
      await CloudSync.instance.deleteRecording(userId: r.userId, recordingId: id);
    }
    return rows;
  }

  Future<List<Recording>> getAllRecordings({int? userId}) async {
    final db = await database;
    final maps = userId == null
        ? await db.query('recordings', orderBy: 'date DESC')
        : await db.query(
            'recordings',
            where: 'userId = ?',
            whereArgs: [userId],
            orderBy: 'date DESC',
          );
    return maps.map((map) => Recording.fromMap(map)).toList();
  }

  Future<void> close() async {
    final db = await database;
    await db.close();
  }
}
