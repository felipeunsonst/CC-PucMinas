//Felipe Costa Unsonst
//854155

public class ComplementCalculator {

    public static void main(String[] args) {
        int a = 0b0001010; 
        int b = 0b0000101; 
        int c = 0b001010;  

        System.out.printf("a = %8s -> C1(a) = %8s -> C2(a) = %8s%n", Integer.toBinaryString(a), C1(8, a), C2(8, a));
        System.out.printf("b = %7s -> C1(b) = %7s -> C2(b) = %7s%n", Integer.toBinaryString(b), C1(7, b), C2(7, b));
        System.out.printf("c = %6s -> C1(c) = %6s -> C2(c) = %6s%n", Integer.toBinaryString(c), C1(6, c), C2(6, c));
    }

    public static String C1(int nbits, int x) {
        int mask = (1 << nbits) - 1;
        return String.format("%" + nbits + "s", Integer.toBinaryString(~x & mask)).replace(' ', '0');
    }

    public static String C2(int nbits, int x) {
        int complement1 = Integer.parseInt(C1(nbits, x), 2);
        int complement2 = (complement1 + 1) & ((1 << nbits) - 1); 
        return String.format("%" + nbits + "s", Integer.toBinaryString(complement2)).replace(' ', '0');
    }
}
