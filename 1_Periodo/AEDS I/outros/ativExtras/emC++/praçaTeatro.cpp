/*
A Praça do Teatro na capital Berland tem formato retangular com tamanho n  ×  m metros. Por ocasião do aniversário da cidade, foi decidido pavimentar a Praça com lajes quadradas de granito. Cada laje tem o tamanho a  ×  a .

Qual é o menor número de lajes necessárias para pavimentar a Praça? É permitido cobrir uma superfície maior que a Praça do Teatro, mas a Praça tem que ser coberta. Não é permitido quebrar as lajes. As laterais das lajes deverão ficar paralelas às laterais da Praça.

Entrada
A entrada contém três números inteiros positivos na primeira linha: n ,   m e a ( 1 ≤   n ,  m ,  a  ≤ 10 9 ).

Saída
Escreva o número necessário de lajes.
*/

#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    // Calcula o número de lajes na direção n
    long long lajes_n = (n + a - 1) / a;//arredonda o numero
    // Calcula o número de lajes na direção m
    long long lajes_m = (m + a - 1) / a;

    // Calcula o número total de lajes
    long long total_lajes = lajes_n * lajes_m;
  
    cout << total_lajes << endl;

    return 0;
}
