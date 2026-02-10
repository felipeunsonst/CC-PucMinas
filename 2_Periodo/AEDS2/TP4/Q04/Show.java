import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Show {
    private String SHOW_ID;
    private String TYPE;
    private String TITLE;
    private String DIRECTOR;
    private String[] CAST;
    private String COUNTRY;
    private Date DATE_ADDED;
    private int RELEASE_YEAR;
    private String RATING;
    private String DURATION;
    private String[] LISTED_IN;

    public Show() {
        this.SHOW_ID = "NaN";
        this.TYPE = "NaN";
        this.TITLE = "NaN";
        this.DIRECTOR = "NaN";
        this.CAST = new String[]{"NaN"};
        this.COUNTRY = "NaN";
        this.DATE_ADDED = null;
        this.RELEASE_YEAR = -1;
        this.RATING = "NaN";
        this.DURATION = "NaN";
        this.LISTED_IN = new String[]{"NaN"};
    }

    public Show(String SHOW_ID, String TYPE, String TITLE, String DIRECTOR, String[] CAST, String COUNTRY,
                Date DATE_ADDED, int RELEASE_YEAR, String RATING, String DURATION, String[] LISTED_IN) {
        this.SHOW_ID = SHOW_ID;
        this.TYPE = TYPE;
        this.TITLE = TITLE;
        this.DIRECTOR = (DIRECTOR.isEmpty()) ? "NaN" : DIRECTOR;
        this.CAST = (CAST.length == 0 || CAST[0].isEmpty()) ? new String[]{"NaN"} : CAST;
        this.COUNTRY = (COUNTRY.isEmpty()) ? "NaN" : COUNTRY;
        this.DATE_ADDED = DATE_ADDED;
        this.RELEASE_YEAR = RELEASE_YEAR;
        this.RATING = (RATING.isEmpty()) ? "NaN" : RATING;
        this.DURATION = (DURATION.isEmpty()) ? "NaN" : DURATION;
        this.LISTED_IN = (LISTED_IN.length == 0 || LISTED_IN[0].isEmpty()) ? new String[]{"NaN"} : LISTED_IN;
    }

    public String getTITLE() { return TITLE; }
    public String getDIRECTOR() { return DIRECTOR; }
    public String getSHOW_ID() { return SHOW_ID; }
    public String getTYPE() { return TYPE; }
    public String getCOUNTRY() { return COUNTRY; }
    public Date getDATE_ADDED() { return DATE_ADDED; }
    public int getRELEASE_YEAR() { return RELEASE_YEAR; }
    public String getRATING() { return RATING; }
    public String getDURATION() { return DURATION; }
    public String[] getCAST() { return CAST; }
    public String[] getLISTED_IN() { return LISTED_IN; }

    public static Show buscarPorID(String idBuscado, String caminhoArquivo) {
        try (BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))) {
            String linha = br.readLine(); // pular header
            while ((linha = br.readLine()) != null) {
                String[] dados = linha.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)", -1);
                if (dados.length < 12) continue;

                String show_id = dados[0].trim();
                if (!show_id.equalsIgnoreCase(idBuscado)) continue;

                String type = dados[1].trim().replaceAll("\"", "");
                String title = dados[2].trim().replaceAll("\"", "");
                String director = dados[3].trim().replaceAll("\"", "");
                String[] cast = (dados[4].trim().isEmpty()) ? new String[]{"NaN"} : dados[4].trim().split(", ");
                String country = dados[5].trim();

                Date dateAdded = null;
                if (!dados[6].trim().isEmpty()) {
                    try {
                        String dataLimpa = dados[6].trim().replaceAll("\"", "");
                        SimpleDateFormat formato = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH);
                        dateAdded = formato.parse(dataLimpa);
                    } catch (ParseException e) {
                        dateAdded = null;
                    }
                }

                int releaseYear = -1;
                if (!dados[7].trim().isEmpty()) {
                    try {
                        releaseYear = Integer.parseInt(dados[7].trim().replaceAll("\"", ""));
                    } catch (NumberFormatException e) {
                        releaseYear = -1;
                    }
                }

                String rating = (dados[8].trim().isEmpty()) ? "NaN" : dados[8].trim().replaceAll("\"", "");
                String duration = dados[9].trim();
                String[] listedIn = (dados[10].trim().isEmpty()) ? new String[]{"NaN"} : dados[10].trim().split(", ");

                return new Show(show_id, type, title, director, cast, country, dateAdded, releaseYear, rating, duration, listedIn);
            }
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
        }
        return null;
    }

    private enum Cor { RED, BLACK }

    private static class No {
        Show elemento;
        No esq, dir;
        Cor cor;

        public No(Show elem) {
            this.elemento = elem;
            this.cor = Cor.RED;
        }
    }

    public static class ArvoreAlvinegra {
        private No raiz;
        private int comparacoes = 0;

        private boolean isRed(No no) {
            return no != null && no.cor == Cor.RED;
        }

        private No rotacionarEsq(No h) {
            No x = h.dir;
            h.dir = x.esq;
            x.esq = h;
            x.cor = h.cor;
            h.cor = Cor.RED;
            return x;
        }

        private No rotacionarDir(No h) {
            No x = h.esq;
            h.esq = x.dir;
            x.dir = h;
            x.cor = h.cor;
            h.cor = Cor.RED;
            return x;
        }

        private void trocarCor(No h) {
            h.cor = (h.cor == Cor.RED) ? Cor.BLACK : Cor.RED;
            if (h.esq != null) h.esq.cor = (h.esq.cor == Cor.RED) ? Cor.BLACK : Cor.RED;
            if (h.dir != null) h.dir.cor = (h.dir.cor == Cor.RED) ? Cor.BLACK : Cor.RED;
        }

        public void inserir(Show show) {
            raiz = inserirRec(raiz, show);
            raiz.cor = Cor.BLACK;
        }

        private No inserirRec(No h, Show show) {
            if (h == null) return new No(show);

            comparacoes++;
            int cmp = show.getTITLE().compareTo(h.elemento.getTITLE());
            if (cmp < 0) {
                h.esq = inserirRec(h.esq, show);
            } else if (cmp > 0) {
                h.dir = inserirRec(h.dir, show);
            } 

            if (isRed(h.dir) && !isRed(h.esq)) h = rotacionarEsq(h);
            if (isRed(h.esq) && isRed(h.esq.esq)) h = rotacionarDir(h);
            if (isRed(h.esq) && isRed(h.dir)) trocarCor(h);

            return h;
        }

        public boolean pesquisar(String titulo) {
            System.out.print("=>raiz ");
            No p = raiz;
            while (p != null) {
                comparacoes++;
                if (titulo.equals(p.elemento.getTITLE())) {
                    return true;
                } else if (titulo.compareTo(p.elemento.getTITLE()) < 0) {
                    System.out.print("esq ");
                    p = p.esq;
                } else {
                    System.out.print("dir ");
                    p = p.dir;
                }
            }
            return false;
        }

        public int getComparacoes() {
            return comparacoes;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String caminhoArquivo = "/tmp/disneyplus.csv";
        ArvoreAlvinegra arvore = new ArvoreAlvinegra();

        while (true) {
            String entrada = sc.nextLine().trim();
            if (entrada.equalsIgnoreCase("FIM")) break;
            Show show = buscarPorID(entrada, caminhoArquivo);
            if (show != null) arvore.inserir(show);
        }

        long inicio = System.nanoTime();
        while (sc.hasNext()) {
            String tituloPesquisa = sc.nextLine().trim();
            if (tituloPesquisa.equalsIgnoreCase("FIM")) break;
            boolean encontrado = arvore.pesquisar(tituloPesquisa);
            System.out.println(encontrado ? "SIM" : "NAO");
        }
        long fim = System.nanoTime();

        double tempoExecucao = (fim - inicio) / 1e6;
        String matricula = "854155";

        try (PrintWriter writer = new PrintWriter(new FileWriter(matricula + "_avinegra.txt"))) {
            writer.printf("%s\t%.3f\t%d\n", matricula, tempoExecucao, arvore.getComparacoes());
        } catch (IOException e) {
            System.out.println("Erro ao escrever o log: " + e.getMessage());
        }

        sc.close();
    }
}
