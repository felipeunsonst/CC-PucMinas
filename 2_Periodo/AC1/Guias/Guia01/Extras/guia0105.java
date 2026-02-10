//FELIPE COSTA UNSONST
//854155

public class Guia_0105 {

    public static String ASCII2hex(String asciiStr) {
        StringBuilder hex = new StringBuilder();
        for (int i = 0; i < asciiStr.length(); i++) {
            hex.append(Integer.toHexString(asciiStr.charAt(i)));
        }
        return hex.toString();
    }

    public static String hex2ASCII(String hexStr) {
        StringBuilder output = new StringBuilder();
        for (int i = 0; i < hexStr.length(); i += 2) {
            String str = hexStr.substring(i, i + 2);
            output.append((char) Integer.parseInt(str, 16));
        }
        return output.toString();
    }

    public static void main(String[] args) {
        // Definindo as strings de teste
        String str1 = "PUC-Minas";
        String str2 = "2025-01";
        String str3 = "Belo Horizonte - M.G.";
        
        // Converta as strings para hexadecimal ASCII
        System.out.println("Guia_0101 - Tests");

        System.out.println("PUC-Minas = " + ASCII2hex(str1) + " (16_ASCII)");
        System.out.println("2025-01 = " + ASCII2hex(str2) + " (16_ASCII)");
        System.out.println("Belo Horizonte - M.G. = " + ASCII2hex(str3) + " (2_ASCII)");

        // Converte octal e hexadecimal para ASCII
        String octalStr = "156 157 151 164 145";
        String hexStr = "4D 61 6E 68 61";

        // Utilizando os métodos para conversão
        String asciiFromOctal = octalToASCII(octalStr);
        String asciiFromHex = hex2ASCII(hexStr.replaceAll(" ", ""));

        System.out.println("156 157 151 164 145 (8) = " + asciiFromOctal);
        System.out.println("4D 61 6E 68 61 (16) = " + asciiFromHex);
    }

    public static String octalToASCII(String octalStr) {
        String[] octalVals = octalStr.split(" ");
        StringBuilder output = new StringBuilder();
        for (String oct : octalVals) {
            int decimal = Integer.parseInt(oct, 8);
            output.append((char) decimal);
        }
        return output.toString();
    }
}
