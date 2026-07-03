//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <math.h>

void recursiva1(int x, int atual){//função que sera usada no metodo 0511
     if (x > 0) { 
        printf("%d ", atual); 
        recursiva1(x - 1, atual + 4);
    }
}

void metodo0511(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    recursiva1(n, 4);
    printf("\n");

}

void recursiva2(int x, int atual){//função que sera usada no metodo 0512
     if (x > 0) { 
        printf("%d ", atual); 
        recursiva2(x - 1, atual + 12);
    }
}

void metodo0512(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    recursiva2(n, 12);
    printf("\n");
}

void recursiva3(int x, int atual){//função que sera usada no metodo 0513
     if (x > 0) { 
        printf("%d ", atual); 
        recursiva3(x - 1, atual / 3);
    }
  
}

void metodo0513(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    int a =1;
    for(int i =0; i<n; i++){
        a *= 3;
    }

    recursiva3(n, a);
    printf("\n");
}

void recursiva4(int x, int atual){ //função que sera usada no metodo 0514
    int numerador = 1;
    if(x>0){
        printf("%d/%d  ", numerador, atual);
        recursiva4(x-1, atual+4);
      
    }
}

void metodo0514(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    recursiva4(n, 4);
      printf("\n");
}

void recursiva5(int num, int atual, int ex){ //função que sera usada no metodo 0515
    int numerador = 1;
    if(num>0){
        printf("%d/%lf  ", numerador, pow(atual, ex));
        recursiva5(num-1, atual, ex + 2);
    }
}

void metodo0515(){
    int x;
    printf("digite a base do denominador:\n");
    scanf("%d", &x);

    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    recursiva5(n, x, 1);
    printf("\n");
}


void soma(int x){ //função que sera usada no metodo 0516
    int tudo = 4;
    int soma = 0;
    for(int i = 1; i<x; i++){
        if((tudo + 4) % 5 != 0){
            tudo = tudo+4;
        } else if((tudo + 4) % 5 == 0){
            tudo = tudo +8;
        }
        soma += tudo;
    }
    printf("a soma e: %d\n", soma + 4);
}

void metodo0516(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    soma(n);
}

void somaInversos(int num) { //função que sera usada no metodo 0517
    double soma = 0.0;
    int contador = 0;
    int x = 3;
    
    while (contador < num) {
        if (x % 3 == 0 && x % 5 != 0) {
            soma += 1.0 / x;
            contador++;
        }
        x += 3; 
    }
    
    printf("a soma e: %.2lf\n", soma);
}

void metodo0517() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    somaInversos(n);
    
}

void recursiva8(int x){
    int soma =0;
    int atual = 4;

    for(int i = 1; i<=x; i++){
        soma = soma + atual;
        atual = atual + i;
        
    }

    printf("%d\n", soma);
}

void metodo0518(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    recursiva8(n);
}

void recursiva9(int x){
    double soma =0.0;
    double inicial = 4.0;

    for(int i = 0; i<x; i++){
        soma += pow(inicial, 2);
        inicial = inicial +1;
    }

    printf("a soma final e: %.2lf\n", soma);
} 

void metodo0519(){
    int n;
    printf("Digite a quantidade de numeros");
    scanf("%d", &n);
    
   recursiva9(n);
}

double recursiva10(int x){
     double soma = 0.0;
    int numero = 14;
    
    for (int i = 0; i < x; i++) {
        soma += 1.0 / numero;
        numero -= 4;  
    }
    
    return soma;
}

void metodo0520(){
    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);
    
    
    recursiva10(n);
}

int recursiva11(int n) {
    if (n == 0 || n == 1) {
        return 1; 
    } else {
        return n * recursiva11(n - 1); 
    }
}

void metodo05E1(){
    int n;
    printf("digite o numero a ser calculado o fatorial\n");
    scanf("%d", &n);

    int resultado = recursiva11(n);
    printf("o fatorial do numero digitado e: %d\n", resultado);
}

int fatorial(int x) {
    int fat = 1;
    for (int i = 1; i <= x; i++) {
        fat *= i;
    }
    return fat;
}

void metodo05E2() {
    double resultado = 1.0;
    int numerador = 3; 
    int denominador = 2;  

    int n;
    printf("digite a quantidade de numeros:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        resultado *= (1 + (double) numerador / fatorial(denominador));  
        numerador += 2; 
        denominador += 2;  
    }

    printf("resultado de f(%d) = %lf\n", n, resultado);  // Imprime o resultado
}



int main(){
    int opcao;

    do{

    printf("digite o numero correspondente ao metodo desejado(1 a 12) ou 0 para terminar:\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
        metodo0511();
        break;
        case 2:
        metodo0512();
        break;
        case 3:
        metodo0513();
        break;
        case 4:
        metodo0514();
        break;
        case 5:
        metodo0515();
        break;
        case 6:
        metodo0516();
        break;
        case 7:
        metodo0517();
        break;
        case 8:
        metodo0518();
        break;
        case 9:
        metodo0519();
        break;
        case 10:
        metodo0520();
        break;
        case 11:
        metodo05E1();
        break;
        case 12:
        metodo05E2();
        break;
        


    }

        
    }while(opcao != 0);

    return 0;
}