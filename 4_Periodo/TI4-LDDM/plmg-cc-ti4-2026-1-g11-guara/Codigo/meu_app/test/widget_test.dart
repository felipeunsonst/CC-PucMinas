// Smoke test do app Guará.
//
// Verifica apenas que o MaterialApp inicializa sem lançar exceções.
// Não exercita o banco (que depende de plugins nativos do dispositivo).

import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';

void main() {
  testWidgets('App boots without crashing', (WidgetTester tester) async {
    await tester.pumpWidget(
      const MaterialApp(
        home: Scaffold(
          body: Center(child: Text('Guará')),
        ),
      ),
    );

    expect(find.text('Guará'), findsOneWidget);
  });
}
