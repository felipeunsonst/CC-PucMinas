import java.util.Scanner;

public class CifraRec {
    public static String cifras(String cif, int indice) {
        if (indice == cif.length()) {
            return ""; 
        }

        char c = cif.charAt(indice);
        String vogaisAcentuadas = "áãâéêíîóõôúû";
        
        char novoChar;
        if (vogaisAcentuadas.contains(String.valueOf(c))) {
            novoChar = c; 
        } else {
            novoChar = (char) (c + 3); 
        }

        return novoChar + cifras(cif, indice + 1);
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        while (true) {
            String cif = entrada.nextLine();

            if (cif.equals("FIM")) {
                break;
            }

            String nova = cifras(cif, 0); 
            System.out.println(nova);
        }

        entrada.close();
    }
}
