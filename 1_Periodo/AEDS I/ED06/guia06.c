//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <string.h>
#include <math.h>

void recursiva1(int z, int atual){
    if(z>0){
        printf("%d ", atual);
        recursiva1(z-1, atual +4);
    }
}

void metodo0611(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    recursiva1(n, 4);
     printf("\n");
}

void recursiva2(int z, int atual){
    if(z>0){
        printf("%d ", atual);
        recursiva2(z-1, atual -4);
    }
}

void metodo0612(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    int a =4;
    for(int i =1; i<n; i++){
        a = a +4;
    }

    recursiva2(n, a);
     printf("\n");
}

void recursiva3(int z, int atual){
     if(z>0){
         if(atual<4){
            printf("1/1 ");
            recursiva3(z-1, atual + 3);
         } else {
        printf("1/%d ", atual);
        recursiva3(z-1, atual + 4);
         }
    }
}

void metodo0613(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    recursiva3(n, 1);
    printf("\n");
}

void recursiva4(int z, int atual){
    if(z>0){
         if(atual<4){
            printf("1/1 ");
         } else {
        printf("1/%d ", atual);
        recursiva4(z-1, atual - 4);
         }
    }
}

void metodo0614(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    int a =0;
    for(int i =1; i<n; i++){
        a = a +4;
    }

    recursiva4(n, a);
    printf("\n");
}

int recursiva5(int z, int atual, int prox, int soma){
    if (z == 0) {
        return soma;
    }
    return recursiva5(z - 1, atual + prox, prox + 2, soma + atual);
}

void metodo0615(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    int resultado = recursiva5(n, 4, 2, 0);
    printf("%d", resultado);
    printf("\n");
}

double recursiva6(int z, double atual, double prox, double soma){
    if(z==0){
        return soma;
    }

    double termo = 1 / atual;
    return recursiva6(z - 1, atual + prox, prox + 2, soma + termo);
}

void metodo0616(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    double resultado = recursiva6(n, 4, 2, 0);
    printf("%.2lf", resultado);
    printf("\n");
}

void recursiva7(char palavra[100], int total ,int caracter){
     if(total==0){
         return;
      }
      printf("%c\n", palavra[caracter]);
      recursiva7(palavra, total-1, caracter+1);
}

void metodo0617(){
    char sequencia[100];
    printf("digite uma cadeia de caracteres:\n");
    fgets(sequencia, 100, stdin);

    int i = strlen(sequencia);
    int j = i;
    while(j>0){
        j--;
    }

    recursiva7(sequencia, i ,j);
    printf("\n");
}

int recursiva8(char palavra[100], int total, int caracter, int impar){
    if(total==0){
        return impar;
    }
        if(palavra[caracter] == '1' || palavra[caracter] == '3' || palavra[caracter] == '5' || palavra[caracter] == '7' || palavra[caracter] == '9'){
            impar++;
        }
       return recursiva8(palavra, total -1, caracter +1, impar);
}

void metodo0618(){
    char sequencia[100];
    printf("digite uma cadeia de caracteres:\n");
    fgets(sequencia, 100, stdin);

    int i = strlen(sequencia);
    int j = i;
    while(j>0){
        j--;
    }

    int resultado = recursiva8(sequencia, i ,j, 0);
    printf("a quantidade de impares: %d\n", resultado);
    printf("\n");
}

int recursiva9(char palavra[100], int total, int caracter, int maiores){
     if(total==0){
        return maiores;
    }
        if(palavra[caracter] <= 'Z' && palavra[caracter] >= 'M'){
            maiores++;
        }
       return recursiva9(palavra, total -1, caracter +1, maiores);
}

void metodo0619(){
    char sequencia[100];
    printf("digite uma cadeia de caracteres:\n");
    fgets(sequencia, 100, stdin);

    int i = strlen(sequencia);
    int j = i;
    while(j>0){
        j--;
    }

    int resultado = recursiva9(sequencia, i ,j, 0);
    printf("a quantidade de letras maiores que M: %d\n", resultado);
    printf("\n");
}

int recursiva10(int z, int antigo, int novo, int par){
    if(z == 0) {
        return par;
    } 
    if(novo % 2 == 0){
        par += novo;  
        z--;  
    }
    int proximo = antigo + novo;  
    return recursiva10(z, novo, proximo, par);  

}

void metodo0620(){
    int n;
    printf("digite o numero par a ser encontrado na sequencia de fibonacci:\n");
    scanf("%d", &n);

    int resultado = recursiva10(n, 0, 1, 0);
    printf("o %d termo par da sequencia de fibonacci e: %d\n", n, resultado);
}

int recursiva11(int y, int vezes, int soma, int expoente){
	if(vezes -1 == 0){
		return soma;
	}
	
	return recursiva11(y, vezes-1, soma + (int)pow(y, expoente), expoente + 2);
}

void metodo06E1(){
	int x;
	printf("Digite o valor da base:\n");
	scanf("%d", &x);

	int n;
	printf("Digite a quantidade de vezes que o expoente irá aumentar em 2:\n");
	scanf("%d", &n);

	int resultado = recursiva11(x, n, 1, 2);
	printf("A soma é: %d\n", resultado);
}

double recursiva12(int termos, int numerador, int denominador, unsigned long long fatorialAtual) {
    if (termos == 0) {
        return 1;  
    }

    double termoAtual = (double) numerador / fatorialAtual;

    return termoAtual + recursiva12(termos - 1, numerador * 3 + 1, denominador + 1, fatorialAtual * (denominador + 1));
}

void metodo06E2() {
    int n;
    printf("Digite o número de termos:\n");
    scanf("%d", &n);

    double resultado = recursiva12(n, 2, 3, 6);
    printf("O valor de e é: %lf\n", resultado);
}


int main(){

    int x;
    
    do{
    printf("digite o numero correspondente ao metodo desejado (1 a 12) ou 0 para encerrar:\n");
    scanf("%d", &x);
	getchar();

    switch(x){
        case 1:
        metodo0611();
        break;
        case 2:
        metodo0612();
        break;
        case 3:
        metodo0613();
        break;
        case 4:
        metodo0614();
        break;
        case 5:
        metodo0615();
        break;
        case 6:
        metodo0616();
        break;
        case 7:
        metodo0617();
        break;
        case 8:
        metodo0618();
        break;
        case 9:
        metodo0619();
        break;
        case 10:
        metodo0620();
        break;
        case 11:
        metodo06E1();
        break;
        case 12:
        metodo06E2();
        break;
        
    }

    }while(x!=0);
    
    return 0;
}