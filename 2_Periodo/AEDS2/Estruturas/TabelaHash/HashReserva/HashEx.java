import java.util.Scanner;

public class HashEx {
    int tabela[];
    int m1, m2, m, reserva;
    final int NULO = -1;

    public HashEx() {
        this(13, 7);
    }

    public HashEx(int m1, int m2) {
        this.m1 = m1;
        this.m2 = m2;
        this.m = m1 + m2;
        this.tabela = new int[this.m];
        for (int i = 0; i < m1; i++) {
            tabela[i] = NULO;
        }
        reserva = 0;
    }

    public int h(int elemento) {
        return elemento % m1;
    }

    public boolean inserir(int elemento) {
        boolean resp = false;
        if (elemento != NULO) {
            int pos = h(elemento);
            if (tabela[pos] == NULO) {
                tabela[pos] = elemento;
                resp = true;
            } else if (reserva < m2) {
                tabela[m1 + reserva] = elemento;
                reserva++;
                resp = true;
            }
        }
        return resp;
    }

    public boolean pesquisar(int elemento) {
        boolean resp = false;
        int pos = h(elemento);
        if (tabela[pos] == elemento) {
            resp = true;
        } else if (tabela[pos] != NULO) {
            for (int i = 0; i < reserva; i++) {
                if (tabela[m1 + i] == elemento) {
                    resp = true;
                    break;
                }
            }
        }
        return resp;
    }

    public boolean remover(int elemento) {
        boolean resp = false;
        if (elemento != NULO) {
            int pos = h(elemento);
            if (tabela[pos] == elemento) {
                tabela[pos] = NULO;
                resp = true;
            } else {
                for (int i = 0; i < reserva; i++) {
                    int idx = m1 + i;
                    if (tabela[idx] == elemento) {
                        tabela[idx] = tabela[m1 + reserva - 1];  // Compacta
                        tabela[m1 + reserva - 1] = NULO;
                        reserva--;
                        resp = true;
                        break;
                    }
                }
            }
        }
        return resp;
    }

    public void listar() {
        for (int i = 0; i < m; i++) {
            System.out.print(tabela[i] + " ");
        }
        System.out.println();
    }
}

class Main {
    public static void main(String[] args) {
        HashEx hash = new HashEx();
        Scanner entrada = new Scanner(System.in);
        int n;

        do {
            System.out.println("Escolha uma das opções abaixo:");
            System.out.println("1-Inserir número");
            System.out.println("2-Remover número");
            System.out.println("3-Listar números");
            System.out.println("4-Pesquisar número");
            System.out.println("5-Sair");
            n = entrada.nextInt();

            if (n == 1) {
                System.out.println("Digite um elemento:");
                int x = entrada.nextInt();
                if (hash.inserir(x)) {
                    System.out.println("Inserção feita com sucesso");
                } else {
                    System.out.println("Não foi possível fazer a inserção");
                }
            } else if (n == 2) {
                System.out.println("Digite um elemento:");
                int x = entrada.nextInt();
                if (hash.remover(x)) {
                    System.out.println("Remoção feita com sucesso");
                } else {
                    System.out.println("Não foi possível fazer a remoção");
                }
            } else if (n == 3) {
                hash.listar();
            } else if (n == 4) {
                System.out.println("Digite um elemento:");
                int x = entrada.nextInt();
                if (hash.pesquisar(x)) {
                    System.out.println("O elemento está presente na tabela");
                } else {
                    System.out.println("Elemento não encontrado");
                }
            } else if (n == 5) {
                System.out.println("Saindo...");
            }
        } while (n != 5);

        entrada.close();
    }
}
