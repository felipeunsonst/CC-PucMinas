//FELIPE COSTA UNSONST
//854155
//correção da prova

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void f_01(int n, char text){
    for(int x = n/2; x < n; x++){
        text[n+1]=text[x];
        text[x] = text[n-x];
        text[n-x] = text[n+1];
        text[n+1] = '\0';
}

void p_01(){
	char p1[] = {"patso"}
	f_01(5, p1);
	printf("%s\n", p1);
	//resposta letra c posta
}

int f_02a(int v, int m, int n, int a[]){
 int z = 0;
    for(int x = 1; x <=v; x++){
        for(int y = n - 1; y >= 1; y--){
            z=a[y];
            a[y] = a[y-1];
            a[y-1] = z;
        }       
}

void p_02(){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
	p_02(3,0,10,a);
    // resposta correta letra C=p:(n-1), q:(x>m) 
	//para que a saida seja 8 9 0 1 2 3 4 5 6 7
}

int f_03(int n, int m[][n]){
  int z = 0;
    for(int x = 0; x <n; x++){
        for(int y =0; y < n; y++){
            if(x-y<0 && x+1<n-y){
                z = z+m[x][y];
            }
        }
    }
    return (z);
}
void p_03(){
    int m[][5] = {{1,2,3,4,5},{2,1,4,5,3},{3,4,5,2,1},{4,5,1,3,2},{5,3,2,1,4}};
    printf("%d", f_03(5,m));
	//resposta correta B
}
int f_04(int m, char * text1, int n, char * text2){
    int result = 0;
    if(text1 && text1[m] != '\0' && text2 && text2[n] != '\0'){
        if(text1[m] != text2[n])
            result = 0 + f_04 (m+1, text1,n,text2);
        else
            result = 1 + f_04(m+1,text1,n+1,text2);
    }
    return result;
}
void p_04(){
	char p1[] = "pista";
	char p2[] = "despistar";
	printf("%d", f_04(0,p2,0,p1));
    // Resposta correta letra A
}

struct s_Fraction{
    int x, y, z;
};

struct s_Fraction f_05(double a){
    struct s_Fraction f = {0,0,0};
    int y = 2;
    if(a > 0){
        f.x = (int)a;
        a = (a-f.x);
    }
    f.y = (int)(a*128);
    f.z = 128;
    while(y <= 64)
        if(f.y%y==0 && f.z%y==0){
            f.y=f.y/y;
            f.z=f.z/y;
        }
        else
            y = y*2;
    return (f);
};


void p_05(){
    struct s_Fraction a = f_05(3.94);
    printf("(%d,%d/%d)\n", a.x, a.y, a.z);
    // Resposta correta letra A
}

int f_06(char *arquivo, int arr[], int n, int m){
    FILE *arq = fopen(arquivo, "w");
    int soma = 0;
    int cont = 0;
    for (int i = 0; i < n && soma + arr[i] < m; i++){
        soma += arr[i];
        cont++;
    }
	//Quantidade de valores somados
    fprintf(arq, "%d\n", cont);
    for (int i = 0; i < cont; i++){
		//Valores somados
        fprintf(arq, "%d ", arr[i]);
    }
    fprintf(arq, "\n");

    fclose(arq);
    return cont;
}

void p_06() {
    int arr[] = {1,2,3,4,5,6};
    int qnt = 6;
    int m;
    printf("digite o limite da soma:\n");
    scanf("%d", &m);
    int quantidade = f_06("DADOS.TXT", arr, 1nt, m);
    printf("%d\n", quantidade);
}

int f_07(char *name) {
		FILE *arq; 
	    arq = fopen(name, "r");
        int linha = 0, coluna = 0;
        fscanf(f,"%d", &linha);
        fscanf(f,"%d", &coluna);
	
        int maior = 0;
        int menor = 1000;
		int maior1 = 0;
		int maior2 = 0;
		int menor1 = 0; 
		int menor2 =0;
        int matriz[linha][coluna];
	
        for(int i = 0; i < linha; i++){
            for(int j = 0; j < coluna; j++){
                fscanf(f, "%d", &matriz[i][j]);
                if(matriz[i][j] > maior){
                    maior = matriz[i][j];
                    maior1 = i;
                    maior2 = j;
                }
                if(matriz[i][j] < menor){
                    menor = matriz[i][j];
                    menor1 = i;
                    menor2 = j;
                }
            }
        }
        if(maior1 == menor1 || maior1 == menor1){
            return 1;
        }else{
            return -1;
        }
        fclose(arq);
}

void p_07(){   
    int n = f_07("MATRIZ.txt");
    printf("%d", n);
}

struct s_Park{
    int he;
    int me;
    int se;
    int hs;
    int ms;
    int ss;
};

void p_08() {
   
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
