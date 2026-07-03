//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void metodo0811(){
	int tamanho;
	printf("digite o tamanho desejado do array\n");
	scanf("%d", &tamanho);

	if(tamanho>0){
		int array[tamanho];
		printf("digite os valores do array(impares e positivos)\n");
		for(int i = 0; i<tamanho; i++){
				scanf("%d", &array[i]);
				if(array[i]%2!=0 && array[i]>0){
					printf("%d ", array[i]);
			    } 
		}
		
     }else if(tamanho<0){
		printf("tamanho invalido\n");
	}

	printf("\n");
}

void metodo0812() {
    FILE *arq;
    arq = fopen("ARQUIVO02.txt", "rt");
    
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    int c[100];
    int i = 0;
    int outro[100];
    int tamanho = 0;
    int tamanho2 = 0;
    
    while (fscanf(arq, "%d", &c[i]) == 1) {
        tamanho++;
        if (c[i] % 2 != 0 && c[i] > 0) {
            outro[tamanho2] = c[i];  
            tamanho2++;
        }
        i++;
    }

    fclose(arq);  

    FILE *arq2;
    arq2 = fopen("RESULTADO02.txt", "w");
    if (arq2 == NULL) {
        printf("Erro ao abrir o arquivo para escrita\n");
        return;
    }

    fprintf(arq2, "%d\n", tamanho);
    
    
    for (int j = 0; j < tamanho2; j++) {
        fprintf(arq2, "%d", outro[j]);
    }
    
    fclose(arq2);  
    printf("As informações foram guardadas no arquivo RESULTADO02.txt\n");
}

void gerarInt(int inferior, int superior){
    
    if (superior <= inferior) {
        printf("Intervalo inválido.\n");
        return;
    }

    int numeros =  1 + (superior - inferior);
    int array[numeros];

    srand(time(0));

    for(int i = 0; i < numeros; i++){
        array[i] = inferior + rand() % (superior - inferior + 1);
    }

    FILE *arq;
    arq = fopen("DADOS.txt", "w");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arq, "%d\n", numeros);

    for(int j = 0; j < numeros; j++){
        fprintf(arq, "%d\n", array[j]);
    }

    fclose(arq);
    printf("Os numeros foram gravados no arquivo DADOS.txt\n");
}

void metodo0813(){
    int primeiro, segundo;
    printf("Digite o primeiro valor que definirá o começo do intervalo:\n");
    scanf("%d", &primeiro);
    printf("Digite o segundo valor que definirá o final do intervalo:\n");
    scanf("%d", &segundo);
    
    gerarInt(primeiro, segundo);
}

void lerArquivo(FILE *DADOS, int n) {
    int array[100];
    int menor = -1;  

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] % 2 != 0) {  
            if (menor == -1 || array[i] < menor) {
                menor = array[i]; 
            }
        }
    }

    if (menor != -1) {
        fprintf(DADOS, "%d", menor);  
        printf("O menor ímpar foi gravado no arquivo DADOS.txt\n");
    } else {
        printf("Nenhum número ímpar foi encontrado.\n");
    }
}

void metodo0814() {
    FILE *arq = fopen("DADOS.txt", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo DADOS.txt.\n");
        return;
    }

    int x;
    printf("Digite a quantidade de números do array:\n");
    scanf("%d", &x);

    lerArquivo(arq, x);

    fclose(arq); 
}

void acharMaior(FILE *DADOS, int n) {
    int array[100];
    int maior = 0;  

    printf("Digite os elementos do array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] % 2 == 0 && array[i]%3==0) {  
            if (maior == 0 || array[i] > maior) {
                maior = array[i]; 
            }
        }
    }

    if (maior != -1) {
        fprintf(DADOS, "%d", maior);  
        printf("O menor ímpar foi gravado no arquivo DADOS2.txt\n");
    } else {
        printf("Nenhum número ímpar foi encontrado.\n");
    }
}


void metodo0815() {
    FILE *arq = fopen("DADOS2.txt", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo DADOS2.txt.\n");
        return;
    }

    int x;
    printf("Digite a quantidade de números do array:\n");
    scanf("%d", &x);

    acharMaior(arq, x);

    fclose(arq); 
}

void acharMedia(FILE *DADOS) {
    int numeros[100];
    int contador = 0;

    while (fscanf(DADOS, "%d", &numeros[contador]) == 1) {
        contador++;
    }

    if (contador == 0) {
        printf("Nenhum dado encontrado no arquivo.\n");
        return;
    }

    int soma = 0;
    for (int i = 0; i < contador; i++) {
        soma += numeros[i];
    }

    double media = (double) soma / contador;

    FILE *arq2 = fopen("mediaBaixo.txt", "w");
    FILE *arq3 = fopen("mediaCima.txt", "w");

    if (arq2 == NULL || arq3 == NULL) {
        printf("Erro ao abrir os arquivos de saída.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        if (numeros[i] <= media) {
            fprintf(arq2, "%d\n", numeros[i]); 
        } else {
            fprintf(arq3, "%d\n", numeros[i]);  
        }
    }

    printf("Os dados foram gravados em ambos os arquivos (mediaBaixo.txt e mediaCima.txt).\n");

    fclose(arq2);
    fclose(arq3);
}

void metodo0816() {
    FILE *arq = fopen("DADOS.TXT", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo DADOS.TXT\n");
        return;
    }

    acharMedia(arq);

    fclose(arq);
}

void ordenadoOuN(int array[100], int n){ 
    int contador = 0;
    for(int i = 0; i < n - 1; i++){  
        if(array[i] < array[i+1]){  
            contador++;
        }
    }

    if(contador > 0){
        printf("O vetor não está ordenado em ordem decrescente\n");
    } else {
        printf("O vetor está ordenado em ordem decrescente\n");
    }
}

void metodo0817(){
    int sequencia[100];
    int tamanho = 0; 
    int numero = 0;
    printf("Digite uma sequência de valores e -1 para parar:\n");
    while(numero != -1 && tamanho < 100){
        scanf("%d", &numero);
        if(numero == -1){
            continue;
        }

        sequencia[tamanho] = numero;
        tamanho++;
    }

    ordenadoOuN(sequencia, tamanho);
}


void acharValor(int valor, int posicao, FILE *DADOS) {
    int array[100];
    int contador = 0;

    while(fscanf(DADOS, "%d", &array[contador]) == 1) {
        contador++;
    }

    if (contador > posicao && array[posicao] == valor) {
        printf("O valor %d foi encontrado na posição %d\n", valor, posicao);
    } else {
        printf("O valor não foi encontrado na posição desejada\n");
    }
}


void metodo0818(){
	
	FILE *arq;
	arq =  fopen("DADOS4.txt", "r");

	int v;
	printf("digite o valor a ser procurado\n");
	scanf("%d", &v);

	int p;
	printf("digite a posicao a ser verificada\n");
	scanf("%d", &p);

	acharValor(v, p, arq);
	fclose(arq);
	
}

void acharValor2(int valor, FILE *DADOS, int contador){ 
    int array[100];
    while(fscanf(DADOS, "%d", &array[contador]) == 1) {
        contador++;
    }

    for(int i = 0; i < contador; i++){
        if(array[i] == valor){
            printf("O valor desejado está na posição %d\n", i);
            return;
        }
    }

    printf("O valor não foi encontrado.\n");
}


void metodo0819(){ 
	
	FILE *arq;
	arq =  fopen("DADOS5.txt", "r");

	int v;
	printf("digite o valor a ser procurado\n");
	scanf("%d", &v);

	acharValor2(v, arq, 0);
	fclose(arq);
	
}

void quantidadeValor(int valor, FILE *DADOS, int contador){ 
	int array[100];
	while(fscanf(DADOS, "%d", &array[contador]) == 1) {
        contador++;
    }

	int quantidade = 0;
	for(int i = 0; i<contador; i++){
		if(array[i] == valor){
			quantidade++;
		}
	}

	printf("sao %d vezes que o numero desejado aparece\n", quantidade);

}

void metodo0820(){ 
	
	FILE *arq;
	arq =  fopen("DADOS6.txt", "r");

	int v;
	printf("digite o valor a ser procurado\n");
	scanf("%d", &v);

	acharValor2(v, arq, 0);

	fclose(arq);
	
}

void divisao(int n) {
    int array[100];
    int quantidade = 0;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && i % 2 != 0) {
            array[quantidade] = i;  
            quantidade++;          
        }
    }

    FILE *arq = fopen("DIVISORES.TXT", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arq, "%d\n", quantidade);
    
    for (int j = 0; j < quantidade; j++) {
        fprintf(arq, "%d ", array[j]);
    }
    fprintf(arq, "\n");
    
    fclose(arq);
    
    printf("%d\n", quantidade);
    for (int j = 0; j < quantidade; j++) {
        printf("%d ", array[j]);
    }
    printf("\n");
}

void metodo08E1() {
    int x;
    printf("Digite um numero:\n");
    scanf("%d", &x);

    divisao(x);
}

void retorno(FILE *palavras) {
    char palavra[100];
    int contador = 0;

    while (fscanf(palavras, "%s", palavra) == 1) {
        int len = strlen(palavra);

        
        if (!((palavra[0] == 'd' || palavra[0] == 'D') || (palavra[len - 1] == 'd' || palavra[len - 1] == 'D'))) {
            printf("%s\n", palavra);
            contador++;
        }

        if (contador == 10) {
            break;  
        }
    }
}

void metodo08E2() {
    FILE *arq = fopen("PALAVRAS.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo PALAVRAS.txt.\n");
        return;
    }

    retorno(arq);

    fclose(arq); 
}


int main() {
  int opcao;


    do{
    printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo0811\n2-metodo0812\n3-metodo0813\n4-metodo0814\n5-metodo0815\n6-metodo0816\n7-metodo0817\n8-metodo0818\n9-metodo0819\n10-metodo0820\n11-metodo08E1\n12-metodo08E2\n");
    scanf("%d", &opcao);
	getchar();


    switch(opcao){
        case 1:
        metodo0811();
        break;
        
        case 2:
        metodo0812();
        break;
        
        case 3:
        metodo0813();
        break;
        
        case 4:
        metodo0814();
        break;
        
        case 5:
        metodo0815();
        break;
        
        case 6:
        metodo0816();
        break;
        
        case 7:
        metodo0817();
        break;
        
        case 8:
        metodo0818();
        break;
        
        case 9:
        metodo0819();
        break;
        
        case 10:
        metodo0820();
        break;
        
        case 11:
        metodo08E1();
        break;
        
        case 12:
        metodo08E2();
        break;

    }

    }while(opcao !=0);

    return 0;
}
