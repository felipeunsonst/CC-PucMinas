#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SHOWS 1450
#define MAX_STR 256
#define MAX_DIGITO 10

typedef struct {
    char show_id[MAX_STR];
    char type[MAX_STR];
    char title[MAX_STR];
    char director[MAX_STR];
    char cast[MAX_STR];
    char country[MAX_STR];
    char date_added[MAX_STR];
    int release_year;
    char rating[MAX_STR];
    char duration[MAX_STR];
    char listed_in[MAX_STR];
} Show;

void lerShow(Show *s, char *linha) {
    char *campos[12], buffer[MAX_STR], *ptr = linha;
    int campoIndex = 0, entreAspas = 0, bufIndex = 0;

    while (*ptr && campoIndex < 12) {
        if (*ptr == '"') {
            entreAspas ^= 1;
        } else if (*ptr == ',' && !entreAspas) {
            buffer[bufIndex] = '\0';
            campos[campoIndex++] = strdup(buffer);
            bufIndex = 0;
        } else {
            buffer[bufIndex++] = *ptr;
        }
        ptr++;
    }
    buffer[bufIndex] = '\0';
    campos[campoIndex] = strdup(buffer);

    strcpy(s->show_id, campos[0][0] ? campos[0] : "NaN");
    strcpy(s->type, campos[1][0] ? campos[1] : "NaN");
    strcpy(s->title, campos[2][0] ? campos[2] : "NaN");
    strcpy(s->director, campos[3][0] ? campos[3] : "NaN");
    strcpy(s->cast, campos[4][0] ? campos[4] : "NaN");
    strcpy(s->country, campos[5][0] ? campos[5] : "NaN");
    strcpy(s->date_added, campos[6][0] ? campos[6] : "NaN");
    s->release_year = campos[7][0] ? atoi(campos[7]) : -1;
    strcpy(s->rating, campos[8][0] ? campos[8] : "NaN");
    strcpy(s->duration, campos[9][0] ? campos[9] : "NaN");
    strcpy(s->listed_in, campos[10][0] ? campos[10] : "NaN");

    for (int i = 0; i <= campoIndex; i++) {
        free(campos[i]);
    }
}

void ordenarCast(char *cast) {
    if (!strcmp(cast, "NaN")) return;

    char nomes[MAX_SHOWS][MAX_STR];
    int n = 0;
    char *token = strtok(cast, ",");

    while (token && n < MAX_SHOWS) {
        while (*token == ' ') token++;
        strncpy(nomes[n++], token, MAX_STR);
        token = strtok(NULL, ",");
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(nomes[i], nomes[j]) > 0) {
                char temp[MAX_STR];
                strcpy(temp, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], temp);
            }
        }
    }

    cast[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(cast, nomes[i]);
        if (i < n - 1) strcat(cast, ", ");
    }
}

void imprimirShow(Show *s) {
    char castTemp[MAX_STR];
    strcpy(castTemp, s->cast);
    ordenarCast(castTemp);

    printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##\n",
        s->show_id, s->title, s->type, s->director, castTemp, s->country,
        s->date_added, s->release_year, s->rating, s->duration, s->listed_in);
}

int getMaxReleaseYear(Show arr[], int n) {
    int maior = arr[0].release_year;
    for (int i = 1; i < n; i++) {
        if (arr[i].release_year > maior)
            maior = arr[i].release_year;
    }
    return maior;
}

void countSort(Show arr[], int n, int exp, int *movs) {
    Show temp[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i].release_year / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i].release_year / exp) % 10;
        temp[count[idx] - 1] = arr[i];
        count[idx]--;
        *movs += 3;
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

void bubbleDesempate(Show arr[], int ini, int fim, int *comps, int *movs) {
    for (int i = ini; i < fim - 1; i++) {
        for (int j = ini; j < fim - 1 - (i - ini); j++) {
            (*comps)++;
            if (strcasecmp(arr[j].title, arr[j + 1].title) > 0) {
                Show aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                *movs += 3;
            }
        }
    }
}

void radixSortReleaseYear(Show arr[], int n, int *comps, int *movs) {
    int max = getMaxReleaseYear(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp, movs);

    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && arr[j].release_year == arr[i].release_year)
            j++;
        bubbleDesempate(arr, i, j, comps, movs);
        i = j;
    }
}

int main() {
    FILE *f = fopen("/tmp/disneyplus.csv", "r");
    if (!f) {
        perror("Arquivo não encontrado");
        return 1;
    }

    Show base[MAX_SHOWS];
    int total = 0;
    char linha[4096];

    fgets(linha, sizeof(linha), f);
    while (fgets(linha, sizeof(linha), f) && total < MAX_SHOWS) {
        linha[strcspn(linha, "\n")] = '\0';
        lerShow(&base[total++], linha);
    }
    fclose(f);

    Show selecionados[MAX_SHOWS];
    int n = 0;
    char entrada[MAX_STR];

    while (fgets(entrada, sizeof(entrada), stdin)) {
        entrada[strcspn(entrada, "\n")] = '\0';
        if (!strcmp(entrada, "FIM")) break;

        for (int i = 0; i < total; i++) {
            if (!strcmp(base[i].show_id, entrada)) {
                selecionados[n++] = base[i];
                break;
            }
        }
    }

    int comp = 0, mov = 0;
    clock_t ini = clock();

    radixSortReleaseYear(selecionados, n, &comp, &mov);

    clock_t fim = clock();
    double tempo = (double)(fim - ini) / CLOCKS_PER_SEC * 1000.0;

    for (int i = 0; i < n; i++)
        imprimirShow(&selecionados[i]);

    FILE *log = fopen("854155_radixsort.txt", "w");
    if (log) {
        fprintf(log, "854155\t%d\t%d\t%.2lf\n", comp, mov, tempo);
        fclose(log);
    }

    return 0;
}
