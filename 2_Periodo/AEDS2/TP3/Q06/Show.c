#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 256
#define INITIAL_CAPACITY 10

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

typedef struct {
    Show *dados;
    int topo;
    int capacidade;
} Pilha;

void initPilha(Pilha *p) {
    p->capacidade = INITIAL_CAPACITY;
    p->topo = 0;
    p->dados = (Show *)malloc(p->capacidade * sizeof(Show));
}

void destruirPilha(Pilha *p) {
    free(p->dados);
}

void expandirPilha(Pilha *p) {
    p->capacidade *= 2;
    p->dados = (Show *)realloc(p->dados, p->capacidade * sizeof(Show));
}

void empilhar(Pilha *p, Show s) {
    if (p->topo == p->capacidade) {
        expandirPilha(p);
    }
    p->dados[p->topo++] = s;
}

Show desempilhar(Pilha *p) {
    Show vazio;
    strcpy(vazio.title, "NaN");
    if (p->topo > 0) {
        return p->dados[--p->topo];
    }
    return vazio;
}

void preencherCampo(char *dest, const char *valor) {
    strcpy(dest, (valor && strlen(valor) > 0) ? valor : "NaN");
}

void extrairCampos(char *linha, char *destinos[]) {
    int entreAspas = 0, k = 0;
    char temp[MAX_STR];
    int i = 0, j = 0;

    while (linha[i] && k < 12) {
        if (linha[i] == '"') {
            entreAspas = !entreAspas;
        } else if (linha[i] == ',' && !entreAspas) {
            temp[j] = '\0';
            destinos[k] = strdup(temp);
            j = 0;
            k++;
        } else {
            temp[j++] = linha[i];
        }
        i++;
    }
    temp[j] = '\0';
    destinos[k] = strdup(temp);
}

void lerShow(Show *reg, char *linha) {
    char *campos[12];
    extrairCampos(linha, campos);

    preencherCampo(reg->show_id, campos[0]);
    preencherCampo(reg->type, campos[1]);
    preencherCampo(reg->title, campos[2]);
    preencherCampo(reg->director, campos[3]);
    preencherCampo(reg->cast, campos[4]);
    preencherCampo(reg->country, campos[5]);
    preencherCampo(reg->date_added, campos[6]);
    reg->release_year = strlen(campos[7]) ? atoi(campos[7]) : -1;
    preencherCampo(reg->rating, campos[8]);
    preencherCampo(reg->duration, campos[9]);
    preencherCampo(reg->listed_in, campos[10]);

    for (int i = 0; i <= 10; i++) free(campos[i]);
}

void ordenarCast(char *texto) {
    if (strcmp(texto, "NaN") == 0) return;
    char nomes[100][MAX_STR];
    int total = 0;
    char *nome = strtok(texto, ",");
    while (nome && total < 100) {
        while (*nome == ' ') nome++;
        strncpy(nomes[total++], nome, MAX_STR);
        nome = strtok(NULL, ",");
    }
    for (int x = 0; x < total - 1; x++) {
        for (int y = x + 1; y < total; y++) {
            if (strcmp(nomes[x], nomes[y]) > 0) {
                char aux[MAX_STR];
                strcpy(aux, nomes[x]);
                strcpy(nomes[x], nomes[y]);
                strcpy(nomes[y], aux);
            }
        }
    }
    texto[0] = '\0';
    for (int i = 0; i < total; i++) {
        strcat(texto, nomes[i]);
        if (i < total - 1) strcat(texto, ", ");
    }
}

void imprimirShow(Show *s, int index) {
    char copia[MAX_STR];
    strcpy(copia, s->cast);
    ordenarCast(copia);

    printf("[%d] => %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##\n",
           index, s->show_id, s->title, s->type, s->director, copia, s->country,
           s->date_added, s->release_year, s->rating, s->duration, s->listed_in);
}

int main() {
    FILE *fp = fopen("/tmp/disneyplus.csv", "r");
    if (!fp) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    Show base[1500];
    int qtd = 0;
    char linha[4096];

    fgets(linha, sizeof(linha), fp);
    while (fgets(linha, sizeof(linha), fp)) {
        linha[strcspn(linha, "\r\n")] = 0;
        lerShow(&base[qtd++], linha);
    }
    fclose(fp);

    Pilha pilha;
    initPilha(&pilha);

    // Leitura dos IDs válidos
    char entrada[MAX_STR];
    while (fgets(entrada, sizeof(entrada), stdin)) {
        entrada[strcspn(entrada, "\r\n")] = 0;
        if (strcmp(entrada, "FIM") == 0) break;

        for (int i = 0; i < qtd; i++) {
            if (strcmp(base[i].show_id, entrada) == 0) {
                empilhar(&pilha, base[i]);
                break;
            }
        }
    }

    // Processamento de comandos
    while (fgets(entrada, sizeof(entrada), stdin)) {
        entrada[strcspn(entrada, "\r\n")] = 0;

        if (entrada[0] == 'I') {
            char *cmd = strtok(entrada, " ");
            char *id = strtok(NULL, " ");
            for (int i = 0; i < qtd; i++) {
                if (strcmp(base[i].show_id, id) == 0) {
                    empilhar(&pilha, base[i]);
                    break;
                }
            }
        } else if (strcmp(entrada, "R") == 0) {
            Show r = desempilhar(&pilha);
            if (strcmp(r.title, "NaN") != 0) {
                printf("(R) %s\n", r.title);
            }
        }
    }

    // Impressão final
    for (int i = pilha.topo - 1; i >= 0; i--) {
        imprimirShow(&pilha.dados[i], i);
    }

    destruirPilha(&pilha);
    return 0;
}
