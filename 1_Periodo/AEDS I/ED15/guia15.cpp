//FELIPE COSTA UNSONST
//1523384

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream> 
#include <vector>
#include <cstring>
using namespace std;

char* acrescentarCaractere(char* s, char c) {
    size_t tamanho = strlen(s);
    
    s = (char*)realloc(s, tamanho + 2);
    
    s[tamanho] = c;
    s[tamanho + 1] = '\0'; 
    
    return s; 
}


void metodo1511(){
	cout << "digite uma cadeia de caracteres: ";
    char* cadeia = (char*)malloc(100); 
    cin.getline(cadeia, 100);

    char caractere;
    cout << "digite o caractere a ser acrescentado: ";
    cin >> caractere;

    cadeia = acrescentarCaractere(cadeia, caractere);

    cout << "Cadeia atualizada: " << cadeia << endl;

    free(cadeia);
}

char* str_pop_back(char* s) {
    size_t tamanho = strlen(s);
    if (tamanho == 0) {
        return s; 
    }

    s[tamanho - 1] = '\0';

    s = (char*)realloc(s, tamanho);

    return s;
}

void metodo1512() {
	cout << "digite uma cadeia de caracteres: ";
    char* cadeia = (char*)malloc(100); 
    cin.getline(cadeia, 100);

    cadeia = str_pop_back(cadeia);

    cout << "cadeia atualizada: " << cadeia << endl;

    free(cadeia);
}

char* str_push_front(char c, char* s) {
    size_t tamanho = strlen(s);

    s = (char*)realloc(s, tamanho + 2);

    memmove(s + 1, s, tamanho + 1); 

    s[0] = c;

    return s; 
}

void metodo1513(){
	cout << "digite uma cadeia de caracteres: ";
    char* cadeia = (char*)malloc(100); 
    cin.getline(cadeia, 100);

    char caractere;
    cout << "digite o caractere a ser inserido no início: ";
    cin >> caractere;

    cadeia = str_push_front(caractere, cadeia);

    cout << "cadeia atualizada: " << cadeia << endl;

    free(cadeia);

}

char* str_pop_front(char* s) {
    if (strlen(s) == 0) {
        return s; 
    }

    memmove(s, s + 1, strlen(s)); 

    s = (char*)realloc(s, strlen(s) + 1);

    return s; 
}

void metodo1514(){
	cout << "digite uma cadeia de caracteres: ";
    char* cadeia = (char*)malloc(100); 
    cin.getline(cadeia, 100);

    cadeia = str_pop_front(cadeia);

    cout << "Cadeia atualizada: " << cadeia << endl;

    free(cadeia);
}

char* str_push_mid(char* s, char c) {
    size_t tamanho = strlen(s);

    if (tamanho < 2) {
        return s; 
    }

    size_t pos = tamanho / 2;

    s = (char*)realloc(s, tamanho + 2);

    memmove(s + pos + 1, s + pos, tamanho - pos + 1); 

    s[pos] = c;

    return s; 
}

void metodo1515(){
	cout << "digite uma cadeia de caracteres: ";
    char* cadeia = (char*)malloc(100); 
    cin.getline(cadeia, 100);

    char caractere;
    cout << "digite o caractere a ser inserido no meio: ";
    cin >> caractere;

    cadeia = str_push_mid(cadeia, caractere);

    cout << "cadeia atualizada: " << cadeia << endl;

    free(cadeia);
}

char* str_pop_mid(char* s) {
    size_t tamanho = strlen(s);

    if (tamanho < 2) {
        return s; 
    }

    size_t pos = tamanho / 2;

    memmove(s + pos, s + pos + 1, tamanho - pos);

    s = (char*)realloc(s, tamanho);

    return s; 
}

void metodo1516(){
	cout << "digite uma cadeia de caracteres: ";
    char* cadeia = (char*)malloc(100);
    cin.getline(cadeia, 100);

    cadeia = str_pop_mid(cadeia);

    cout << "cadeia atualizada: " << cadeia << endl;

    free(cadeia);
}

char* str_insert(char* s, char c, int index) {
    size_t tamanho = strlen(s);

    if (index < 0 || index > tamanho) {
        cout << "indice inválido!" << endl;
        return s; 
    }

    s = (char*)realloc(s, tamanho + 2); 

    memmove(s + index + 1, s + index, tamanho - index + 1);

    s[index] = c;

    return s; 


void metodo1517(){
	cout << "digite uma cadeia de caracteres: ";
    char* cadeia = (char*)malloc(100); 
    cin.getline(cadeia, 100);

    cout << "digite o caractere a ser inserido: ";
    char caractere;
    cin >> caractere;

    cout << "digite a posição para inserir: ";
    int posicao;
    cin >> posicao;

    cadeia = str_insert(cadeia, caractere, posicao);

    cout << "cadeia atualizada: " << cadeia << endl;

    free(cadeia);
}

char* str_remove(char* s, int index) {
    size_t tamanho = strlen(s);

    if (index < 0 || index >= tamanho) {
        cout << "indice inválido!" << endl;
        return s; 
    }

    memmove(s + index, s + index + 1, tamanho - index);

    s = (char*)realloc(s, tamanho); 

    return s; 
}

void metodo1518(){
	 cout << "digite uma cadeia de caracteres: ";
    char* cadeia = (char*)malloc(100);
    cin.getline(cadeia, 100);

    cout << "digite a posição para remover: ";
    int posicao;
    cin >> posicao;

    cadeia = str_remove(cadeia, posicao);

    cout << "cadeia atualizada: " << cadeia << endl;

    free(cadeia);
}

char* str_chr(char* s, char c) {
    while (*s != '\0') {
        if (*s == c) {
            return s; 
        }
        s++; 
    }

    return nullptr; 
}

void metodo1519(){
	cout << "digite uma cadeia de caracteres: ";
    char cadeia[100];
    cin.getline(cadeia, 100);

    cout << "digite o caractere a ser procurado: ";
    char caractere;
    cin >> caractere;

    char* resultado = str_chr(cadeia, caractere);

    if (resultado != nullptr) {
        cout << "primeira ocorrência encontrada na posição: " << (resultado - cadeia) << endl;
    } else {
        cout << "caractere não encontrado na cadeia." << endl;
    }
}

char* str_tok(char* s, char delimiter) {
    static char* current = nullptr;

    if (s != nullptr) {
        current = s;
    }

    if (current == nullptr || *current == '\0') {
        return nullptr;
    }

    char* start = current;

    while (*current != '\0' && *current != delimiter) {
        current++;
    }

    if (*current == delimiter) {
        *current = '\0';
        current++;
    } else {
        current = nullptr;
    }

    return start;
}

void metodo1520() {
    char cadeia[100];
    char delimiter;

    cout << "digite uma cadeia de caracteres: ";
    cin.getline(cadeia, 100);

    cout << "digite o delimitador: ";
    cin >> delimiter;

    cout << "tokens separados:" << endl;
    char* token = str_tok(cadeia, delimiter);
    while (token != nullptr) {
        cout << token << endl;
        token = str_tok(nullptr, delimiter); 
    }

}

char* str_prefix(char* prefix, char* s) {
    if (!prefix || !s) {
        return nullptr;
    }

    while (*prefix != '\0') {
        if (*prefix != *s) {
            return nullptr; 
        }
        prefix++;
        s++;
    }

    return s;
}

void metodo15E1() {
	char cadeia[100];
    char prefixo[50];

    cout << "digite uma cadeia de caracteres: ";
    cin.getline(cadeia, 100);

    cout << "digite o prefixo: ";
    cin.getline(prefixo, 50);

    char* resultado = str_prefix(prefixo, cadeia);
    if (resultado) {
        cout << "o prefixo \"" << prefixo << "\" foi encontrado no início da cadeia!" << endl;
    } else {
        cout << "o prefixo \"" << prefixo << "\" NÃO foi encontrado no início da cadeia." << endl;
    }
}

char* str_suffix_chr(char* s, char* sufix) {
    if (!s || !sufix) {
        return nullptr;
    }

    int len_s = strlen(s);
    int len_sufix = strlen(sufix);

    if (len_sufix > len_s) {
        return nullptr;
    }

    char* s_start = s + len_s - len_sufix;

    if (strcmp(s_start, sufix) == 0) {
        return s_start; 
    }

    return nullptr; 
}

void metodo15E2() {
    char cadeia[100];
    char sufixo[50];

    cout << "digite uma cadeia de caracteres: ";
    cin.getline(cadeia, 100);

    cout << "digite o sufixo: ";
    cin.getline(sufixo, 50);

    char* resultado = str_suffix_chr(cadeia, sufixo);
    if (resultado) {
        cout << "o sufixo \"" << sufixo << "\" foi encontrado no final da cadeia!" << endl;
    } else {
        cout << "o sufixo \"" << sufixo << "\" NÃO foi encontrado no final da cadeia." << endl;
    }
}


int main(){
	int opcao;


    do{
	    cout<<"digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo1511\n2-metodo1512\n3-metodo1513\n4-metodo1514\n5-metodo1515\n6-metodo1516\n7-metodo1517\n8-metodo1518\n9-metodo1519\n10-metodo1520\n11-metodo1X51\n12-metodo15E2\n";
	    cin>>opcao;
		getchar();
	
	
	    switch(opcao){
	        case 1:
	        metodo1511();
	        break;
	        
	        case 2:
	        metodo1512();
	        break;
	        
	        case 3:
	        metodo1513();
	        break;
	        
	        case 4:
	        metodo1514();
	        break;
	        
	        case 5:
	        metodo1515();
	        break;
	        
	        case 6:
	        metodo1516();
	        break;
	        
	        case 7:
	        metodo1517();
	        break;
	        
	        case 8:
	        metodo1518();
	        break;
	        
	        case 9:
	        metodo1519();
	        break;
	        
	        case 10:
	        metodo1520();
	        break;
	        
	        case 11:
	        metodo15E1();
	        break;
	        
	        case 12:
	        metodo15E2();
	        break;
	
	    }

    }while(opcao !=0);

    return 0;
}
