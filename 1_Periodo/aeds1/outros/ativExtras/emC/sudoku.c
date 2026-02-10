/*
Você terá de criar um programa que leia uma matriz 9x9 de números de 1 a 9 e, em seguida, realizar a operação desejada pelo usuário até que o valor 0, indicando a finalização do programa, seja apresentado. As opções referentes à funcionalidade do programa são:

1. Atualizar índice: Juntamente com a opção 1, na mesma linha, serão apresentadas o índice da linha (entre 0 a 8), o índice da coluna (0 a 8), e o novo algarismo (1 a 9) que irá substituir o algarismo antigo na posição indicada.

2. Verificar linha: Juntamente com a opção 2, na mesma linha, será apresentada o índice da linha (entre 0 a 8) a ser verificada. Se não houver repetição de números, deve-se imprimir o caractere 'N'; caso contrário, imprima 'S'.

3. Verificar coluna: Juntamente com a opção 3, na mesma linha, será apresentada o índice da coluna (entre 0 a 8) a ser verificada. Se não houver repetição de números, deve-se imprimir o caractere 'N'; caso contrário, imprima 'S'.

4. Verificar quadrante: Juntamente com a opção 4, na mesma linha, será apresentada o índice do quadrante (0 a 8) a ser verificado. Se não houver repetição de números, deve-se imprimir o caractere 'N'; caso contrário, imprima 'S'. Os quadrantes estão enumerados na seguinte forma:

0 1 2
3 4 5
6 7 8

5. Verificar matriz: Se não houver repetição de números, deve-se imprimir o caractere 'N'; caso contrário, imprima 'S'

Qualquer outro valor que não esteja no intervalo [0,5], assume-se que o usuário deseja imprimir a matriz de maneira formatada, deixando claro a separação dos quadrantes via espaços e linhas em branco.

RESTRIÇÕES: Não se pode utilizar nenhum conceito (ainda) não visto em sala de aula
*/


#include <stdio.h>
int main()
{
    int m[9][9],op,lin=0,col=0,alg,cont=0,rep=0,quad,i, l, c, li, co;

    for(l=0; l<9; l++){
        for(c=0; c<9; c++){
            scanf("%d%*c",&m[l][c]);
        }
    }
    do{
        scanf("%d%*c",&op);
        switch(op){

        case 0:
            /*finaliza o programa*/
            break;
        case 1:
            /* vai sustituir o algarismo antigo na posição indicada.*/

            scanf("%d%*c",&lin); /*escolhe a linha de 0 a 8*/
            scanf("%d%*c",&col); /*escolhe a coluna de 1 a 9*/
            scanf("%d%*c",&alg); /*escolhe o algarismo de 1 a 9*/
            m[lin][col]=alg;
            break;

        case 2:
            /*Se não houver repetição de números na linha (entre 0 a 8), imprimi-se o caractere 'N'; caso contrário, imprima 'S'.*/
            lin=0, rep=0, col=0;
            scanf("%d%*c",&lin);
            for(l=0; l<9; l++){
                cont=0;
                for (c=0; c<9; c++){
                    if(m[lin][col]==m[lin][c]){
                        cont++;
                    }
                    if(cont>1){
                        rep++;
                    }
                }
                col++;
            }

            if(rep>1){
                printf("S\n");
            }else{
                printf("N\n");
            }

            break;

        case 3:
            /*Se não houver repetição de números na coluna(entre 0 a 8), deve-se imprimir o caractere 'N'; caso contrário, imprima 'S'.*/
            lin=0, rep=0, col=0;
            scanf("%d%*c",&col);
            for(l=0; l<9; l++){
                cont=0;
                for(c=0; c<9; c++){
                    if( m[lin][col] == m[c][col]){
                        cont++;
                    }
                    if(cont>1){
                        rep++;
                    }
                }
                lin++;
            }

            if(rep>0){
                printf("S\n");
            }else{
                printf("N\n");
            }
            break;

        case 4:
              /* Se não houver repetição de números dentro dos quadrantes, deve-se imprimir o caractere 'N'; caso contrário, imprima 'S'. Os quadrantes estão enumerados na seguinte forma:*/
            scanf("%d%*c",&quad);
            if(quad<3){
                lin=0;
            }
            else if(quad>=3 && quad<=5){
                lin=3;
            }
            else if(quad>=6 && quad<=8){
                lin=6;
            }

            if(quad==0 || quad==3 || quad==6){
                col=0;
            }
            else if(quad==1 || quad==4 || quad==7){
                col=3;
            }
            else if(quad==2 || quad==5 || quad==8){
                col=6;
            }

            rep=0;
            for(l=lin; l<lin+3; l++){
                for(c=col; c<col+3; c++){
                    cont=0;
                    for(li=lin; li<lin+3; li++){
                        for(co=col; co<col+3; co++){
                            if(m[l][c]==m[li][co] && (l!=li || c!=co)) /*comparando as matrizes*/{
                                cont++;
                            }
                        }
                    }
                    if(cont>0){
                        rep++;
                    }
                }
            }
            if(rep>0){
                printf("S\n");
            }else{
                printf("N\n");
            }

            break;

        case 5:
            /*5 se não houver repetição de números, deve-se imprimir o caractere 'N', caso contrário, imprima 'S'*/
            rep=0;
            for(l=0; l<9; l++)  /*lendo as linhas pra ve se repete*/{
                for (c=0; c<9; c++){
                    for(co=c+1; co<9; co++){
                        if(m[l][c]==m[l][co]){
                            rep=1;
                        }
                    }
                }
            }

            int rep1=0;
            for(l=0; l<9; l++)  /*lendo cluna pra ve se repete*/{
                for (c=0; c<9; c++){
                    for(lin=l+1; lin<9; lin++){
                        if(m[l][c]==m[lin][c]){
                            rep1=1;
                        }
                    }
                }
            }

            int rep2=0;
            int linha=0;
            int coluna=0;
             do {
        for (l = linha; l < linha + 3; l++) {
            for (c = 0; c < 9; c++) {
                for (lin = linha; lin < linha + 3; lin++) {
                    for (col = 0; col < 9; col++) {
                        if (l != lin || c != col) { /*Evita comparar o mesmo elemento*/
                            if (m[l][c] != 0 && m[l][c] == m[lin][col]) {
                                rep2 = 1;
                            }
                        }
                    }
                }
            }
        }
        linha = linha + 3;
    } while (linha < 9);

            if(rep>0 && rep1>0 && rep2>0){
                printf("S\n");
            }else{
                printf("N\n");
            }
            break;


        default:
            for(l=0; l<9; l++){
                if(l==3 || l==6){
                    printf("\n");
                }
                for(c=0; c<9; c++){
                    if(c==3 || c==6){
                        printf(" ");
                    }
                    printf("%d ",m[l][c]);
                }
                printf("\n");
            }
            break;
        }
    }
    while(op!=0);

    return 0;
}
