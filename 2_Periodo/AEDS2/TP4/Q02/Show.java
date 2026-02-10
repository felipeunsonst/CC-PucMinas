import java.io.*;
import java.text.*;
import java.util.*;

public class Shows {

    static class Show {
        private String SHOW_ID, TYPE, TITLE, DIRECTOR, COUNTRY, RATING, DURATION;
        private String[] CAST, LISTED_IN;
        private Date DATE_ADDED;
        private int RELEASE_YEAR;

        public Show() { }

        public Show(String show_id, String type, String title, String director, String[] cast, String country,
                    Date date_added, int release_year, String rating, String duration, String[] listed_in) {
            this.SHOW_ID = show_id;
            this.TYPE = type;
            this.TITLE = title;
            this.DIRECTOR = director;
            this.CAST = cast;
            this.COUNTRY = country;
            this.DATE_ADDED = date_added;
            this.RELEASE_YEAR = release_year;
            this.RATING = rating;
            this.DURATION = duration;
            this.LISTED_IN = listed_in;
        }

        public String getTITLE() { return TITLE; }
        public int getRELEASE_YEAR() { return RELEASE_YEAR; }
    }

    static class NoString {
        String chave;
        NoString esq, dir;

        public NoString(String chave) {
            this.chave = chave;
            this.esq = this.dir = null;
        }
    }

    static class ArvoreString {
        private NoString raiz;

        public void inserir(String chave) throws Exception {
            raiz = inserir(chave, raiz);
        }

        private NoString inserir(String chave, NoString no) throws Exception {
            if (no == null) {
                return new NoString(chave);
            } else if (chave.compareTo(no.chave) < 0) {
                no.esq = inserir(chave, no.esq);
            } else if (chave.compareTo(no.chave) > 0) {
                no.dir = inserir(chave, no.dir);
            } else {
                throw new Exception("Erro: elemento duplicado na árvore interna");
            }
            return no;
        }

        public boolean pesquisar(String chave) {
            return pesquisar(chave, raiz);
        }

        private boolean pesquisar(String chave, NoString no) {
            if (no == null) return false;
            else if (chave.equals(no.chave)) {
                System.out.print("SIM\n");
                return true;
            } else if (chave.compareTo(no.chave) < 0) {
                System.out.print("ESQ ");
                return pesquisar(chave, no.esq);
            } else {
                System.out.print("DIR ");
                return pesquisar(chave, no.dir);
            }
        }
    }

    static class NoInt {
        int chave;
        NoInt esq, dir;
        ArvoreString arvoreInterna;

        public NoInt(int chave) {
            this.chave = chave;
            this.esq = this.dir = null;
            this.arvoreInterna = new ArvoreString();
        }
    }

    static class ArvoreInt {
        private NoInt raiz;
        private int comparacoes = 0;

        public void inserir(Show show) throws Exception {
            raiz = inserir(show, raiz);
        }

        private NoInt inserir(Show show, NoInt no) throws Exception {
            int chave = show.getRELEASE_YEAR() % 15;
            if (no == null) {
                NoInt novo = new NoInt(chave);
                novo.arvoreInterna.inserir(show.getTITLE());
                return novo;
            } else if (chave < no.chave) {
                no.esq = inserir(show, no.esq);
            } else if (chave > no.chave) {
                no.dir = inserir(show, no.dir);
            } else {
                no.arvoreInterna.inserir(show.getTITLE());
            }
            return no;
        }

        public boolean pesquisar(String titulo) {
            System.out.print("=>raiz ");
            return pesquisar(titulo, raiz);
        }

        private boolean pesquisar(String titulo, NoInt no) {
            boolean encontrado = false;
            if (no != null) {
                encontrado = no.arvoreInterna.pesquisar(titulo);
                if (!encontrado) {
                    System.out.print("esq ");
                    encontrado = pesquisar(titulo, no.esq);
                    if (!encontrado) {
                        System.out.print("dir ");
                        encontrado = pesquisar(titulo, no.dir);
                    }
                }
            }
            return encontrado;
        }

        public int getComparacoes() {
            return comparacoes;
        }
    }

    public static Show buscarPorID(String idBuscado, String caminhoArquivo) {
        try (BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))) {
            String linha = br.readLine();
            while ((linha = br.readLine()) != null) {
                String[] dados = linha.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
                if (dados.length < 12) continue;

                String show_id = dados[0].trim();
                if (!show_id.equalsIgnoreCase(idBuscado)) continue;

                String title = dados[2].trim().replaceAll("\"", "");
                int releaseYear = -1;
                try {
                    releaseYear = Integer.parseInt(dados[7].trim().replaceAll("\"", ""));
                } catch (Exception e) { }

                return new Show(show_id, "", title, "", new String[]{}, "", null, releaseYear, "", "", new String[]{});
            }
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
        }
        return null;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String caminhoArquivo = "/tmp/disneyplus.csv";
        ArvoreInt arvore = new ArvoreInt();

        while (true) {
            String entrada = sc.nextLine().trim();
            if (entrada.equalsIgnoreCase("FIM")) break;
            Show show = buscarPorID(entrada, caminhoArquivo);
            if (show != null && show.getRELEASE_YEAR() != -1) {
                try {
                    arvore.inserir(show);
                } catch (Exception e) { }
            }
        }

        long inicio = System.nanoTime();
        while (sc.hasNext()) {
            String titulo = sc.nextLine().trim();
            if (titulo.equalsIgnoreCase("FIM")) break;
            boolean encontrado = arvore.pesquisar(titulo);
            if (!encontrado) System.out.println("NAO");
        }
        long fim = System.nanoTime();

        double tempoExecucao = (fim - inicio) / 1e6;
        String matricula = "854155";

        try (PrintWriter writer = new PrintWriter(new FileWriter(matricula + "_arvoreArvore.txt"))) {
            writer.printf("%s\t%.3f\t%d\n", matricula, tempoExecucao, arvore.getComparacoes());
        } catch (IOException e) {
            System.out.println("Erro ao escrever o log: " + e.getMessage());
        }

        sc.close();
    }
}
