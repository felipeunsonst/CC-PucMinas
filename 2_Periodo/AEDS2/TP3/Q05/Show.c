#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 256

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

typedef struct Node {
    Show dado;
    struct Node *prox;
} Node;

Node *inicio = NULL;

void preencherCampo(char *dest, const char *valor) {
    strcpy(dest, (strlen(valor) > 0) ? valor : "NaN");
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
            destinos[k] = malloc(strlen(temp) + 1);
            strcpy(destinos[k++], temp);
            j = 0;
        } else {
            temp[j++] = linha[i];
        }
        i++;
    }
    temp[j] = '\0';
    destinos[k] = malloc(strlen(temp) + 1);
    strcpy(destinos[k], temp);
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

    for (int i = 0; i < 11; i++) free(campos[i]);
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
    for (int x = 0; x < total - 1; x++)
        for (int y = x + 1; y < total; y++)
            if (strcmp(nomes[x], nomes[y]) > 0) {
                char aux[MAX_STR];
                strcpy(aux, nomes[x]);
                strcpy(nomes[x], nomes[y]);
                strcpy(nomes[y], aux);
            }
    texto[0] = '\0';
    for (int i = 0; i < total; i++) {
        strcat(texto, nomes[i]);
        if (i < total - 1) strcat(texto, ", ");
    }
}

void imprimirShow(Show *s, int pos) {
    char copia[MAX_STR];
    strcpy(copia, s->cast);
    ordenarCast(copia);
    printf("[%d] => %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##\n",
           pos, s->show_id, s->title, s->type, s->director, copia, s->country,
           s->date_added, s->release_year, s->rating, s->duration, s->listed_in);
}

void inserirInicio(Show s) {
    Node *novo = malloc(sizeof(Node));
    novo->dado = s;
    novo->prox = inicio;
    inicio = novo;
}

void inserirFim(Show s) {
    Node *novo = malloc(sizeof(Node));
    novo->dado = s;
    novo->prox = NULL;
    if (inicio == NULL) {
        inicio = novo;
    } else {
        Node *temp = inicio;
        while (temp->prox != NULL)
            temp = temp->prox;
        temp->prox = novo;
    }
}

void inserir(Show s, int pos) {
    if (pos == 0) {
        inserirInicio(s);
        return;
    }
    Node *temp = inicio;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->prox;
    if (temp == NULL) return;
    Node *novo = malloc(sizeof(Node));
    novo->dado = s;
    novo->prox = temp->prox;
    temp->prox = novo;
}

Show removerInicio() {
    if (inicio == NULL) exit(1);
    Node *temp = inicio;
    inicio = inicio->prox;
    Show s = temp->dado;
    free(temp);
    return s;
}

Show removerFim() {
    if (inicio == NULL) exit(1);
    if (inicio->prox == NULL) {
        Show s = inicio->dado;
        free(inicio);
        inicio = NULL;
        return s;
    }
    Node *ant = NULL, *temp = inicio;
    while (temp->prox != NULL) {
        ant = temp;
        temp = temp->prox;
    }
    ant->prox = NULL;
    Show s = temp->dado;
    free(temp);
    return s;
}

Show remover(int pos) {
    if (pos == 0) return removerInicio();
    Node *temp = inicio;
    for (int i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->prox;
    if (temp == NULL || temp->prox == NULL) exit(1);
    Node *removido = temp->prox;
    temp->prox = removido->prox;
    Show s = removido->dado;
    free(removido);
    return s;
}

#define MAX_BASE 1450
Show base[MAX_BASE];
int qtdBase = 0;

Show buscarShow(char *id) {
    for (int i = 0; i < qtdBase; i++)
        if (strcmp(base[i].show_id, id) == 0)
            return base[i];
    Show vazio;
    strcpy(vazio.title, "NaN");
    return vazio;
}

int main() {
    FILE *fp = fopen("/tmp/disneyplus.csv", "r");
    if (!fp) return 1;

    char linha[4096];
    fgets(linha, sizeof(linha), fp);
    while (fgets(linha, sizeof(linha), fp)) {
        linha[strcspn(linha, "\n")] = 0;
        lerShow(&base[qtdBase++], linha);
    }
    fclose(fp);

    char entrada[MAX_STR];
    while (fgets(entrada, sizeof(entrada), stdin)) {
        entrada[strcspn(entrada, "\n")] = 0;
        if (strcmp(entrada, "FIM") == 0) break;
        inserirFim(buscarShow(entrada));
    }

    int m;
    scanf("%d\n", &m);
    for (int i = 0; i < m; i++) {
        fgets(entrada, sizeof(entrada), stdin);
        entrada[strcspn(entrada, "\n")] = 0;

        if (strncmp(entrada, "II", 2) == 0) inserirInicio(buscarShow(entrada + 3));
        else if (strncmp(entrada, "IF", 2) == 0) inserirFim(buscarShow(entrada + 3));
        else if (strncmp(entrada, "I*", 2) == 0) {
            int p; char id[MAX_STR];
            sscanf(entrada + 3, "%d %s", &p, id);
            inserir(buscarShow(id), p);
        } else if (strncmp(entrada, "RI", 2) == 0) printf("(R) %s\n", removerInicio().title);
        else if (strncmp(entrada, "RF", 2) == 0) printf("(R) %s\n", removerFim().title);
        else if (strncmp(entrada, "R*", 2) == 0) {
            int p;
            sscanf(entrada + 3, "%d", &p);
            printf("(R) %s\n", remover(p).title);
        }
    }

    Node *temp = inicio;
    int pos = 0;
    while (temp != NULL) {
        imprimirShow(&temp->dado, pos++);
        temp = temp->prox;
    }
    return 0;
}
