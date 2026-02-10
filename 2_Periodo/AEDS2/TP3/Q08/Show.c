#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_STR 256
#define MATRICULA "854155"

typedef struct Show {
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
    Show data;
    struct Node* prev;
    struct Node* next;
} Node;


void ordenarCast(char *cast) {
    if (strcmp(cast, "NaN") == 0) return;

    char nomes[100][MAX_STR];
    int qtd = 0;

    char *token = strtok(cast, ",");
    while (token != NULL && qtd < 100) {
        while (*token == ' ') token++; 
        strncpy(nomes[qtd++], token, MAX_STR);
        token = strtok(NULL, ",");
    }

    for (int i = 0; i < qtd - 1; i++) {
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(nomes[i], nomes[j]) > 0) {
                char temp[MAX_STR];
                strcpy(temp, nomes[i]);
                strcpy(nomes[i], nomes[j]);
                strcpy(nomes[j], temp);
            }
        }
    }

    cast[0] = '\0';
    for (int i = 0; i < qtd; i++) {
        strcat(cast, nomes[i]);
        if (i < qtd - 1) strcat(cast, ", ");
    }
}

void imprimirShow(const Show* s) {
    char castOrdenado[MAX_STR * 2];
    strcpy(castOrdenado, s->cast);
    ordenarCast(castOrdenado);

    printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##\n",
        s->show_id, s->title, s->type, s->director, castOrdenado, s->country,
        s->date_added, s->release_year, s->rating, s->duration, s->listed_in);
}

time_t parseDate(const char *data) {
    if (strcmp(data, "NaN") == 0) return 0;

    struct tm tm = {0};
    setlocale(LC_TIME, "C");

    if (strptime(data, "%B %d, %Y", &tm) == NULL) {
        return 0;
    }
    return mktime(&tm);
}

int compararShows(const Show* a, const Show* b, long *comparacoes) {
    (*comparacoes)++;
    time_t da = parseDate(a->date_added);
    time_t db = parseDate(b->date_added);

    if (da != db)
        return (da < db) ? -1 : 1;
    return strcasecmp(a->title, b->title);
}

Node* criarNode(Show data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

void inserirFim(Node** head, Node** tail, Show data) {
    Node* node = criarNode(data);
    if (*tail == NULL) {
        *head = *tail = node;
    } else {
        (*tail)->next = node;
        node->prev = *tail;
        *tail = node;
    }
}

Node* particao(Node* low, Node* high, long *comparacoes) {
    Show pivot = high->data;
    Node* i = low->prev;

    for (Node* j = low; j != high; j = j->next) {
        if (compararShows(&(j->data), &pivot, comparacoes) <= 0) {
            i = (i == NULL) ? low : i->next;
            Show temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
    i = (i == NULL) ? low : i->next;
    Show temp = i->data;
    i->data = high->data;
    high->data = temp;
    return i;
}

void quickSort(Node* low, Node* high, long *comparacoes) {
    if (high != NULL && low != high && low != high->next) {
        Node* p = particao(low, high, comparacoes);
        quickSort(low, p->prev, comparacoes);
        quickSort(p->next, high, comparacoes);
    }
}

Node* ultimo(Node* head) {
    while (head && head->next)
        head = head->next;
    return head;
}

void lerShow(Show *s, char *linha) {
    char *campos[12];
    int campoIndex = 0, entreAspas = 0, bufIndex = 0;
    char *ptr = linha, buffer[MAX_STR];

    while (*ptr != '\0' && campoIndex < 12) {
        if (*ptr == '"') {
            entreAspas = !entreAspas;
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

    strcpy(s->show_id, strlen(campos[0]) ? campos[0] : "NaN");
    strcpy(s->type, strlen(campos[1]) ? campos[1] : "NaN");
    strcpy(s->title, strlen(campos[2]) ? campos[2] : "NaN");
    strcpy(s->director, strlen(campos[3]) ? campos[3] : "NaN");
    strcpy(s->cast, strlen(campos[4]) ? campos[4] : "NaN");
    strcpy(s->country, strlen(campos[5]) ? campos[5] : "NaN");
    strcpy(s->date_added, strlen(campos[6]) ? campos[6] : "NaN");
    s->release_year = strlen(campos[7]) ? atoi(campos[7]) : -1;
    strcpy(s->rating, strlen(campos[8]) ? campos[8] : "NaN");
    strcpy(s->duration, strlen(campos[9]) ? campos[9] : "NaN");
    strcpy(s->listed_in, strlen(campos[10]) ? campos[10] : "NaN");

    for (int j = 0; j <= campoIndex; j++) free(campos[j]);
}


int main() {
    FILE *fp = fopen("/tmp/disneyplus.csv", "r");
    if (!fp) {
        perror("Erro ao abrir CSV");
        return 1;
    }

    char linha[4096];
    fgets(linha, sizeof(linha), fp); 

    Show allShows[1500];
    int total = 0;
    while (fgets(linha, sizeof(linha), fp) && total < 1500) {
        linha[strcspn(linha, "\n")] = 0;
        lerShow(&allShows[total++], linha);
    }
    fclose(fp);

    Node *head = NULL, *tail = NULL;
    char entrada[MAX_STR];

    while (fgets(entrada, sizeof(entrada), stdin)) {
        entrada[strcspn(entrada, "\n")] = 0;
        if (strcmp(entrada, "FIM") == 0) break;

        for (int i = 0; i < total; i++) {
            if (strcmp(allShows[i].show_id, entrada) == 0) {
                inserirFim(&head, &tail, allShows[i]);
                break;
            }
        }
    }

    long comparacoes = 0;
    clock_t ini = clock();

    quickSort(head, tail, &comparacoes);

    clock_t fim = clock();
    double tempo = ((double)(fim - ini)) / CLOCKS_PER_SEC * 1000.0;

    for (Node* node = head; node != NULL; node = node->next)
        imprimirShow(&node->data);

    FILE* log = fopen(MATRICULA"_quicksort2.txt", "w");
    if (log) {
        fprintf(log, "%s\t%.0lf\t%ld\n", MATRICULA, tempo, comparacoes);
        fclose(log);
    }

    while (head) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}
