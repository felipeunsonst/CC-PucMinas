import java.util.Scanner;
import java.util.Random;

public class Aleatorio {

    public static String ale(String al) {
        int tam = al.length();
        StringBuilder nova = new StringBuilder(al); 
        Random random = new Random();
  
        char letra1;
        do {
            letra1 = al.charAt(random.nextInt(tam));
        } while (!Character.isLowerCase(letra1));

        char letra2 = (char) (random.nextInt(26) + 97); 

        for (int i = 0; i < tam; i++) {
            if (nova.charAt(i) == letra1) {
                nova.setCharAt(i, letra2); 
            }
        }

        return nova.toString();
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        while (true) {
            String al = entrada.nextLine();

            if (al.equals("FIM")) {
                break;
            }

            String nova = ale(al); 
            System.out.println(" " + nova);
        }

        entrada.close();
    }
}
