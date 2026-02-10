//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void printMatriz(int l, int c, int m[l][c]){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			printf("%d ", m[i][j]);
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

void matrizNoArquivo(int l, int c, int m[l][c], FILE *ma){
	for(int i = 0; i < l; i++){
		for(int j = 0; j < c; j++){
			fprintf(ma, "%d ", m[i][j]);  
		}
		fprintf(ma, "\n");
	}
}

void metodo0912(){
	int linha, coluna;
	printf("Digite a quantidade de linhas e colunas da matriz:\n");
	scanf("%d", &linha);
	scanf("%d", &coluna);

	int matriz[linha][coluna];

	printf("Agora digite os termos da matriz:\n");

	for(int i = 0; i < linha; i++){
		for(int j = 0; j < coluna; j++){
			scanf("%d", &matriz[i][j]);
		}
	}

	FILE *arq;
	arq = fopen("MATRIZ_01.txt", "w");

	if(arq == NULL){
		printf("Falha ao abrir o arquivo.\n");
		return;  
	}

	matrizNoArquivo(linha, coluna, matriz, arq);

	fclose(arq);  
	printf("matriz gravada no arquivo com sucesso.\n");
}


void metodo0913(){
	int linha, coluna;
	printf("digite a quantidade de linhas e colunas:\n");
	scanf("%d %d", &linha, &coluna);

	if(linha = coluna){
		int matriz[linha][coluna];
		printf("digite os valores da matriz:\n");
		for(int i = 0; i < linha; i++){
			for(int j = 0; j < coluna; j++){
				scanf("%d", &matriz[i][j]);
			}
		}

		for(int i=0; i<linha; i++){
			for(int j=0; j<coluna; j++){
				if(i = j){
					printf("%d ", matriz[i][j]);
				}
			}
			printf("\n");
		}
	} else{
		printf("a matriz nao e quadrada, portanto, não sera impresso sua diagonal");
	}
}

void metodo0914(){
	int linha, coluna;
	printf("digite a quantidade de linhas e colunas:\n");
	scanf("%d %d", &linha, &coluna);

	if(linha = coluna){
		int n = linha;
		int matriz[n][n];
		printf("digite os valores da matriz:\n");
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matriz[i][j]);
			}
		}

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(j+i == n-1){
					printf("%d ", matriz[i][j]);
				}
			}
		}
			printf("\n");
		} else{
		printf("a matriz nao e quadrada, portanto, não sera impresso sua diagonal");
	}
}


void metodo0915() {
    int linha, coluna;
    printf("digite a quantidade de linhas e colunas:\n");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

   printf("digite os valores da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

     if (linha == coluna) {  
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
				if(j<=i){
					 printf("%d ", matriz[i][j]); 
				}
            }
            printf("\n");
        }
    } else {
        printf("a matriz não é quadrada.\n");
    }
}


void metodo0916() {
    int linha, coluna;
    printf("digite a quantidade de linhas e colunas:\n");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

    printf("digite os valores da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
                scanf("%d", &matriz[i][j]);
            } 
        }

	if (linha == coluna) {  
        for (int i = 0; i < linha; i++) {
			for (int k = 0; k < i; k++) {
                printf("  "); 
            }
            for (int j = i; j < linha; j++) {
				if(j>=i){
					printf("%d ", matriz[i][j]); 
				} 
            }
            printf("\n");
        }
    } else {
       printf("a matriz não é quadrada.\n");
    }
   
}

void metodo0917() {
    int linha, coluna;
    printf("digite a quantidade de linhas e colunas:\n");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

   printf("digite os valores da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
                scanf("%d", &matriz[i][j]);
            } 
        }

    if (linha == coluna) {  
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < linha - i - 1; j++) {
                printf("  ");  
            }
            for (int j = linha - i - 1; j < linha; j++) {
                printf("%.d ", matriz[i][j]);
            }
            printf("\n");
        }
    } else {
       printf("a matriz não é quadrada.\n");
    } 
}


void metodo0918(){
    int linha, coluna;
    printf("digite a quantidade de linhas e colunas:\n");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

   printf("digite os valores da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    if (linha == coluna) {
        for (int i = 0; i < linha; i++) {
            for (int j = 0; j < coluna; j++) {
                if (j < (linha - 1 - i)) {
                    printf("%d ", matriz[i][j]); 
                } else if (j == (linha - 1 - i)) {
                    printf("%d ", matriz[i][j]); 
                } else {
                    printf("  "); 
                }
            }
            printf("\n");
        }
    } else {
        printf("a matriz não é quadrada.\n");
    }

}

void metodo0919(){
	int linha, coluna;
	int zero = 0;
    printf("digite a quantidade de linhas e colunas:\n");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

   printf("digite os valores da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

     if (linha == coluna) {  
       for (int i = 0; i < linha; i++) {
        for (int j = 0; j <= i; j++) { 
            if (matriz[i][j] != 0) {
                zero++; 
            }
        }
    }

    if (zero > 0) {
        printf("nao sao todos os valores que sao zeros.\n");
    } else {
        printf("todos os valores sao zeros.\n");
    }
    } else {
        printf("a matriz não é quadrada.\n");
    }
}

void metodo0920(){
	 int linha, coluna;
	int zero=0;
    printf("digite a quantidade de linhas e colunas:\n");
    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

    printf("digite os valores da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
                scanf("%d", &matriz[i][j]);
            } 
        }

	if (linha == coluna) {  
       for (int i = 0; i < linha; i++) {
        for (int j = i + 1; j < coluna; j++) { 
            if (matriz[i][j] != 0) {
                zero++; 
            }
        }
    }

  
	    if (zero > 0) {
	        printf("nao sao todos os valores que sao zeros acima da diagonal principal.\n");
	    } else {
	        printf("todos os valores acima da diagonal principal sao zeros.\n");
	    }
    } else {
       printf("a matriz nao e quadrada.\n");
    }
   
}

void metodo09E1(){
	int linha, coluna;
	printf("digite a quantidade de linhas e colunas:\n");
	scanf("%d", &linha);
	getchar();
	scanf("%d", &coluna);
	getchar();

	int matriz[linha][coluna];

	 printf("digite os valores da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
                scanf("%d", &matriz[i][j]);
            } 
        }

	for (int j = 0; j < coluna; j++) {
        for (int i = 0; i < linha; i++) {
                printf("%d ", matriz[i][j]); 
            } 
		printf("\n");
        }
}

void metodo09E2(){
	int linha, coluna;
	printf("digite a quantidade de linhas e colunas:\n");
	scanf("%d", &linha);
	getchar();
	scanf("%d", &coluna);
	getchar();

	int matriz[linha][coluna];

	 printf("digite os valores da matriz:\n");
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
                scanf("%d", &matriz[i][j]);
            } 
        }

	for (int i = linha-1; i >= 0; i--) {
        for (int j = coluna-1; j >=0; j--) {
                printf("%d ", matriz[i][j]);
            } 
		printf("\n");
        }
}

int main(){
int opcao;


    do{
    printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo0911\n2-metodo0912\n3-metodo0913\n4-metodo0914\n5-metodo0915\n6-metodo0916\n7-metodo0917\n8-metodo0918\n9-metodo0919\n10-metodo0920\n11-metodo09E1\n12-metodo0999E2\n");
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
