#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TAM 1000
#define CSV_PATH "/tmp/disneyplus.csv"

typedef struct {
    char show_id[20];
    char type[30];
    char title[200];
} Show;

typedef struct Node {
    Show show;
    int altura;
    struct Node* esq;
    struct Node* dir;
} Node;

int comparacoes = 0;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(Node* no) {
    return no == NULL ? 0 : no->altura;
}

int balanceamento(Node* no) {
    return (no == NULL) ? 0 : altura(no->esq) - altura(no->dir);
}

Node* rotacionarDir(Node* y) {
    Node* x = y->esq;
    Node* T2 = x->dir;
    x->dir = y;
    y->esq = T2;

    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    return x;
}

Node* rotacionarEsq(Node* x) {
    Node* y = x->dir;
    Node* T2 = y->esq;
    y->esq = x;
    x->dir = T2;

    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    return y;
}

Node* inserir(Node* raiz, Show show) {
    if (raiz == NULL) {
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->show = show;
        novo->esq = novo->dir = NULL;
        novo->altura = 1;
        return novo;
    }

    comparacoes++;
    if (strcmp(show.title, raiz->show.title) < 0) {
        raiz->esq = inserir(raiz->esq, show);
    } else if (strcmp(show.title, raiz->show.title) > 0) {
        raiz->dir = inserir(raiz->dir, show);
    } else {
        return raiz;
    }

    raiz->altura = 1 + max(altura(raiz->esq), altura(raiz->dir));

    int balance = balanceamento(raiz);

    if (balance > 1 && strcmp(show.title, raiz->esq->show.title) < 0)
        return rotacionarDir(raiz);
    if (balance < -1 && strcmp(show.title, raiz->dir->show.title) > 0)
        return rotacionarEsq(raiz);
    if (balance > 1 && strcmp(show.title, raiz->esq->show.title) > 0) {
        raiz->esq = rotacionarEsq(raiz->esq);
        return rotacionarDir(raiz);
    }
    if (balance < -1 && strcmp(show.title, raiz->dir->show.title) < 0) {
        raiz->dir = rotacionarDir(raiz->dir);
        return rotacionarEsq(raiz);
    }

    return raiz;
}

int pesquisar(Node* raiz, char* titulo) {
    printf("=>raiz ");
    while (raiz != NULL) {
        comparacoes++;
        int cmp = strcmp(titulo, raiz->show.title);
        if (cmp == 0) {
            return 1;
        } else if (cmp < 0) {
            printf("esq ");
            raiz = raiz->esq;
        } else {
            printf("dir ");
            raiz = raiz->dir;
        }
    }
    return 0;
}

Show buscarPorID(char* idBuscado) {
    FILE* fp = fopen(CSV_PATH, "r");
    char linha[1024];
    Show s;
    strcpy(s.title, ""); 

    if (fp == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return s;
    }

    fgets(linha, sizeof(linha), fp); 

    while (fgets(linha, sizeof(linha), fp) != NULL) {
        char* token = strtok(linha, ",");
        if (token && strcmp(token, idBuscado) == 0) {
            strcpy(s.show_id, token);
            token = strtok(NULL, ","); 
            strcpy(s.type, token ? token : "NaN");
            token = strtok(NULL, ","); 
            strcpy(s.title, token ? token : "NaN");
            break;
        }
    }

    fclose(fp);
    return s;
}

int main() {
    char entrada[100];
    Node* raiz = NULL;
    clock_t inicio, fim;

    while (scanf(" %s", entrada), strcmp(entrada, "FIM") != 0) {
        Show s = buscarPorID(entrada);
        if (strcmp(s.title, "") != 0) {
            raiz = inserir(raiz, s);
        }
    }

    inicio = clock();
    while (scanf(" %[^\n]", entrada), strcmp(entrada, "FIM") != 0) {
        int encontrado = pesquisar(raiz, entrada);
        printf(encontrado ? "SIM\n" : "NAO\n");
    }
    fim = clock();

    double tempo = (double)(fim - inicio) * 1000.0 / CLOCKS_PER_SEC;
    FILE* log = fopen("854155_avl.txt", "w");
    if (log != NULL) {
        fprintf(log, "854155\t%.3lf\t%d\n", tempo, comparacoes);
        fclose(log);
    }

    return 0;
}
