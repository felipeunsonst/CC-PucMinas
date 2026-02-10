//FELIPE COSTA UNSONST
//854155

public class Guia_0101 {
    public static String dec2bin(int x) {
        return Integer.toBinaryString(x);
    }

    public static void main(String[] args) {
       
        int a = 27;   
        int b = 51;
        int c = 725;
        int d = 132;
        int e = 360;
        System.out.println("Guia_0101 - Tests");

        System.out.println("a = " + a);
        System.out.println("bin_a = " + dec2bin(a));
        System.out.println();

        System.out.println("b = " + b);
        System.out.println("bin_b = " + dec2bin(b));
        System.out.println();

        System.out.println("c = " + c);
        System.out.println("bin_c = " + dec2bin(c));
        System.out.println();

        System.out.println("d = " + d);
        System.out.println("bin_d = " + dec2bin(d));
        System.out.println();

        System.out.println("e = " + e);
        System.out.println("bin_e = " + dec2bin(e));
    }
}
