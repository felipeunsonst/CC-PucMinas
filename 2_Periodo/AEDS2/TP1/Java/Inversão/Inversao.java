import java.util.Scanner;

public class Inversao {
    public static String retorna(String in) {
        int tam = in.length();
        StringBuilder nova = new StringBuilder(in); 
        
        for (int i = 0; i < tam / 2; i++) {
            char temp = nova.charAt(i);
            nova.setCharAt(i, nova.charAt(tam - i - 1));
            nova.setCharAt(tam - i - 1, temp);
        }

        return nova.toString();
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        while (true) {
            String in = entrada.nextLine();

            if (in.equals("FIM")) {
                break;
            }

            String nova = retorna(in);
            System.out.println(nova);
        }
        
        entrada.close();
    }
}
