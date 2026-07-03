//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <math.h>
#include <string.h>

void metodo0711(){
    int numero;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &numero);

    int inicial=3;
    int i = 0;
    int j = 1;
    while(i<numero){
        int resultado = inicial * j;
        if(resultado%2!=0){
            printf("%d ", resultado);
        }else{
            numero = numero +1;
        }

        j++;
        i++;
    }

    printf("\n");
}

void metodo0712(){
    int numero;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &numero);

   int valor = 36 + 6 * (numero - 1); 
    for (int i = 0; i < numero; i++) {
        printf("%d ", valor);
        valor -= 6; 
    }
    printf("\n");

 
}

void recursiva(int num, int atual){
    if(num>0){
        printf("%d ", atual);
		recursiva(num-1, atual *4);
    }
		
}

void metodo0713(){
    int n;
    printf("digite a quantidade de numeros da sequencia:\n");
    scanf("%d", &n);

    recursiva(n, 1);
	printf("\n");
}

void metodo0714(){
	int n;
	printf("digite a quantidade de numeros da sequencia:\n");
	scanf("%d", &n);

	int atual = 1;
	for(int j=1; j<n; j++){
		atual = atual *4;
	}

	int numerador = 1;
	for(int i = 1; i<=n; i++){
		printf("%d/%d ", numerador, atual);
		atual = atual/4;

	}
	printf("\n");
}

void metodo0715(){
	int n;
	printf("digite a quantidade de numeros da sequencia:\n");
	scanf("%d", &n);

	int numerador = 1; 
	int x;

	printf("digite a base da exponenciacao:\n");
	scanf("%d", &x);

	int expoente = 2;
	
	for(int i = 0; i<n; i++){
		printf("%d/%.2lf ",numerador,  pow(x, expoente));
		expoente = expoente +2;
	}

	printf("\n");
	
}

void metodo0716(){

	int n;
	printf("primeiramente, digite a quantidade de numeros a serem somados:\n");
	scanf("%d", &n);

	int x;

	printf("digite a base da exponenciacao:\n");
	scanf("%d", &x);

	int expoente = 2;
	double soma = 0;
	double resultado = 0;
	
	for(int i = 0; i<n; i++){
		resultado = 1/pow(x, expoente);
		soma = soma + resultado;
		expoente = expoente +2;
		
	}
	
	FILE *arq2;
	arq2 = fopen("RESULTADO06.txt", "w");
	fprintf(arq2, "%.2lf",soma);
	
	fclose(arq2);
	printf("a soma dos resultados foram gravadas no arquivo RESULTADO06\n");
	
}

void metodo0717(){
	int n;
	printf("digite a quantidade de numeros da sequencia:\n");
	scanf("%d", &n);

	double atual = 1.0;
	for(int j=1; j<n; j++){
		atual = atual *4;
	}

	double resultado = 0.0;
	double soma = 0.0;
	for(int i = 1; i<=n; i++){
		resultado = 1/atual;
		soma = soma + resultado;
		atual = atual/4;

	}
	FILE *arq;
	arq = fopen("RESULTADO07.txt", "w");
	fprintf(arq, "%.2lf",soma);
	
	fclose(arq);
	printf("a soma dos resultados foram gravadas no arquivo RESULTADO07\n");
}

void metodo0718(){
	int n;
	printf("digite uma quantidade de numeros\n");
	scanf("%d", &n);

	
	int anterior = 0;
	int atual = 1;
	int fibonacci;
	int soma = 0;

	//fibonacci = anterior + atual
	for(int i = 0; i<n; i++){
		fibonacci = atual + anterior;
		anterior = atual;
		atual = fibonacci;
		if(fibonacci%2!=0){
			n = n+ 1;
		} else {
			soma = soma + fibonacci;
		}
			
	}
	
	FILE *arq;
	arq = fopen("RESULTADO08.txt", "w");
	fprintf(arq, "%d", soma);

	fclose(arq);
	printf("a soma dos resultados foram gravadas no arquivo RESULTADO08\n");
	
}

void metodo0719(){
	char sequencia[100];
	printf("digite uma sequencia de caracteres\n");
	fgets(sequencia, 100, stdin);
	sequencia[strcspn(sequencia,"\n")] = '\0';

	int quantidade;
	quantidade=strlen(sequencia);

	FILE *arq;
	arq = fopen("RESULTADO09.txt", "w");

	for(int i =0; i<quantidade; i++){
		if(sequencia[i]>='a' && sequencia[i] <= 'z'){
			fprintf(arq, "%c", sequencia[i]);
		}
	}

	fclose(arq);
	printf("a soma dos resultados foram gravadas no arquivo RESULTADO09\n");

	
}

void metodo0720(){
	char sequencia[100];
	printf("digite uma sequencia de caracteres\n");
	fgets(sequencia, 100, stdin);
	sequencia[strcspn(sequencia,"\n")] = '\0';

	int quantidade;
	quantidade=strlen(sequencia);

	FILE *arq;
	arq = fopen("RESULTADO10.txt", "w");

	for(int i =0; i<quantidade; i++){
		if(sequencia[i]<= '4'){
			fprintf(arq, "%c", sequencia[i]);
		}
	}

	fclose(arq);
	printf("a soma dos resultados foram gravadas no arquivo RESULTADO10\n");
}

void metodo07E1(){
	int n;
	printf("digite um valor inteiro:\n");
	scanf("%d", &n);

	FILE *arq;
	arq = fopen("RESULTADO11.txt", "w");

	for(int i = n; i>0 ; i--){
		if(i%2==0 && n%i==0){
			fprintf(arq, "%d ", i);
		}
	}

	fclose(arq);
	printf("a soma dos resultados foram gravadas no arquivo RESULTADO11\n");
}

void metodo07E2(){

    FILE *arq = fopen("RESULTADO12.txt", "r");
    
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char c[100];
    int contador = 0;

    while (fscanf(arq, "%99s", c) == 1) {
        if (c[0] == 'D' || c[0] == 'd') {
            contador++;
        }
    }

    fclose(arq); 
    printf("Sao %d palavras que comecam com D ou d\n", contador);

}

int main(){

    int x;

    do{
        printf("digite o numero correspondente ao metodo(1 a 12) ou 0 para encerrar\n");
        scanf("%d", &x);
		getchar();
		
        switch(x){
            case 1:
            metodo0711();
            break;
            case 2:
            metodo0712();
            break;
            case 3:
            metodo0713();
            break;
            case 4:
            metodo0714();
            break;
            case 5:
            metodo0715();
            break;
            case 6:
            metodo0716();
            break;
            case 7:
            metodo0717();
            break;
            case 8:
            metodo0718();
            break;
            case 9:
            metodo0719();
            break;
            case 10:
            metodo0720();
            break;
            case 11:
            metodo07E1();
            break;
            case 12:
            metodo07E2();
            break;

        }

    }while(x!=0);
        
    return 0;
}

