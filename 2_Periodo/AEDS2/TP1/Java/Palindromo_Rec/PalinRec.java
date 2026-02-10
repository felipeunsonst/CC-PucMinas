import java.util.Scanner;

public class PalinRec {
    
    public static boolean Palindromo(String p, int inicio, int fim) {
        if (inicio >= fim) {
            return true;
        }
        if (p.charAt(inicio) != p.charAt(fim)) {
            return false; 
        }
        return Palindromo(p, inicio + 1, fim - 1); 
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        while (true) {
            String p = entrada.nextLine();
            
            if (p.equals("FIM")) {
                break; 
            }

			int tam = p.length();

            if (Palindromo(p, 0, tam- 1)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }

        entrada.close();
    }
}
