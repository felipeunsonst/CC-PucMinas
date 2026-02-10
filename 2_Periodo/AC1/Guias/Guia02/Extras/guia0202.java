// FELIPE COSTA UNSONST
// 854155

public class Guia_0202 {

    public static String double2bin(double numero) {
        int parteInteira = (int) numero;
        double parteDecimal = numero - parteInteira;

        StringBuilder binarioInteiro = new StringBuilder();
        if (parteInteira == 0) {
            binarioInteiro.append("0");
        } else {
            while (parteInteira > 0) {
                binarioInteiro.insert(0, parteInteira % 2);
                parteInteira /= 2;
            }
        }

        binarioInteiro.append(",");

        StringBuilder binarioDecimal = new StringBuilder();
        while (parteDecimal > 0 && binarioDecimal.length() < 10) { 
            parteDecimal *= 2;
            if (parteDecimal >= 1) {
                binarioDecimal.append("1");
                parteDecimal -= 1;
            } else {
                binarioDecimal.append("0");
            }
        }
        
        return binarioInteiro.append(binarioDecimal).toString();
    }

    public static double bin2double(String binario) {
        double result = 0.0;
        int pointIndex = binario.indexOf(',');

        if (pointIndex == -1) {
            pointIndex = binario.length();
        }

        for (int i = 0; i < pointIndex; i++) {
            if (binario.charAt(i) == '1') {
                result += Math.pow(2, pointIndex - i - 1);
            }
        }

        for (int i = pointIndex + 1; i < binario.length(); i++) {
            if (binario.charAt(i) == '1') {
                result += Math.pow(2, -(i - pointIndex));
            }
        }

        return result;
    }

    public static void main(String[] args) {
        String[] binarios = {
            "0,101",
            "1,11",
            "11,001",
            "100,0101",
            "111,111"
        };

        System.out.println("Guia_0202 - Tests");
        for (String binario : binarios) {
            double decimal = bin2double(binario);
            System.out.printf("%s em decimal é %.6f%n", binario, decimal);
        }
    }
}
