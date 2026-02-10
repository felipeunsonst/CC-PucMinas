#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX 1000
#define MAX_STR 300

typedef struct {
    char show_id[MAX_STR];
    char type[MAX_STR];
    char title[MAX_STR];
    char director[MAX_STR];
    char country[MAX_STR];
    int release_year;
    char rating[MAX_STR];
    char duration[MAX_STR];
} Show;

int comparacoes = 0, movimentacoes = 0;

void trim(char *str) {
    int len = strlen(str);
    while (len > 0 && (str[len-1] == '\n' || str[len-1] == '\r')) str[--len] = '\0';
}

int comparar(Show a, Show b) {
    comparacoes++;
    int cmp = strcasecmp(a.director, b.director);
    if (cmp != 0) return cmp;
    return strcasecmp(a.title, b.title);
}

void swap(Show *a, Show *b) {
    Show tmp = *a;
    *a = *b;
    *b = tmp;
    movimentacoes += 3;
}

void heapify(Show arr[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && comparar(arr[esq], arr[maior]) > 0) maior = esq;
    if (dir < n && comparar(arr[dir], arr[maior]) > 0) maior = dir;

    if (maior != i) {
        swap(&arr[i], &arr[maior]);
        heapify(arr, n, maior);
    }
}

void heapSortParcial(Show arr[], int n, int limite) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= n - limite; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }

    for (int i = 0; i < limite / 2; i++) {
        swap(&arr[n - limite + i], &arr[n - 1 - i]);
    }
}

void imprimirShow(Show s) {
    printf("=> %s ## %s ## %s ## [%s] ## %s ## %d ## %s ## %s ##\n",
           s.show_id, s.title, s.type, s.director,
           s.country, s.release_year, s.rating, s.duration);
}

void gerarLog(long tempo) {
    FILE *f = fopen("matricula_heapsort.txt", "w");
    if (f) {
        fprintf(f, "854155\t%d\t%d\t%ld\n", comparacoes, movimentacoes, tempo);
        fclose(f);
    }
}

int lerCSV(const char *arquivo, Show lista[]) {
    FILE *fp = fopen(arquivo, "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    char linha[1000];
    int count = 0;

    fgets(linha, sizeof(linha), fp); // Pula cabeçalho

    while (fgets(linha, sizeof(linha), fp) && count < MAX) {
        char *campos[12];
        int i = 0;

        campos[i++] = strtok(linha, ",");
        while (i < 12 && (campos[i++] = strtok(NULL, ",")));

        if (i < 12) continue;

        trim(campos[0]);
        trim(campos[1]);
        trim(campos[2]);
        trim(campos[3]);
        trim(campos[5]);
        trim(campos[7]);
        trim(campos[8]);
        trim(campos[9]);

        strcpy(lista[count].show_id, campos[0]);
        strcpy(lista[count].type, campos[1]);
        strcpy(lista[count].title, campos[2]);
        strcpy(lista[count].director, strlen(campos[3]) == 0 ? "NaN" : campos[3]);
        strcpy(lista[count].country, strlen(campos[5]) == 0 ? "NaN" : campos[5]);
        lista[count].release_year = strlen(campos[7]) == 0 ? -1 : atoi(campos[7]);
        strcpy(lista[count].rating, strlen(campos[8]) == 0 ? "NaN" : campos[8]);
        strcpy(lista[count].duration, strlen(campos[9]) == 0 ? "NaN" : campos[9]);

        count++;
    }

    fclose(fp);
    return count;
}

int main() {
    char entrada[MAX_STR];
    char ids[100][MAX_STR];
    int totalIds = 0;

    // Leitura dos IDs
    while (1) {
        fgets(entrada, MAX_STR, stdin);
        trim(entrada);
        if (strcmp(entrada, "FIM") == 0) break;
        strcpy(ids[totalIds++], entrada);
    }

    Show todos[MAX], selecionados[100];
    int total = lerCSV("/tmp/disneyplus.csv", todos);
    int selCount = 0;

    for (int i = 0; i < totalIds; i++) {
        for (int j = 0; j < total; j++) {
            if (strcmp(ids[i], todos[j].show_id) == 0) {
                selecionados[selCount++] = todos[j];
                break;
            }
        }
    }

    clock_t inicio = clock();
    heapSortParcial(selecionados, selCount, 10);
    clock_t fim = clock();

    for (int i = selCount - 10; i < selCount; i++) {
        imprimirShow(selecionados[i]);
    }

    gerarLog((fim - inicio) * 1000 / CLOCKS_PER_SEC);
    return 0;
}
