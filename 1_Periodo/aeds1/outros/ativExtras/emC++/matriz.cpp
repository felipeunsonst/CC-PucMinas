/*
Crie uma função capaz de somar os elementos das linhas L1 e L2 de uma matriz. O resultado deve ser colocado na linha L2. Faça o mesmo com a multiplicação.
*/


#include <iostream>

using namespace std;

void somarLinhas(int** matriz, int colunas, int L1, int L2) {
    for (int j = 0; j < colunas; ++j) {
        matriz[L2][j] += matriz[L1][j];
    }
}

void multiplicarLinhas(int** matriz, int colunas, int L1, int L2) {
    for (int j = 0; j < colunas; ++j) {
        matriz[L2][j] *= matriz[L1][j];
    }
}

void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int linhas, colunas;

    cout << "Digite o número de linhas: ";
    cin >> linhas;
    cout << "Digite o número de colunas: ";
    cin >> colunas;

    // Alocar memória para a matriz
    int** matriz = new int*[linhas];
    for (int i = 0; i < linhas; ++i) {
        matriz[i] = new int[colunas];
    }

    // Ler os elementos da matriz
    cout << "Digite os elementos da matriz:" << endl;
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz, linhas, colunas);

    int L1, L2;
    cout << "Digite o número das linhas que deseja somar (L1 e L2): ";
    cin >> L1 >> L2;

    // Verificar se as linhas são válidas
    if (L1 >= 0 && L1 < linhas && L2 >= 0 && L2 < linhas) {
        // Somar linhas
        somarLinhas(matriz, colunas, L1, L2);
        cout << "Matriz após somar a linha " << L1 << " na linha " << L2 << ":" << endl;
        imprimirMatriz(matriz, linhas, colunas);

        // Ler novamente as linhas para multiplicar
        cout << "Digite o número das linhas que deseja multiplicar (L1 e L2): ";
        cin >> L1 >> L2;

        if (L1 >= 0 && L1 < linhas && L2 >= 0 && L2 < linhas) {
            // Multiplicar linhas
            multiplicarLinhas(matriz, colunas, L1, L2);
            cout << "Matriz após multiplicar a linha " << L1 << " na linha " << L2 << ":" << endl;
            imprimirMatriz(matriz, linhas, colunas);
        } else {
            cout << "Linhas inválidas para multiplicação." << endl;
        }
    } else {
        cout << "Linhas inválidas para soma." << endl;
    }

    // Liberar memória alocada
    for (int i = 0; i < linhas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}
