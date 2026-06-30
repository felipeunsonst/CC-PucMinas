import 'package:shared_preferences/shared_preferences.dart';

/// Camada de persistência leve baseada em SharedPreferences.
///
/// Analogia: pense no SQLite como um arquivo de armazém (estruturado, com
/// prateleiras e formulários), e no SharedPreferences como um post-it grudado
/// na geladeira — para anotações pequenas e rápidas (quem está logado,
/// último e-mail digitado, preferência de tema, etc.).
class SessionHelper {
  SessionHelper._();

  static const String _kLoggedUserId = 'logged_user_id';
  static const String _kLoggedUserName = 'logged_user_name';
  static const String _kLoggedUserEmail = 'logged_user_email';
  static const String _kRememberEmail = 'remember_email';
  static const String _kIsLoggedIn = 'is_logged_in';

  /// Salva os dados da sessão após login/cadastro bem sucedido.
  static Future<void> saveSession({
    required int userId,
    required String name,
    required String email,
  }) async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setInt(_kLoggedUserId, userId);
    await prefs.setString(_kLoggedUserName, name);
    await prefs.setString(_kLoggedUserEmail, email);
    await prefs.setBool(_kIsLoggedIn, true);
  }

  /// Lembrar último e-mail digitado (UX para pré-preencher login).
  static Future<void> rememberEmail(String email) async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setString(_kRememberEmail, email);
  }

  static Future<String?> getRememberedEmail() async {
    final prefs = await SharedPreferences.getInstance();
    return prefs.getString(_kRememberEmail);
  }

  static Future<bool> isLoggedIn() async {
    final prefs = await SharedPreferences.getInstance();
    return prefs.getBool(_kIsLoggedIn) ?? false;
  }

  static Future<int?> getLoggedUserId() async {
    final prefs = await SharedPreferences.getInstance();
    return prefs.getInt(_kLoggedUserId);
  }

  static Future<String?> getLoggedUserName() async {
    final prefs = await SharedPreferences.getInstance();
    return prefs.getString(_kLoggedUserName);
  }

  static Future<String?> getLoggedUserEmail() async {
    final prefs = await SharedPreferences.getInstance();
    return prefs.getString(_kLoggedUserEmail);
  }

  /// Encerra sessão. Mantém o "remember email" para facilitar próximo login.
  static Future<void> clearSession() async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.remove(_kLoggedUserId);
    await prefs.remove(_kLoggedUserName);
    await prefs.remove(_kLoggedUserEmail);
    await prefs.setBool(_kIsLoggedIn, false);
  }
}
