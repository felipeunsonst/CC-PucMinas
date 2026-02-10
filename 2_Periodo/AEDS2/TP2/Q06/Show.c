#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>


#define MAX_SHOWS 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char show_id[32];
    char type[32];
    char title[256];
    char director[256];
    char cast[512];
    char country[64];
    struct tm date_added;
    int has_date;
    int release_year;
    char rating[16];
    char duration[32];
    char listed_in[256];
} Show;

void remove_quotes(char* str) {
    size_t len = strlen(str);
    if (len > 1 && str[0] == '"' && str[len - 1] == '"') {
        memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
    }
}

int parse_csv_line(char* line, char fields[][512], int max_fields) {
    int field_index = 0, char_index = 0;
    int in_quotes = 0;
    char* ptr = line;
    char current[512] = "";
    while (*ptr) {
        if (*ptr == '"') {
            in_quotes = !in_quotes;
        } else if (*ptr == ',' && !in_quotes) {
            current[char_index] = '\0';
            strncpy(fields[field_index++], current, 512);
            char_index = 0;
            current[0] = '\0';
            if (field_index >= max_fields) break;
        } else {
            current[char_index++] = *ptr;
        }
        ptr++;
    }
    current[char_index] = '\0';
    strncpy(fields[field_index++], current, 512);
    return field_index;
}

int nome_mes_para_int(const char* mes) {
    const char* meses[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(mes, meses[i]) == 0)
            return i;
    }
    return -1;
}

int parse_date(char* date_str, struct tm* date_tm) {
    remove_quotes(date_str);
    if (strlen(date_str) == 0) return 0;

    char mes_str[20];
    int dia, ano;
    if (sscanf(date_str, "%s %d, %d", mes_str, &dia, &ano) != 3)
        return 0;

    int mes = nome_mes_para_int(mes_str);
    if (mes == -1) return 0;

    memset(date_tm, 0, sizeof(struct tm));
    date_tm->tm_year = ano - 1900;
    date_tm->tm_mon = mes;
    date_tm->tm_mday = dia;

    return 1;
}


// Carrega os shows do arquivo
int load_shows(const char* filename, Show* shows) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file); 
    int count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) && count < MAX_SHOWS) {
        char fields[12][512];
        int parsed = parse_csv_line(line, fields, 12);
        if (parsed < 11) continue;

        Show* s = &shows[count];

        strncpy(s->show_id, fields[0], 31);
        strncpy(s->type, fields[1], 31);
        strncpy(s->title, fields[2], 255);
        strncpy(s->director, fields[3], 255);
        strncpy(s->cast, fields[4], 511);
        strncpy(s->country, fields[5], 63);
        s->has_date = parse_date(fields[6], &s->date_added);
        s->release_year = atoi(fields[7]);
        strncpy(s->rating, fields[8], 15);
        strncpy(s->duration, fields[9], 31);
        strncpy(s->listed_in, fields[10], 255);

        count++;
    }
    fclose(file);
    return count;
}

int find_min_index(Show* shows, int start, int end) {
    if (start == end) return start;

    int min_index_rest = find_min_index(shows, start + 1, end);

    return (strcasecmp(shows[start].title, shows[min_index_rest].title) < 0) ? start : min_index_rest;
}

void selection_sort_recursive(Show* shows, int start, int n) {
    if (start >= n - 1) return;

    int min_index = find_min_index(shows, start, n - 1);

    if (min_index != start) {
        Show temp = shows[start];
        shows[start] = shows[min_index];
        shows[min_index] = temp;
    }

    selection_sort_recursive(shows, start + 1, n);
}


void gerar_log(const char* matricula, double tempo_execucao) {
    FILE* log_file = fopen("matricula_quicksort.txt", "w");
    if (log_file) {
        fprintf(log_file, "%s\t%f\n", matricula, tempo_execucao);
        fclose(log_file);
    } else {
        printf("Erro ao criar o arquivo de log.\n");
    }
}

void imprimir_show(const Show* s) {
    char data[32];
    if (s->has_date)
        strftime(data, sizeof(data), "%B %d, %Y", &s->date_added);
    else
        strcpy(data, "NaN");

    printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##\n",
        s->show_id, s->title, s->type, s->director, s->cast, s->country, data,
        s->release_year, s->rating, s->duration, s->listed_in);
}



int main() {
    setlocale(LC_TIME, "en_US.UTF-8");

    Show shows[MAX_SHOWS];
    int qtd = load_shows("/tmp/disneyplus.csv", shows);

    clock_t inicio = clock();

    selection_sort_recursive(shows, 0, qtd);

    clock_t fim = clock();
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    const char* matricula = "854155";  
    gerar_log(matricula, tempo_execucao);

    for (int i = 0; i < qtd; i++) {
        imprimir_show(&shows[i]);
    }

    

    return 0;
}
