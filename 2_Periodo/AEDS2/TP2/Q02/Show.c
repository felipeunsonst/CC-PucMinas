#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX_LINE 1024
#define MAX_FIELDS 12
#define MAX_STR 256
#define MAX_ARRAY 20

typedef struct {
    char show_id[MAX_STR];
    char type[MAX_STR];
    char title[MAX_STR];
    char director[MAX_STR];
    char cast[MAX_ARRAY][MAX_STR];
    int cast_size;
    char country[MAX_STR];
    char date_added[MAX_STR];
    int release_year;
    char rating[MAX_STR];
    char duration[MAX_STR];
    char listed_in[MAX_ARRAY][MAX_STR];
    int listed_in_size;
} Show;

void inicializarShow(Show *s) {
    strcpy(s->show_id, "NaN"); //strcpy copia o coteudo do segundo para o primiero, atribui
    strcpy(s->type, "NaN");
    strcpy(s->title, "NaN");
    strcpy(s->director, "NaN");
    strcpy(s->cast[0], "NaN");
    s->cast_size = 1;
    strcpy(s->country, "NaN");
    strcpy(s->date_added, "NaN");
    s->release_year = -1;
    strcpy(s->rating, "NaN");
    strcpy(s->duration, "NaN");
    strcpy(s->listed_in[0], "NaN");
    s->listed_in_size = 1;
}

// Função para remover aspas e espaços de uma string
void limparCampo(char *str) {
    char *src = str, *dst = str;
    while (*src) {
        if (*src != '"') *dst++ = *src;
        src++;
    }
    *dst = '\0';
    while (*str == ' ') str++;
}

void imprimirShow(Show *s) {
    printf("%s ## %s ## %s ## ", s->show_id, s->title, s->type);

    // Diretor
    if (strcmp(s->director, "NaN") == 0 || strlen(s->director) == 0)
        printf("[NaN] ## ");
    else
        printf("[%s] ## ", s->director);

    // Cast
    if (s->cast_size == 1 && strcmp(s->cast[0], "NaN") == 0) {
        printf("[NaN] ## ");
    } else {
        printf("[");
        for (int i = 0; i < s->cast_size; i++) {
            printf("%s", s->cast[i]);
            if (i < s->cast_size - 1) printf(", ");
        }
        printf("] ## ");
    }

    // Country
    printf("%s ## ", strcmp(s->country, "NaN") == 0 ? "[NaN]" : s->country);

    // Data formatada
    if (strcmp(s->date_added, "NaN") == 0) {
        printf("[NaN] ## ");
    } else {
        struct tm tm;
        char dataFormatada[50];
        memset(&tm, 0, sizeof(struct tm));

        if (strptime(s->date_added, "%b %d, %Y", &tm)) {
            strftime(dataFormatada, sizeof(dataFormatada), "%B %d, %Y", &tm);
            printf("%s ## ", dataFormatada);
        } else {
            printf("%s ## ", s->date_added);
        }
    }

    // release_year
    printf("%s ## ", s->release_year == -1 ? "[NaN]" : (char[12]){0});
    if (s->release_year != -1) printf("%d", s->release_year);

    // rating
    printf(" ## %s ## ", strcmp(s->rating, "NaN") == 0 ? "[NaN]" : s->rating);

    // duration
    printf("%s ## ", strcmp(s->duration, "NaN") == 0 ? "[NaN]" : s->duration);

    // listed_in
    if (s->listed_in_size == 1 && strcmp(s->listed_in[0], "NaN") == 0) {
        printf("[NaN]");
    } else {
        printf("[");
        for (int i = 0; i < s->listed_in_size; i++) {
            printf("%s", s->listed_in[i]);
            if (i < s->listed_in_size - 1) printf(", ");
        }
        printf("]");
    }

    printf(" ##\n");
}



// Função para dividir string em array
int dividirCampo(char *campo, char array[MAX_ARRAY][MAX_STR]) {
    int count = 0;
    char *token = strtok(campo, ","); //funciona como imput.split em jjava, o token delimita partes de uma string como por ex por virgulas, e o strtok separa essas partes
    while (token && count < MAX_ARRAY) {
        while (*token == ' ') token++; // remove espaço inicial
        strncpy(array[count++], token, MAX_STR);//strncpy(destino, origem, tamanho_maximo);
        token = strtok(NULL, ",");
    }
    return count;
}

// Função que busca o Show por ID
int buscarPorID(const char *idBuscado, const char *arquivoCSV, Show *resultado) {
    FILE *file = fopen(arquivoCSV, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    char linha[MAX_LINE];
    fgets(linha, sizeof(linha), file); // pula o cabeçalho

    while (fgets(linha, sizeof(linha), file)) {
        char *campos[MAX_FIELDS];
        int i = 0;
        char *token = strtok(linha, ",");

        while (token && i < MAX_FIELDS) {
            campos[i++] = token;
            token = strtok(NULL, ",");
        }

        if (i < 11) continue;

        limparCampo(campos[0]);
        if (strcmp(campos[0], idBuscado) != 0) continue;

        inicializarShow(resultado);
        strcpy(resultado->show_id, campos[0]);
        strcpy(resultado->type, campos[1]);
        strcpy(resultado->title, campos[2]);

        limparCampo(campos[3]);
        strcpy(resultado->director, strlen(campos[3]) > 0 ? campos[3] : "NaN");

        limparCampo(campos[4]);
        if (strlen(campos[4]) > 0) {
            resultado->cast_size = dividirCampo(campos[4], resultado->cast);
        }

        limparCampo(campos[5]);
        strcpy(resultado->country, strlen(campos[5]) > 0 ? campos[5] : "NaN");

        limparCampo(campos[6]);
        strcpy(resultado->date_added, strlen(campos[6]) > 0 ? campos[6] : "NaN");

        limparCampo(campos[7]);
        resultado->release_year = (strlen(campos[7]) > 0) ? atoi(campos[7]) : -1;

        limparCampo(campos[8]);
        strcpy(resultado->rating, strlen(campos[8]) > 0 ? campos[8] : "NaN");

        limparCampo(campos[9]);
        strcpy(resultado->duration, strlen(campos[9]) > 0 ? campos[9] : "NaN");

        limparCampo(campos[10]);
        if (strlen(campos[10]) > 0) {
            resultado->listed_in_size = dividirCampo(campos[10], resultado->listed_in);
        }

        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}

int main() {
    char entrada[MAX_STR];
    const char *arquivo = "/tmp/disneypluas";

    while (1) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        if (strcmp(entrada, "FIM") == 0) break;

        Show s;
        if (buscarPorID(entrada, arquivo, &s)) {
            imprimirShow(&s);
        } else {
            printf("Show ID '%s' não encontrado.\n", entrada);
        }
    }

    return 0;
}
