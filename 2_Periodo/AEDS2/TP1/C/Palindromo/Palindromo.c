#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char palavra[100];

    while (true) {
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0';

        if (strcmp(palavra, "FIM") == 0) {
            break;
        }

        int tam = strlen(palavra);
        bool pali = true;

        for (int i = 0; i < tam / 2; i++) {
            if (palavra[i] != palavra[tam - i - 1]) {
                pali = false;
                break;
            }
        }

        if (pali) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
