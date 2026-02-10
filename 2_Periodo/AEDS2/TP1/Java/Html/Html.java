import java.io.*;
import java.net.*;

public class Html {
    static final char[] caracteresEspeciais = {
        225, 233, 237, 243, 250, 224, 232, 236, 242, 249,
        227, 245, 226, 234, 238, 244, 251
    };

    static int[] vogais;

    public static void main(String[] args) {
        MyIO.setCharset("UTF-8");
        String titulo = "";
        String url = "";
        String conteudoHtml = "";
        int qtdConsoantes = 0, qtdBr = 0, qtdTabelas = 0;

        do {
            titulo = MyIO.readLine();
            if (!verificaFim(titulo)) {
                url = MyIO.readLine();
                conteudoHtml = obterHtml(url);

                contarVogais(conteudoHtml);
                qtdConsoantes = contarConsoantes(conteudoHtml);
                qtdBr = contarBr(conteudoHtml);
                qtdTabelas = contarTabelas(conteudoHtml);

                vogais[0] -= qtdTabelas;
                vogais[1] -= qtdTabelas;
                qtdConsoantes -= (2 * qtdBr + 3 * qtdTabelas);

                imprimirResultados();
                System.out.printf("consoante(%s) ", qtdConsoantes);
                System.out.printf("<br>(%s) ", qtdBr);
                System.out.printf("<table>(%s) ", qtdTabelas);
                System.out.printf("%s\n", titulo);
            }
        } while (!verificaFim(titulo));
    }

    public static boolean verificaFim(String texto) {
        return texto.equals("FIM");
    }

    public static void contarVogais(String html) {
        vogais = new int[23];
        for (char c : html.toCharArray()) {
            if (c == 'a') vogais[0]++;
            else if (c == 'e') vogais[1]++;
            else if (c == 'i') vogais[2]++;
            else if (c == 'o') vogais[3]++;
            else if (c == 'u') vogais[4]++;
            else if (ehEspecial(c)) {
                for (int i = 0; i < caracteresEspeciais.length; i++) {
                    if (c == caracteresEspeciais[i]) {
                        vogais[i + 5]++;
                        break;
                    }
                }
            }
        }
    }

    public static boolean ehEspecial(char c) {
        for (char especial : caracteresEspeciais) {
            if (c == especial) return true;
        }
        return false;
    }

    public static int contarConsoantes(String html) {
        int contador = 0;
        String consoantes = "bcdfghjklmnpqrstvwxyz";
        for (char consoante : consoantes.toCharArray()) {
            for (char caractere : html.toCharArray()) {
                if (caractere == consoante) contador++;
            }
        }
        return contador;
    }

    public static int contarBr(String html) {
        return contarOcorrencias(html, "<br>");
    }

    public static int contarTabelas(String html) {
        return contarOcorrencias(html, "<table>");
    }

    public static int contarOcorrencias(String texto, String termo) {
        int contador = 0;
        for (int i = 0; i <= texto.length() - termo.length(); i++) {
            if (texto.substring(i, i + termo.length()).equals(termo)) contador++;
        }
        return contador;
    }

    public static void imprimirResultados() {
        char[] vogaisBase = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < 5; i++) {
            System.out.printf("%c(%s) ", vogaisBase[i], vogais[i]);
        }
        for (int i = 0; i < caracteresEspeciais.length; i++) {
            System.out.printf("%c(%s) ", caracteresEspeciais[i], vogais[i + 5]);
        }
    }

    public static String obterHtml(String endereco) {
        StringBuilder resposta = new StringBuilder();
        try {
            URL url = new URL(endereco);
            try (BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()))) {
                String linha;
                while ((linha = br.readLine()) != null) {
                    resposta.append(linha).append("\n");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return resposta.toString();
    }
}
