//um codigo que mostra todos os n numeros da sequencia de fibonacci, sendo n dado pelo usuário

#include <stdio.h> 

// Função para imprimir a sequência de Fibonacci
void fibonacci(int n) {
    int antigo = 0, novo = 1; // Declara e inicializa as duas primeiras variáveis da sequência

   
    for (int i = 0; i < n; i++) {
        printf("i = %d numero = %d\n", i, antigo);
        int proximo = antigo + novo; // Calcula o próximo valor da sequência
        antigo = novo; // Atualiza o valor antigo
        novo = proximo; // Atualiza o valor novo
    }
}

int main() {
    int n; 
    printf("Digite o valor de n: "); 
    scanf("%d", &n); 

    
    if (n <= 0) {
        printf("Por favor, insira um número maior que zero.\n"); 
        return 1; // Encerra o programa com um código de erro
    }

    
    fibonacci(n); 
    return 0; 
}
