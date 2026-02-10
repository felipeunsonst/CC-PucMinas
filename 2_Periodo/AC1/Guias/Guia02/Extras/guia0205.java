// FELIPE COSTA UNSONST
// 854155

public class Guia_0205 {
    public static double bin2double(String binario) {
        double result = 0.0;
        int pointIndex = binario.indexOf('.');
        
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
        
        binarioInteiro.append(".");
        
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

    public static String add(String bin1, String bin2) {
        double dec1 = bin2double(bin1);
        double dec2 = bin2double(bin2);
        double sum = dec1 + dec2;
        return double2bin(sum);
    }

    public static String subtract(String bin1, String bin2) {
        double dec1 = bin2double(bin1);
        double dec2 = bin2double(bin2);
        double difference = dec1 - dec2;
        return double2bin(difference);
    }

    public static String multiply(String bin1, String bin2) {
        double dec1 = bin2double(bin1);
        double dec2 = bin2double(bin2);
        double product = dec1 * dec2;
        return double2bin(product);
    }

    public static String divide(String bin1, String bin2) {
        double dec1 = bin2double(bin1);
        double dec2 = bin2double(bin2);
        double quotient = dec1 / dec2;
        return double2bin(quotient);
    }

    public static String modulo(String bin1, String bin2) {
        double dec1 = bin2double(bin1);
        double dec2 = bin2double(bin2);
        double remainder = dec1 % dec2;
        return double2bin(remainder);
    }

    public static void main(String[] args) {
        System.out.println("Guia_0205 - Tests");

        String bin1, bin2;

        bin1 = "101.01";
        bin2 = "10.011";
        System.out.printf("%s + %s = %s%n", bin1, bin2, add(bin1, bin2));

        bin1 = "1000.001";
        bin2 = "10.01";
        System.out.printf("%s - %s = %s%n", bin1, bin2, subtract(bin1, bin2));

        bin1 = "101.110";
        bin2 = "10.001";
        System.out.printf("%s * %s = %s%n", bin1, bin2, multiply(bin1, bin2));

        bin1 = "10110.01";
        bin2 = "11.011";
        System.out.printf("%s / %s = %s%n", bin1, bin2, divide(bin1, bin2));

        bin1 = "1101101";
        bin2 = "1011";
        System.out.printf("%s %% %s = %s%n", bin1, bin2, modulo(bin1, bin2));
    }
}
