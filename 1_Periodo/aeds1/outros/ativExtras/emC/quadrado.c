/*Faça um programa que leia um inteiro positivo qualquer e um caractere que indica o tipo de quadrado (de lado l) a ser impresso na tela utilizando o caractere '*'. Se o caractere for:

'c', imprima um quadrado totalmente preenchido;
'b', imprima somente suas bordas;
'p', imprima suas bordas e a diagonal principal;
's', imprima suas bordas e a diagonal secundária;
'h', imprima suas bordas e sua divisão horizontal (no meio);
'v' imprima suas bordas e sua divisão vertical (no meio);
caso contrário, imprima a mensagem de erro: "Não existe essa opção".
RESTRIÇÕES: Não se pode utilizar nenhum conceito não visto em sala de aula (por ex., strings)
*/
#include <stdio.h>

int main(){
  int lado;
  char x;
   int i;
   int j;

  /*media do lado decretada pelo usuario*/
  scanf("%d%*c", &lado);
  /*dar ao usuario a opção de qual tipo de quadrado imprimir*/
  scanf("%c%*c", &x);



  switch (x){
    case 'c':
      /*pensando como matriz, i representa as linhas e j as colunas em que em ambas será impresso os asteriscos que formarão o quadrado*/

    for(i=0; i<lado; i++){
      for(j=0; j<lado; j++){
        printf("*");
      }
      printf("\n");
    } break;
      case 'b':
            for (i = 0; i < lado; i++) {
                for (j = 0; j < lado; j++) {
                  /*quando uma dessas condições for verdadeira, imprime-se o asterisco, caso contrário, imprime espaços, possibilitando a construção das bordas do quadrado*/
                    if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        case 'p':
            for (i = 0; i < lado; i++) {
                for (j = 0; j < lado; j++) {
                  /* nesse caso, com essas condições, especificamente i==j, é possivel construir o quadrado preenchido com a diagonal principal*/
                    if (i == j || i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        case 's':
            for (i = 0; i < lado; i++) {
                for (j = 0; j < lado; j++) {
                  /*mantendo o pensamento de que funciona como uma matriz, a condição i+j==lado-1, permite construir uma diagonal secundaria, baseando-se nos valores de i e j*/
                    if (i + j == lado - 1 || i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        case 'h':
            for (i = 0; i < lado; i++) {
                for (j = 0; j < lado; j++) {
                  /*como aqui visamos por uma linha que divide o quadrado na metade, a condição i==lado/2 permite a impressão dos asteriscos em uma linha horizontal no meio*/
                    if (i == lado/2 || i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        case 'v':
            for (i = 0; i < lado; i++) {
                for (j = 0; j < lado; j++) {
                  /* mesma ideia do caso anterior, porém a linha agora é vertical, sendo necessário dividir as colunas como em j== lado/2*/
                    if (j == lado/2 || i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        default:
            printf("nao existe essa opcao\n");
    }

    return 0;
}
