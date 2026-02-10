// FELIPE COSTA UNSONST
// 854155

public class Guia_0204 {

    public static double baseToDecimal(String numero, int base) {
        int pointIndex = numero.indexOf(',');
        if (pointIndex == -1) {
            pointIndex = numero.length();
        }

        double decimal = 0.0;
        for (int i = 0; i < pointIndex; i++) {
            char digit = numero.charAt(i);
            int value = Character.isDigit(digit) ? digit - '0' : digit - 'A' + 10;
            decimal = decimal * base + value;
        }

        for (int i = pointIndex + 1; i < numero.length(); i++) {
            char digit = numero.charAt(i);
            int value = Character.isDigit(digit) ? digit - '0' : digit - 'A' + 10;
            decimal += value / Math.pow(base, i - pointIndex);
        }

        return decimal;
    }

    public static String decimalToBase(double decimal, int base) {
        int inteiro = (int) decimal;
        double fracao = decimal - inteiro;

        StringBuilder result = new StringBuilder();
        if (inteiro == 0) {
            result.append("0");
        } else {
            while (inteiro > 0) {
                int remainder = inteiro % base;
                result.insert(0, remainder < 10 ? (char) (remainder + '0') : (char) (remainder - 10 + 'A'));
                inteiro /= base;
            }
        }

        result.append(",");

        int count = 0;
        while (fracao > 0 && count < 10) {
            fracao *= base;
            int digit = (int) fracao;
            result.append(digit < 10 ? (char) (digit + '0') : (char) (digit - 10 + 'A'));
            fracao -= digit;
            count++;
        }

        return result.toString();
    }

    public static String baseToBase(String numero, int baseInicial, int baseFinal) {
        double decimal = baseToDecimal(numero, baseInicial);
        return decimalToBase(decimal, baseFinal);
    }

    public static void main(String[] args) {
        String[] numeros = {
            "0,231",
            "0,5C2",
            "0,735",
            "6,2345",
            "B,A5E"
        };

        int[] basesIniciais = {4, 16, 8, 8, 16};
        int[] basesFinais = {2, 4, 2, 4, 4};

        System.out.println("Guia_0204 - Tests");
        for (int i = 0; i < numeros.length; i++) {
            String numero = numeros[i];
            int baseInicial = basesIniciais[i];
            int baseFinal = basesFinais[i];
            String convertido = baseToBase(numero, baseInicial, baseFinal);
            System.out.printf("%s (base %d) = %s (base %d)%n", numero, baseInicial, convertido, baseFinal);
        }
    }
}
