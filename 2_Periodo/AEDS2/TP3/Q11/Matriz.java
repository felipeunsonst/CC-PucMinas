import java.util.Scanner;

class Celula {
    public int elemento;
    public Celula inf, sup, esq, dir;
    public int linha, coluna;

    public Celula() {
        this(0, 0, 0);
    }

    public Celula(int elemento) {
        this(0, 0, elemento);
    }

    public Celula(int linha, int coluna, int elemento) {
        this.linha = linha;
        this.coluna = coluna;
        this.elemento = elemento;
        sup = inf = esq = dir = null;
    }
}

public class Matriz {
    private Celula inicio;
    private int linha, coluna;

    public Matriz() {
        this(3, 3);
    }

    public Matriz(int linha, int coluna) {
        this.linha = linha;
        this.coluna = coluna;

        Celula anterior = null;
        Celula linhaAnterior = null;

        for (int i = 0; i < linha; i++) {
            Celula atual = null;
            anterior = null;
            Celula temp = linhaAnterior;

            for (int j = 0; j < coluna; j++) {
                Celula nova = new Celula(i, j, 0);

                if (j == 0) {
                    atual = nova;
                    if (i == 0) {
                        this.inicio = nova;
                    }
                } else {
                    anterior.dir = nova;
                    nova.esq = anterior;
                }

                if (temp != null) {
                    temp.inf = nova;
                    nova.sup = temp;
                    temp = temp.dir;
                }

                anterior = nova;
            }

            linhaAnterior = atual;
        }
    }

    public Matriz somar(Matriz x) {
        if (this.linha != x.linha || this.coluna != x.coluna) {
            return null;
        }
        Matriz result = new Matriz(linha, coluna);

        Celula linhaA = this.inicio;
        Celula linhaB = x.inicio;
        Celula linhaR = result.inicio;

        for (int i = 0; i < linha; i++) {
            Celula colunaA = linhaA;
            Celula colunaB = linhaB;
            Celula colunaR = linhaR;

            for (int j = 0; j < coluna; j++) {
                colunaR.elemento = colunaA.elemento + colunaB.elemento;

                colunaA = colunaA.dir;
                colunaB = colunaB.dir;
                colunaR = colunaR.dir;
            }
            linhaA = linhaA.inf;
            linhaB = linhaB.inf;
            linhaR = linhaR.inf;
        }
        return result;
    }

    public Matriz multiplicacao(Matriz x) {
        if (this.coluna != x.linha) {
            return null; 
        }
        Matriz result = new Matriz(this.linha, x.coluna);

        Celula linhaA = this.inicio;
        Celula linhaR = result.inicio;

        for (int i = 0; i < this.linha; i++) {
            Celula colunaR = linhaR;
            for (int j = 0; j < x.coluna; j++) {
                int soma = 0;
                Celula colunaA = linhaA;
                Celula linhaB = x.inicio;

                for (int k = 0; k < j; k++) {
                    linhaB = linhaB.dir;
                }

                for (int k = 0; k < this.coluna; k++) {
                    soma += colunaA.elemento * linhaB.elemento;
                    colunaA = colunaA.dir;
                    linhaB = linhaB.inf;
                }

                colunaR.elemento = soma;
                colunaR = colunaR.dir;
            }
            linhaA = linhaA.inf;
            linhaR = linhaR.inf;
        }
        return result;
    }

    public void diagonalPrincipal() {
        if (linha != coluna) {
            return;
        }
        Celula atual = inicio;
        for (int i = 0; i < linha; i++) {
            System.out.print(atual.elemento + " ");
            if (atual.dir != null && atual.inf != null)
                atual = atual.dir.inf;
        }
        System.out.println();
    }

    public void diagonalSecundaria() {
        if (linha != coluna) {
            return;
        }
        Celula atual = inicio;
        for (int i = 0; i < coluna - 1; i++) {
            atual = atual.dir;
        }
        for (int i = 0; i < linha; i++) {
            System.out.print(atual.elemento + " ");
            if (atual.esq != null && atual.inf != null)
                atual = atual.esq.inf;
        }
        System.out.println();
    }

    public void mostrar() {
        Celula linhaAtual = inicio;

        for (int i = 0; i < linha; i++) {
            Celula colunaAtual = linhaAtual;

            for (int j = 0; j < coluna; j++) {
                System.out.print(colunaAtual.elemento + " ");
                colunaAtual = colunaAtual.dir;
            }

            System.out.println();
            linhaAtual = linhaAtual.inf;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int casos = sc.nextInt();

        for (int t = 0; t < casos; t++) {
            int l1 = sc.nextInt();
            int c1 = sc.nextInt();
            Matriz m1 = new Matriz(l1, c1);

            for (int i = 0; i < l1; i++) {
                Celula atual = m1.inicio;
                for (int k = 0; k < i; k++) atual = atual.inf;
                Celula col = atual;
                for (int j = 0; j < c1; j++) {
                    col.elemento = sc.nextInt();
                    col = col.dir;
                }
            }

            int l2 = sc.nextInt();
            int c2 = sc.nextInt();
            Matriz m2 = new Matriz(l2, c2);

            for (int i = 0; i < l2; i++) {
                Celula atual = m2.inicio;
                for (int k = 0; k < i; k++) atual = atual.inf;
                Celula col = atual;
                for (int j = 0; j < c2; j++) {
                    col.elemento = sc.nextInt();
                    col = col.dir;
                }
            }

            m1.diagonalPrincipal();
            m1.diagonalSecundaria();

            Matriz soma = m1.somar(m2);
            if (soma != null) {
                soma.mostrar();
            } else {
                System.out.println("Soma nao possivel");//coloquei para debug
            }

            Matriz mult = m1.multiplicacao(m2);
            if (mult != null) {
                mult.mostrar();
            } else {
                System.out.println("Multiplicacao nao possivel");//coloquei para debug
            }
        }

        sc.close();
    }
}
