//Felipe Costa Unsonst
//854155
public class BaseOperations {
    public static void main(String[] args) {
        System.out.println("a: " + baseEval("11101", "-", "1101", 2) + " = 0");
        System.out.println("b: " + baseEval("101.1001", "-", "10.01", 2) + " = " + baseEval("101.1001", "+", "01.1100", 2));
        System.out.println("c: " + baseEval("321", "-", "213", 4) + " = " + baseEval("110101", "+", "011001", 2));
        System.out.println("d: " + baseEval("354", "-", "265", 8) + " = " + baseEval("011101100", "+", "101001011", 2));
        System.out.println("e: " + baseEval("6A2", "-", "C14", 16) + " = " + baseEval("011010100010", "+", "001111101100", 2));
    }

    public static String baseEval(String x, String op, String y, int base) {
        int num1 = Integer.parseInt(x.replace(".", ""), base);
        int num2 = Integer.parseInt(y.replace(".", ""), base);
        int result;

        if (op.equals("-")) {
            result = num1 + (~num2 + 1); 
        } else if (op.equals("+")) {
            result = num1 + num2;
        } else {
            throw new IllegalArgumentException("Operation not supported.");
        }

        if (x.contains(".") || y.contains(".")) {
            String[] partsX = x.split("\\.");
            String[] partsY = y.split("\\.");
            int fractionalLength = Math.max(partsX.length > 1 ? partsX[1].length() : 0, partsY.length > 1 ? partsY[1].length() : 0);
            String binaryString = Integer.toBinaryString(result);
            return binaryString.substring(0, binaryString.length() - fractionalLength) + "." + binaryString.substring(binaryString.length() - fractionalLength);
        }

        return Integer.toString(result, base);
    }
}
