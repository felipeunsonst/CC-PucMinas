//Faça um codigo que transposte uma matriz dada pelo usuário

#include <stdio.h>


void transposta(int linhas, int colunas, int matriz[linhas][colunas]){
    int transpor[colunas][linhas];

    for(int i = 0; i < linhas; i++){
      for(int j = 0; j < colunas; j++){
        transpor[j][i] = matriz[i][j];
      }
    }

    for(int i = 0; i < colunas; i++){
      for(int j = 0; j < linhas; j++){
      printf("%d", transpor[i][j]);
      }
      printf("\n");
    }
}

int main() {
    int linhas, colunas;

    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];

    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++){
            scanf(" %d", &matriz[i][j]);
        }
    }

    transposta(linhas, colunas, matriz); 
}
