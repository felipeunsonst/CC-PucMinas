import java.io.*;
import java.text.*;
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
    public String getSHOW_ID() { return SHOW_ID; }

    public static Show buscarPorID(String idBuscado, String caminhoArquivo) {
        try (BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))) {
            String linha = br.readLine();
            while ((linha = br.readLine()) != null) {
                String[] dados = linha.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)", -1);
                if (dados.length < 11) continue;
                String show_id = dados[0].trim();
                if (!show_id.equalsIgnoreCase(idBuscado)) continue;

                String type = dados[1].trim().replaceAll("\"", "");
                String title = dados[2].trim().replaceAll("\"", "");
                String director = dados[3].trim().replaceAll("\"", "");
                String[] cast = (dados[4].trim().isEmpty()) ? new String[]{"NaN"} : dados[4].trim().split(",\\s*");
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
                String[] listedIn = (dados[10].trim().isEmpty()) ? new String[]{"NaN"} : dados[10].trim().split(",\\s*");

                return new Show(show_id, type, title, director, cast, country, dateAdded, releaseYear, rating, duration, listedIn);
            }
        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
        }
        return null;
    }

    public static void main(String[] args) throws Exception {
        long inicio = System.currentTimeMillis();

        HashRehash tabela = new HashRehash();

        Scanner sc = new Scanner(System.in);
        String caminhoArquivo = "/tmp/disneyplus.csv";

        String linha = sc.nextLine();
        while (!linha.equals("FIM")) {
            Show s = Show.buscarPorID(linha, caminhoArquivo);
            if (s != null) {
                tabela.inserir(s);
            }
            linha = sc.nextLine();
        }

        linha = sc.nextLine();
        while (!linha.equals("FIM")) {
            int[] resp = tabela.pesquisarDetalhado(linha);
            System.out.print(" (Posicao: " + resp[0] + ") ");
            System.out.println(resp[1] == 1 ? "SIM" : "NAO");
            linha = sc.nextLine();
        }

        long fim = System.currentTimeMillis();
        double tempo = (fim - inicio) / 1000.0;

        PrintWriter log = new PrintWriter("854155_hashRehash.txt");
        log.printf("854155\t%.3f\n", tempo);
        log.close();
        sc.close();
    }
}

class HashRehash {
    private Show[] tabela;
    private int tamHash = 21;

    public HashRehash() {
        tabela = new Show[tamHash];
    }

    private int hash(String title) {
        int soma = 0;
        for (int i = 0; i < title.length(); i++) {
            soma += title.charAt(i);
        }
        return soma % tamHash;
    }

    public void inserir(Show show) {
        String title = show.getTITLE();
        int soma = 0;
        for (int i = 0; i < title.length(); i++) {
            soma += title.charAt(i);
        }

        for (int i = 0; i < tamHash; i++) {
            int pos = (soma + i) % tamHash;
            if (tabela[pos] == null || tabela[pos].getTITLE().equals(title)) {
                tabela[pos] = show;
                return;
            }
        }
    }

    public int[] pesquisarDetalhado(String title) {
        int soma = 0;
        for (int i = 0; i < title.length(); i++) {
            soma += title.charAt(i);
        }

        for (int i = 0; i < tamHash; i++) {
            int pos = (soma + i) % tamHash;
            if (tabela[pos] == null) {
                return new int[] { pos, 0 };
            } else if (tabela[pos].getTITLE().equals(title)) {
                return new int[] { pos, 1 };
            }
        }
        return new int[] { -1, 0 };
    }
}
