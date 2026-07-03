//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void metodo1011(){
	int x,y;
	printf("digite os numeros que definirao o intervalo:\n");
	scanf("%d", &x);
	scanf("%d", &y);
	
	if(x>=y){
		printf("o intervalo nao pode ser gerado com o primeiro numero sendo maior que o segundo\n");
	} else{
		printf("digite a quantidade de numeros a serem gerados:\n");
		int quantidade;
		scanf("%d", &quantidade);

		if(quantidade> 1+(y-x)){
			printf("nao e possivel gerar essa quantidade\n");
		} else{
			int array[quantidade];
	
			 srand(time(0));
	
			for(int i = 0; i<quantidade; i++){
				array[i] = x + rand() % (y - x + 1);
			}
	
			FILE *arq;
			arq = fopen("DADOS.txt", "w");
			fprintf(arq, "%d\n", quantidade);
	
			for(int i = 0; i<quantidade; i++){
				fprintf(arq, "%d ", array[i]);
			}
	
			fclose(arq);
	
			printf("os numeros foram gravados no arquivo DADOS.txt\n");
		}
	}
	
}

int lerArquivo(FILE *arq, int arr[]){
	int contador=0;
	while(fscanf(arq, "%d", &arr[contador]) == 1){
		contador++;
	}
	return contador;
}

int acharValor(int arr[], int tam, int valor){
	int cont=0;
	for(int i = 0; i<tam; i++){
		if(arr[i] == valor){
			cont++;
		}
	}
	return cont;
}

void metodo1012(){
	FILE *arquivo;
	arquivo = fopen("DADOS2.txt", "r");

	int array[100];
	int tamanho;

	tamanho = lerArquivo(arquivo, array);

	int numero;
	printf("digite o numero a ser encontrado no arranjo:\n");
	scanf("%d", &numero);

	int indice = acharValor(array, tamanho, numero);
	if(indice>0){
		printf("o numero foi encontrado\n");
	} else{
		printf("o numero nao foi encontrado\n");
	}

	fclose(arquivo);

}

int compararArray(int arr1[], int tam1, int arr2[]){
	int cont=0;
	for(int i = 0; i<tam1; i++){
		if(arr1[i] != arr2[i]){
			cont++;
		}
	}
	return cont;
	
}

void metodo1013(){
	
	FILE *arquivo1;
	arquivo1 = fopen("DADOS2.txt", "r");
	FILE *arquivo2;
	arquivo2 = fopen("DADOS3.txt", "r");

	int array1[100];
	int tamanho1;
	int array2[100];
	int tamanho2;

	tamanho1 = lerArquivo(arquivo1, array1);
	tamanho2 = lerArquivo(arquivo2, array2);
	if(tamanho1 == tamanho2){
		int verdade = compararArray(array1, tamanho1, array2);
		if(verdade>0){
			printf("os arrajos nao sao iguais\n");
		} else{
			printf("os arranjos sao iguais\n");
		}
	}else{
		printf("os tamanhos nao sao iguais, com isso, nao havera a comparacao\n");
	}

	fclose(arquivo1);
	fclose(arquivo2);
	
}

int somarArray(int arr1[], int tam1, int arr2[], int n, int arr3[]){
	for(int i = 0; i<tam1; i++){
		arr3[i] = arr1[i] + (arr2[i] *n);
	}
	return 0;
	
}

void metodo1014(){
	FILE *arquivo1;
	arquivo1 = fopen("DADOS2.txt", "r");
	FILE *arquivo2;
	arquivo2 = fopen("DADOS3.txt", "r");

	int array1[100];
	int tamanho1;
	int array2[100];
	int tamanho2;
	int soma[100];

	tamanho1 = lerArquivo(arquivo1, array1);
	tamanho2 = lerArquivo(arquivo2, array2);
	
	if(tamanho1 == tamanho2){
		printf("digite uma constante para ocorrer a multiplicacao no segundo arranjo\n");
		int constante;
		scanf("%d", &constante);
		
		int resultado = somarArray(array1, tamanho1, array2, constante, soma);
        
        if (resultado == 0) {  
            for(int i = 0; i < tamanho1; i++){
                printf("%d ", soma[i]);
            }
            printf("\n");
        } else {
            printf("erro ao somar os arrays.\n");
        }
	}else{
		printf("os tamanhos nao sao iguais, com isso, nao havera a soma\n");
	}


	fclose(arquivo1);
	fclose(arquivo2);
}

int ordenadoOuN(int arr[], int tam, int cont){
	for(int i=tam-1; i>0; i--){
		for(int j = i-1; j>0; j--){
			if(arr[i]<arr[j]){
				cont++;
			}
		}
	}
	return cont;
}

void metodo1015(){
	FILE *arquivo;
	arquivo = fopen("DADOS2.txt", "r");

	int array[100];
	int tamanho;

	tamanho = lerArquivo(arquivo, array);

	int resultado = ordenadoOuN(array, tamanho, 0);
	if(resultado>0){
		printf("o array nao esta ordenado\n");
	}else{
		printf("o array esta ordenado\n");
	}
	
	fclose(arquivo);
}

void obterTransposta(int linhas, int colunas, int matriz[linhas][colunas], int transposta[colunas][linhas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
}

int lerMatrizDoArquivo(FILE *arquivo, int matriz[100][100], int *linhas, int *colunas) {
    fscanf(arquivo, "%d %d", linhas, colunas);
    for (int i = 0; i < *linhas; i++) {
        for (int j = 0; j < *colunas; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }
    return 1;
}

void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void metodo1016() {
    FILE *arquivo;
    arquivo = fopen("DADOS4.txt", "r");

    int matriz[100][100], transposta[100][100];
    int linhas, colunas;

    lerMatrizDoArquivo(arquivo, matriz, &linhas, &colunas);
    fclose(arquivo);

    obterTransposta(linhas, colunas, matriz, transposta);
    imprimirMatriz(colunas, linhas, transposta);
}

int verificarMatriz(int l, int c, int m[l][c], int cont){
	for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if(m[i][j] != 0){
				cont++;
			}
        }
    }
	return cont;
}

void metodo1017(){
	FILE *arquivo;
	arquivo = fopen("DADOS5.txt", "r");

	int matriz[100][100];
    int linhas, colunas;

	lerMatrizDoArquivo(arquivo, matriz, &linhas, &colunas);
	fclose(arquivo);

	int resultado = verificarMatriz(linhas, colunas, matriz, 0);
	if(resultado>0){
		printf("a matriz nao e composta apenas de zeros\n");
	}else{
		printf("a matriz e composta apenas de zeros\n");
	}
}

int igualdadeMatriz(int l1, int c1, int m1[l1][c1], int cont, int l2, int c2, int m2[l2][c2]){
	if(l1 != l2 || c1 != c2){
		cont++;
	} else {
		for (int i = 0; i < l1; i++) {
	        for (int j = 0; j < c1; j++) {
	            if(m1[i][j] != m2[i][j]){
					cont++;
				}
	        }
	    }
	}
	return cont;
}

void metodo1018(){
	FILE *arquivo1;
	arquivo1 = fopen("DADOS4.txt", "r");
	FILE *arquivo2;
	arquivo2 = fopen("DADOS6.txt", "r");

	int matriz1[100][100];
    int linhas1, colunas1;
	int matriz2[100][100];
    int linhas2, colunas2;

	lerMatrizDoArquivo(arquivo1, matriz1, &linhas1, &colunas1);
	fclose(arquivo1);
	lerMatrizDoArquivo(arquivo2, matriz2, &linhas2, &colunas2);
	fclose(arquivo2);

	int resultado = igualdadeMatriz(linhas1, colunas1, matriz1, 0, linhas2, colunas2, matriz2);
	if(resultado>0){
		printf("as matrizes nao sao iguais\n");
	}else{
		printf("as matrizes sao iguais\n");
	}
}

int somarMatrizes(int l1, int c1, int m1[l1][c1], int l2, int c2, int m2[l2][c2], int n, int l3, int c3, int m3[l3][c3]){
	for(int i = 0; i<l1; i++){
		for(int j=0; j<c1; j++){
			m3[i][j] = m1[i][j] + (m2[i][j] * n);
		}
	}
	return 0;
	
}

void metodo1019(){
	FILE *arquivo1;
	arquivo1 = fopen("DADOS4.txt", "r");
	FILE *arquivo2;
	arquivo2 = fopen("DADOS6.txt", "r");

	int matriz1[100][100];
    int linha1, coluna1;
	int matriz2[100][100];
    int linha2, coluna2;

	lerMatrizDoArquivo(arquivo1, matriz1, &linha1, &coluna1);
	fclose(arquivo1);
	lerMatrizDoArquivo(arquivo2, matriz2, &linha2, &coluna2);
	fclose(arquivo2);
	
	if(linha1 == linha2 && coluna1 == coluna2){
		printf("digite uma constante para ocorrer a multiplicacao na segunda matriz\n");
		int constante;
		scanf("%d", &constante);

		int soma[100][100];
		int resultado = somarMatrizes(linha1, coluna1, matriz1, linha2, coluna2, matriz2, constante, linha1, coluna1, soma);
        
        if (resultado == 0) {  
            for(int i = 0; i < linha1; i++){
				for(int j = 0; j<coluna1; j++){
					printf("%d ", soma[i][j]);
				}
            }
            printf("\n");
        } else {
            printf("erro ao somar as matrizes.\n");
        }
	}else{
		printf("os tamanhos nao sao iguais, com isso, nao havera a soma\n");
	}


	fclose(arquivo1);
	fclose(arquivo2);
}

int multiplicarMatrizes(int l1, int c1, int m1[l1][c1], int l2, int c2, int m2[l2][c2], int l3, int c3, int m3[l3][c3]){
    if (c1 != l2) { 
        return -1;
    }

    for(int i = 0; i < l1; i++){
        for(int j = 0; j < c2; j++){
            m3[i][j] = 0; 
            for(int k = 0; k < c1; k++){
                m3[i][j] += m1[i][k] * m2[k][j]; 
            }
        }
    }
    return 0;
}

void metodo1020(){
    FILE *arquivo1;
    arquivo1 = fopen("DADOS4.txt", "r");
    FILE *arquivo2;
    arquivo2 = fopen("DADOS6.txt", "r");

    int matriz1[100][100];
    int linhas1, colunas1;
    int matriz2[100][100];
    int linhas2, colunas2;

    lerMatrizDoArquivo(arquivo1, matriz1, &linhas1, &colunas1);
    fclose(arquivo1);
    lerMatrizDoArquivo(arquivo2, matriz2, &linhas2, &colunas2);
    fclose(arquivo2);
    
    if (colunas1 == linhas2) {
        int resultado[100][100];
        int multiplicacao = multiplicarMatrizes(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, linhas1, colunas2, resultado);
        
        if (multiplicacao == 0) {  
            for (int i = 0; i < linhas1; i++) {
                for (int j = 0; j < colunas2; j++) {
                    printf("%d ", resultado[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Erro ao multiplicar as matrizes.\n");
        }
    } else {
        printf("Os tamanhos nao sao compatíveis para multiplicação.\n");
    }
}

void decrescente(int arr[], int tam, int novo[]){
    for (int i = 0; i < tam; i++) {
        novo[i] = arr[i];
    }

    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (novo[i] < novo[j]) {
                int temp = novo[i];
                novo[i] = novo[j];
                novo[j] = temp;
            }
        }
    }
}

void metodo10E1(){
    FILE *arquivo;
    arquivo = fopen("DADOS7.txt", "r");

    int array[100];
    int tamanho;
    tamanho = lerArquivo(arquivo, array);

    int novo[100];
    decrescente(array, tamanho, novo);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", novo[i]);
    }
    
    fclose(arquivo);
}


int ehIdentidade(int matriz[100][100], int ordem) {
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            if ((i == j && matriz[i][j] != 1) || (i != j && matriz[i][j] != 0)) {
                return 0; 
            }
        }
    }
    return 1;
}

void metodo10E2(){
    FILE *arquivo1;
	arquivo1 = fopen("DADOS4.txt", "r");
    FILE *arquivo2;
	arquivo2= fopen("DADOS6.txt", "r");


    int matriz1[100][100];
    int linhas1, colunas1;
    int matriz2[100][100];
    int linhas2, colunas2;

   
    lerMatrizDoArquivo(arquivo1, matriz1, &linhas1, &colunas1);
    fclose(arquivo1);
    
    lerMatrizDoArquivo(arquivo2, matriz2, &linhas2, &colunas2);
    fclose(arquivo2);
    
    if (colunas1 == linhas2) { 
        int resultado[100][100];
        int multiplicacao = multiplicarMatrizes(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, linhas1, colunas2, resultado);
        
        if (multiplicacao == 0) {  
            if (ehIdentidade(resultado, linhas1)) {
                printf("O produto das matrizes é a matriz identidade.\n");
            } else {
                printf("O produto das matrizes NÃO é a matriz identidade.\n");
            }
        } else {
            printf("Erro ao multiplicar as matrizes.\n");
        }
    } else {
        printf("Os tamanhos nao sao compatíveis para multiplicação.\n");
    }
}

int main(){
int opcao;


    do{
    printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo1011\n2-metodo1012\n3-metodo1013\n4-metodo1014\n5-metodo1015\n6-metodo1016\n7-metodo1017\n8-metodo1018\n9-metodo1019\n10-metodo1020\n11-metodo10E1\n12-metodo10E2\n");
    scanf("%d", &opcao);
	getchar();


    switch(opcao){
        case 1:
        metodo1011();
        break;
        
        case 2:
        metodo1012();
        break;
        
        case 3:
        metodo1013();
        break;
        
        case 4:
        metodo1014();
        break;
        
        case 5:
        metodo1015();
        break;
        
        case 6:
        metodo1016();
        break;
        
        case 7:
        metodo1017();
        break;
        
        case 8:
        metodo1018();
        break;
        
        case 9:
        metodo1019();
        break;
        
        case 10:
        metodo1020();
        break;
        
        case 11:
        metodo10E1();
        break;
        
        case 12:
        metodo10E2();
        break;

    }

    }while(opcao !=0);

    return 0;
}

