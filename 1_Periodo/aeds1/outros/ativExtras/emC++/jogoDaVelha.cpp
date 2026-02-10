/*
Certamente, todo mundo está familiarizado com o jogo da velha. As regras são
realmente muito simples. Dois jogadores se revezam marcando as células em uma
grade 3 × 3 (um jogador sempre desenha cruzes, o outro - zeros). O jogador que
conseguir primeiro colocar três das suas marcas numa linha horizontal, vertical
ou diagonal vence e o jogo termina. O jogador que desenha os cruzamentos vai
primeiro. Se a grade for preenchida, mas nem X nem 0 formarem a linha exigida,
um sorteio será anunciado.

Você recebe uma grade 3 × 3 , cada célula da grade está vazia ou ocupada por uma
cruz ou um zero. Você tem que encontrar o jogador (primeiro ou segundo), cujo
turno é o próximo, ou imprimir um dos veredictos abaixo:

ilegal — se o layout do tabuleiro fornecido não puder aparecer durante um jogo
válido; o primeiro jogador ganhou — se no layout do tabuleiro determinado o
primeiro jogador acabou de ganhar; o segundo jogador ganhou — se no layout do
tabuleiro determinado o segundo jogador acabou de ganhar; draw — se o layout do
tabuleiro fornecido acabou de empatar. Entrada A entrada consiste em três
linhas, cada uma das linhas contém caracteres " . ", " X " ou " 0 " (um ponto
final, uma letra maiúscula X ou um dígito zero).

Saída
Imprima um dos seis veredictos: primeiro , segundo , ilegal , o primeiro jogador
venceu , o segundo jogador venceu ou empatou .

problema 3c codeforces
*/

/*
Certamente, todo mundo está familiarizado com o jogo da velha. As regras são realmente muito simples. Dois jogadores se revezam marcando as células em uma grade 3 × 3 (um jogador sempre desenha cruzes, o outro - zeros). O jogador que conseguir primeiro colocar três das suas marcas numa linha horizontal, vertical ou diagonal vence e o jogo termina. O jogador que desenha os cruzamentos vai primeiro. Se a grade for preenchida, mas nem X nem 0 formarem a linha exigida, um sorteio será anunciado.

Você recebe uma grade 3 × 3 , cada célula da grade está vazia ou ocupada por uma cruz ou um zero. Você tem que encontrar o jogador (primeiro ou segundo), cujo turno é o próximo, ou imprimir um dos veredictos abaixo:

ilegal — se o layout do tabuleiro fornecido não puder aparecer durante um jogo válido;
o primeiro jogador ganhou — se no layout do tabuleiro determinado o primeiro jogador acabou de ganhar;
o segundo jogador ganhou — se no layout do tabuleiro determinado o segundo jogador acabou de ganhar;
draw — se o layout do tabuleiro fornecido acabou de empatar.
Entrada
A entrada consiste em três linhas, cada uma das linhas contém caracteres " . ", " X " ou " 0 " (um ponto final, uma letra maiúscula X ou um dígito zero).

Saída
Imprima um dos seis veredictos: primeiro , segundo , ilegal , o primeiro jogador venceu , o segundo jogador venceu ou empatou .

problema 3c codeforces
*/

#include <iostream>
using namespace std;

int main() {
    int linha = 3, coluna = 3;
    char matriz[linha][coluna];

    // Entrada dos dados na matriz
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            cin >> matriz[i][j];
            if (matriz[i][j] != '.' && matriz[i][j] != 'X' && matriz[i][j] != '0') {
                cout << "illegal" << endl;
                return 0;
            }
        }
    }

    int quantidadeX = 0, quantidadeO = 0, quantidadePonto = 0;

    // Contagem dos caracteres
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (matriz[i][j] == 'X') {
                quantidadeX++;
            }
            if (matriz[i][j] == '0') {
                quantidadeO++;
            }
            if (matriz[i][j] == '.') {
                quantidadePonto++;
            }
        }
    }

    bool ganhadorX = false, ganhadorO = false;

    // Verificação de linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (matriz[i][0] == matriz[i][1] && matriz[i][1] == matriz[i][2]) {
            if (matriz[i][0] == 'X') {
                ganhadorX = true;
            }
            if (matriz[i][0] == '0') {
                ganhadorO = true;
            }
        }
        if (matriz[0][i] == matriz[1][i] && matriz[1][i] == matriz[2][i]) {
            if (matriz[0][i] == 'X') {
                ganhadorX = true;
            }
            if (matriz[0][i] == '0') {
                ganhadorO = true;
            }
        }
    }

    // Verificação das diagonais
    if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2]) {
        if (matriz[0][0] == 'X') {
            ganhadorX = true;
        }
        if (matriz[0][0] == '0') {
            ganhadorO = true;
        }
    }
    if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0]) {
        if (matriz[0][2] == 'X') {
            ganhadorX = true;
        }
        if (matriz[0][2] == '0') {
            ganhadorO = true;
        }
    }

    // Validação do estado do jogo
    if (quantidadeO > quantidadeX || quantidadeX > quantidadeO + 1) {
        cout << "illegal" << endl;
    } else if (ganhadorX && ganhadorO) {
        cout << "illegal" << endl;
    } else if (ganhadorX && quantidadeX == quantidadeO) {
        cout << "illegal" << endl;
    } else if (ganhadorO && quantidadeX > quantidadeO) {
        cout << "illegal" << endl;
    } else {
        if (ganhadorX) {
            cout << "the first player won" << endl;
        } else if (ganhadorO) {
            cout << "the second player won" << endl;
        } else if (quantidadePonto == 0) {
            cout << "draw" << endl;
        } else if (quantidadeX > quantidadeO) {
            cout << "second" << endl;
        } else {
            cout << "first" << endl;
        }
    }

    return 0;
}
