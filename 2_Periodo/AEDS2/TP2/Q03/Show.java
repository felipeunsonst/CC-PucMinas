import java.io.BufferedReader;
import java.io.FileReader;
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
		    SimpleDateFormat sdf = new SimpleDateFormat("MMMM dd, yyyy", Locale.ENGLISH);
		    String tituloFormatado = TITLE.replaceAll("\"", "");
		    String castFormatado;
			    if (CAST.length == 1 && CAST[0].equals("NaN")) {
			        castFormatado = "[NaN]";
			    } else {
			        castFormatado = (CAST.length > 1) ? "[" + String.join(", ", CAST) + "]" : CAST[0];
			    }
		    String[] listedInLimpo = Arrays.stream(LISTED_IN).map(s -> s.replaceAll("\"", "")).toArray(String[]::new);

		    String listedInFormatado;
		    if (listedInLimpo.length == 1 && listedInLimpo[0].equals("NaN")) {
		        listedInFormatado = "[NaN]";
		    } else {
		        listedInFormatado = (listedInLimpo.length > 1) ? "[" + String.join(", ", listedInLimpo) + "]" : listedInLimpo[0];
		    }
		
		    System.out.println("=>" + SHOW_ID + " ## " +
		            tituloFormatado + " ## " +
		            TYPE + " ## " +
		            DIRECTOR + " ## " +
		            castFormatado + " ## " +
		            COUNTRY + " ## " +
		            (DATE_ADDED != null ? sdf.format(DATE_ADDED) : "NaN") + " ## " +
		            RELEASE_YEAR + " ## " +
		            RATING + " ## " +
		            DURATION + " ## " +
		            listedInFormatado + " ## ");
	}



    public Show clone() {
        return new Show(SHOW_ID, TYPE, TITLE, DIRECTOR, CAST.clone(), COUNTRY, DATE_ADDED,
                RELEASE_YEAR, RATING, DURATION, LISTED_IN.clone());
    }

    static int comparacoes = 0;

    public static List<Show> carregarPorIds(String caminho, List<String> idsDesejados) {
        List<Show> showsSelecionados = new ArrayList<>();
        try (BufferedReader br = new BufferedReader(new FileReader(caminho))) {
            String linha = br.readLine(); // pula o cabeçalho
            while ((linha = br.readLine()) != null) {
                String[] dados = linha.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)");
                if (dados.length < 12) continue;

                String show_id = dados[0].trim();
                if (!idsDesejados.contains(show_id)) continue;

                String type = dados[1].trim();
                String title = dados[2].trim();
                String director = dados[3].trim();
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
                    } catch (NumberFormatException e) {}
                }

                String rating = dados[8].trim();
                String duration = dados[9].trim();
                String[] listedIn = (dados[10].trim().isEmpty()) ? new String[]{"NaN"} : dados[10].trim().split(", ");

                Show show = new Show(show_id, type, title, director, cast, country, dateAdded, releaseYear, rating, duration, listedIn);
                showsSelecionados.add(show);
            }

        } catch (IOException e) {
            System.out.println("Erro ao ler o arquivo: " + e.getMessage());
        }

        return showsSelecionados;
    }

	public static boolean buscarSequencialTitulo(String titulo, List<Show> lista) {
        for (Show show : lista) {
            comparacoes++;
            if (show.getTITLE().equalsIgnoreCase(titulo)) {
                return true;
            }
        }
        return false;
    }



   public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String caminhoCSV = "/tmp/disneyplus.csv";
        List<String> ids = new ArrayList<>();

        while (true) {
            String entrada = sc.nextLine().trim();
            if (entrada.equalsIgnoreCase("FIM")){
				break;
			}
            ids.add(entrada);
        }

        List<Show> vetor = carregarPorIds(caminhoCSV, ids);

        List<String> titulosBusca = new ArrayList<>();
        while (true) {
            String entrada = sc.nextLine().trim();
            if (entrada.equalsIgnoreCase("FIM")){
				break;
			}
            titulosBusca.add(entrada);
        }

        long inicio = System.nanoTime();

        for (String titulo : titulosBusca) {
            boolean achou = buscarSequencialTitulo(titulo, vetor);
            System.out.println(achou ? "SIM" : "NAO");
        }

        long fim = System.nanoTime();
        double tempo = (fim - inicio) / 1e6; 

        String matricula = "854155";
        try (PrintWriter log = new PrintWriter("854155_sequencial.txt")) {
            log.println(matricula + "\t" + tempo + "\t" + comparacoes);
        } catch (IOException e) {
            System.out.println("Erro ao escrever log.");
        }

        sc.close();
    }
}
