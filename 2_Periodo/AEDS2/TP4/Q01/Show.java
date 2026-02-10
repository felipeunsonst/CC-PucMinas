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
            String linha = br.readLine();
            while ((linha = br.readLine()) != null) {
                String[] dados = linha.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
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

                    }
                }

                int releaseYear = -1;
                if (!dados[7].trim().isEmpty()) {
                    try {
                        releaseYear = Integer.parseInt(dados[7].trim().replaceAll("\"", ""));
                    } catch (NumberFormatException e) {

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

    static class No {
        Show elemento;
        No esquerda, direita;

        public No(Show elemento) {
            this.elemento = elemento;
            this.esquerda = null;
            this.direita = null;
        }
    }

    static class ArvoreBinaria {
        private No raiz;
        private int comparacoes = 0;

        public void inserir(Show show) throws Exception {
            raiz = inserir(show, raiz);
        }

        private No inserir(Show show, No no) throws Exception {
            if (no == null) {
                return new No(show);
            } else if (show.getTITLE().compareTo(no.elemento.getTITLE()) < 0) {
                comparacoes++;
                no.esquerda = inserir(show, no.esquerda);
            } else if (show.getTITLE().compareTo(no.elemento.getTITLE()) > 0) {
                comparacoes++;
                no.direita = inserir(show, no.direita);
            } else {
                comparacoes++;
            }
            return no;
        }

        public boolean pesquisar(String titulo) {
            System.out.print("=>raiz ");
            return pesquisar(titulo, raiz);
        }

        private boolean pesquisar(String titulo, No no) {
            boolean resp;
            if (no == null) {
                resp = false;
            } else if (titulo.equals(no.elemento.getTITLE())) {
                comparacoes++;
                resp = true;
            } else if (titulo.compareTo(no.elemento.getTITLE()) < 0) {
                comparacoes++;
                System.out.print("esq ");
                resp = pesquisar(titulo, no.esquerda);
            } else {
                comparacoes++;
                System.out.print("dir ");
                resp = pesquisar(titulo, no.direita);
            }
            return resp;
        }

        public int getComparacoes() {
            return comparacoes;
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String caminhoArquivo = "/tmp/disneyplus.csv";
        ArvoreBinaria arvore = new ArvoreBinaria();

        while (true) {
            String entrada = sc.nextLine().trim();
            if (entrada.equalsIgnoreCase("FIM")) break;
            Show show = buscarPorID(entrada, caminhoArquivo);
            if (show != null) {
                try {
                    arvore.inserir(show);
                } catch (Exception e) {
        
                }
            }
        }

        long inicio = System.nanoTime();
        while (sc.hasNext()) {
            String tituloPesquisa = sc.nextLine().trim();
            if (tituloPesquisa.equalsIgnoreCase("FIM")) break;
            boolean encontrado = arvore.pesquisar(tituloPesquisa);
            if (encontrado) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }
        long fim = System.nanoTime();

        double tempoExecucao = (fim - inicio) / 1e6; 
        String matricula = "854155";

        try (PrintWriter writer = new PrintWriter(new FileWriter(matricula + "_arvoreBinaria.txt"))) {
            writer.printf("%s\t%.3f\t%d\n", matricula, tempoExecucao, arvore.getComparacoes());
        } catch (IOException e) {
            System.out.println("Erro ao escrever o log: " + e.getMessage());
        }

        sc.close();
    }
}
