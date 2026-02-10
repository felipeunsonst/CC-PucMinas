import java.util.Scanner;

public class ExpBoolRec {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String entrada = "";

        do {
            entrada = scanner.nextLine();
            if (!isEquals(entrada, "0")) {
                System.out.println(solveEquation(entrada) ? "1" : "0");
            }
        } while (!isEquals(entrada, "0"));

        scanner.close();
    }

    public static String treatment(String input) {
        int n = input.charAt(0) - 48;
        String expressao = removeBlank(input);
        expressao = replaceAll("and", 'a', expressao);
        expressao = replaceAll("or", 'o', expressao);
        expressao = replaceAll("not", 'n', expressao);

        for (int x = 0; x < n; x++) {
            char c = (char) ('A' + x);
            char newC = expressao.charAt(x + 1);
            expressao = replaceAll(c, newC, expressao);
        }

        return subString(expressao, n + 1, expressao.length());
    }

    public static String solveExp(String input) {
        char operation = input.charAt(0);
        switch (operation) {
            case 'a':
                for (int y = 2; y < input.length(); y++) {
                    if (input.charAt(y) == '0') return "0";
                }
                return "1";
            case 'o':
                for (int y = 2; y < input.length(); y++) {
                    if (input.charAt(y) == '1') return "1";
                }
                return "0";
            case 'n':
                return input.charAt(2) == '0' ? "1" : "0";
            default:
                return "";
        }
    }

    public static boolean solveEquation(String input) {
        return solveRecursive(treatment(input));
    }

    public static boolean solveRecursive(String expressao) {
        if (!expressao.contains("(")) {
            return isEquals(expressao, "1");
        } else {
            int start = expressao.lastIndexOf('(');
            int end = expressao.indexOf(')', start);
            String subExp = subString(expressao, start - 1, end + 1);
            String resultString = solveExp(subExp);
            expressao = subString(expressao, 0, start - 1) + resultString + subString(expressao, end + 1, expressao.length());
            return solveRecursive(expressao);
        }
    }

    public static boolean isEquals(String obj1, String obj2) {
        return obj1.equals(obj2);
    }

    public static String subString(String s, int start, int end) {
        return s.substring(start, Math.min(end, s.length()));
    }

    public static String removeBlank(String input) {
        return input.replaceAll("\\s+", "");
    }

    public static String replaceAll(Object base, char newChar, String input) {
        return input.replace(base.toString(), Character.toString(newChar));
    }
}
