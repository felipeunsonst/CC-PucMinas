/*
Faça um programa em c++ que apresenta a seguinte saída, perguntando ao usuário o número máximo (no exemplo, 9). Este número deve ser sempre ímpar.

      1 2 3 4 5 6 7 8 9
        2 3 4 5 6 7 8
          3 4 5 6 7
            4 5 6
              5  
              */

#include <iostream>
#include <iomanip> // para std::setw

int main() {
    int maxNum;

    // Solicita ao usuário para inserir um número ímpar
    do {
        std::cout << "Digite um número máximo ímpar: ";
        std::cin >> maxNum;
    } while (maxNum % 2 == 0); // Continua pedindo até que um número ímpar seja inserido

    // Verifica se o número é positivo
    if (maxNum < 1) {
        std::cout << "O número deve ser positivo e ímpar." << std::endl;
        return 1;
    }

    // Gera a saída desejada
    for (int i = 0; i <= maxNum / 2; ++i) {
        // Imprime os espaços iniciais
        for (int j = 0; j < i; ++j) {
            std::cout << "  ";
        }
        // Imprime a sequência de números
        for (int j = i + 1; j <= maxNum - i; ++j) {
            std::cout << j << " ";
        }
        std::cout << std::endl; // significa /n
    }

    return 0;
}
