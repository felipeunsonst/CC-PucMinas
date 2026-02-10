//FELIPE COSTA UNSONST
//854155

public class Guia_0102 {
    public static int bin2dec(String x) {
        return Integer.parseInt(x, 2);
    }

    public static void main(String[] args) {
        String a = "10011";  
        String b = "10101";
        String c = "10110";
        String d = "110010";
        String e = "111011";

        System.out.println("Guia_0102 - Tests");

        System.out.println("a = " + a);
        System.out.println("dec_a = " + bin2dec(a));
        System.out.println();

        System.out.println("b = " + b);
        System.out.println("dec_b = " + bin2dec(b));
        System.out.println();

        System.out.println("c = " + c);
        System.out.println("dec_c = " + bin2dec(c));
        System.out.println();

        System.out.println("d = " + d);
        System.out.println("dec_d = " + bin2dec(d));
        System.out.println();

        System.out.println("e = " + e);
        System.out.println("dec_e = " + bin2dec(e));
    }
}
