import java.util.Scanner;

public class LsRec {
    
    public static boolean ehVogal(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        } else {
            return false;
        }
    }
    
    public static boolean um(String l, int index) {
        if (index == l.length()) {
            return true;
        } else {
            if (!ehVogal(l.charAt(index))) {
                return false;
            } else {
                return um(l, index + 1);
            }
        }
    }
    
    public static boolean dois(String l, int index) {
        if (index == l.length()) {
            return true;
        } else {
            char c = l.charAt(index);
            if (ehVogal(c) || (c >= '0' && c <= '9')) {
                return false;
            } else {
                return dois(l, index + 1);
            }
        }
    }
    
    public static boolean tres(String l, int index) {
        if (index == l.length()) {
            return true;
        } else {
            if (!(l.charAt(index) >= '0' && l.charAt(index) <= '9')) {
                return false;
            } else {
                return tres(l, index + 1);
            }
        }
    }
    
    public static boolean quatro(String l, int index, int count) {
        if (index == l.length()) {
            return count == 2;
        } else {
            char c = l.charAt(index);
            if (c == '.' || c == ',') {
                count++;
            }
            if (!(c >= '0' && c <= '9') && c != '.' && c != ',') {
                return false;
            } else {
                return quatro(l, index + 1, count);
            }
        }
    }
    
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        while (true) {
            String palavra = entrada.nextLine();
            if (palavra.equals("FIM")) {
                break;
            }
            
            if (um(palavra, 0)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }
            
            if (dois(palavra, 0)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }
            
            if (tres(palavra, 0)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }
            
            if (quatro(palavra, 0, 1)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }
        entrada.close();
    }
}
