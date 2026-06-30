import 'dart:async';

import 'package:flutter/material.dart';
import 'package:speech_to_text/speech_to_text.dart' as stt;

import '../colors.dart';
import '../data/database_helper.dart';
import '../data/session_helper.dart';
import '../models/recording.dart';

class GravacaoPage extends StatefulWidget {
  const GravacaoPage({super.key});

  @override
  State<GravacaoPage> createState() => _GravacaoPageState();
}

class _GravacaoPageState extends State<GravacaoPage> {
  List<Recording> gravacoes = [];
  bool loading = true;

  @override
  void initState() {
    super.initState();
    _loadRecordings();
  }

  Future<void> _loadRecordings() async {
    final userId = await SessionHelper.getLoggedUserId();
    if (!mounted) return;
    if (userId == null) {
      setState(() {
        gravacoes = [];
        loading = false;
      });
      return;
    }

    final saved = await DatabaseHelper.instance.getAllRecordings(userId: userId);
    if (!mounted) return;
    setState(() {
      gravacoes = saved;
      loading = false;
    });
  }

  String _formatDate(DateTime date) {
    return '${date.day.toString().padLeft(2, "0")}/${date.month.toString().padLeft(2, "0")} ${date.hour.toString().padLeft(2, "0")}:${date.minute.toString().padLeft(2, "0")}';
  }

  @override
  Widget build(BuildContext context) {
    return SafeArea(
      child: Column(
        children: [
          const SizedBox(height: 100),
          Padding(
            padding: const EdgeInsets.symmetric(horizontal: 20),
            child: Row(
              children: const [],
            ),
          ),
          const SizedBox(height: 18),
          GestureDetector(
            onTap: () {
              Navigator.push(
                context,
<<<<<<< Updated upstream
                MaterialPageRoute(builder: (_) => const GravacaoSessionPage()),
              );
=======
                MaterialPageRoute(builder: (_) => const GravacaoSessionPage(autoStart: true)),
              ).then((saved) {
                if (saved == true) {
                  _loadRecordings();
                }
              });
>>>>>>> Stashed changes
            },
            child: Center(
              child: Container(
                width: 220,
                height: 220,
                decoration: BoxDecoration(
                  color: corPrincipal,
                  shape: BoxShape.circle,
                  boxShadow: [
                    BoxShadow(
                      color: Color.fromRGBO(0, 0, 0, 0.12),
                      blurRadius: 22,
                      offset: const Offset(0, 12),
                    ),
                  ],
                ),
                child: Center(
                  child: ClipOval(
                    child: Image.asset(
                      'assets/images/logo.png',
                      width: 120,
                      height: 120,
                      fit: BoxFit.contain,
                    ),
                  ),
                ),
              ),
            ),
          ),
          const SizedBox(height: 40),
          Expanded(
            child: Container(
              width: double.infinity,
              decoration: BoxDecoration(
                color: Colors.white,
                borderRadius: const BorderRadius.vertical(
                  top: Radius.circular(30),
                ),
                boxShadow: [
                  BoxShadow(
                                    MaterialPageRoute(builder: (_) => const GravacaoSessionPage(autoStart: true)),
                    blurRadius: 16,
                    offset: const Offset(0, -8),
                  ),
                ],
              ),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  const Padding(
                    padding: EdgeInsets.symmetric(horizontal: 24, vertical: 20),
                    child: Text(
                      'Gravações recentes',
                      style: TextStyle(
                        fontSize: 18,
                        fontWeight: FontWeight.bold,
                      ),
                    ),
                  ),
                  Expanded(
                    child: loading
                        ? const Center(child: CircularProgressIndicator())
                        : gravacoes.isEmpty
                            ? const Center(
                                child: Text(
                                  'Nenhuma gravação encontrada. Faça uma nova gravação para salvar.',
                                  textAlign: TextAlign.center,
                                  style: TextStyle(fontSize: 16, color: Colors.black54),
                                ),
                              )
                            : ListView.separated(
                                padding: const EdgeInsets.symmetric(horizontal: 16),
                                itemCount: gravacoes.length,
                                separatorBuilder: (_, _) => const SizedBox(height: 14),
                                itemBuilder: (context, index) {
                                  final recording = gravacoes[index];
                                  return RecordingCard(
                                    recording: recording,
                                    onDelete: () async {
                                      if (recording.id != null) {
                                        await DatabaseHelper.instance.deleteRecording(recording.id!);
                                        _loadRecordings();
                                      }
                                    },
                                  );
                                },
                              ),
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}

<<<<<<< Updated upstream
class GravacaoSessionPage extends StatelessWidget {
  const GravacaoSessionPage({super.key});
=======
class RecordingCard extends StatefulWidget {
  final Recording recording;
  final VoidCallback onDelete;

  const RecordingCard({super.key, required this.recording, required this.onDelete});

  @override
  State<RecordingCard> createState() => _RecordingCardState();
}

class _RecordingCardState extends State<RecordingCard> {
  bool isPlaying = false;

  String _formatDate(DateTime date) {
    return '${date.day.toString().padLeft(2, "0")}/${date.month.toString().padLeft(2, "0")} ${date.hour.toString().padLeft(2, "0")}:${date.minute.toString().padLeft(2, "0")}';
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 110,
                child: Column(
        color: Colors.white,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [
          BoxShadow(
            color: Color.fromRGBO(0, 0, 0, 0.05),
            blurRadius: 14,
            offset: const Offset(0, 8),
          ),
        ],
      ),
      padding: const EdgeInsets.all(18),
      child: Row(
        children: [
          GestureDetector(
            onTap: () {
              setState(() {
                isPlaying = !isPlaying;
              });
            },
            child: Container(
              width: 50,
              height: 50,
              decoration: BoxDecoration(
                color: const Color.fromRGBO(2, 173, 90, 0.24),
                borderRadius: BorderRadius.circular(14),
              ),
              child: Icon(
                isPlaying ? Icons.pause : Icons.play_arrow,
                color: corEscura,
                size: 28,
              ),
            ),
          ),
          const SizedBox(width: 18),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  'Gravação ${widget.recording.id ?? ''}',
                  style: const TextStyle(
                    fontSize: 16,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                const SizedBox(height: 8),
                Text(
                  _formatDate(widget.recording.date),
                  style: const TextStyle(fontSize: 14, color: Colors.black54),
                ),
class RecordingCard extends StatefulWidget {
  final Recording recording;
  final VoidCallback onDelete;

  const RecordingCard({super.key, required this.recording, required this.onDelete});

  @override
  State<RecordingCard> createState() => _RecordingCardState();
}

class _RecordingCardState extends State<RecordingCard> {
  bool isPlaying = false;

  String _formatDate(DateTime date) {
    return '${date.day.toString().padLeft(2, "0")}/${date.month.toString().padLeft(2, "0")} ${date.hour.toString().padLeft(2, "0")}:${date.minute.toString().padLeft(2, "0")}';
  }

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 110,
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [
          BoxShadow(
            color: Color.fromRGBO(0, 0, 0, 0.05),
            blurRadius: 14,
            offset: const Offset(0, 8),
          ),
        ],
      ),
      padding: const EdgeInsets.all(18),
      child: Row(
        children: [
          GestureDetector(
            onTap: () {
              setState(() {
                isPlaying = !isPlaying;
              });
            },
            child: Container(
              width: 50,
              height: 50,
              decoration: BoxDecoration(
                color: const Color.fromRGBO(2, 173, 90, 0.24),
                borderRadius: BorderRadius.circular(14),
              ),
              child: Icon(
                isPlaying ? Icons.pause : Icons.play_arrow,
                color: corEscura,
                size: 28,
              ),
            ),
          ),
          const SizedBox(width: 18),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  'Gravação ${widget.recording.id ?? ''}',
                  style: const TextStyle(
                    fontSize: 16,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                const SizedBox(height: 8),
                Text(
                  _formatDate(widget.recording.date),
                  style: const TextStyle(fontSize: 14, color: Colors.black54),
                ),
                const SizedBox(height: 6),
                Text(
                  widget.recording.path,
                  style: const TextStyle(fontSize: 12, color: Colors.black45),
                  overflow: TextOverflow.ellipsis,
                ),
              ],
            ),
          ),
          PopupMenuButton<String>(
            icon: const Icon(Icons.more_horiz, color: Colors.black54),
            onSelected: (value) {
              if (value == 'delete') {
                widget.onDelete();
              }
            },
            itemBuilder: (context) => const [
              PopupMenuItem(
                value: 'delete',
                child: Text('Excluir'),
              ),
            ],
          ),
        ],
      ),
    );
  }
}

class GravacaoSessionPage extends StatefulWidget {
  final bool autoStart;

  const GravacaoSessionPage({super.key, this.autoStart = false});

  @override
  State<GravacaoSessionPage> createState() => _GravacaoSessionPageState();
}

class _GravacaoSessionPageState extends State<GravacaoSessionPage> {
  late stt.SpeechToText _speechToText;
  bool _isListening = false;
  String _transcription = '';
  String _timerText = '00:00';
  int _elapsedSeconds = 0;
  Timer? _timer;
  bool _keepListeningOnIdle = false;
  bool _isInitialized = false;
  String _errorMessage = '';
  bool _isInitializing = false;

  @override
  void initState() {
    super.initState();
    _speechToText = stt.SpeechToText();
    _initializeSpeechToText();
  }

  Future<void> _initializeSpeechToText() async {
    if (_isInitialized || _isInitializing) return;
    try {
      setState(() {
        _isInitializing = true;
      });
      bool available = await _speechToText.initialize(
        onError: (error) {
          final String errorMsg = error.errorMsg;
          if (mounted) {
            if (_keepListeningOnIdle) {
              setState(() {
                _errorMessage = 'Erro de áudio: $errorMsg. Reiniciando...';
                _isListening = false;
              });
              _stopTimer();
              _restartListeningDelayed();
              return;
            }

            setState(() {
              _errorMessage = 'Erro de áudio: $errorMsg';
              _isListening = false;
            });
            _stopTimer();
          }
        },
        onStatus: (status) {
          if (status == 'done' || status == 'notListening') {
            if (_keepListeningOnIdle) {
              if (mounted) {
                setState(() {
                  _isListening = false;
                  _errorMessage = 'Reconhecimento pausado. Reiniciando...';
                });
              }
              _stopTimer();
              _restartListeningDelayed();
              return;
            }
            if (mounted && _isListening) {
              setState(() => _isListening = false);
              _stopTimer();
            }
          }
        },
      );

      if (available) {
        if (mounted) {
          setState(() {
            _isInitialized = true;
            _errorMessage = '';
            _isInitializing = false;
          });
          if (widget.autoStart) {
            WidgetsBinding.instance.addPostFrameCallback((_) {
              if (mounted) _startListening();
            });
          }
        }
      } else {
        if (mounted) {
          setState(() {
            _errorMessage = 'Não disponível. Ative o Ditado nas configurações do sistema.';
            _isInitializing = false;
          });
        }
      }
    } catch (e) {
      if (mounted) {
        setState(() {
          _errorMessage = 'Erro na inicialização: $e';
          _isInitializing = false;
        });
      }
    }
  }

  void _startListening() async {
    if (_isListening) return;
    if (!_isInitialized) {
      await _initializeSpeechToText();
      if (!_isInitialized) return;
    }

    try {
      await _speechToText.listen(
        onResult: (result) {
          if (!mounted) return;
          if (result.recognizedWords.trim().isEmpty) return;
          setState(() {
            _transcription = result.recognizedWords;
          });
        },
      );

      if (_speechToText.isListening) {
        if (mounted) {
          setState(() {
            _keepListeningOnIdle = true;
            _isListening = true;
            _errorMessage = '';
          });
        }
        _startTimer();
      } else {
        if (mounted) {
          setState(() {
            _errorMessage = 'O sistema operacional recusou iniciar a escuta.';
          });
        }
      }
    } catch (e) {
      if (mounted) {
        setState(() {
          _errorMessage = 'Erro: $e';
        });
      }
    }
  }

  Future<void> _stopListening() async {
    _keepListeningOnIdle = false;
    try {
      await _speechToText.stop();
      if (mounted) {
        setState(() => _isListening = false);
      }
      _stopTimer();
    } catch (e) {}
  }

  void _startTimer() {
    _timer?.cancel();
    _elapsedSeconds = 0;
    _timer = Timer.periodic(const Duration(seconds: 1), (timer) {
      if (mounted) {
        setState(() {
          _elapsedSeconds++;
          int minutes = _elapsedSeconds ~/ 60;
          int seconds = _elapsedSeconds % 60;
          _timerText = '${minutes.toString().padLeft(2, '0')}:${seconds.toString().padLeft(2, '0')}';
        });
      }
    });
  }

  void _stopTimer() {
    _timer?.cancel();
  }

  void _restartListeningDelayed() {
    Future.delayed(const Duration(milliseconds: 400), () {
      if (!mounted || !_keepListeningOnIdle) return;
      _startListening();
    });
  }

  @override
  void dispose() {
    _keepListeningOnIdle = false;
    _stopTimer();
    _speechToText.cancel();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: Padding(
          padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 18),
          child: Column(
            children: [
              Container(
                width: 270,
                height: 270,
                decoration: BoxDecoration(
                  color: Colors.white,
                  shape: BoxShape.circle,
                  boxShadow: [
                    BoxShadow(
                      color: Color.fromRGBO(0, 0, 0, 0.12),
                      blurRadius: 22,
                      offset: const Offset(0, 12),
                    ),
                  ],
                ),
                child: Center(
                  child: Column(
                    mainAxisSize: MainAxisSize.min,
                    children: [
                      const Icon(Icons.mic, color: corPrincipal, size: 48),
                      const SizedBox(height: 12),
                      Text(
                        _timerText,
                        style: const TextStyle(
                          fontSize: 28,
                          fontWeight: FontWeight.bold,
                        ),
                      ),
                      const SizedBox(height: 6),
                      Text(
                        'Max 5:00 minutos',
                        style: TextStyle(
                          fontSize: 14,
                          color: Colors.grey.shade600,
                        ),
                      ),
                    ],
                  ),
                ),
              ),
              const SizedBox(height: 24),
              Container(
                width: double.infinity,
                height: 160,
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.circular(20),
                  border: Border.all(color: const Color.fromRGBO(0, 122, 63, 0.25), width: 1.8),
                ),
                padding: const EdgeInsets.all(16),
                child: Align(
                  alignment: Alignment.topLeft,
                  child: Text(
                    _transcription.isEmpty ? 'Transcrição do áudio aparecerá aqui...' : _transcription,
                    style: const TextStyle(fontSize: 14, color: Colors.black54),
                  ),
                ),
              ),
              const SizedBox(height: 20),
              Row(
                children: [
                  Expanded(
                    child: OutlinedButton(
                      style: OutlinedButton.styleFrom(
                        foregroundColor: corPrincipal,
                        side: const BorderSide(
                          color: corPrincipal,
                          width: 1.8,
                        ),
                        padding: const EdgeInsets.symmetric(vertical: 16),
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(18),
                        ),
                        backgroundColor: Colors.white,
                      ),
                      onPressed: () => Navigator.pop(context),
                      child: const Text(
                        'Cancelar',
                        style: TextStyle(fontSize: 16),
                      ),
                    ),
                  ),
                  const SizedBox(width: 14),
                  Expanded(
                    child: ElevatedButton(
                      style: ElevatedButton.styleFrom(
                        backgroundColor: corPrincipal,
                        foregroundColor: Colors.white,
                        padding: const EdgeInsets.symmetric(vertical: 16),
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(18),
                        ),
                      ),
                      onPressed: _transcription.isEmpty
                          ? null
                          : () async {
                              await _stopListening();
                              final userId = await SessionHelper.getLoggedUserId();
                              if (userId == null) {
                                if (mounted) {
                                  ScaffoldMessenger.of(context).showSnackBar(
                                    const SnackBar(
                                      content: Text('Usuário não encontrado. Faça login novamente.'),
                                    ),
                                  );
                                }
                                return;
                              }

                              await DatabaseHelper.instance.insertRecording(
                                Recording(
                                  userId: userId,
                                  date: DateTime.now(),
                                  path: 'local_recording_${DateTime.now().millisecondsSinceEpoch}.m4a',
                                ),
                              );

                              if (mounted) {
                                ScaffoldMessenger.of(context).showSnackBar(
                                  const SnackBar(
                                    content: Text('Gravação salva no banco local.'),
                                  ),
                                );
                              }

                              Navigator.pop(context, true);
                            },
                      child: const Text(
                        'Salvar',
                        style: TextStyle(fontSize: 16),
                      ),
                    ),
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }
}
                ),
              ],
            ),
          ),
          PopupMenuButton<String>(
            icon: const Icon(Icons.more_horiz, color: Colors.black54),
            onSelected: (value) {
              if (value == 'delete') {
                widget.onDelete();
              }
            },
            itemBuilder: (context) => const [
              PopupMenuItem(
                value: 'delete',
                child: Text('Excluir'),
              ),
            ],
          ),
        ],
      ),
    );
  }
}

class GravacaoSessionPage extends StatefulWidget {
  final bool autoStart;

  const GravacaoSessionPage({super.key, this.autoStart = false});

  @override
  State<GravacaoSessionPage> createState() => _GravacaoSessionPageState();
}

class _GravacaoSessionPageState extends State<GravacaoSessionPage> {
  late stt.SpeechToText _speechToText;
  bool _isListening = false;
  String _transcription = '';
  String _timerText = '00:00';
  int _elapsedSeconds = 0;
  Timer? _timer;
  bool _keepListeningOnIdle = false;
  bool _isInitialized = false;
  String _errorMessage = '';
  bool _isInitializing = false;

  @override
  void initState() {
    super.initState();
    _speechToText = stt.SpeechToText();
    // Inicializa assim que a tela abre, evitando conflito no clique do botão
    _initializeSpeechToText();
  }

  Future<void> _initializeSpeechToText() async {
    if (_isInitialized || _isInitializing) return;
    
    try {
      setState(() {
        _isInitializing = true;
      });
      
      print('Inicializando speech to text...');
      
      bool available = await _speechToText.initialize(
        onError: (error) {
          print('Erro no speech to text: $error');
          final String errorMsg = error.errorMsg;
          if (mounted) {
            if (_keepListeningOnIdle) {
              setState(() {
                _errorMessage = 'Erro de áudio: $errorMsg. Reiniciando...';
                _isListening = false;
              });
              _stopTimer();
              _restartListeningDelayed();
              return;
            }

            setState(() {
              _errorMessage = 'Erro de áudio: $errorMsg';
              _isListening = false;
            });
            _stopTimer();
          }
        },
        onStatus: (status) {
          print('Status do speech to text: $status');
          if (status == 'done' || status == 'notListening') {
            if (_keepListeningOnIdle) {
              if (mounted) {
                setState(() {
                  _isListening = false;
                  _errorMessage = 'Reconhecimento pausado. Reiniciando...';
                });
              }
              _stopTimer();
              _restartListeningDelayed();
              return;
            }
            if (mounted && _isListening) {
              setState(() => _isListening = false);
              _stopTimer();
            }
          }
        },
      );

      if (available) {
        print('Speech to text inicializado com sucesso');
        if (mounted) {
          setState(() {
            _isInitialized = true;
            _errorMessage = '';
            _isInitializing = false;
          });
          // Se a página foi aberta com a intenção de iniciar a gravação,
          // iniciamos a escuta automaticamente após a inicialização.
          if (widget.autoStart) {
            // Dispara após o frame atual para evitar chamadas de setState
            // durante a construção.
            WidgetsBinding.instance.addPostFrameCallback((_) {
              if (mounted) _startListening();
            });
          }
        }
      } else {
        print('Speech to text não disponível');
        if (mounted) {
          setState(() {
            _errorMessage = 'Não disponível. Ative o Ditado nas configurações do Mac.';
            _isInitializing = false;
          });
        }
      }
    } catch (e) {
      print('Erro ao inicializar speech to text: $e');
      if (mounted) {
        setState(() {
          _errorMessage = 'Erro na inicialização: $e';
          _isInitializing = false;
        });
      }
    }
  }

  void _startListening() async {
    if (_isListening) return;

    // Garantia de que está inicializado antes de tentar ouvir
    if (!_isInitialized) {
      await _initializeSpeechToText();
      if (!_isInitialized) return;
    }

    try {
      print('Iniciando escuta no android...');

      // Removemos listenFor, pauseFor e localeId para estabilidade no Desktop
      await _speechToText.listen(
        onResult: (result) {
          if (!mounted) return;
          if (result.recognizedWords.trim().isEmpty) return;
          setState(() {
            _transcription = result.recognizedWords;
          });
        },
      );

      // `listen()` may return void on some plugin versions; check the
      // SpeechToText instance to confirm listening state instead of
      // assuming a boolean return value.
      if (_speechToText.isListening) {
        if (mounted) {
          setState(() {
            _keepListeningOnIdle = true;
            _isListening = true;
            _errorMessage = '';
          });
        }
        _startTimer();
        print('Escuta iniciada com sucesso');
      } else {
        print('Falha ao iniciar escuta nativa');
        if (mounted) {
          setState(() {
            _errorMessage = 'O sistema operacional recusou iniciar a escuta.';
          });
        }
      }
    } catch (e) {
      print('Erro ao iniciar escuta: $e');
      if (mounted) {
        setState(() {
          _errorMessage = 'Erro: $e';
        });
      }
    }
  }

  Future<void> _stopListening() async {
    _keepListeningOnIdle = false;
    try {
      await _speechToText.stop();
      if (mounted) {
        setState(() => _isListening = false);
      }
      _stopTimer();
      print('Gravação finalizada. Transcrição: $_transcription');
    } catch (e) {
      print('Erro ao parar escuta: $e');
    }
  }

  void _startTimer() {
    _timer?.cancel();
    _elapsedSeconds = 0;
    _timer = Timer.periodic(const Duration(seconds: 1), (timer) {
      if (mounted) {
        setState(() {
          _elapsedSeconds++;
          int minutes = _elapsedSeconds ~/ 60;
          int seconds = _elapsedSeconds % 60;
          _timerText =
              '${minutes.toString().padLeft(2, '0')}:${seconds.toString().padLeft(2, '0')}';
        });
      }

      // Não interrompe automaticamente a gravação; o usuário controla
      // encerramento com Cancelar ou Salvar.
    });
  }

  void _stopTimer() {
    _timer?.cancel();
  }

  void _restartListeningDelayed() {
    Future.delayed(const Duration(milliseconds: 400), () {
      if (!mounted || !_keepListeningOnIdle) return;
      _startListening();
    });
  }

  @override
  void dispose() {
    _keepListeningOnIdle = false;
    _stopTimer();
    _speechToText.cancel();
    super.dispose();
  }
>>>>>>> Stashed changes

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SafeArea(
        child: Padding(
          padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 18),
          child: Column(
            children: [
              if (_errorMessage.isNotEmpty)
                Padding(
                  padding: const EdgeInsets.only(bottom: 16),
                  child: Container(
                    padding: const EdgeInsets.all(12),
                    decoration: BoxDecoration(
                      color: Colors.red.shade100,
                      borderRadius: BorderRadius.circular(8),
                      border: Border.all(color: Colors.red.shade300),
                    ),
                    child: Text(
                      _errorMessage,
                      style: TextStyle(color: Colors.red.shade800, fontSize: 12),
                      textAlign: TextAlign.center,
                    ),
                  ),
                ),
              GestureDetector(
                onTap: _isInitializing ? null : (_isListening ? _stopListening : _startListening),
                child: Container(
                  width: 270,
                  height: 270,
                  decoration: BoxDecoration(
                    color: _isListening
                        ? const Color.fromRGBO(211, 44, 44, 0.15)
                        : Colors.white,
                    shape: BoxShape.circle,
                    boxShadow: [
                      BoxShadow(
                        color: Color.fromRGBO(0, 0, 0, 0.12),
                        blurRadius: 22,
                        offset: const Offset(0, 12),
                      ),
                    ],
                  ),
                  child: Center(
                    child: Column(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Icon(
                          _isListening ? Icons.mic : Icons.mic_none,
                          color: _isListening ? Colors.red : corPrincipal,
                          size: 48,
                        ),
                        const SizedBox(height: 12),
                        Text(
                          _timerText,
                          style: const TextStyle(
                            fontSize: 28,
                            fontWeight: FontWeight.bold,
                          ),
                        ),
                        const SizedBox(height: 6),
                        Text(
                          _isListening
                              ? 'Gravando...'
                              : (_isInitializing
                                  ? 'Inicializando...'
                                  : 'Clique para gravar'),
                          style: TextStyle(
                            fontSize: 14,
                            color: _isListening
                                ? Colors.red
                                : Colors.grey.shade600,
                          ),
                        ),
                      ],
                    ),
                  ),
                ),
              ),
              const SizedBox(height: 24),
              Container(
                width: double.infinity,
                height: 160,
                decoration: BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.circular(20),
                  border: Border.all(
                      color: const Color.fromRGBO(0, 122, 63, 0.25), width: 1.5),
                ),
                padding: const EdgeInsets.all(16),
                child: SingleChildScrollView(
                  child: Align(
                    alignment: Alignment.topLeft,
                    child: Text(
                      _transcription.isEmpty
                          ? 'Transcrição do áudio aparecerá aqui...'
                          : _transcription,
                      style: TextStyle(
                        fontSize: 14,
                        color: _transcription.isEmpty
                            ? Colors.black54
                            : Colors.black87,
                      ),
                    ),
                  ),
                ),
              ),
              const SizedBox(height: 20),
              Row(
                children: [
                  Expanded(
                    child: OutlinedButton(
                      style: OutlinedButton.styleFrom(
                        foregroundColor: corPrincipal,
                        side: const BorderSide(
                          color: corPrincipal,
                          width: 1.8,
                        ),
                        padding: const EdgeInsets.symmetric(vertical: 16),
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(18),
                        ),
                        backgroundColor: Colors.white,
                      ),
                      onPressed: () {
                        _stopListening();
                        Navigator.pop(context);
                      },
                      child: const Text(
                        'Cancelar',
                        style: TextStyle(fontSize: 16),
                      ),
                    ),
                  ),
                  const SizedBox(width: 14),
                  Expanded(
                    child: ElevatedButton(
                      style: ElevatedButton.styleFrom(
                        backgroundColor: corPrincipal,
                        foregroundColor: Colors.white,
                        padding: const EdgeInsets.symmetric(vertical: 16),
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(18),
                        ),
                      ),
<<<<<<< Updated upstream
                      onPressed: () => Navigator.pop(context),
=======
                      onPressed: _transcription.isEmpty
                          ? null
                          : () async {
                              await _stopListening();
                              final userId = await SessionHelper.getLoggedUserId();
                              if (userId == null) {
                                if (mounted) {
                                  ScaffoldMessenger.of(context).showSnackBar(
                                    const SnackBar(
                                      content: Text('Usuário não encontrado. Faça login novamente.'),
                                    ),
                                  );
                                }
                                return;
                              }

                              await DatabaseHelper.instance.insertRecording(
                                Recording(
                                  userId: userId,
                                  date: DateTime.now(),
                                  path: 'local_recording_${DateTime.now().millisecondsSinceEpoch}.m4a',
                                ),
                              );

                              if (mounted) {
                                ScaffoldMessenger.of(context).showSnackBar(
                                  const SnackBar(
                                    content: Text('Gravação salva no banco local.'),
                                  ),
                                );
                              }

                              Navigator.pop(context, true);
                            },
>>>>>>> Stashed changes
                      child: const Text(
                        'Salvar',
                        style: TextStyle(fontSize: 16),
                      ),
                    ),
                  ),
                ],
              ),
            ],
          ),
        ),
      ),
    );
  }
}

class GravacaoData {
  final String title;
  final String subtitle;

  const GravacaoData({required this.title, required this.subtitle});
}

class GravacaoCard extends StatefulWidget {
  final GravacaoData gravacaoing;

  const GravacaoCard({super.key, required this.gravacaoing});

  @override
  State<GravacaoCard> createState() => _GravacaoCardState();
}

class _GravacaoCardState extends State<GravacaoCard> {
  bool isPlaying = false;

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 110,
      decoration: BoxDecoration(
        color: Colors.white,
        borderRadius: BorderRadius.circular(20),
        boxShadow: [
          BoxShadow(
            color: Color.fromRGBO(0, 0, 0, 0.05),
            blurRadius: 14,
            offset: const Offset(0, 8),
          ),
        ],
      ),
      padding: const EdgeInsets.all(18),
      child: Row(
        children: [
          GestureDetector(
            onTap: () {
              setState(() {
                isPlaying = !isPlaying;
              });
            },
            child: Container(
              width: 50,
              height: 50,
              decoration: BoxDecoration(
                color: const Color.fromRGBO(2, 173, 90, 0.24),
                borderRadius: BorderRadius.circular(14),
              ),
              child: Icon(
                isPlaying ? Icons.pause : Icons.play_arrow,
                color: corEscura,
                size: 28,
              ),
            ),
          ),
          const SizedBox(width: 18),
          Expanded(
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  widget.gravacaoing.title,
                  style: const TextStyle(
                    fontSize: 16,
                    fontWeight: FontWeight.bold,
                  ),
                ),
                const SizedBox(height: 8),
                Text(
                  widget.gravacaoing.subtitle,
                  style: const TextStyle(fontSize: 14, color: Colors.black54),
                ),
              ],
            ),
          ),
          PopupMenuButton<String>(
            icon: const Icon(Icons.more_horiz, color: Colors.black54),
            onSelected: (value) {
              if (value == 'delete') {
                print('Excluir clicado');
              }
            },
            itemBuilder: (context) => [
              const PopupMenuItem(
                value: 'delete',
                child: Text('Excluir'),
              ),
            ],
          ),
        ],
      ),
    );
  }
}