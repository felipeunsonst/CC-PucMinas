// ignore_for_file: library_private_types_in_public_api

import 'package:flutter/material.dart';
import 'data/cloud_sync.dart';
import 'data/database_helper.dart';
import 'data/session_helper.dart';
import 'pages/contatosPage.dart';
import 'pages/gravacaoPage.dart';
import 'pages/loginPage.dart';
import 'pages/notificacoesPage.dart';
import 'pages/perfilPage.dart';
import './colors.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();
  // 1) SQLite local — fonte de verdade no dispositivo.
  await DatabaseHelper.instance.database;
  // 2) Tenta inicializar nuvem (Firebase). Se não estiver configurada, segue local.
  await CloudSync.instance.init();
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'GUARÁ',
      debugShowCheckedModeBanner: false,
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: corPrincipal),
        scaffoldBackgroundColor: corBackground,
        useMaterial3: true,
      ),
      home: const _StartupGate(),
    );
  }
}

<<<<<<< Updated upstream
=======
/// Decide a tela inicial conforme a sessão persistida no SharedPreferences.
/// Analogia: é o "porteiro" — vê se já tem crachá (sessão) e libera direto
/// para a Home, ou manda para a recepção (Login).
class _StartupGate extends StatefulWidget {
  const _StartupGate();

  @override
  State<_StartupGate> createState() => _StartupGateState();
}

class _StartupGateState extends State<_StartupGate> {
  bool? _logged;

  @override
  void initState() {
    super.initState();
    _initializeSession();
  }

  Future<void> _initializeSession() async {
    bool logged = await SessionHelper.isLoggedIn();

    if (logged) {
      final userId = await SessionHelper.getLoggedUserId();
      logged = userId != null;
    }

    if (mounted) setState(() => _logged = logged);
  }

  @override
  Widget build(BuildContext context) {
    if (_logged == null) {
      return const Scaffold(
        body: Center(child: CircularProgressIndicator()),
      );
    }
    return _logged! ? const HomePage() : const LoginPage();
  }
}

>>>>>>> Stashed changes
class LogoCircle extends StatelessWidget {
  final double size;
  const LogoCircle({super.key, this.size = 120});

  @override
  Widget build(BuildContext context) {
    final double paddingValue = (size * 0.01).clamp(4.0, 16.0);

    return Container(
      width: size,
      height: size,
      decoration: BoxDecoration(
        color: Colors.white,
        shape: BoxShape.circle,
        border: Border.all(color: corEscura, width: 3),
        boxShadow: [
          BoxShadow(
            color: Color.fromRGBO(0, 0, 0, 0.08),
            blurRadius: 18,
            offset: const Offset(0, 10),
          ),
        ],
      ),
      padding: EdgeInsets.all(paddingValue),
      child: ClipOval(
        child: Image.asset('assets/images/logo.png', fit: BoxFit.contain),
      ),
    );
  }
}

class HomePage extends StatefulWidget {
  const HomePage({super.key});

  @override
  _HomePageState createState() => _HomePageState();
}

class _HomePageState extends State<HomePage> {
  int _indiceAtual = 1;

  static const List<Widget> _telas = [
    ContatosPage(),
    GravacaoPage(),
    NotificacoesPage(),
    PerfilPage(),
  ];

  void onTabTapped(int index) {
    setState(() {
      _indiceAtual = index;
    });
  }
  
  @override
  Widget build(BuildContext context) {
    return Scaffold(

      body: _telas[_indiceAtual],

      bottomNavigationBar: BottomNavigationBar(
        currentIndex: _indiceAtual,
        onTap: (index) {
          setState(() {
            _indiceAtual = index;
          });
        },
        type: BottomNavigationBarType.fixed,
        selectedItemColor: corPrincipal,
        selectedLabelStyle: TextStyle(
          fontSize: 12,
          fontWeight: FontWeight.bold,
        ),

        unselectedLabelStyle: TextStyle(
          fontSize: 12,
        ),

        items: [
          BottomNavigationBarItem(
            icon: Icon(Icons.group, size: 30),
            label: 'Contatos',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.mic, size: 34),
            label: 'Gravar',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.notifications, size: 30),
            label: 'Notificações',
          ),
          BottomNavigationBarItem(
            icon: Icon(Icons.person, size: 30),
            label: 'Perfil',
          ),
        ],
      ),
    );
  }
}