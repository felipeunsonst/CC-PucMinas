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


	//metodos setters
	public void setSHOW_ID(String SHOW_ID){this.SHOW_ID = SHOW_ID;}
	public void setTYPE(String TYPE){this.TYPE = TYPE;}
	public void setTITLE(String TITLE){this.TITLE = TITLE;}
	public void setDIRCETOR( String DIRECTOR){this.DIRECTOR = DIRECTOR;}
	public void setCAST(String[] CAST){this.CAST = CAST;}
	public void setCOUNTRY(String COUNTRY){this.COUNTRY = COUNTRY;}
	public void setDATE_ADDED(Date DATE_ADDED){this.DATE_ADDED = DATE_ADDED;}
	public void setRELEASE_YEAR(int RELEASE_YEAR){this.RELEASE_YEAR = RELEASE_YEAR;}
	public void setDURATION(String DURATION){this.DURATION = DURATION;}
	public void setRATING(String RATING){this.RATING = RATING;}
	public void setLIESTED_IN(String[] LISTED_IN){this.LISTED_IN = LISTED_IN;}

    // métodos getters
    public String getSHOW_ID() { return SHOW_ID; }
    public String getTYPE() { return TYPE; }
    public String getTITLE() { return TITLE; }
    public String getDIRECTOR() { return DIRECTOR; }
    public String[] getCAST() { return CAST; }
    public String getCOUNTRY() { return COUNTRY; }
    public Date getDATE_ADDED() { return DATE_ADDED; }
    public int getRELEASE_YEAR() { return RELEASE_YEAR; }
    public String getRATING() { return RATING; }
    public String getDURATION() { return DURATION; }
    public String[] getLISTED_IN() { return LISTED_IN; }
   
    public void imprimir() {
    SimpleDateFormat sdf = new SimpleDateFormat("MMMM d, yyyy", Locale.ENGLISH);
    String tituloFormatado = TITLE.replaceAll("\"", "");

    String[] castOrdenado = CAST.clone();
    for (int i = 0; i < castOrdenado.length; i++) {
        castOrdenado[i] = castOrdenado[i].replaceAll("\"", "");
    }
    Arrays.sort(castOrdenado, String.CASE_INSENSITIVE_ORDER);

    String[] listedInFormatado = LISTED_IN.clone();
    for (int i = 0; i < listedInFormatado.length; i++) {
        listedInFormatado[i] = listedInFormatado[i].replaceAll("\"", "");
    }

    String dataFormatada = (DATE_ADDED != null) ? sdf.format(DATE_ADDED) : "NaN";

    System.out.println("=> " + SHOW_ID + " ## " +
            tituloFormatado + " ## " +
            TYPE + " ## [" +
            DIRECTOR + "] ## [" +
            String.join(", ", castOrdenado) + "] ## " +
            COUNTRY + " ## " +
            dataFormatada + " ## " +
            RELEASE_YEAR + " ## " +
            RATING + " ## " +
            DURATION + " ## [" +
            String.join(", ", listedInFormatado) + "] ##");
}





    public Show clone() {
        return new Show(SHOW_ID, TYPE, TITLE, DIRECTOR, CAST.clone(), COUNTRY, DATE_ADDED,
                RELEASE_YEAR, RATING, DURATION, LISTED_IN.clone());
    }

	public static void countingSort(List<Show> lista, int[] comparacoes, int[] movimentacoes) {
    if (lista.isEmpty()) return;

    int minAno = Integer.MAX_VALUE;
    int maxAno = Integer.MIN_VALUE;

    for (Show s : lista) {
        int ano = s.getRELEASE_YEAR();
        if (ano < minAno) minAno = ano;
        if (ano > maxAno) maxAno = ano;
    }

    int range = maxAno - minAno + 1;
    List<List<Show>> buckets = new ArrayList<>(Collections.nCopies(range, null));

    for (int i = 0; i < range; i++) {
        buckets.set(i, new ArrayList<>());
    }

    for (Show s : lista) {
        int index = s.getRELEASE_YEAR() - minAno;
        buckets.get(index).add(s);
        movimentacoes[0]++;
    }

    lista.clear();

    for (List<Show> bucket : buckets) {
        insertionSortTitulo(bucket, comparacoes, movimentacoes);
        lista.addAll(bucket);
    }
}

// Usado para ordenar por título dentro dos buckets
private static void insertionSortTitulo(List<Show> lista, int[] comparacoes, int[] movimentacoes) {
    for (int i = 1; i < lista.size(); i++) {
        Show chave = lista.get(i);
        int j = i - 1;

        while (j >= 0) {
            comparacoes[0]++;
            String tituloAtual = lista.get(j).getTITLE().replaceAll("\"", "").toLowerCase();
            String tituloChave = chave.getTITLE().replaceAll("\"", "").toLowerCase();
            if (tituloAtual.compareTo(tituloChave) > 0) {
                lista.set(j + 1, lista.get(j));
                movimentacoes[0]++;
                j--;
            } else {
                break;
            }
        }

        lista.set(j + 1, chave);
        movimentacoes[0]++;
    }
}

	public static void gerarLog(long tempoExecucao, int comparacoes, int movimentacoes) {
	    String matricula = "854155";
	    try {
	        FileWriter arq = new FileWriter("matricula_counting.txt");
	        PrintWriter gravarArq = new PrintWriter(arq);
	        gravarArq.printf("%s\t%d\t%d\t%d\n", matricula, comparacoes, movimentacoes, tempoExecucao);
	        gravarArq.close();
	    } catch (IOException e) {
	        System.out.println("erro ao escrever o log: " + e.getMessage());
	    }
	}



    public static Show buscarPorID(String idBuscado, String caminhoArquivo) {
        try (BufferedReader br = new BufferedReader(new FileReader(caminhoArquivo))) {
            String linha = br.readLine(); 

            while ((linha = br.readLine()) != null) {
                String[] dados = linha.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
                if (dados.length < 12) continue;

                String show_id = dados[0].trim();//remove espaço no começo e no final
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
				        System.out.println("Erro ao converter DATE_ADDED: '" + dados[6] + "'");
				    }
				}



               int releaseYear = -1;
			   if (!dados[7].trim().isEmpty()) {
			       try {
			           releaseYear = Integer.parseInt(dados[7].trim().replaceAll("\"", ""));
			       } catch (NumberFormatException e) {
			           System.out.println("Erro ao converter RELEASE_YEAR: '" + dados[7] + "'");
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

    public static void main(String[] args) {
	    Scanner scanner = new Scanner(System.in);
	    String caminhoArquivo = "/tmp/disneyplus.csv";
	    List<Show> listaShows = new ArrayList<>();
	
	    while (true) {
	        String entrada = scanner.nextLine().trim();
	        if (entrada.equalsIgnoreCase("FIM")) break;
	        Show show = buscarPorID(entrada, caminhoArquivo);
	        if (show != null) {
	            listaShows.add(show);
	        }
	    }
	    scanner.close();
	
	    int[] comparacoes = {0};
	    int[] movimentacoes = {0};
	
	    long inicio = System.currentTimeMillis();
	    countingSort(listaShows, comparacoes, movimentacoes);
	    long fim = System.currentTimeMillis();
	
	    for (Show s : listaShows) {
	        s.imprimir();
	    }
	
	    gerarLog(fim - inicio, comparacoes[0], movimentacoes[0]);
	}

}
