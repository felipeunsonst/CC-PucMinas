#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SHOWS 1000
#define MAX_LINE 1000

typedef struct {
    char show_id[20];
    char type[20];
    char title[100];
    char director[100];
    char cast[300];
    char country[50];
    char date_added[30];
    int release_year;
    char rating[10];
    char duration[20];
    char listed_in[200];
} Show;

void substituirQuebraLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void tratarCampo(char *campo) {
    if (campo[0] == '\0' || strcmp(campo, "") == 0 || strcmp(campo, "\n") == 0)
        strcpy(campo, "NaN");
}

void lerLinhaCSV(char *linha, Show *s) {
    char *token;
    int i = 0;

    token = strtok(linha, ",");
    while (token != NULL && i < 11) {
        tratarCampo(token);
        switch (i) {
            case 0: strcpy(s->show_id, token); break;
            case 1: strcpy(s->type, token); break;
            case 2: strcpy(s->title, token); break;
            case 3: strcpy(s->director, token); break;
            case 4: strcpy(s->cast, token); break;
            case 5: strcpy(s->country, token); break;
            case 6: strcpy(s->date_added, token); break;
            case 7: s->release_year = atoi(token); break;
            case 8: strcpy(s->rating, token); break;
            case 9: strcpy(s->duration, token); break;
            case 10: strcpy(s->listed_in, token); break;
        }
        token = strtok(NULL, ",");
        i++;
    }

    if (i <= 7) s->release_year = 0;
    if (i <= 8) strcpy(s->rating, "NaN");
    if (i <= 9) strcpy(s->duration, "NaN");
    if (i <= 10) strcpy(s->listed_in, "NaN");
}

int compararTitulos(const void *a, const void *b) {
    Show *s1 = (Show *)a;
    Show *s2 = (Show *)b;
    return strcmp(s1->title, s2->title);
}

int buscaBinaria(Show *shows, int n, char *titulo) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        int meio = (esq + dir) / 2;
        int cmp = strcmp(shows[meio].title, titulo);
        if (cmp == 0)
            return 1;
        else if (cmp < 0)
            esq = meio + 1;
        else
            dir = meio - 1;
    }
    return 0;
}

int main() {
    char entrada[200];
    int indices[MAX_SHOWS], totalIndices = 0;
    Show shows[MAX_SHOWS];
    int totalShows = 0;

    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        substituirQuebraLinha(entrada);
        if (strcmp(entrada, "FIM") == 0) break;
        indices[totalIndices++] = atoi(entrada);
    }

    FILE *fp = fopen("/tmp/disneyplus.csv", "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    char linha[MAX_LINE];
    int linhaAtual = 0;

    while (fgets(linha, sizeof(linha), fp)) {
        for (int i = 0; i < totalIndices; i++) {
            if (linhaAtual == indices[i]) {
                lerLinhaCSV(linha, &shows[totalShows++]);
                break;
            }
        }
        linhaAtual++;
    }

    fclose(fp);

    qsort(shows, totalShows, sizeof(Show), compararTitulos);

    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        substituirQuebraLinha(entrada);
        if (strcmp(entrada, "FIM") == 0) break;

        if (buscaBinaria(shows, totalShows, entrada))
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
