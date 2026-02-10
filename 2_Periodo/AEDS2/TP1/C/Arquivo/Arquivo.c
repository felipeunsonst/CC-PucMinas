#include <stdio.h>

int main() {
    int quantidade;
    FILE *arquivo = fopen("dados.bin", "wb");
    
    if (!arquivo) {
        return 1;
    }
    
    scanf("%d", &quantidade);
    double valor;

    for (int i = 0; i < quantidade; i++) {
        scanf("%lf", &valor);
        fwrite(&valor, sizeof(double), 1, arquivo);
    }
    
    fclose(arquivo);
    arquivo = fopen("dados.bin", "rb");
    if (!arquivo) {
        perror("Erro ao reabrir o arquivo");
        return 1;
    }
    
    for (int i = quantidade - 1; i >= 0; i--) {
        fseek(arquivo, i * sizeof(double), SEEK_SET);
        fread(&valor, sizeof(double), 1, arquivo);
    
        if (valor == (int)valor) {
            printf("%d\n", (int)valor);
        } else {
            printf("%.6lf\n", valor);
        }
    }
    
    fclose(arquivo);
    remove("dados.bin"); 
    
    return 0;
}
