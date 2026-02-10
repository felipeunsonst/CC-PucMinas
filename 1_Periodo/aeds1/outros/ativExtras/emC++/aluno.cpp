/*
Os alunos de uma determinada disciplina são avaliados através de três provas e um trabalho. As notas obtidas nas provas e no trabalho possuem diferentes pesos 
para o cálculo da média final do aluno. As provas têm os seguintes pesos: Prova 1 (20%), Prova 2 (30%), Prova 3 (30%), e o Trabalho (20%).

Escreva um programa em C++ que:

Solicite ao usuário as notas das três provas e do trabalho.
Calcule a média ponderada das notas, utilizando os pesos especificados.
Verifique se o aluno foi aprovado ou reprovado. Um aluno é considerado aprovado se a média final for maior ou igual a 60.0.
Exiba uma mensagem informando se o aluno foi aprovado ou reprovado, juntamente com a média calculada.
Utilize a estrutura de classes em C++ para implementar este programa, criando uma classe chamada Aluno que possui métodos para ler as notas,
calcular a média ponderada e verificar a aprovação. 
*/

#include <iostream>

class Aluno {
private:
    float notaProva1;
    float notaProva2;
    float notaProva3;
    float notaTrabalho;

public:
    // Método para ler as notas
    void lerNotas() {
        std::cout << "Digite a nota da Prova 1: ";
        std::cin >> notaProva1;
        std::cout << "Digite a nota da Prova 2: ";
        std::cin >> notaProva2;
        std::cout << "Digite a nota da Prova 3: ";
        std::cin >> notaProva3;
        std::cout << "Digite a nota do Trabalho: ";
        std::cin >> notaTrabalho;
    }

    // Método para calcular a média ponderada
    float calcularMedia() {
        float media = /*pesos*/ (notaProva1 * 0.20) + (notaProva2 * 0.30) + (notaProva3 * 0.30) + (notaTrabalho * 0.20);
        return media;
    }

    // Método para verificar se o aluno passou
    void verificarAprovacao() {
        float media = calcularMedia();
        if (media >= 60.0) {
            std::cout << "Aluno aprovado com media: " << media << std::endl;
        } else {
            std::cout << "Aluno reprovado com media: " << media << std::endl;
        }
    }
};

int main() {
    Aluno aluno;
    aluno.lerNotas();
    aluno.verificarAprovacao();
    return 0;
}
