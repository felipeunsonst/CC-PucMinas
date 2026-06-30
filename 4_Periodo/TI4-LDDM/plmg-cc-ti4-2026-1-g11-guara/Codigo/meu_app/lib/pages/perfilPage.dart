import 'package:flutter/material.dart';

import '../colors.dart';
import '../data/session_helper.dart';
import '../main.dart';
import 'InfoPage.dart';
import 'gravacaoPage.dart';
import 'loginPage.dart';

class PerfilPage extends StatefulWidget {
  const PerfilPage({super.key});

  @override
  State<PerfilPage> createState() => _PerfilPageState();
}

class _PerfilPageState extends State<PerfilPage> {
  String _nome = 'Usuário';
  String _email = '';

  @override
  void initState() {
    super.initState();
    _carregarUsuario();
  }

  Future<void> _carregarUsuario() async {
    final nome = await SessionHelper.getLoggedUserName();
    final email = await SessionHelper.getLoggedUserEmail();
    if (!mounted) return;
    setState(() {
      _nome = nome ?? 'Usuário';
      _email = email ?? '';
    });
  }

  Future<void> _logout() async {
    await SessionHelper.clearSession();
    if (!mounted) return;
    Navigator.pushAndRemoveUntil(
      context,
      MaterialPageRoute(builder: (_) => const LoginPage()),
      (route) => false,
    );
  }

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: SingleChildScrollView(
        padding: const EdgeInsets.fromLTRB(16, 0, 16, 24),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Padding(
              padding: const EdgeInsets.fromLTRB(0, 18, 0, 0),
              child: Row(
                children: [
                  GestureDetector(
                    onTap: () {},
                    child: Container(padding: const EdgeInsets.all(10)),
                  ),
                  const Spacer(),
                  GestureDetector(
                    onTap: () {
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (_) => const GravacaoSessionPage(),
                        ),
                      );
                    },
                    child: const LogoCircle(size: 50),
                  ),
                ],
              ),
            ),
            const SizedBox(height: 20),
            Container(
              width: 110,
              height: 110,
              decoration: BoxDecoration(
                color: const Color.fromRGBO(2, 173, 90, 0.12),
                borderRadius: BorderRadius.circular(20),
                border: Border.all(
                  color: const Color.fromRGBO(0, 122, 63, 0.4),
                  width: 1.5,
                ),
              ),
              child: const Icon(Icons.person, size: 60, color: corPrincipal),
            ),
            const SizedBox(height: 20),
            Text(
              _nome,
              style: const TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 4),
            if (_email.isNotEmpty)
              Text(
                _email,
                style: const TextStyle(fontSize: 14, color: Colors.black54),
              ),
            const SizedBox(height: 8),
            const Text(
              'Segurança pessoal e contatos de emergência',
              textAlign: TextAlign.center,
              style: TextStyle(fontSize: 15, color: Colors.black54),
            ),
            const SizedBox(height: 24),
            PerfilOptionTile(
              icon: Icons.help_outline,
              title: 'Ajuda',
              subtitle: 'Saiba mais sobre o funcionamento do app.',
              onTap: () {
                Navigator.push(
                  context,
                  MaterialPageRoute(builder: (_) => const InfoPage()),
                );
              },
            ),
            PerfilOptionTile(
              icon: Icons.logout,
              title: 'Sair',
              subtitle: 'Encerra sua sessão neste dispositivo.',
              onTap: _logout,
            ),
          ],
        ),
      ),
    );
  }
}

class PerfilOptionTile extends StatelessWidget {
  final IconData icon;
  final String title;
  final String subtitle;
  final VoidCallback? onTap;

  const PerfilOptionTile({
    super.key,
    required this.icon,
    required this.title,
    required this.subtitle,
    this.onTap,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      margin: const EdgeInsets.only(bottom: 14),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(18),
        boxShadow: const [
          BoxShadow(
            color: Color.fromRGBO(0, 0, 0, 0.04),
            blurRadius: 12,
            offset: Offset(0, 8),
          ),
        ],
      ),
      child: ListTile(
        onTap: onTap,
        contentPadding: const EdgeInsets.all(16),
        leading: Container(
          width: 48,
          height: 48,
          decoration: BoxDecoration(
            color: corBackground,
            borderRadius: BorderRadius.circular(14),
          ),
          child: Icon(icon, color: corPrincipal),
        ),
        title: Text(
          title,
          style: const TextStyle(fontSize: 16, fontWeight: FontWeight.w700),
        ),
        subtitle: Text(
          subtitle,
          style: const TextStyle(fontSize: 14, color: Colors.black54),
        ),
        trailing: const Icon(
          Icons.arrow_forward_ios,
          size: 18,
          color: Colors.black38,
        ),
      ),
    );
  }
}
