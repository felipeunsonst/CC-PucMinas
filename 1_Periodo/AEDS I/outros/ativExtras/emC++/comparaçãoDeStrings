/*
Crie um progama capaz de ler dois nomes de pessoas e imprimi-los em ordem alfabética. 
*/

#include <iostream>
using namespace std;

int compararNomes(const char nome1[], const char nome2[]) {
    int i = 0;
    while (nome1[i] != '\0' && nome2[i] != '\0') {
        if (nome1[i] < nome2[i]) {
            return -1; // nome1 vem antes de nome2
        } else if (nome1[i] > nome2[i]) {
            return 1; // nome1 vem depois de nome2
        }
        i++;
    }
    // Se chegarmos aqui, significa que os prefixos são iguais, então verificamos o tamanho
    if (nome1[i] == '\0' && nome2[i] == '\0') {
        return 0; // Nomes são exatamente iguais
    } else if (nome1[i] == '\0') {
        return -1; // nome1 é menor (prefixo de nome2)
    } else {
        return 1; // nome2 é menor (prefixo de nome1)
    }
}

int main() {
    const int tamanhoMaximo = 100;
    char nome1[tamanhoMaximo];
    char nome2[tamanhoMaximo];

    cout << "Digite o primeiro nome: ";
    cin >> nome1;

    cout << "Digite o segundo nome: ";
    cin >> nome2;

    int resultadoComparacao = compararNomes(nome1, nome2);

    if (resultadoComparacao < 0) {
        cout << nome1 << endl << nome2 << endl;
    } else if (resultadoComparacao > 0) {
        cout << nome2 << endl << nome1 << endl;
    } else {
        cout << nome1 << endl << nome2 << endl; // Nomes são iguais, imprimir na ordem dada
    }

    return 0;
}
