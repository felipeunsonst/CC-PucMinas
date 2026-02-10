/*
Faça um programa que permita a realizar cálculos bizarros entre dois números x e y. Primeiro, deve-se ler os números x e y do usuário (que podem não ter a mesma quantidade de algarismos) e, em seguida, ler a opção desejada do usuário (um inteiro) que pode ser uma das seguintes:

1. Remoção do y-ésimo dígito de x, contado da direita para a esquerda (então, y = 0 é o primeiro algarismo)

2. Construção do número cujos dígitos alternam entre aqueles em y e em x (então, o primeiro algarismo à esquerda é o último algarismo de y, em seguida, o segundo algarismo da resposta é o último de x)

3. Construção do número cujos dígitos são aqueles em x e em y (então, da direita para esquerda, temos os algarismos de x e, depois, os de y)

RESTRIÇÕES: Não se pode utilizar nenhum conceito não visto em sala de aula (por ex., biblioteca math.h) ou vetores.
*/


#include <stdio.h>

int main() {
    int x, y, opcao, resultado, potencia, multiplicador, temp, i;

    /*solicitar e ler os números x e y fornecidos pelo usuário*/
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &opcao);

    switch (opcao) {
         /*remoção do y-ésimo dígito de x*/
        case 1:
            potencia = 1;
            for (i = 0; i < y; i++) {
                potencia *= 10; /*aumenta a potência de 10 para o dígito na posição 'y'*/
            }
            temp = x / (potencia * 10); /*divide 'x' para remover o dígito na posição 'y'*/
            resultado = temp * potencia + (x % potencia); /*reconstroi 'x' sem o dígito na posição 'y'*/
             printf("%d\n", resultado);
            break;

            /*construção do número cujos dígitos alternam entre x e y*/
        case 2:
            resultado = 0;
            multiplicador = 1;
            /*alternadamente, adiciona dígitos de x e y ao resultado*/
            while (x > 0 || y > 0) {
                if (y > 0) {
                    resultado += (y % 10) * multiplicador; /*adiciona o último dígito de 'y' ao resultado*/
                    y /= 10; /*remove o último dígito de 'y'*/
                    multiplicador *= 10; /*atualiza o multiplicador para a próxima posição do resultado*/
                }
                if (x > 0) {
                    resultado += (x % 10) * multiplicador; /*adiciona o último dígito de 'x' ao resultado*/
                    x /= 10; /*remove o último dígito de 'x'*/
                    multiplicador *= 10; /*atualiza o multiplicador para a próxima posição do resultado*/
                }
            }
             printf("%d\n", resultado);
            break;


            /*construção do número cujos dígitos são os dígitos de x seguidos pelos de y*/
        case 3:
            potencia = 1;
            /*encontra a potência necessária para concatenar x e y*/
            while (y >= potencia) {
                potencia *= 10;
            }
            /*concatena x e y*/
            resultado = x * potencia + y;
             printf("%d\n", resultado);
            break;
    }


    return 0;
}
