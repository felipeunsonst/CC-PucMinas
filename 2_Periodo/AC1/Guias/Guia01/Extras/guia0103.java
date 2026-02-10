//FELIPE COSTA UNSONST
//854155

public class Guia_0103 {
    public static String dec2bin(int x) {
        return Integer.toBinaryString(x);
    }

    public static String dec2quaternary(int x) {
        return Integer.toString(x, 4);
    }

    public static String dec2octal(int x) {
        return Integer.toOctalString(x);
    }

    public static String dec2hex(int x) {
        return Integer.toHexString(x);
    }

    public static void main(String[] args) {
        int a = 54;   
        int b = 67;   
        int c = 76;   
        int d = 157;  
        int e = 731;  

        System.out.println("Guia_0103 - Tests");

        System.out.println("a (decimal) = " + a);
        System.out.println("a (quaternary) = " + dec2quaternary(a));
        System.out.println();

        System.out.println("b (decimal) = " + b);
        System.out.println("b (octal) = " + dec2octal(b));
        System.out.println();

        System.out.println("c (decimal) = " + c);
        System.out.println("c (hexadecimal) = " + dec2hex(c));
        System.out.println();

        System.out.println("d (decimal) = " + d);
        System.out.println("d (hexadecimal) = " + dec2hex(d));
        System.out.println();

        System.out.println("e (decimal) = " + e);
        System.out.println("e (hexadecimal) = " + dec2hex(e));
    }
}
