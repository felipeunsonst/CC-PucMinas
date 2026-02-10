// FELIPE COSTA UNSONST
// 854155

public class Guia_0201 {
    public static double bin2double(String binary) {
        double result = 0.0;
        int pointIndex = binary.indexOf('.');
        
        if (pointIndex == -1) {
            pointIndex = binary.length();
        }
        
        for (int i = 0; i < pointIndex; i++) {
            if (binary.charAt(i) == '1') {
                result += Math.pow(2, pointIndex - i - 1);
            }
        }
        
        for (int i = pointIndex + 1; i < binary.length(); i++) {
            if (binary.charAt(i) == '1') {
                result += Math.pow(2, -(i - pointIndex));
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        System.out.println("Guia_0201 - Tests");

        String[] binaryNumbers = {"0.00101", "0.01101", "0.10001", "1.10111", "11.11101"};
        
        for (String bin : binaryNumbers) {
            System.out.println("Binary: " + bin);
            System.out.println("Decimal: " + bin2double(bin));
            System.out.println();
        }
    }
}
