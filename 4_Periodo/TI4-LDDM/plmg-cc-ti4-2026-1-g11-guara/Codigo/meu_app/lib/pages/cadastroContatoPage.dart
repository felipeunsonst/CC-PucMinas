import 'package:flutter/material.dart';

import '../colors.dart';
import '../data/database_helper.dart';
import '../data/session_helper.dart';
import '../main.dart';
import '../models/contact.dart';
import 'gravacaoPage.dart';

class CadastroContatoPage extends StatefulWidget {
  final Contact? contact;

  const CadastroContatoPage({super.key, this.contact});

  @override
  State<CadastroContatoPage> createState() => _CadastroContatoPageState();
}

class _CadastroContatoPageState extends State<CadastroContatoPage> {
  final _formKey = GlobalKey<FormState>();
  final TextEditingController nomeController = TextEditingController();
  final TextEditingController relacaoController = TextEditingController();
  final TextEditingController telefoneController = TextEditingController();
  bool _salvando = false;

  @override
  void initState() {
    super.initState();
    // Pré-preenche em modo edição.
    final c = widget.contact;
    if (c != null) {
      nomeController.text = c.name;
      relacaoController.text = c.relationship;
      telefoneController.text = c.phoneNumber;
    }
  }

  @override
  void dispose() {
    nomeController.dispose();
    relacaoController.dispose();
    telefoneController.dispose();
    super.dispose();
  }

  Future<void> _salvar() async {
    if (!_formKey.currentState!.validate()) return;
    setState(() => _salvando = true);

    try {
      final userId = await SessionHelper.getLoggedUserId() ??
          DatabaseHelper.defaultUserId;

      if (widget.contact == null) {
        // Inserção.
        await DatabaseHelper.instance.insertContact(
          Contact(
            userId: userId,
            name: nomeController.text.trim(),
            relationship: relacaoController.text.trim(),
            phoneNumber: telefoneController.text.trim(),
          ),
        );
      } else {
        // Atualização.
        await DatabaseHelper.instance.updateContact(
          Contact(
            id: widget.contact!.id,
            userId: widget.contact!.userId,
            name: nomeController.text.trim(),
            relationship: relacaoController.text.trim(),
            phoneNumber: telefoneController.text.trim(),
            dateCreated: widget.contact!.dateCreated,
          ),
        );
      }

      if (!mounted) return;
      Navigator.pop(context, true);
    } catch (e) {
      if (!mounted) return;
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text('Erro ao salvar contato: $e')),
      );
    } finally {
      if (mounted) setState(() => _salvando = false);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: corBackground,
      body: SafeArea(
        child: SingleChildScrollView(
          padding: const EdgeInsets.fromLTRB(16, 0, 16, 24),
          child: Form(
            key: _formKey,
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.center,
              children: [
                Padding(
                  padding: const EdgeInsets.fromLTRB(0, 18, 0, 8),
                  child: Row(
                    children: [
                      Align(
                        alignment: Alignment.centerLeft,
                        child: IconButton(
                          icon: const Icon(Icons.arrow_back),
                          onPressed: () => Navigator.pop(context),
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
                  width: 220,
                  height: 220,
                  decoration: BoxDecoration(
                    color: const Color.fromRGBO(2, 173, 90, 0.12),
                    borderRadius: BorderRadius.circular(16),
                    border: Border.all(
                      color: const Color.fromRGBO(0, 122, 63, 0.4),
                      width: 1.5,
                    ),
                  ),
                  child: const Icon(Icons.person, size: 100, color: corPrincipal),
                ),
                const SizedBox(height: 24),
                const Text(
                  'Informações do contato',
                  style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
                ),
                const SizedBox(height: 12),
                _buildInput(
                  label: 'Nome',
                  controller: nomeController,
                  icon: Icons.person,
                  validator: (v) =>
                      (v == null || v.trim().isEmpty) ? 'Informe o nome' : null,
                ),
                const SizedBox(height: 12),
                _buildInput(
                  label: 'Relação',
                  controller: relacaoController,
                  icon: Icons.group,
                  validator: (v) =>
                      (v == null || v.trim().isEmpty) ? 'Informe a relação' : null,
                ),
                const SizedBox(height: 12),
                _buildInput(
                  label: 'Telefone',
                  controller: telefoneController,
                  icon: Icons.phone,
                  keyboardType: TextInputType.phone,
                  validator: (v) =>
                      (v == null || v.trim().isEmpty) ? 'Informe o telefone' : null,
                ),
                const SizedBox(height: 28),
                SizedBox(
                  width: double.infinity,
                  child: ElevatedButton(
                    style: ElevatedButton.styleFrom(
                      backgroundColor: corPrincipal,
                      padding: const EdgeInsets.symmetric(vertical: 18),
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(16),
                      ),
                      elevation: 2,
                    ),
                    onPressed: _salvando ? null : _salvar,
                    child: _salvando
                        ? const SizedBox(
                            height: 22,
                            width: 22,
                            child: CircularProgressIndicator(
                              color: Colors.white,
                              strokeWidth: 2,
                            ),
                          )
                        : Text(
                            widget.contact != null
                                ? 'Salvar Alterações'
                                : 'Cadastrar Contato',
                            style: const TextStyle(fontSize: 15, color: Colors.white),
                          ),
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }

  Widget _buildInput({
    required String label,
    required TextEditingController controller,
    required IconData icon,
    TextInputType keyboardType = TextInputType.text,
    String? Function(String?)? validator,
  }) {
    return TextFormField(
      controller: controller,
      keyboardType: keyboardType,
      validator: validator,
      decoration: InputDecoration(
        prefixIcon: Icon(icon, color: corPrincipal),
        labelText: label,
        filled: true,
        fillColor: Colors.white,
        contentPadding: const EdgeInsets.symmetric(vertical: 16),
        border: OutlineInputBorder(
          borderRadius: BorderRadius.circular(16),
          borderSide: BorderSide.none,
        ),
      ),
    );
  }
}
