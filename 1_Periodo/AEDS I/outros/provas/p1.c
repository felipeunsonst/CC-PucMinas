//FELIPE COSTA UNSONST
//854155
//correção da prova

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void p_01(){
    printf ("a.) %d = %d\n", (4 / (2 * 2) / 1), (4 / 2 + 2 / 4) ); 

    printf ("b.) %d = %d\n", ((4 / 2) + (2 / 4)), (2 - (4 / 2) + 2 * (4 / 2 / 2)) );

    printf ( "c.) %d = %d\n", ((4 + 2) * 2 / 4), (4 * 2 * 2 / 4) );

    printf ( "d.) %d = %d\n", (((4 + 2) / 4) + (4 * (4 / 2) / 2)), ((2 + 2 * 4) / (2 + 4) + 2));

    //resposta correta letra B
}

int f_02a(int x){
        int y = 0, z = 0, p = x;
        while (p > 4){
            if (p % 10 % 2 == 0){y = y + p % 10 - 1;}
			else{z = z / 10 + p % 10 + 1;}
            p = p / 10;}
        return (y + z);}

void p_02(){
    printf("%d\n", f_02a(567890));
    // resposta correta letra A=17
}

int f_03(char *text){
    int a = 0, x = 0, t = strlen(text);
    if(t > 0){
        a = (text[0] - 48 + text [t - 1] - 48);
        for (x = 0; x < t - 2; x++){
            text[x] = text[x + 1];
		} 
		text[x] = '/0';        
        a = a + f_03(text);
    }
    return (a);
}
void p_03(){
    char text [] = "123456";
    printf("%d\n", f_03(text));
	//resposta correta B
}
int f_04(int a, int b){
    while(a > 0 && b > 0 && a > - b){
        a -= b;
        if(a < b){a = a + b; b = a - b; a = a - b;
        }
    }
    return (a);
}
void p_04(){
    printf("%d\n", f_04(54, 24));
    // Resposta correta letra C= 6
}

int f_05(int n){
    int s = 0, z = 0;
    while(n > 0){
        z = z + 4;
        if(z % 5 == 0)
            n = n + 1;
        else
            s = s + z;
            n = n - 1;
    }
    return(s);
}
void p_05(){
    printf("A. %d\n", f_05(7));
    printf("B. %d\n", f_05(8));
    printf("C. %d\n", f_05(9));
    printf("D. %d\n", f_05(10));
    // Resposta correta letra D = f_05(10) = 252
}

bool bissexto(int a) {
    int b =0;
	int c =a;
	for(int i= 4; i<a; i=i+4){
		a=a-1;
		if(a==0){
			b++;
		}
	}
	for(int j=100; j<a; j=j+100){
		if(a==0){
			for(int x=400; x<c; x=x+400){
				if(c==0){
					b++;
				}else{
					b--;
				}
			}
		}
	}

	if(b>0){
		return true;
	}

	if(b<=0){
		return false;
	}
}

void p_06() {
	int ano =0;
	scanf("%d", &ano);
	getchar();

	if(bissexto(ano)){
		printf("o ano e bissexto\n");
	}else{
		printf("o ano nao e bissexto\n");
	}
}

int adicao(int n) {
    int soma = 0;
    while (n > 0) {
        soma += n % 10;  
        n /= 10;         
    }
    return soma;
}
void p_07() {   
    for (int i = 10; i <= 99; i++) {
        for (int j = i + 1; j <= 99; j++) {
            if (adicao(i * i) == j && adicao(j * j) == i) {
                printf("os numeros %d e %d sao quadrados amigos\n", i, j);
            }
        }
    }
}

int testarDescendente(char c) {
    char descendentes[] = {'g', 'j', 'p', 'q', 'y'};
    for (int i = 0; i < 5; i++) {
        if (c == descendentes[i]) {
            return 1; // é descendente
        }
    }
    return 0; // não é descendente
}

int contarDescendentes(char palavra[]) {
    int count = 0;
	int tamanho = strlen(palavra);
    for (int i = 0; i <tamanho; i++) {
        if (testarDescendente(palavra[i])) {
            count++;
        }
    }
    return count;
}

void p_08(void) {
    char palavra1[100], palavra2[100];

    printf("digite a primeira palavra: ");
    scanf("%s", palavra1);
    printf("digite a segunda palavra: ");
    scanf("%s", palavra2);

    int descendentes1 = contarDescendentes(palavra1);
    int descendentes2 = contarDescendentes(palavra2);

    if (descendentes1 > descendentes2) {
        printf("a palavra '%s' tem mais descendentes.\n", palavra1);
    } else if (descendentes2 > descendentes1) {
        printf("a palavra '%s' tem mais descendentes.\n", palavra2);
    } else {
        printf("as duas palavras têm a mesma quantidade de descendentes.\n");
    }
}

int main() {
    int opcao;
	
	do{
		 printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-p_01\n2-p_02\n3-p_03\n4-p_04\n5-p_05\n6-p_06\n7-p_07\n8-p_08\n");
    scanf("%d", &opcao);
	getchar();

		 switch (opcao) {
            case 1:
                p_01();
                break;
            case 2:
                p_02();
                break;
            case 3:
                p_03();
                break;
            case 4:
                p_04();
                break;
            case 5:
                p_05();
                break;
            case 6:
                p_06();
                break;
            case 7:
                p_07();
                break;
            case 8:
                p_08();
                break;
            default:
                printf("opcao invalida!\n");
        }

	}while(opcao!=0);
        


    return 0;
}
