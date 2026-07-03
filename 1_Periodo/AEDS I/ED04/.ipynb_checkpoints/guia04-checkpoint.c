//FELIPE COSTA UNSONST
//1523384

#include <stdio.h> 
#include <string.h>

void metodo0411(){

    int n;
    printf("digite a quantidade de numeros a serem lidos:\n");
    scanf("%d", &n);

    double a, b;
    printf("digite os valores que definirao o intervalo:\n");
    scanf("%lf %lf", &a, &b);

    int j = 0;
    
    double x[100];
    printf("digite os numeros:\n");
    for(int i=0; i<n; i++){
        scanf("%lf", &x[i]);
        if(x[i] >= a && x[i] <= b){
            printf("%lf\n", x[i]);
            j++;
        }
    }

    printf("sao %d numeros que estão presentes no interalo\n", j);
}

void minuscula(char palavra[100]) { //função que será usada no metodo 0412
    int i = 0;

    while (palavra[i] != '\0') {
        i++;
    }

    for (int j = 0; j < i; j++) {
        if (palavra[j] >= 'a' && palavra[j] <= 'm') {
            printf("%c", palavra[j]);
        }
    }

    printf("\n");  
}

void metodo0412() {
    char sequencia[100];
    
 
    printf("digite uma sequência de caracteres:\n ");
    fgets(sequencia, 100, stdin);

    // Remoção manual do caractere de nova linha ('\n')
    int i = 0;
    while (sequencia[i] != '\0') {
        if (sequencia[i] == '\n') {
            sequencia[i] = '\0';  // Substitui o '\n' por um terminador nulo
            break;
        }
        i++;
    }

    // Chama a função minuscula passando a string
    minuscula(sequencia);
}


void contarCaracteres(char palavra[100]){ //função que será usada no metodo 0413
    int i = 0;
    int j =0;

    while (palavra[i] != '\0') {
        i++;
    }

    for (int j = 0; j < i; j++) {
        if (palavra[j] >= 'a' && palavra[j] <= 'm') {
            j++;
        }
    }

    printf("sao %d letras menores que m na sequencia\n", j);
    printf("\n");  
}


void metodo0413(){

    char sequencia[100];
    printf("digite uma sequencia de caracteres:\n");
    fgets(sequencia, 100, stdin);

     int i = 0;
    while (sequencia[i] != '\0') {
        if (sequencia[i] == '\n') {
            sequencia[i] = '\0';  
            break;
        }
        i++;
    }

    contarCaracteres(sequencia);
    
}


void impressao(char palavra[100]) {
    char vazio[100] = ""; // Inicializa a string vazia
    int j = 0;

    // Loop para percorrer a string
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] >= 'a' && palavra[i] <= 'm') {
            vazio[j] = palavra[i];  // Adiciona o caractere na string 'vazio'
            j++;
        }
    }
    
    vazio[j] = '\0'; // Termina a string 'vazio'
    printf("%s\n", vazio); // Imprime a string resultante
}

void metodo0414() {
    char sequencia[100];
    printf("Digite uma sequencia de caracteres:\n");
    fgets(sequencia, 100, stdin);

    // Remover o '\n' da string de entrada
    int i = 0;
    while (sequencia[i] != '\0') {
        if (sequencia[i] == '\n') {
            sequencia[i] = '\0';  
            break;
        }
        i++;
    }

    impressao(sequencia);  // Passa a string completa
}

void letras(char palavra[100]){ //função que será usada no metodo 0415
    int i = 0;
    int j =0;

    while (palavra[i] != '\0') {
        i++;
    }

    for (int j = 0; j < i; j++) {
        if (palavra[j] >= 'a' && palavra[j] <= 'm' || palavra[j] >= 'A' && palavra[j] <= 'M') {
            j++;
        }
    }

    printf("sao %d letras menores que m na sequencia\n", j);
    printf("\n");  

}

void metodo0415(){
    char sequencia[100];

    printf("digite uma sequencia de caracteres:\n");
    fgets(sequencia, 100, stdin);

    int i = 0;
    while (sequencia[i] != '\0') {
        if (sequencia[i] == '\n') {
            sequencia[i] = '\0';  
            break;
        }
        i++;
    }

    letras(sequencia);  // Passa a string completa
    
}

void maiores(char palavra[100]){ //função que sera usada no metodo 0416
    int i = 0; 

    while(palavra[i] != '\0'){
        i++;
    }

    
    for(int j = 0; j<i; i++){
        if(palavra[j] >= 'm' && palavra[j] <= 'z' || palavra[j] >=  'M' && palavra[j] <= 'Z'){
            printf("%c", palavra[j]);
        }
    }
}


void metodo0416(){
    char sequencia[100];
    printf("digite uma sequencia de carateres:\n");
    fgets(sequencia, 100, stdin);

    int i=0;
    while(sequencia[i] != '\0'){
        if(sequencia[i] == '\n'){
            sequencia[i] = '\0';
            break;
        }
        i++;
    }

    maiores(sequencia);
}

void impares(char palavra[100]){ //função que sera usada no metodo 0417

    int i = 0; 

    while(palavra[i] != '\0'){
        i++;
    }

    int z =0;
    
    for(int j = 0; j<i; i++){
        if(palavra[j] == '1' || palavra[j] == '3' || palavra[j] == '5' || palavra[j] == '7' || palavra[j] == '9'){
           z++;
        }
    }

    printf("sao %d numeros impares na sequencia\n", z);
}

void metodo0417(){
   char sequencia[100];
    printf("digite uma sequencia de carateres:\n");
    fgets(sequencia, 100, stdin);

    int i=0;
    while(sequencia[i] != '\0'){
        if(sequencia[i] == '\n'){
            sequencia[i] = '\0';
            break;
        }
        i++;
    }

    impares(sequencia);
}

void simbolos(char palavra[100]){// função que sera usada no metodo 0418
    int i = 0; 

    while(palavra[i] != '\0'){
        i++;
    }

    
    for(int j = 0; j<i; i++){
        if(palavra[j] >= 'A' && palavra[j] <= 'Z' || palavra[j] >= 'a' && palavra[j] <= 'z'  || palavra[j] == '1' || palavra[j] == '2' || palavra[j] == '3' || palavra[j] == '4' || palavra[j] == '5' || palavra[j] == '6' || palavra[j] == '7' || palavra[j] == '8' || palavra[j] == '9' || palavra[j] == '0' ){
            printf("%c", palavra[j]);
        }
    }

}

void metodo0418(){
    char sequencia[100];
    printf("digite uma sequencia de carateres:\n");
    fgets(sequencia, 100, stdin);

    int i=0;
    while(sequencia[i] != '\0'){
        if(sequencia[i] == '\n'){
            sequencia[i] = '\0';
            break;
        }
        i++;
    }

    simbolos(sequencia);
}

void separa(char palavra[100]){
     int i = 0; 

    while(palavra[i] != '\0'){
        i++;
    }

   
    for(int j = 0; j<i; i++){
        if(palavra[j] >= 'A' && palavra[j] <= 'Z' || palavra[j] >= 'a' && palavra[j] <= 'z'  || palavra[j] == '1' || palavra[j] == '2' || palavra[j] == '3' || palavra[j] == '4' || palavra[j] == '5' || palavra[j] == '6' || palavra[j] == '7' || palavra[j] == '8' || palavra[j] == '9' || palavra[j] == '0' ){
          
        } else {
            printf("%c", palavra[j]);
        }
    }
}

void metodo0419(){
    char sequencia[100];
    printf("digite uma sequencia de carateres:\n");
    fgets(sequencia, 100, stdin);

    int i=0;
    while(sequencia[i] != '\0'){
        if(sequencia[i] == '\n'){
            sequencia[i] = '\0';
            break;
        }
        i++;
    }

    simbolos(sequencia);
}

int acumulado(char palavra[100]){
    int i = 0; 

    while(palavra[i] != '\0'){
        i++;
    }

    int z =0;
    
    for(int j = 0; j<i; i++){
        if(palavra[j] >= 'A' && palavra[j] <= 'Z' || palavra[j] >= 'a' && palavra[j] <= 'z'  || palavra[j] == '1' || palavra[j] == '2' || palavra[j] == '3' || palavra[j] == '4' || palavra[j] == '5' || palavra[j] == '6' || palavra[j] == '7' || palavra[j] == '8' || palavra[j] == '9' || palavra[j] == '0' ){
            z++;
        }
    }

    return z;
}

void metodo0420(){
    int n;
    int total = 0;

    printf("digite a quantidade de frases que serao digitadas:\n");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        char sequencia[100];
        printf("digite uma sequencia de carateres:\n");
        fgets(sequencia, 100, stdin);

        int alfaNumerico = acumulado(sequencia);
        total += alfaNumerico;
    }
    
    printf("o total de simbolos alfanumericos e: %d\n", total);
}

void palavras(char palavra[100]){ //função que será usada no metodo 04E1
   int i = 0;

    while(palavra[i] != '\0'){
        i++;
    }

    int espaços = 0;
    int simbolos = 0;
    
    for(int j=0; j<i; j++){
        if(palavra[j] >= 'A' && palavra[j] <= 'Z' || palavra[j] >= 'a' && palavra[j] <= 'z'  || palavra[j] == '1' || palavra[j] == '2' || palavra[j] == '3' || palavra[j] == '4' || palavra[j] == '5' || palavra[j] == '6' || palavra[j] == '7' || palavra[j] == '8' || palavra[j] == '9' || palavra[j] == '0' || palavra[i] == ' '){
            simbolos++;
        }
        
    }


    
}

void metodo04E1(){
     char sequencia[100];
    printf("digite uma sequencia de carateres:\n");
    fgets(sequencia, 100, stdin);

    int i=0;
    while(sequencia[i] != '\0'){
        if(sequencia[i] == '\n'){
            sequencia[i] = '\0';
            break;
        }
        i++;
    }

    palavras(sequencia);
}

void duas(char palavra1[100], char palavra2[100]){ //função que será usada no metodo 04E2
    int i = 0;
    int j = 0;

    while(palavra1[i] != '\0'){
        i++;
    }

    while(palavra2[j] != '\0'){
        j++;
    }

    if(i>j){
        printf("a sequencia que tem mais caracteres e a primeira\n");
    } else if(j>i){
         printf("a sequencia que tem mais caracteres e a segunda\n");
    }


    
}

void metodo04E2(){
    char sequencia1[100];
    char sequencia2[100];

    printf("digite a primeira sequencia:\n");
    fgets(sequencia1, 100, stdin);

    printf("digite a segunda sequencia:\n");
    fgets(sequencia2, 100, stdin);

    int i=0;
    while(sequencia1[i] != '\0'){
        if(sequencia1[i] == '\n'){
            sequencia1[i] = '\0';
            break;
        }
        i++;
    }

    int j=0;
    while(sequencia2[j] != '\0'){
        if(sequencia2[j] == '\n'){
            sequencia2[j] = '\0';
            break;
        }
        i++;
    }

    duas(sequencia1, sequencia2);
}

int main(){
    int opcao;

    do{

    printf("digite o numero correspondente ao metodo desejado(1 a 12) ou 0 para encerrar\n");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
        metodo0411();
        break;
        case 2:
        metodo0412();
        break;
        case 3:
        metodo0413();
        break;
        case 4:
        metodo0414();
        break;
        case 5:
        metodo0415();
        break;
        case 6:
        metodo0416();
        break;
        case 7:
        metodo0417();
        break;
        case 8:
        metodo0418();
        break;
        case 9:
        metodo0419();
        break;
        case 10:
        metodo0420();
        break;
        case 11:
        metodo04E1();
        break;
        case 12:
        metodo04E2();
        break;
    }

    }while(opcao !=0);




    return 0;

    
}