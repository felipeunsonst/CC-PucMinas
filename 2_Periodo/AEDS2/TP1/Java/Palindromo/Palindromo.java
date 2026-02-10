import java.util.Scanner;

public class Palindromo {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in); 
        
        do {
            String p = entrada.nextLine();
            
            if (p.equals("FIM")) {  
                break;  
            }

            int tam = p.length(); 
            boolean pali = true;

            for (int i = 0; i < tam / 2; i++) {  
                if (p.charAt(i) != p.charAt(tam - i - 1)) {  //funciona como um array[i] e array[tam-i-1]
                    pali = false;
                    break;  
                }
            }

            if (pali) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }

        } while (true);  

        entrada.close(); 
    }
}
