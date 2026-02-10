#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int soma(char num[], int indice) {
    if (indice < 0) {
        return 0;
    }

    return (num[indice] - '0') + soma(num, indice - 1);
}

int main() {
    char numeros[100];

    do {
        fgets(numeros, sizeof(numeros), stdin);
        numeros[strcspn(numeros, "\n")] = '\0'; 

        if (strcmp(numeros, "FIM") == 0) {
            break;
        }

        int tam = strlen(numeros);
        int result = soma(numeros, tam - 1);
        printf("%d\n", result);

    } while (true);

    return 0;
}
