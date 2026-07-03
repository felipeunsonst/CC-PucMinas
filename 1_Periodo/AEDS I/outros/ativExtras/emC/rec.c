//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int divisores(int x){
	int par=0;
	int impar=0;
	int z[x];
	for(int i =0; i<x; i++){
		scanf("%d", &z[i]);
		if(z[i]%2==0){
		par++;
		} else if(z[i]%2!=0){
		impar++;
		}
	}

	if(par>impar){
		return par;
	}else if(par<impar){
		return impar;
	}else{
		return 0;
	}
}

void exercicio01(){
	int n;
	printf("digite uma quantidade:\n");
	scanf("%d", &n);

	int resultado = divisores(n);
	if(resultado>0){
		printf("ha mais valores pares\n");
	}else{
		printf("ha mais valores impares\n");
	}
}

bool primo(int numero){
	int naoeprimo =0;
	for(int i=numero-1; i>1; i--){
		if(numero%i==0){
			naoeprimo++;
		}
	}
	if(naoeprimo==0){
		return true;
	}
}

void exercicio02(){
	int n;
	printf("digite uma quantidade:\n");
	scanf("%d", &n);

	int x[n];
	for(int i = 0; i<n; i++){
		scanf("%d", &x[i]);
		if(primo(x[i])){
			printf("o numero %d e primo\n", x[i]);
		}
	}

}

int logico(char ch) {
    return (ch == '&' || ch == '|' || ch == '!');
}

int aritmetico(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int relacional(char ch) {
    return (ch == '<' || ch == '>' || ch == '=');
}

int separador(char ch) {
    return (ch == ' ' || ch == '.' || ch == ',' || ch == ';' || ch == ':' || ch == '_');
}

void exercicio03() {
    char cadeia[100];
    int opcao, i, encontrado = 0;

    printf("digite uma cadeia de caracteres: ");
    fgets(cadeia, sizeof(cadeia), stdin);
    int tamanho = strlen(cadeia);

    do {
        printf("\nescolha uma opção para verificar os caracteres:\n1 - operador lógico\n2 - operador aritmético\n3 - operador relacional\n4 - separadores\n0 - sair\n");
        scanf("%d", &opcao);
        getchar(); 

        encontrado = 0; 

        
        switch (opcao) {
            case 1: 
                for (i = 0; i < tamanho; i++) {
                    if (logico(cadeia[i])) {
                        printf("caractere '%c' é um operador lógico.\n", cadeia[i]);
                        encontrado = 1;
                    }
                }
                break;

            case 2: 
                for (i = 0; i < tamanho; i++) {
                    if (aritmetico(cadeia[i])) {
                        printf("caractere '%c' é um operador aritmético.\n", cadeia[i]);
                        encontrado = 1;
                    }
                }
                break;

            case 3: 
                for (i = 0; i < tamanho; i++) {
                    if (relacional(cadeia[i])) {
                        printf("caractere '%c' é um operador relacional.\n", cadeia[i]);
                        encontrado = 1;
                    }
                }
                break;

            case 4: 
                for (i = 0; i < tamanho; i++) {
                    if (separador(cadeia[i])) {
                        printf("caractere '%c' é um separador.\n", cadeia[i]);
                        encontrado = 1;
                    }
                }
                break;

            default:
                printf("opção inválida\n");
                break;
        }

        if (opcao != 0 && !encontrado) {
            printf("nenhum caractere correspondente encontrado.\n");
        }

    } while (opcao != 0);
}

int contarMaiusculas(char cadeia[], int tamanho) {
    int maiusculas = 0;
    for (int i = 0; i < tamanho; i++) {
        if (cadeia[i] >= 'A' && cadeia[i] <= 'Z') {
            maiusculas++;
        }
    }
    return maiusculas;
}

int contarMinusculas(char cadeia[], int tamanho) {
    int minusculas = 0;
    for (int i = 0; i < tamanho; i++) {
        if (cadeia[i] >= 'a' && cadeia[i] <= 'z') {
            minusculas++;
        }
    }
    return minusculas;
}

int contarDigitos(char cadeia[], int tamanho) {
    int digitos = 0;
    for (int i = 0; i < tamanho; i++) {
        if (cadeia[i] >= '0' && cadeia[i] <= '9') {
            digitos++;
        }
    }
    return digitos;
}

void exercicio04(){
	char cadeia[100];
    int maiusculas, minusculas, digitos, operadores, separadores_cont;
    int opcao, i;

    printf("digite uma cadeia de caracteres: ");
    scanf("%s", cadeia);
	getchar();
    int tamanho;
	tamanho = strlen(cadeia);

    do {
        printf("\nescolha uma opção para verificar os caracteres:\n1 - contar letras maiúsculas\n2 -contar letras minúsculas\n3 - contar dígitos\n4 - contar operadores (lógicos, aritméticos, relacionais)\n5 - contar separadores\n0 - sair\n");
        scanf("%d", &opcao);
        getchar(); 

        maiusculas = minusculas = digitos = operadores = separadores_cont = 0;

        switch (opcao) {
            case 1: 
                maiusculas = contarMaiusculas(cadeia, tamanho);
                printf("quantidade de letras maiúsculas: %d\n", maiusculas);
                break;

            case 2: 
                minusculas = contarMinusculas(cadeia, tamanho);
                printf("quantidade de letras minúsculas: %d\n", minusculas);
                break;

            case 3: 
                digitos = contarDigitos(cadeia, tamanho);
                printf("quantidade de dígitos: %d\n", digitos);
                break;

            case 4:
                for (i = 0; i < tamanho; i++) {
                    if (logico(cadeia[i]) || aritmetico(cadeia[i]) || relacional(cadeia[i])) {
                        operadores++;
                    }
                }
                printf("quantidade de operadores: %d\n", operadores);
                break;

            case 5: 
                for (i = 0; i < tamanho; i++) {
                    if (separador(cadeia[i])) {
                        separadores_cont++;
                    }
                }
                printf("quantidade de separadores: %d\n", separadores_cont);
                break;

            default:
                printf("opção inválida\n");
      
		}
    } while (opcao != 0); 

}

double mediaMaior(double *arr, int tam){
	int somaMaior = 0;
	double q3=0;
	
	for(int i=0; i<tam; i++){
		 if(arr[i]>91.25){
			somaMaior+= arr[i];
			q3++;
		}
	}
	if (q3 == 0){
		return 0;
	}
	double mediaMaior = somaMaior/q3;
	return mediaMaior;
}

double mediaEntre(double *arr, int tam){
	int somaEntre = 0;
	double q2=0;
	
	for(int i=0; i<tam; i++){
		if(arr[i]> -27.25 && arr[i]< 91.25){
			somaEntre += arr[i];
			q2++;
		}
	}
	if (q2 == 0){
		return 0;
	}
	double mediaEntre = somaEntre/q2;
	return mediaEntre;
}

double mediaMenor(double *arr, int tam){
	int somaMenor = 0;
	double q1=0;
	
	for(int i=0; i<tam; i++){
		if(arr[i]< -27.25){
			somaMenor += arr[i];
			q1++;
		}
	}
	if (q1 == 0){
		return 0;
	}
	double mediaMenor = somaMenor/q1;
	return mediaMenor;
}

void exercicio05(){
	int n;
	printf("digite a quantidade de numeros:\n");
	scanf("%d", &n);

	double x[n];
	double r1 = mediaMenor(x, n);
	double r2 = mediaEntre(x, n);
	double r3 = mediaMaior(x, n);

	printf("A media dos menores e: %.2lf\nA media dos numeros entre o intervalo e: %.2lf\nA media dos maiores e: %.2lf\n", r1, r2, r3);

	if(r1<r2 && r1<r3){
		printf("a menor media e: %.2lf", r1);
	}

	if(r2<r1 && r2<r3){
		printf("a menor media e: %.2lf", r2);
	}

	if(r3<r1 && r3<r2){
		printf("a menor media e: %.2lf", r3);
	}
}

double inversao(int n){
	double inverso;
	inverso = 1/pow(n,3);
	return inverso;
}

void exercicio06(){
	int a, b;
	printf("digite os numeros do intervalo aberto:\n");
	scanf("%d", &a);
	scanf("%d", &b);

	int x;
	int quantidade=0;
	int soma = 0;
	
	printf("digite os numeros (-1 para parar)");
	do{
		scanf("%d", &x);
		quantidade++;

		if(x!=a && x!=b && x%2!=0 && x%3==0){
			soma = soma +x;
		}
		if(soma !=0){
			double resultado = inversao(soma);
			printf("%.2lf ", resultado);
		}
		
	}while(x != -1);

	printf("\ntotal de números inseridos: %d\n", quantidade - 1);//coloquei isso so pra gerar alguma coisa caso não realize a soma
}

double porcentagem(int n, int q){
	double proporcao;
	proporcao = (double)n/(double)q;
	return proporcao;
}

void exercicio07(){
	int a, b;
	printf("digite os numeros do intervalo aberto:\n");
	scanf("%d", &a);
	scanf("%d", &b);

	int x;
	int quantidade=0;
	int dentro = 0;
	int fora = 0;

	printf("digite os numeros (0 para parar)");
	do{
		scanf("%d", &x);
		quantidade++;

		if(x!=a && x!=b){
			if(x>a && x<b){
				dentro++;
			}

			if(x<a || x>b){
				fora++;
			}
			
		}

	}while(x != 0);

	double r1 = porcentagem(dentro, quantidade-1);
	double r2 = porcentagem(fora, quantidade-1);

	double p1 = r1 *100;
	double p2 = r2 *100;

	printf("a porcentagem de numeros dentro do intervalo e %.2lf\na porcentagem de numeros fora do intervalo e: %.2lf\n", p1, p2);

}

int ordem(int a, int b, int c){
	if(a<b && b<c){
		return 1;
	}else if(a>b && b>c){
		return 2;
	}else{
		return 3;
	}
}

void exercicio08(){
	int x;
	int y;
	int z;

	printf("digite os numeros:\n");
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);

	int resultado = ordem(x, y, z);
	if(resultado ==1){
		printf("ordem crescente");
	}

	if(resultado ==2){
		printf("ordem decrescente");
	}

	if(resultado ==3){
		printf("nao esta em ordem\n");
		if(x>y && x>z){
			printf("maior e %d\n", x);
		}
		if(y>x && y>z){
			printf("maior e %d\n", y);
		}
		if(z>x && z>y){
			printf("maior e %d\n", z);
		}

		if(x<y && x<z){
			printf("menor e %d\n", x);
		}
		if(y<x && y<z){
			printf("menor e %d\n", y);
		}
		if(z<x && z<y){
			printf("menor e %d\n", z);
		}
	}
}

int ordem2(char a, char b, char c) {
    if (a < b && b < c) {
        return 1; 
    } else if (a > b && b > c) {
        return 2; 
    } else {
        return 3; 
    }
}

void exercicio09() {
    char x, y, z;

    printf("Digite os caracteres:\n");
    scanf(" %c", &x);
    scanf(" %c", &y);
    scanf(" %c", &z);

    int resultado = ordem2(x, y, z);

    if (resultado == 1) {
        printf("Ordem crescente\n");
    } else if (resultado == 2) {
        printf("Ordem decrescente\n");
    } else {
        printf("Não está em ordem\n");
    }
}

int ordem3(char x[], char y[], char z[], int *ordem, char **menor, char **maior) {
    printf("Digite a primeira cadeia: ");
    fgets(x, 100, stdin);
    x[strcspn(x, "\n")] = 0;

    printf("Digite a segunda cadeia: ");
    fgets(y, 100, stdin);
    y[strcspn(y, "\n")] = 0; 

    printf("Digite a terceira cadeia: ");
    fgets(z, 100, stdin);
    z[strcspn(z, "\n")] = 0; 

    
    int compXY = strcmp(x, y);
    int compXZ = strcmp(x, z);
    int compYZ = strcmp(y, z);

    if (compXY < 0 && compXZ < 0 && compYZ < 0) {
        *ordem = -1; 
    } else if (compXY > 0 && compXZ > 0 && compYZ > 0) {
        *ordem = 1; 
    } else {
        *ordem = 0; 
        if (compXY < 0) {
            *menor = x;
            *maior = y;
        } else if (compXY > 0) {
            *menor = y;
            *maior = x;
        } else {
            *menor = x; 
            *maior = z; 
        }

        if (strcmp(*menor, z) > 0) {
            *menor = z;
        }
        if (strcmp(*maior, z) < 0) {
            *maior = z;
        }
    }

    return 0; 
}


void exercicio10() {
    char x[100], y[100], z[100];
    int ordem;
    char *menor, *maior;

    ordem3(x, y, z, &ordem, &menor, &maior);

    if (ordem == -1) {
        printf("As cadeias estão em ordem alfabética decrescente.\n");
    } else if (ordem == 1) {
        printf("As cadeias estão em ordem alfabética crescente.\n");
    } else {
        printf("As cadeias estão em nenhuma das ordens.\n");
        printf("Menor: %s\n", menor);
        printf("Maior: %s\n", maior);
    }
}

int main(){
int opcao;


    do{
    printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-exercicio01\n2-exercicio02\n3-exercicio03\n4-exercicio04\n5-exercicio05\n6-exercicio06\n7-exercicio07\n8-exercicio08\n9-exercicio09\n10-exercicio10\n");
    scanf("%d", &opcao);
	getchar();


    switch(opcao){
        case 1:
        exercicio01();
        break;
        
        case 2:
        exercicio02();
        break;
        
        case 3:
        exercicio03();
        break;
        
        case 4:
       exercicio04();
        break;
        
        case 5:
        exercicio05();
        break;
        
        case 6:
        exercicio06();
        break;
        
        case 7:
        exercicio07();
        break;
        
        case 8:
        exercicio08();
        break;
        
        case 9:
        exercicio09();
        break;
        
        case 10:
        exercicio10();
        break;
    
    }

    }while(opcao !=0);

    return 0;
}
