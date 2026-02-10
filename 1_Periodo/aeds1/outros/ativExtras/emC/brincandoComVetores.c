/*
Você deve fazer um programa que leia do(a) usuário(a) uma sequência de 10 números positivos entre 0 e 100 que serão passados por ele(a) e, em seguida, oferecer as seguintes opções:
0. Sair do programa
1. Atualizar o valor em um índice específico (fornecido pelo(a) usuário(a)) da sequência
2. Exibir sequência
3. Exibir sequência em ordem reversa
4. Exibir a somatória de todos os valores da sequência
5. Exibir a contagem de números duplicados da sequência
6. Exibir os valores únicos (i.e., sem repetição) da sequência
7. Exibir a frequência de todos os valores da sequência
8. Exibir o valor máximo, mínimo e médio (com duas casas decimais) da sequência
9. Exibir os valores pares e ímpares da sequência (sem repetição)
10. Exibir a sequência rotacionada M vezes (quantidade fornecida pelo(a) usuário(a)) para a esquerda
11. Exibir a sequência rotacionada M vezes (quantidade fornecida pelo(a) usuário(a)) para a direita

RESTRIÇÕES: Não se pode utilizar nenhum conceito não visto em sala de aula (por ex., cadeias de caracteres)
 */

#include <stdio.h>

int main() {
    int numeros[10];
    int opcao, i, j, n, soma=0, contagem_duplicados = 0;
    int max = numeros[0], min = numeros[0];
    float media;

    for (i = 0; i < 10; i++) {
        do {
            scanf("%d", &numeros[i]);
        } while (numeros[i] < 0 || numeros[i] > 100); /*verificando se está no intervalo permitido*/
    }

    do {
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                break;

            case 1:
                /*atualizar valor em um índice específico*/
                scanf("%d", &i);
                if (i >= 0 && i < 10) {
                    scanf("%d", &numeros[i]);
                }
                break;

            case 2:
                /*exibir sequência*/
                for (i = 0; i < 10; i++) { /*percorre o vetor para exibir os números*/
                    printf(" %d", numeros[i]);
                }
                printf("\n");
                break;

            case 3:
                /*exibir sequência em ordem reversa*/
                for (i = 9; i >= 0; i--) { /*percorre o vetor de trás para frente para exibir os números*/
                    printf(" %d", numeros[i]);
                }
                printf("\n");
                break;

            case 4:
                /*exibir somatória dos valores*/

                for (i = 0; i < 10; i++) { /*percorre o array para somar os números*/
                    soma += numeros[i];
                }
                printf("%d\n", soma);
                break;

            case 5:
                /*exibir contagem de numeros duplicados*/
                for (i = 0; i < 9; i++) {
                    for (j = i + 1; j < 10; j++) {
                        if (numeros[i] == numeros[j]) { /* compara cada par de números para detectar duplicatas*/
                            contagem_duplicados++;
                            break;
                        }
                    }
                }
                printf("%d", contagem_duplicados);
                break;

            case 6:
                /*exibir valores unicos*/
                for (i = 0; i < 10; i++) {
                    int repetido = 0;
                    for (j = 0; j < i; j++) {
                        if (numeros[i] == numeros[j]) { /*verifica se o número já foi encontrado anteriormente*/
                            repetido = 1;
                            break;
                        }
                    }
                    if (!repetido) { /*se não foi encontrado, é único e é exibido*/
                        printf(" %d", numeros[i]);
                    }
                }
                printf("\n");
                break;

            case 7:
                /*exibir frequencia de valores*/
                for (i = 0; i < 10; i++) {
                    int frequencia = 1;
                    for (j = i + 1; j < 10; j++) {
                        if (numeros[i] == numeros[j]) { /* conta quantas vezes o número ocorre no vetor*/
                            frequencia++;
                        }
                    }
                    printf("%d: %d\n", numeros[i], frequencia);
                }
                break;

            case 8:
                /*exibir valor máximo, mínimo e médio*/
                for (i = 0; i < 10; i++) {
                    soma += numeros[i];
                    if (numeros[i] > max) { /*encontra o valor máximo*/
                        max = numeros[i];
                    }
                    if (numeros[i] < min) { /* encontra o valor mínimo*/
                        min = numeros[i];
                    }
                }
                media = (float)soma / 10; /*calcula a média*/
                printf("%d\n", max);
                printf("%d\n", min);
                printf("%.2f\n", media);
                break;

            case 9:
                /*exibir valores pares e ímpares*/
                for (i = 0; i < 10; i++) {
                    if (numeros[i] % 2 == 0) { /*verifica se o número é par*/
                        printf(" %d", numeros[i]);
                    }
                }
                printf("\n");
                for (i = 0; i < 10; i++) {
                    if (numeros[i] % 2 != 0) { /*verifica se o número é ímpar*/
                        printf(" %d", numeros[i]);
                    }
                }
                printf("\n");
                break;

            case 10:
                /*exibir sequência rotacionada M vezes para a esquerda*/
                scanf("%d", &n);
                n = n % 10; /*garantindo que não rodará mais que o tamanho do vetor*/
                for (i = n; i < 10; i++) {
                    printf(" %d", numeros[i]);
                }
                for (i = 0; i < n; i++) {
                    printf(" %d", numeros[i]);
                }
                printf("\n");
                break;

            case 11:
                /*exibir sequência rotacionada M vezes para a direita*/
                scanf("%d", &n);
                n = n % 10; /*garantindo que não rodará mais que o tamanho do vetor*/
                for (i = 10 - n; i < 10; i++) {
                    printf(" %d", numeros[i]);
                }
                for (i = 0; i < 10 - n; i++) {
                    printf(" %d", numeros[i]);
                }
                printf("\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
