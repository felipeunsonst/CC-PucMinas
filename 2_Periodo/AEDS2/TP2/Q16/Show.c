#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAX_SHOWS 1000
#define MAX_LEN 512

typedef struct {
    char show_id[MAX_LEN];
    char type[MAX_LEN];
    char title[MAX_LEN];
    char director[MAX_LEN];
    char cast[MAX_LEN];
    char country[MAX_LEN];
    char date_added[MAX_LEN];
    int release_year;
    char rating[MAX_LEN];
    char duration[MAX_LEN];
    char listed_in[MAX_LEN];
} Show;

void limparCampo(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != '\"') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

void toLower(char *str) {
    for (; *str; ++str) *str = tolower(*str);
}

int parseCSV(char *linha, Show *s) {
    int campo = 0;
    char *ptr = linha;
    char valor[MAX_LEN];
    int i = 0, v = 0;
    int aspas = 0;

    while (1) {
        char c = ptr[i];
        if (c == '"') aspas = !aspas;
        else if ((c == ',' && !aspas) || c == '\0' || c == '\n') {
            valor[v] = '\0';
            limparCampo(valor);

            switch (campo) {
                case 0: strncpy(s->show_id, valor, MAX_LEN); break;
                case 1: strncpy(s->type, valor[0] ? valor : "NaN", MAX_LEN); break;
                case 2: strncpy(s->title, valor[0] ? valor : "NaN", MAX_LEN); break;
                case 3: strncpy(s->director, valor[0] ? valor : "NaN", MAX_LEN); break;
                case 4: strncpy(s->cast, valor[0] ? valor : "NaN", MAX_LEN); break;
                case 5: strncpy(s->country, valor[0] ? valor : "NaN", MAX_LEN); break;
                case 6: strncpy(s->date_added, valor[0] ? valor : "NaN", MAX_LEN); break;
                case 7: s->release_year = valor[0] ? atoi(valor) : -1; break;
                case 8: strncpy(s->rating, valor[0] ? valor : "NaN", MAX_LEN); break;
                case 9: strncpy(s->duration, valor[0] ? valor : "NaN", MAX_LEN); break;
                case 10: strncpy(s->listed_in, valor[0] ? valor : "NaN", MAX_LEN); break;
                default: break;
            }

            campo++;
            v = 0;
            if (c == '\0' || c == '\n' || campo >= 11) break;
        } else {
            valor[v++] = c;
        }
        i++;
    }

    return (campo >= 11);
}

void insertionSort(Show arr[], int n, int *comp, int *mov) {
    for (int i = 1; i < n; i++) {
        Show chave = arr[i];
        int j = i - 1;

        while (j >= 0) {
            (*comp)++;
            char tipoJ[MAX_LEN], tipoK[MAX_LEN];
            char tituloJ[MAX_LEN], tituloK[MAX_LEN];
            strcpy(tipoJ, arr[j].type);
            strcpy(tipoK, chave.type);
            strcpy(tituloJ, arr[j].title);
            strcpy(tituloK, chave.title);
            toLower(tipoJ); toLower(tipoK);
            toLower(tituloJ); toLower(tituloK);

            int cmpTipo = strcmp(tipoJ, tipoK);
            int trocar = 0;

            if (cmpTipo > 0) trocar = 1;
            else if (cmpTipo == 0 && strcmp(tituloJ, tituloK) > 0) trocar = 1;

            if (trocar) {
                arr[j + 1] = arr[j];
                (*mov)++;
                j--;
            } else break;
        }

        arr[j + 1] = chave;
        (*mov)++;
    }
}

void imprimirShow(Show *s) {
    printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##\n",
           s->show_id, s->title, s->type, s->director,
           s->cast, s->country, s->date_added, s->release_year,
           s->rating, s->duration, s->listed_in);
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8"); 
    Show shows[MAX_SHOWS];
    int total = 0;

    char entrada[100];
    while (scanf(" %s", entrada), strcmp(entrada, "FIM") != 0) {
        FILE *fp = fopen("/tmp/disneyplus.csv", "r");
        if (!fp) {
            perror("Erro abrindo arquivo");
            return 1;
        }

        char linha[1024];
        fgets(linha, sizeof(linha), fp); 

        while (fgets(linha, sizeof(linha), fp)) {
            if (strstr(linha, entrada)) {
                if (parseCSV(linha, &shows[total])) {
                    total++;
                }
                break;
            }
        }

        fclose(fp);
    }

    int comp = 0, mov = 0;
    insertionSort(shows, total, &comp, &mov);

    int imprimir = total < 10 ? total : 10;
    for (int i = 0; i < imprimir; i++) {
        imprimirShow(&shows[i]);
    }

    FILE *log = fopen("854155_insercao.txt", "w");
    if (log) {
        fprintf(log, "854155\t%d\t%d\t0\n", comp, mov);
        fclose(log);
    }

    return 0;
}
