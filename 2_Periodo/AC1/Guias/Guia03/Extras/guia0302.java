//Felipe Costa Unsonst
//854155

public class ComplementCalculator {
    public static void main(String[] args) {
        String a = "123"; 
        String b = "C4"; 
        String c = "312"; 
        String d = "153"; 
        String e = "7D";  

        System.out.printf("a = %s (base 4) -> C1(a) = %s -> C2(a) = %s%n", a, C1(6, a, 4), C2(6, a, 4));
        System.out.printf("b = %s (base 16) -> C1(b) = %s -> C2(b) = %s%n", b, C1(8, b, 16), C2(8, b, 16));
        System.out.printf("c = %s (base 4) -> C1(c) = %s -> C2(c) = %s%n", c, C1(6, c, 4), C2(6, c, 4));
        System.out.printf("d = %s (base 8) -> C1(d) = %s -> C2(d) = %s%n", d, C1(10, d, 8), C2(10, d, 8));
        System.out.printf("e = %s (base 16) -> C1(e) = %s -> C2(e) = %s%n", e, C1(8, e, 16), C2(8, e, 16));
    }

    public static String C1(int nbits, String x, int basex) {
        int num = Integer.parseInt(x, basex);
        int mask = (1 << nbits) - 1; 
        return String.format("%" + nbits + "s", Integer.toBinaryString(~num & mask)).replace(' ', '0');
    }

    public static String C2(int nbits, String x, int basex) {
        int num = Integer.parseInt(x, basex);
        int complement1 = Integer.parseInt(C1(nbits, x, basex), 2);
        int complement2 = (complement1 + 1) & ((1 << nbits) - 1); 
        return String.format("%" + nbits + "s", Integer.toBinaryString(complement2)).replace(' ', '0');
    }
}
