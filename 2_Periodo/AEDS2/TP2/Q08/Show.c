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

void shellsort(Show* shows, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Show temp = shows[i];
            int j = i;

            while (j >= gap) {
                int cmp_type = strcasecmp(shows[j - gap].type, temp.type);
                int cmp_title = strcasecmp(shows[j - gap].title, temp.title);

                if (cmp_type > 0 || (cmp_type == 0 && cmp_title > 0)) {
                    shows[j] = shows[j - gap];
                    j -= gap;
                } else {
                    break;
                }
            }
            shows[j] = temp;
        }
    }
}

void gerar_log(const char* matricula, double tempo_execucao) {
    FILE* log_file = fopen("matricula_shellsort.txt", "w");
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

    // Processar cast em ordem alfabética
    char cast_copy[512];
    strncpy(cast_copy, s->cast, sizeof(cast_copy));
    cast_copy[sizeof(cast_copy) - 1] = '\0';

    char* nomes[64];
    int count = 0;
    char* token = strtok(cast_copy, ",");

    while (token && count < 64) {
        while (*token == ' ') token++;  
        nomes[count++] = token;
        token = strtok(NULL, ",");
    }

    int compare_nomes(const void* a, const void* b) {
        return strcasecmp(*(char**)a, *(char**)b);
    }
    qsort(nomes, count, sizeof(char*), compare_nomes);

    char cast_ordenado[512] = "";
    for (int i = 0; i < count; i++) {
        strcat(cast_ordenado, nomes[i]);
        if (i < count - 1) strcat(cast_ordenado, ", ");
    }

    printf("=> %s ## %s ## %s ## %s ## [%s] ## %s ## %s ## %d ## %s ## %s ## [%s] ##\n",
        s->show_id, s->title, s->type, s->director, cast_ordenado, s->country, data,
        s->release_year, s->rating, s->duration, s->listed_in);
}


Show* buscar_por_id(const char* id, Show* todos, int total) {
    for (int i = 0; i < total; i++) {
        if (strcmp(todos[i].show_id, id) == 0) {
            return &todos[i];
        }
    }
    return NULL;
}

int main() {
    setlocale(LC_TIME, "en_US.UTF-8");

    Show todos[MAX_SHOWS];
    int total = load_shows("/tmp/disneyplus.csv", todos);

    Show selecionados[MAX_SHOWS];
    int qtd_selecionados = 0;
    char id[32];

    while (scanf(" %s", id) && strcmp(id, "FIM") != 0) {
        Show* encontrado = buscar_por_id(id, todos, total);
        if (encontrado) {
            selecionados[qtd_selecionados++] = *encontrado;
        }
    }

    clock_t inicio = clock();
    shellsort(selecionados, qtd_selecionados);
    clock_t fim = clock();

    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    gerar_log("854155", tempo_execucao);

    for (int i = 0; i < qtd_selecionados; i++) {
        imprimir_show(&selecionados[i]);
    }

    return 0;
}
