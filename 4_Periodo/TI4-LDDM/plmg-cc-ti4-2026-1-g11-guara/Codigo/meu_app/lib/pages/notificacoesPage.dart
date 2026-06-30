import 'package:flutter/material.dart';
import '../colors.dart';
import '../main.dart';
import 'gravacaoPage.dart';

class NotificacoesPage extends StatelessWidget {
  const NotificacoesPage({super.key});

  @override
  Widget build(BuildContext context) {
    final notificacoes = const [
      NotificacaoData(
        title: 'Alerta enviado',
        subtitle: 'Sua rede foi notificada com sucesso.',
      ),
      NotificacaoData(
        title: 'Gravação salva',
        subtitle: 'O áudio da última sessão foi armazenado.',
      ),
      NotificacaoData(
        title: 'Contato atualizado',
        subtitle: 'Os detalhes do contato foram alterados.',
      ),
    ];

    return SafeArea(
      child: Column(
        children: [
          Padding(
            padding: const EdgeInsets.fromLTRB(16, 18, 16, 8),
            child: Row(
              children: [
                GestureDetector(
                  onTap: () {
                    
                  },
                  child: Container(
                    padding: const EdgeInsets.all(10),
                  ),
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
          Expanded(
            child: ListView.separated(
              padding: const EdgeInsets.all(16),
              itemCount: notificacoes.length,
              separatorBuilder: (_, _) => const SizedBox(height: 14),
              itemBuilder: (context, index) {
                final item = notificacoes[index];
                return NotificacaoCard(notificacao: item);
              },
            ),
          ),
        ],
      ),
    );
  }
}

class NotificacaoData {
  final String title;
  final String subtitle;

  const NotificacaoData({required this.title, required this.subtitle});
}

class NotificacaoCard extends StatelessWidget {
  final NotificacaoData notificacao;

  const NotificacaoCard({super.key, required this.notificacao});

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.all(18),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(18),
        boxShadow: [
          BoxShadow(
            color: Color.fromRGBO(0, 0, 0, 0.05),
            blurRadius: 12,
            offset: const Offset(0, 7),
          ),
        ],
      ),
      child: Row(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          CircleAvatar(
            radius: 24,
            backgroundColor: corBackground,
            child: const Icon(Icons.notifications, color: corPrincipal),
          ),
          const SizedBox(width: 16),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(
                  notificacao.title,
                  style: const TextStyle(
                    fontSize: 16,
                    fontWeight: FontWeight.w700,
                  ),
                ),
                const SizedBox(height: 8),
                Text(
                  notificacao.subtitle,
                  style: const TextStyle(fontSize: 14, color: Colors.black54),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}