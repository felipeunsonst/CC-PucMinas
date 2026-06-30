import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:connectivity_plus/connectivity_plus.dart';
import 'package:firebase_core/firebase_core.dart';

import '../models/contact.dart';
import '../models/recording.dart';
import '../models/user.dart';

/// Camada de sincronização com o armazenamento em nuvem (Firebase Firestore).
///
/// Analogia: o SQLite é o "armário em casa" (rápido, sempre acessível).
/// O Firestore é o "cofre na nuvem" — mais seguro contra perda do dispositivo
/// e acessível por outros aparelhos. Esta classe é o "carteiro" que leva
/// cópias entre os dois lados, e nunca falha o app se a nuvem estiver
/// indisponível (o usuário continua trabalhando com o armário local).
class CloudSync {
  CloudSync._();
  static final CloudSync instance = CloudSync._();

  bool _ready = false;
  FirebaseFirestore? _db;

  /// Inicializa o Firebase. Se falhar (ex.: ainda não foi rodado
  /// `flutterfire configure`), retorna false silenciosamente e o app
  /// segue 100% local.
  Future<bool> init() async {
    if (_ready) return true;
    try {
      if (Firebase.apps.isEmpty) {
        await Firebase.initializeApp();
      }
      _db = FirebaseFirestore.instance;
      _ready = true;
      return true;
    } catch (_) {
      _ready = false;
      _db = null;
      return false;
    }
  }

  bool get isReady => _ready && _db != null;

  Future<bool> _hasNetwork() async {
    try {
      final result = await Connectivity().checkConnectivity();
      return !result.contains(ConnectivityResult.none);
    } catch (_) {
      return false;
    }
  }

  Future<bool> _canSync() async {
    if (!isReady) return false;
    return await _hasNetwork();
  }

  // ---------- USERS ----------

  Future<void> upsertUser(User user) async {
    if (!await _canSync()) return;
    if (user.id == null) return;
    try {
      await _db!.collection('users').doc(user.id.toString()).set({
        'id': user.id,
        'name': user.name,
        'email': user.email,
        // Em produção a senha NUNCA deveria ir em texto claro,
        // mas o schema do projeto exige o campo. Usamos um hash leve em
        // database_helper.dart antes de gravar.
        'password': user.password,
        'dateCreated': user.dateCreated.toIso8601String(),
      }, SetOptions(merge: true));
    } catch (_) {
      // Falha silenciosa — local continua sendo a fonte de verdade.
    }
  }

  // ---------- CONTACTS ----------

  Future<void> upsertContact(Contact contact) async {
    if (!await _canSync()) return;
    if (contact.id == null) return;
    try {
      await _db!
          .collection('users')
          .doc(contact.userId.toString())
          .collection('contacts')
          .doc(contact.id.toString())
          .set({
        'id': contact.id,
        'userId': contact.userId,
        'name': contact.name,
        'relationship': contact.relationship,
        'phoneNumber': contact.phoneNumber,
        'dateCreated': contact.dateCreated.toIso8601String(),
      }, SetOptions(merge: true));
    } catch (_) {}
  }

  Future<void> deleteContact({required int userId, required int contactId}) async {
    if (!await _canSync()) return;
    try {
      await _db!
          .collection('users')
          .doc(userId.toString())
          .collection('contacts')
          .doc(contactId.toString())
          .delete();
    } catch (_) {}
  }

  // ---------- RECORDINGS ----------

  Future<void> upsertRecording(Recording recording) async {
    if (!await _canSync()) return;
    if (recording.id == null) return;
    try {
      await _db!
          .collection('users')
          .doc(recording.userId.toString())
          .collection('recordings')
          .doc(recording.id.toString())
          .set({
        'id': recording.id,
        'userId': recording.userId,
        'date': recording.date.toIso8601String(),
        'path': recording.path,
      }, SetOptions(merge: true));
    } catch (_) {}
  }

  Future<void> deleteRecording({required int userId, required int recordingId}) async {
    if (!await _canSync()) return;
    try {
      await _db!
          .collection('users')
          .doc(userId.toString())
          .collection('recordings')
          .doc(recordingId.toString())
          .delete();
    } catch (_) {}
  }
}
