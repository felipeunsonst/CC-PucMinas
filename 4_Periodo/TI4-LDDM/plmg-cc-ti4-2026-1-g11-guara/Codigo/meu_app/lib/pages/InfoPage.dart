import 'package:Guara/colors.dart';
import 'package:flutter/material.dart';
import 'gravacaoPage.dart';
import '../main.dart';

Widget _img() {
  return Image.asset(
    "assets/images/logo.png",
    fit: BoxFit.cover,
  );
}

class InfoPage extends StatelessWidget {
  const InfoPage({super.key});
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: corBackground,
      body: SingleChildScrollView(
        padding: const EdgeInsets.fromLTRB(16, 0, 16, 24),
        child: Center(
          child: Column(
            children: [
              Padding(
                padding: const EdgeInsets.fromLTRB(0, 18, 0, 8),
                child: Row(
                  children: [
                    Align(
                      alignment: Alignment.centerLeft,
                      child: IconButton(
                        icon: const Icon(Icons.arrow_back),
                        onPressed: () {
                          Navigator.pop(context);
                        },
                      ),
                    ),
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
              Container(
                width: double.infinity,
                padding: const EdgeInsets.all(16),
                color: Colors.grey.shade200,
                child: Column(
                  children: [
                    const Text(
                      "Guará",
                      style: TextStyle(
                        fontSize: 22,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                    const SizedBox(height: 12),
                    SizedBox(
                      width: 120,
                      child: _img(),
                    ),
                    const SizedBox(height: 8),
                    const Text(
                      "Versão 1.0.0",
                      style: TextStyle(fontSize: 12),
                    ),
                  ],
                ),
              ),
              const SizedBox(height: 16),
              const Text(
                "Um app de alerta para pessoas que se encontram em situação de perigo ou risco. "
                "Você monta a sua rede de contatos de emergência e, quando se encontra em situação de risco, "
                "ativa um botão que grava o áudio dos arredores e aciona seus contatos de emergência. "
                "Com a transcrição de áudio, uma IA interpreta a situação e pode enviar mensagens para seus contatos "
                "e até contatar a polícia local.",
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 13),
              ),
              const SizedBox(height: 16),
              const Text(
                "ODS",
                style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
              ),
              const SizedBox(height: 8),
              const Text(
                "ODS 3 - Saúde e Bem-Estar: ligado à segurança física, prevenção de acidentes e violência.\n\n"
                "ODS 11 - Cidades e Comunidades Sustentáveis: foco em cidades seguras, resilientes e inclusivas.\n\n"
                "ODS 16 - Paz, Justiça e Instituições Eficazes: redução da violência e fortalecimento do estado de direito.",
                textAlign: TextAlign.center,
                style: TextStyle(fontSize: 13),
              ),
              const SizedBox(height: 16),
              const Text(
                "Desenvolvedores:",
                style: TextStyle(fontWeight: FontWeight.bold),
              ),
              const SizedBox(height: 6),
              const Text("Daniel Matos Marques"),
              const Text("Davi Manoel Bernardes"),
              const Text("Felipe Costa Unsonst"),
              const Text("Felipe Quites Lopes"),
              const Text("Nayron Campos Soares"),
              const Text("Victor Monteiro Martinelli Grataroli"),
              const SizedBox(height: 16),
              const Text(
                "GitHub:",
                style: TextStyle(fontWeight: FontWeight.bold),
              ),
              const SizedBox(height: 6),
              const Text(
                'https://github.com/ICEI-PUC-Minas-CC-TI/plmg-cc-ti4-2026-1-g11-guara',
              ),
            ],
          ),
        ),
      ),
    );
  }
}

