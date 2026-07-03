//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>

void metodo0211(){
    //verificar se o número é par ou impar
    int num;
    printf("digite um numero\n");
    scanf("%d", &num);

    if(num%2==0 || num==0){
        printf("o numero escolhido e par\n");
    } else {
        printf("o numero escolhido e impar\n");
    }


    //entrada: -6
    //saída: o numero escolhido e par

    //entrada: -3
    //saída: o numero escolhido e impar

    //entrada: 0
    //saída: o numero escolhido e par
}

void metodo0212(){
    //verificar se o numero é impar e menor que 15 ou se o numero é par e maior que 15
    int num;
    printf("digite um numero\n");
    scanf("%d", &num);

    if(num%2!=0 && num< -15){
        printf("o numero e impar e menor que 15\n");
    }else if(num%2==0 && num> 15){
        printf("o numero e par e maior que 15\n");
    }else{
        printf("o numero nao se encontra nas condiçoes\n");
    }


    //entrada: -60
    //saida: o numero e impar e menor que 15

    //entrada: -13
    //saída: o numero nao se encontra nas condiçoes

    //entrada: 0
    //saída: o numero nao se encontra nas condiçoes
}

void metodo0213(){
     //verificar se o numero esta enntre o intervalo 25-45

    int num;
    printf("digite um numero\n");
    scanf("%d", &num);

    if(num>=25 && num<=45){
        printf("o numero se encontra entre o intervalo\n");
        }else{
        printf("o numero esta fora do intervalo\n");
    }

    //entrada: 15
    //saida: o numero esta fora do intervalo

    //entrada: 25
    //saída: o numero se encontra entre o intervalo

    //entrada: 30
    //saída: o numero se encontra entre o intervalo
}

void metodo0214(){
    //verificar se o numero esta enntre o intervalo 20-60

    int num;
    printf("digite um numero\n");
    scanf("%d", &num);

    if(num>=20 && num<=60){
        printf("o numero se encontra entre o intervalo\n");
        }else{
        printf("o numero esta fora do intervalo\n");
    }

    //entrada: 5
    //saida: o numero esta fora do intervalo

    //entrada: 15
    //saída: o numero esta fora do intervalo

    //entrada: 20
    //saída: o numero se encontra entre o intervalo
}

void metodo0215(){
    //verificar se o numero dado esta entre dois ou um intervalo

    int num;
    printf("digite um numero\n");
    scanf("%d", &num);

    //intervalo 1 --- 10 a 24
    //intervalo 2 --- 15 a 50

    if(num >= 15 && num <= 24){
        printf("o numero esta presente em ambos os intervalos\n");
    }else if(num <10 || num > 50){
        printf("o numero não se encontra em nenhum intervalo\n");
    }else{
        printf("o numero se encontra em apenas um intervalo\n");
    }

    //entrada: 5
    //saida: o numero não se encontra em nenhum intervalo

    //entrada: 15
    //saida: o numero esta presente em ambos os intervalos

    //entrada: 20
    //saida: o numero esta presente em ambos os intervalos

}


void metodo0216(){
//ler dois numeros e verificar se o primeiro é par e o segundo é ímpar.
    int num1, num2;
    printf("digite dois numeros\n");
    scanf("%d %d", &num1, &num2);

    if(num1%2==0 && num2%2!=0){
        printf("o primeiro é par e o segundo é ímpar\n");
    }else if(num1%2==0 && num2%2==0){
        printf("ambos os numeros são pares\n");
    }else if(num1%2!=0 && num2%2==0){
        printf("o primeiro é impar e o segundo e par\n");
    }else if(num1%2!=0 && num2%2!=0){
        printf("ambos os numeros sao impares\n");
    }



    //entrada: 5, 15
    //saída: ambos os numeros sao impares

    //entrada: 35, 40
    //saida: o primeiro é impar e o segundo e par

    //entrada: 60, 72
    //saida: ambos os numeros são pares

    
}

void metodo0217(){
// ler dois valores inteiros e dizer se o primeiro é ímpar e negativo, e se o segundo é par e positivo.

    int num1, num2;
    printf("digite dois numeros\n");
    scanf("%d %d", &num1, &num2);

    if(num1%2!=0 && num1<0 && num2%2==0 && num2>0){
        printf("primeiro e impar e negativo e se o segundo é par e positivo\n");
    }else{
        printf("os numeros nao estao nas condições (primeiro é ímpar e negativo, e se o segundo é par e positivo.)\n");
    }

    //entrada: -5, -15
    //saída: os numeros nao estao nas condições (primeiro é ímpar e negativo, e se o segundo é par e positivo.)

    //entrada: -13, 20
    //saida: primeiro e impar e negativo e se o segundo é par e positivo

    //entrada: -30, 45
    //saida: os numeros nao estao nas condições (primeiro é ímpar e negativo, e se o segundo é par e positivo.)
}

void metodo0218(){
    //ler dois valores reais do teclado e dizer se o primeiro é menor, igual ou maior que a metade do segundo. 

    int num1, num2;
    printf("digite dois numeros\n");
    scanf("%d %d", &num1, &num2); 

    if(num1 < num2/2){
        printf("o primeiro e menor que a metade do segundo\n");
    }else if(num1 == num2/2){
        printf("o primeiro e igual a metade do segundo\n");
    }else if(num1 > num2/2){
        printf("o primeiro e maior que a metade do segundo\n");
    }

    //entrada: 0.5, 1.5
    //saída: o primeiro e menor que a metade do segundo

    //entrada: 3.0, 3.0
    //saida: o primeiro e maior que a metade do segundo

    //entrada: -5.5, 6.4
    //saida: o primeiro e menor que a metade do segundo
}

void metodo0219(){
//  ler três valores reais do teclado e dizer se o segundo está entre o primeiro e o último, quando esses dois forem diferentes entre si. 
    double num1, num2, num3;
    printf("digite os tres numeros\n");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if(num2 > num1 && num2 < num3 && num1!=num3){
        printf("o segundo esta entre o primeiro e o último\n");
    }else{
        printf("os numeros nao estao em ordem\n");
    }

    //entrada: 0.75, 0.5, 1.8
    //saída: os numeros nao estao em ordem

    //entrada: 3.6, 4.5, 2.4
    //saída: os numeros nao estao em ordem

    //entrada: 6.3, 7.2, 6.5
    //saída: os numeros nao estao em ordem
    
}


void metodo0220(){
//ler três valores reais do teclado e dizer se o segundo não está entre o primeiro e o último, quando todos forem diferentes entre si.
    double num1, num2, num3;
    printf("digite os tres numeros\n");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if(num2 > num1 && num2 < num3 && num1!=num3 && num1!=num2 && num2!=num3){
        printf("o segundo esta entre o primeiro e o último\n");
    }else{
        printf("o segundo nao esta entre o primeiro e o segundo\n");
    }

     //entrada: 0.75, 0.5, 1.8
    //saída: o segundo nao esta entre o primeiro e o segundo

    //entrada: 3.6, 4.5, 2.4
    //saída: o segundo nao esta entre o primeiro e o segundo

    //entrada: 6.3, 7.2, 6.5
    //saída: o segundo nao esta entre o primeiro e o segundo
    
}

void metodo02E1(){
    // ler três valores literais (caracteres) do teclado e dizer se o primeiro valor lido está entre os outros dois, ou se é igual a um deles.
    char a, b, c;

    // Leitura dos três caracteres
    printf("Digite o tres caracteres\n");
    scanf("%c %c %c", &a, &b, &c);  

    // Verifica se o primeiro caractere está entre os outros dois ou se é igual a um deles
    if ((a >= b && a <= c) || (a <= b && a >= c) || a == b || a == c) {
        printf("O primeiro caractere '%c' está entre os outros dois ou é igual a um deles.\n", a);
    } else {
        printf("O primeiro caractere '%c' não está entre os outros dois e não é igual a nenhum deles.\n", a);
    }

    //entrada: 'a','c','e'
    //saída: O primeiro caractere 'a' está entre os outros dois ou é igual a um deles.

    //entrada: 'e','a','c'
    //saída: O primeiro caractere 'e' está entre os outros dois ou é igual a um deles.

    //entrada: 'a','e','a'
    //saída: O primeiro caractere 'a' está entre os outros dois ou é igual a um deles.

}

void metodo02E2(){
     
    char a, b, c;

    // Leitura dos três caracteres
    printf("Digite os tres caracteres\n");
    scanf("%c %c %c", &a, &b, &c); 

    // Verifica se o primeiro caractere está fora do intervalo definido pelos outros dois
    if (b != c && (a < b && a < c || a > b && a > c)) {
        printf("O primeiro caractere '%c' está fora do intervalo definido por '%c' e '%c'.\n", a, b, c);
    } else {
        printf("O primeiro caractere '%c' NÃO está fora do intervalo definido por '%c' e '%c'.\n", a, b, c);
    }

    //entrada: 'a','e','c'
    //saída: O primeiro caractere 'a' está fora do intervalo definido por 'e' e 'c'.

    //entrada: 'e','a','c'
    //saída: O primeiro caractere 'e' está fora do intervalo definido por 'a' e 'c'.

    //entrada: 'a','c','a'
    //saída: O primeiro caractere 'a' NÃO está fora do intervalo definido por 'e' e 'a'.


    
}

int main(){
    int x;

    do{
    printf("\ndigite o numero do case correspondente ao metodo desejado ou 0 para encerrar\n");
    scanf("%d", &x);

    switch(x){

        case 0:
        break;
        
        case 1:
        metodo0211();
        break;

        case 2:
        metodo0212();
        break;

        case 3:
        metodo0213();
        break;

        case 4:
        metodo0214();
        break;

        case 5:
        metodo0215();
        break;

        case 6:
        metodo0216();
        break;

        case 7:
        metodo0217();
        break;

        case 8:
        metodo0218();
        break;

        case 9:
        metodo0219();
        break;

        case 10:
        metodo0220();
        break;

        case 11:
        metodo02E1();
        break;

        case 12:
        metodo02E2();
        break;
        

    }

    }while(x!=0);


    return 0;
}