// FELIPE COSTA UNSONST
// 854155

public class Guia_0203 {

    public static String dbin2base(int base, String binario) {
        int pontoIndex = binario.indexOf(',');
        if (pontoIndex == -1) {
            pontoIndex = binario.length();
        }
        
        String parteInteira = binario.substring(0, pontoIndex);
        String parteDecimal = binario.substring(pontoIndex + 1);

        int inteiroDecimal = Integer.parseInt(parteInteira, 2);
        String inteiroBase = Integer.toString(inteiroDecimal, base).toUpperCase();

        StringBuilder decimalBase = new StringBuilder();
        double parteDecimalDecimal = 0;
        for (int i = 0; i < parteDecimal.length(); i++) {
            if (parteDecimal.charAt(i) == '1') {
                parteDecimalDecimal += Math.pow(2, -(i + 1));
            }
        }
        
        for (int i = 0; i < 10 && parteDecimalDecimal > 0; i++) {
            parteDecimalDecimal *= base;
            int digit = (int) parteDecimalDecimal;
            decimalBase.append(Integer.toString(digit, base).toUpperCase());
            parteDecimalDecimal -= digit;
        }
        
        return inteiroBase + (decimalBase.length() > 0 ? "," + decimalBase : "");
    }
    
    public static void main(String[] args) {
        String[] binarios = {
            "0,011010",
            "0,100011",
            "0,100101",
            "1,111001",
            "1011,1101"
        };

        int[] bases = {4, 8, 16};

        System.out.println("Guia_0203 - Tests");
        for (String binario : binarios) {
            System.out.println("Número binário: " + binario);
            for (int base : bases) {
                String convertido = dbin2base(base, binario);
                System.out.printf("Base %d: %s%n", base, convertido);
            }
            System.out.println();
        }
    }
}
