import java.text.Normalizer;
import java.util.Scanner;

public class Anagrama {
    
    public static boolean saoAnagramas(String a, String b) {
        if (a.length() != b.length()) {
            return false; 
        }

        int[] contagem = new int[256]; 

        for (int i = 0; i < a.length(); i++) {
            contagem[a.charAt(i)]++; 
            contagem[b.charAt(i)]--; 
        }

        for (int valor : contagem) {
            if (valor != 0) {
                return false;
            }
        }

        return true; 
    }

    public static String tratarString(String texto) {
        return Normalizer.normalize(texto.toLowerCase(), Normalizer.Form.NFD)
                         .replaceAll("[^a-z]", ""); 
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        while (true) {
            String linha = entrada.nextLine().trim();

            if (linha.equalsIgnoreCase("FIM")) {
                break; 
            }

            String[] palavras = linha.split("[- ]+");

            String palavra1 = tratarString(palavras[0]);
            String palavra2 = tratarString(palavras[1]);

            if (saoAnagramas(palavra1, palavra2)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }

        entrada.close();
    }
}
