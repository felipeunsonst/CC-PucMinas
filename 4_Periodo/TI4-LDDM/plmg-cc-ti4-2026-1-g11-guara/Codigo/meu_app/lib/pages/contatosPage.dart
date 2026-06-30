import 'package:flutter/material.dart';
import '../colors.dart';
import '../data/database_helper.dart';
import '../data/session_helper.dart';
import '../models/contact.dart';
import '../main.dart';
import 'cadastroContatoPage.dart';
import 'gravacaoPage.dart';

class ContatosPage extends StatefulWidget {
  const ContatosPage({super.key});

  @override
  State<ContatosPage> createState() => _ContatosPageState();
}

class _ContatosPageState extends State<ContatosPage> {
  List<Contact> contatos = [];
  bool loading = true;

  @override
  void initState() {
    super.initState();
    _loadContacts();
  }

  Future<void> _loadContacts() async {
    final userId = await SessionHelper.getLoggedUserId();
    final savedContacts = await DatabaseHelper.instance.getAllContacts(
      userId: userId,
    );
    if (!mounted) return;
    setState(() {
      contatos = savedContacts;
      loading = false;
    });
  }

  Future<void> _openContactForm({Contact? contact}) async {
    final result = await Navigator.push<bool>(
      context,
      MaterialPageRoute(
        builder: (_) => CadastroContatoPage(contact: contact),
      ),
    );

    if (result == true) {
      await _loadContacts();
    }
  }

  Future<void> _confirmDelete(Contact contact) async {
    final confirmed = await showDialog<bool>(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: const Text('Excluir contato'),
          content: Text('Deseja excluir ${contact.name}?'),
          actions: [
            TextButton(
              onPressed: () => Navigator.pop(context, false),
              child: const Text('Cancelar'),
            ),
            TextButton(
              onPressed: () => Navigator.pop(context, true),
              child: const Text('Excluir'),
            ),
          ],
        );
      },
    );

    if (confirmed == true) {
      await DatabaseHelper.instance.deleteContact(contact.id!);
      await _loadContacts();
    }
  }

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Column(
        children: [
          Padding(
            padding: const EdgeInsets.fromLTRB(16, 18, 16, 8),
            child: Row(
              children: [
                GestureDetector(
                  onTap: () {},
                  child: Container(
                    padding: const EdgeInsets.all(10),
                  ),
                ),
                const Spacer(),
                GestureDetector(
                  onTap: () {
                    Navigator.push<bool>(
                      context,
                      MaterialPageRoute(
                        builder: (_) => const GravacaoSessionPage(),
                      ),
                    ).then((saved) {
                      if (saved == true) {
                        // nothing to do here for contacts
                      }
                    });
                  },
                  child: const LogoCircle(size: 50),
                ),
              ],
            ),
          ),
          if (loading)
            const Expanded(
              child: Center(child: CircularProgressIndicator()),
            )
          else
            Expanded(
              child: contatos.isEmpty
                  ? const Center(
                      child: Text(
                        'Nenhum contato cadastrado ainda.',
                        style: TextStyle(fontSize: 16, color: Colors.black54),
                      ),
                    )
                  : ListView.separated(
                      padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
                      itemCount: contatos.length,
                      separatorBuilder: (_, _) => const SizedBox(height: 16),
                      itemBuilder: (context, index) {
                        final contato = contatos[index];
                        return ContatoCard(
                          contato: contato,
                          onEdit: () => _openContactForm(contact: contato),
                          onDelete: () => _confirmDelete(contato),
                        );
                      },
                    ),
            ),
          Container(
            padding: const EdgeInsets.fromLTRB(16, 12, 16, 20),
            color: corBackground,
            child: Row(
              children: [
                Expanded(
                  child: OutlinedButton(
                    style: OutlinedButton.styleFrom(
                      foregroundColor: corPrincipal,
                      side: const BorderSide(color: corPrincipal, width: 1.8),
                      padding: const EdgeInsets.symmetric(vertical: 16),
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(16),
                      ),
                      backgroundColor: Colors.white,
                    ),
                    onPressed: () => _openContactForm(),
                    child: const Text(
                      'Adicionar',
                      style: TextStyle(fontSize: 15),
                    ),
                  ),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}

class ContatoCard extends StatelessWidget {
  final Contact contato;
  final VoidCallback onEdit;
  final VoidCallback onDelete;

  const ContatoCard({
    super.key,
    required this.contato,
    required this.onEdit,
    required this.onDelete,
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      padding: const EdgeInsets.all(18),
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [
          BoxShadow(
            color: const Color.fromRGBO(0, 0, 0, 0.04),
            blurRadius: 14,
            offset: const Offset(0, 8),
          ),
        ],
      ),
      child: Row(
        children: [
          Container(
            width: 52,
            height: 52,
            decoration: BoxDecoration(
              color: const Color.fromRGBO(2, 173, 90, 0.12),
              borderRadius: BorderRadius.circular(16),
              border: Border.all(
                color: const Color.fromRGBO(0, 122, 63, 0.4),
              ),
            ),
            child: const Icon(Icons.person, size: 30, color: corPrincipal),
          ),
          const SizedBox(width: 16),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text(
                  contato.name,
                  style: const TextStyle(
                    fontSize: 16,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                const SizedBox(height: 6),
                Text(
                  contato.relationship,
                  style: const TextStyle(fontSize: 14, color: Colors.black54),
                ),
                const SizedBox(height: 6),
                Text(
                  contato.phoneNumber,
                  style: const TextStyle(fontSize: 14, color: Colors.black87),
                ),
              ],
            ),
          ),
          PopupMenuButton<String>(
            icon: const Icon(Icons.more_horiz, color: Colors.black54),
            onSelected: (value) {
              if (value == 'edit') {
                onEdit();
              } else if (value == 'delete') {
                onDelete();
              }
            },
            itemBuilder: (context) => const [
              PopupMenuItem(value: 'edit', child: Text('Editar')),
              PopupMenuItem(value: 'delete', child: Text('Excluir')),
            ],
          ),
        ],
      ),
    );
  }
}
