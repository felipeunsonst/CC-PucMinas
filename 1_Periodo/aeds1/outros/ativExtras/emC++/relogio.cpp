#include <iostream>

class Relogio {
private:
    int hora;
    int minuto;
    int segundo;

public:
    // Construtor padrão inicializa o relógio para 00:00:00
    Relogio() : hora(0), minuto(0), segundo(0) {}

    // Método para configurar o horário desejado
    void setHora(int h, int m, int s) {
        hora = h;
        minuto = m;
        segundo = s;
    }

    // Método para obter o horário atual
    void getHora(int& h, int& m, int& s) const {
        h = hora;
        m = minuto;
        s = segundo;
    }

    // Método para avançar o horário para o próximo segundo
    void avancarSegundo() {
        segundo++;
        if (segundo >= 60) {
            segundo = 0;
            minuto++;
            if (minuto >= 60) {
                minuto = 0;
                hora++;
                if (hora >= 24) {
                    hora = 0;  // Volta para 00:00:00 caso passe de 23:59:59
                }
            }
        }
    }
};

int main() {
    Relogio relogio;

    // Configura o relógio para 14:30:00
    relogio.setHora(14, 30, 0);

    // Obtém o horário atual
    int hora, minuto, segundo;
    relogio.getHora(hora, minuto, segundo);
    std::cout << "Horario atual: " << hora << ":" << minuto << ":" << segundo << std::endl;

    // Avança o relógio em 1 segundo
    relogio.avancarSegundo();

    // Obtém o horário após avançar 1 segundo
    relogio.getHora(hora, minuto, segundo);
    std::cout << "Horario atualizado: " << hora << ":" << minuto << ":" << segundo << std::endl;

    return 0;
}
