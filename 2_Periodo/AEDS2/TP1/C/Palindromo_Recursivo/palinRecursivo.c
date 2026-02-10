#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool ehPalindromo(char palavra[], int inicio, int fim) {
    if (inicio >= fim) {
        return true; 
    }
    if (palavra[inicio] != palavra[fim]) {
        return false; 
    }
    return ehPalindromo(palavra, inicio + 1, fim - 1); 
}

int main() {
    char palavra[100];

    while (true) {
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0'; 

        if (strcmp(palavra, "FIM") == 0) {
            break; 
        }

		int tam = strlen(palavra);

        if (ehPalindromo(palavra, 0, tam - 1)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
