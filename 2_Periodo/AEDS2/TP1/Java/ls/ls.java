import java.util.Scanner;

public class ls {

    public static boolean um(String l) {
        int tam = l.length();
        for (int i = 0; i < tam; i++) {
            char c = l.charAt(i);
            if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                  c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
                return false;
            }
        }
        return true;
    }

    public static boolean dois(String l) {
        int tam = l.length();
        for (int i = 0; i < tam; i++) {
            char c = l.charAt(i);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c>='0' && c<='9') {
                return false;
            }
        }
        return true;
    }

    public static boolean tres(String l) {
        int tam = l.length();
        for (int i = 0; i < tam; i++) {
            if (!(l.charAt(i) >= '0' && l.charAt(i) <= '9')) {
                return false;
            }
        }
        return true;
    }

    public static boolean quatro(String l) {
        int tam = l.length();
        int count = 1;
		for (int i = 0; i < tam; i++) {
            char c = l.charAt(i);
            if(c == '.' || c == ','){
				count++;
			}
			if (!(c >= '0' && c <= '9')){
                return false;
            }
			if(count!=2){
				return false;
			}
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        while (true) {
            String palavra = entrada.nextLine();

            if (palavra.equals("FIM")) {
                break;
            }

            if (um(palavra)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }

            if (dois(palavra)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }

            if (tres(palavra)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }

            if (quatro(palavra)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
        }

        entrada.close();
    }
}
