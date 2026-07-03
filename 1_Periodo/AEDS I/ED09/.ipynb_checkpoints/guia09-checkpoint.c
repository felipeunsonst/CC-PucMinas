//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void printMatriz(int l, int c, int m[l][c]){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			printf("%d", m[i][j]);
		}
		printf("\n");
	}
}

void metodo0911(){
	int linha, coluna;
	printf("digite a quantidade de linhas e colunas da matriz:\n");
	scanf("%d", &linha);
	scanf("%d", &coluna);

	int matriz[linha][coluna];

	printf("agora digite os termos da matriz:\n");

	for(int i=0; i<linha; i++){
		for(int j=0; j<coluna; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	printMatriz(linha, coluna, matriz);
	
}

void metodo0912(){

}

void metodo0913(){

}

void metodo0914(){

}

void metodo0915(){

}

void metodo0916(){

}

void metodo0917(){

}

void metodo0918(){

}

void metodo0919(){

}

void metodo0920(){

}

void metodo09E1(){

}

void metodo09E2(){

}

int main(){
int opcao;


    do{
    printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo099911\n2-metodo099912\n3-metodo099913\n4-metodo099914\n5-metodo099915\n6-metodo099916\n7-metodo099917\n8-metodo099918\n9-metodo099919\n10-metodo099920\n11-metodo0999E1\n12-metodo0999E2\n");
    scanf("%d", &opcao);
	getchar();


    switch(opcao){
        case 1:
        metodo0911();
        break;
        
        case 2:
        metodo0912();
        break;
        
        case 3:
        metodo0913();
        break;
        
        case 4:
        metodo0914();
        break;
        
        case 5:
        metodo0915();
        break;
        
        case 6:
        metodo0916();
        break;
        
        case 7:
        metodo0917();
        break;
        
        case 8:
        metodo0918();
        break;
        
        case 9:
        metodo0919();
        break;
        
        case 10:
        metodo0920();
        break;
        
        case 11:
        metodo09E1();
        break;
        
        case 12:
        metodo09E2();
        break;

    }

    }while(opcao !=0);

    return 0;
}
