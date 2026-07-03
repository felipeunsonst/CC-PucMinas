//FELIPE COSTA UNSONST
//1523384

#include <stdio.h>

void metodo0311() {
    /*
    - ler uma palavra do teclado; 
    - mostrar as letras maiúsculas.  
    Exemplo: palavra = "PaLaVrA" 
    */
    
    char palavra[100];

    // Lê a palavra do teclado
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    int i = 0;
    
    while (palavra[i] != '\0') {  // Percorre cada caractere da palavra até o fim ('\0')
        if (palavra[i] >= 'A' && palavra[i] <= 'Z') {  // Verifica se o caractere está entre 'A' (65) e 'Z' (90)
            printf("A palavra so com letras maiusculas e: %c", palavra[i]);  // Imprime o caractere maiúsculo
        }
        i++;
    }
    printf("\n");  
}

void metodo0312(){
    /*
    - ler uma palavra do teclado; 
    - contar e mostrar apenas as letras minúsculas.  
    Exemplo: palavra = "PaLaVrA"
    */
    
    char palavra[100];

    // Lê a palavra do teclado
    printf("Digite uma palavra:\n ");
    scanf("%s", palavra);
    
    int i=0;
    int j = 0;
    
    while (palavra[i] != '\0') {  
        if (palavra[i] >= 'a' && palavra[i] <= 'z') {  
            printf("A palavra so com letras minusculas e: %c", palavra[i]); 
             j++; //verifica quantos caracteres se adequam na regra
        }
        i++;
    }
    printf("\na palavra tem %d caracteres que se adequam a regra", j);
    printf("\n");  
}

void metodo0313(){
    /*
    - ler uma palavra do teclado; 
    - contar e mostrar as letras minúsculas percorrendo do fim para o início da palavra.  
    Exemplo: palavra = "PaLaVrA"
    */
    
    char palavra[100];

    // Lê a palavra do teclado
    printf("Digite uma palavra:\n ");
    scanf("%s", palavra);

    int i=0; 
    int j=0;
    
    while(palavra[i] != '\0'){
        i++;
    }

    for(i ; i >= 0; i--){
        if (palavra[i] >= 'a' && palavra[i] <= 'z') {  
            printf(" %c", palavra[i]); 
             j++; //verifica quantos caracteres se adequam na regra
        }
    }

    printf("\na palavra tem %d caracteres que se adequam a regra", j);
    printf("\n");
}

void metodo0314(){
    /*
    - ler uma cadeia de caracteres do teclado; 
    - contar e mostrar todos símbolos que forem letras, ou maiúsculas ou minúsculas.  
    Exemplo: palavra = "P4LaVr@" 
    */
    
    char palavra[100];

    // Lê a palavra do teclado
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    int i = 0;
    int j =0;
    while (palavra[i] != '\0') {  // Percorre cada caractere da palavra até o fim ('\0')
        if(palavra[i] >= 'A' && palavra[i] <= 'Z' || palavra[i] >= 'a' && palavra[i] <= 'z'){
           printf("%c", palavra[i]);
            j++;//verifica quantos caracteres se adequam na regra
        }
        i++;
    }
    printf("\na palavra tem %d caracteres que se adequam a regra", j);
    printf("\n");  

}

void metodo0315(){
    /*
    - ler uma cadeia de caracteres do teclado; 
    - contar e mostrar todos os dígitos, percorrendo do fim para o início da cadeia de caracteres. 
    Exemplo: palavra = "P4LaVr@1"
    */
    
    char palavra[100];

    // Lê a palavra do teclado
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int i=0;
    while(palavra[i] != '\0'){
        i++;
    }

    int j=0;

    for(i; i >=0; i--){
        if(palavra[i] == '1' || palavra[i] == '2' || palavra[i] == '3' || palavra[i] == '4' ||  palavra[i] == '5' ||  palavra[i] == '6' ||  palavra[i] == '7' ||  palavra[i] == '8' ||  palavra[i] == '9' || palavra[i] == '0'){   
        printf("%c", palavra[i]);
            j++; //verifica quantos caracteres se adequam na regra
        }
    }
    printf("\na palavra tem %d caracteres que se adequam a regra", j);
    printf("\n");
}

void metodo0316(){
    /*
    - ler uma cadeia de caracteres do teclado; 
    - contar e mostrar tudo o que não for dígito e também não for letra. 
    Exemplo: palavra = "P4LaVr@O!" 

    */

    char palavra[100];

    printf("digite uma palavra: ");
    scanf("%s", palavra);

    int i= 0;
    int j=0;

    while(palavra[i] != '\0'){
        if(palavra[i] == '1' || palavra[i] == '2' || palavra[i] == '3' || palavra[i] == '4' ||  palavra[i] == '5' ||  palavra[i] == '6' ||  palavra[i] == '7' ||  palavra[i] == '8' ||  palavra[i] == '9' || palavra[i] == '0' || palavra[i] >= 'A' && palavra[i] <= 'Z' || palavra[i] >= 'a' && palavra[i] <= 'z'){
            //não esta nas condições, portanto não executa
        }else{
            printf("%c", palavra[i]);
            j++;
        }
        i++;
    }

    printf("\na palavra tem %d caracteres que se adequam a regra", j);
    printf("\n");

}

void metodo0317(){
    /*
    - ler dois valores inteiros (a,b), limites para definirem um intervalo [a:b]; 
    - ler uma quantidade (n) de valores inteiros a serem testados;
    - repetir a leitura de outros tantos valores, quantos os indicados pela quantidade, um (x) por vez;
    - contar e mostrar quantos dentre esses valores lidos (x)  
    os que forem múltiplos de 5, e pertençam ao intervalo [a:b].  
    Exemplo: [ 15: 60 ], e n = 7, com { 10, 20, 30, 42, 54, 60, 84 }
    */

    int a, b;

    printf("Digite os numeros que definirao o intervalo: ");
    scanf("%d %d", &a, &b);

    int n;

    printf("\nDigite a quantidade de numeros a serem testados: ");
    scanf("%d", &n);

    int x[100];
    printf("\nDigite os numeros da sequencia: ");

    int j = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);  // Aqui você lê cada número e o armazena no array x[i]
        if(x[i] >= a && x[i] <= b){
            if(x[i] % 5 == 0){
                printf("%d ", x[i]);
                j++;
            }
        }
    }

    printf("\nSao %d numeros que estao entre o intervalo e sao multiplos de 5\n", j);
}

void metodo0318(){
    /*
    - ler dois valores inteiros (a,b), limites para definirem um intervalo [a:b];
    - ler uma quantidade (n) de valores inteiros a serem testados; 
    - ler outros tantos valores quantos os indicados pela quantidade, um (x) por vez; 
    - contar e mostrar quantos dentre esses valores lidos (x) 
    os que forem múltiplos de 3, que não forem também múltiplos de 5,e pertençam ao intervalo [a:b]. 
    Exemplo: [ 20: 60 ], e n = 7, com { 10, 20, 30, 48, 52, 60, 84 }
    */

     int a, b;

    printf("Digite os numeros que definirao o intervalo: ");
    scanf("%d %d", &a, &b);

    int n;

    printf("\nDigite a quantidade de numeros a serem testados: ");
    scanf("%d", &n);

    int x[100];
    printf("\nDigite os numeros da sequencia: ");

    int j = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &x[i]);  // Aqui você lê cada número e o armazena no array x[i]
        if(x[i] >= a && x[i] <= b){
            if(x[i] % 3 == 0){
                if(x[i] % 5 != 0){
                printf("%d ", x[i]);
                j++;
                }
            }
        }
    }

    printf("\nSao %d numeros que estao entre o intervalo e sao multiplos de 3 e nao de 5\n", j);
}

void metodo0319(){
    /*
    - ler dois valores reais (a e b), o primeiro (a) menor que o segundo (b), confirmadamente, para definirem um intervalo aberto (a:b); 
    - ler a quantidade (n) de valores reais a serem testados, e ler outros tantos valores (x) quantos os indicados por essa quantidade; 
    - contar e mostrar todos os valores lidos, pertencentes ao do intervalo, 
cujas partes inteiras forem ímpares.  

    Exemplo: ( 2.5: 7.8 ), e n = 7, com { 1.0, 2.4, 3.3, 4.1, 5.5, 6.3, 8.4 }
    */

    double a, b;
    printf("digite os dois valores que definirao o intervalo:\n");
    scanf("%lf %lf", &a, &b);


    int n;
    printf("digite a quantidade de numeros a serem testados:\n");
    scanf("%d", &n);

    double x[100];
    printf("\nDigite os numeros da sequencia: ");

    int j=0;


    for(int i = 0; i < n; i++){
        scanf("%lf", &x[i]);  // Aqui você lê cada número e o armazena no array x[i]
        if(x[i] >= a && x[i] <= b){
            int parte_inteira = (int)x[i];
            if(parte_inteira % 2 != 0){
                printf("%lf ", x[i]);
                j++;
            }
        }
    }

     printf("\nSao %d numeros que estao entre o intervalo e possuem a parte inteira impar\n", j);
}

void metodo0320(){
    /*
    - ler dois valores reais (a e b), maiores que 0 e menores que 1, confirmadamente,  para definirem um intervalo aberto (a:b);
    - ler uma quantidade (n) de valores reais a serem testados, e ler outros tantos valores quantos os indicados por essa quantidade; 
    - contar e mostrar todos os valores lidos que tenham suas partes fracionárias fora do intervalo ]a:b[.  
    Exemplo: ( 0.25: 0.50 ), e n = 7, com { 1.0, 2.8, 3.3, 4.1, 5.5, 6.9, 8.4 }
    */

  double a, b;
    printf("digite os dois valores que definirao o intervalo(maior que zero e menor que 1, o primeiro deve ser menor que o segundo):\n");
    scanf("%lf %lf", &a, &b);


    int n;
    printf("digite a quantidade de numeros a serem testados:\n");
    scanf("%d", &n);

    double x[100];
    printf("\nDigite os numeros da sequencia: ");

    int j=0;


    for(int i = 0; i < n; i++){
        scanf("%lf", &x[i]);  // Aqui você lê cada número e o armazena no array x[i]
        if(x[i] >= a || x[i] <= b){
            double parte_fracionaria = x[i] - (int)x[i];
            if(parte_fracionaria <= a || parte_fracionaria >= b){
               printf("%lf ", x[i]);
               j++;
            }
        }
    }

     printf("\nSao %d numeros que possuem sua parte fracionaria fora do intervalo\n", j);

}

void metodo03E1(){
    /*
    - ler uma linha do teclado; 
    - separar em outra cadeia de caracteres e mostrar  todos os símbolos não alfanuméricos (letras ou dígitos) na cadeia de caracteres. 
    Exemplo: sequência = "P4LaVr@O! & pAl4vR1n#a" 
    */

    char sequencia[100];
    int i = 0;

    // Ler a linha do teclado
    printf("digite uma sequência de caracteres: ");
    fgets(sequencia, 100, stdin);

    // Percorrer a sequência e extrair os símbolos não alfanuméricos
    while (sequencia[i] != '\0') {
        if (!((sequencia[i] >= '0' && sequencia[i] <= '9') || 
              (sequencia[i] >= 'A' && sequencia[i] <= 'Z') || 
              (sequencia[i] >= 'a' && sequencia[i] <= 'z')) &&
              sequencia[i] != '\n') {
            printf("%c", sequencia[i]);
        }
        i++;
    }

}

void metodo03E2(){
    /*
    - ler uma cadeia de caracteres do teclado; 
    - dizer se a sequência contém apenas símbolos que NÃO são letras. 
    Exemplo: sequência = "4@0!1#"
    */

    char sequencia[100];
    int i = 0;
    int j = 0;

    // Ler a linha do teclado
    printf("digite uma sequência de caracteres:\n ");
    fgets(sequencia, 100, stdin);

    // Percorrer a sequência e extrair os símbolos não alfanuméricos
    while (sequencia[i] != '\0') {
        if (((sequencia[i] >= 'A' && sequencia[i] <= 'Z') || 
              (sequencia[i] >= 'a' && sequencia[i] <= 'z')) &&
              sequencia[i] != '\n') {
            j++;//indica que há letra
        }
        i++;
    }

    if(j!=0){
        printf("a sequencia digitada NAO possui apenas simbolos diferentes de letras\n");
    }else{
        printf("a sequencia possui apenas simbolos diferentes de letras\n");
    }
}


int main() {
  int opcao;


    do{
    printf("digite o numero correspondente ao metodo desejado(1 a 12) ou 0 para encerrar:\n");
    scanf("%d", &opcao);


    switch(opcao){
        case 1:
        metodo0311();
        break;
        
        case 2:
        metodo0312();
        break;
        
        case 3:
        metodo0313();
        break;
        
        case 4:
        metodo0314();
        break;
        
        case 5:
        metodo0315();
        break;
        
        case 6:
        metodo0316();
        break;
        
        case 7:
        metodo0317();
        break;
        
        case 8:
        metodo0318();
        break;
        
        case 9:
        metodo0319();
        break;
        
        case 10:
        metodo0320();
        break;
        
        case 11:
        metodo03E1();
        break;
        
        case 12:
        metodo03E2();
        break;

    }

    }while(opcao !=0);

    return 0;
}
