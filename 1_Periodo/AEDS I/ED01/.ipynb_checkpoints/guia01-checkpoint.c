//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void metodo0111(){
    int l; //valor do lado do quadrado
    printf("digite a medida do lado\n");
    scanf("%d", &l);

    //area quadrado = l * l
    // area do outro quadrado = 2(l * l)

    int area2;
    area2 = 2 * l * 2 * l;

    printf("a area do quadrado com o dobro do lado dado %d\n", area2);

   //entrada: 2
   //saída: 16

   //entrada: 3
   //saída: 36

   //entrada: 4
   //saída: 64

   //entrada:5
   //saída:100
}

void metodo0112(){
     int l;
    printf("digite a medida do lado\n");
    scanf("%d", &l);

    //area = l * l
    //perimetro = l + l + l +l

    //area de um terço do lado = l/3 * l/3
    // perimetro = l/3 + l/3 + l/3 + l/3

    // Convertendo l para float para c�lculos precisos
    float lado = (float)l;

    float area2 = (lado/3) * (lado/3);
    float perimetro2 = 4 * (lado/3);

    printf("A area e o perimetro com um terco do lado sao, respectivamente: %f %f\n", area2, perimetro2);

    //entrada= 5
    // saida = 2,777 e 6,666

}

void metodo0113(){
     int l, c; //comprimento e largura

    printf("digite a medida da largura e do comprimento\n");
    scanf("%d %d", &l, &c);

    //area = l x c
    //area2 = 3(l) * 3(c)

    int areaMultiplicada = 3 * l * 3 *c;

    //entrada= 3 e 5
    // saida = 9 x 15 = 135;

    printf("a area do retangulo com seus valores multiplicados por 3 e: %d\n", areaMultiplicada);
}

void metodo0114(){
     int l, c; //largura e comprimento do retangulo

    printf("digite a medida dos lados\n");
    scanf("%d %d", &l, &c);

    //area =  c * l
    //area nova= (l/6) * (c/6)

    //perimetro = 2l + 2c
    //perimetro novo = (l/3) + (c/3)

    // convertendo l para float para cálculos precisos
    float lado1 = (float)l;
    // convertendo c para float para cálculos precisos
    float lado2 = (float)c;

    float areaNova = (lado1/6.0f) * (lado2/6.0f);
    float perimetroNovo = (lado1/3.0f) + (lado2/3.0f);

    //entrada= 3 e 5
    //saida=  0,41666666666666666666666666666667 e  2,6666666666666666666666666666667


    printf("a area e o perimetro sao, respectivamente: %f %f\n", areaNova, perimetroNovo);

}

void metodo0115(){
    int b, h; //base e altura do triangulo

    printf("digite a medida da base e da altura do triangulo\n");
    scanf("%d %d", &b, &h);

    //area triangulo = (b*h)/2
    //area triangulo nova = (b*h/2)/2

    float base = (float)b;
    float altura = (float)h;

    float areaNova= base * (altura/4.0f);

    //entrada = 3 e 4
    //saída = 3

    printf("a area nova e: %f", areaNova);
}

void metodo0116(){
     float l; //variavel que repesetnta a medida do lado

    printf("digite a medida do lado do triangulo\n");
    scanf("%f", &l);

    //area triangulo equilatero = (pow(l,2)*sqrt(3))/4
    //altura triangulo equilatero = (l * sqrt(3))/2
    //perimetro = 3l

    //nova medida = 4 * l

    //conversão do tipo
    float lado = (float)l * 4;

    float area = (pow(lado,2)*sqrt(3))/4;
    float altura = (lado * sqrt(3))/2;
    float perimetro = 3 * lado;

    printf("a medida da area, da altura e do perimetro sao, respectivamente: %f %f %f\n", area, altura, perimetro);

    //entrada = 5
    //saida = area: 173,20508    altura:17,32051   perimetro: 60
}

void metodo0117(){
     float lado;
    printf("digite o valor do lado:\n");
    scanf("%f", &lado);


    //volume= lado * lado * lado
    //novo volume = 7 * lado * 7 * lado * 7 * lado
    float volumeMultiplicado = 7 * lado * 7 * lado * 7 * lado;

    printf("o volume após as multiplicaçoes e: %f\n", volumeMultiplicado);

    //entrada: 5.0
    //saída: 42.875
}

void metodo0118(){
    float c, l, a; //comprimento largura e altura
    printf("digite as medidas do paralelepipedo:\n");
    scanf("%f %f %f", &c, &l, &a);

    //volume paralelepido= c * l * a
    //volume requistado na questão = c/5 * l/5 * a/5 ===> (c*l*a)/125

    float volume = (c*l*a)/125;

    printf("o volume com as medidas por um quinto e: %f\n", volume);

    //entrada:  3.0, 4.0 e 5.0
    //saida: 0,48

}

void metodo0119(){
     float raio;
    printf("digite a medida do raio\n");
    scanf("%f", &raio);


    //area circunferencia= pi*r^2
    //area semi-circunferencia= (pi*r^2)/2
    //area nova= (pi*(r/4)^2)/2


    float area= (M_PI*pow((raio/4), 2))/2;
    printf("a area do semi-circulo com um quarto do raio e: %f\n", area);

    //entrada: 4
    //saida: 1,57079632679489661923

    //entrada: 5
    //saida:
}

void metodo0120(){
     float raio;
    printf("digite a medida do raio do circulo:\n");
    scanf("%f", &raio);

    //volume esfera: (4 * PI * r^3)/3
    //novo volume: (4 * PI * (3r/5)^3)/3

    float volume= (4 * M_PI * pow((3 * raio/5),3))/3;
    printf("o volume com tres quintos do raio e: %f\n", volume);

    //entrada: 5.0
    //saida: 113,04
}

void metodo01E1(){
    float area;
    // area = PI * R^2
    // area = 3,14 * R^2
    // R = raiz(area/3,14)

    printf("digite a medida da area:\n");
    scanf("%f", &area);

    float resultadoInicial= area/M_PI;
    float raio = sqrt(resultadoInicial);
    float resultadoFinal = raio/9;

    printf("a medida de um nono do raio da area dada e %f\n", resultadoFinal);

    //entrada: 5.0
    //saída: 0,14020957
}

void metodo01E2(){
    float volume;

    printf("digite a medida do volume da esfera\n");
    scanf("%f", &volume);

    //volume esfera = (4 * PI * R^3)/3
    // raio = raiz cubica((volume*3)/(4 * PI))
    //area = 4 * PI * R^2

    float resultadoInicial = (volume * 3)/(4* M_PI);
    float raio = cbrt(resultadoInicial);
    float resultadoFinal = (3*raio)/7;
    float area = 4* M_PI * pow(raio, 2);

    printf("a medida de tres setimos do raio do volume dado e a area dessa esfera e, respectivamente %f e %f\n", resultadoFinal, area);

    //entrada: 5.0
    //saída: 0,60626699 e 14,1380893
    
}


int main(){
    int x;

    do{
    printf("escolha um valor de x correspondente ao metodo desejado(0 para encerrar):\n");
    scanf("%d", &x);

    switch(x){

        case 0:
            break;
        case 1:
            metodo0111();
            break;
        case 2:
            metodo0112();
            break;
        case 3:
            metodo0113();
            break;
        case 4:
            metodo0114();
            break;
        case 5:
            metodo0115();
            break;
        case 6:
            metodo0116();
            break;
        case 7:
            metodo0117();
            break;
        case 8:
            metodo0118();
            break;
        case 9:
            metodo0119();
            break;
        case 10:
            metodo0120();
            break;
        case 11:
            metodo01E1();
            break;
        case 12:
            metodo01E2();
            break;

    }

    }while(x!=0);

    return 0;

}
