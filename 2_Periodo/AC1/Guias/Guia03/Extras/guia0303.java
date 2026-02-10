//Felipe Costa Unsonst
//854155

public class ComplementCalculator {
    public static void main(String[] args) {
        String a = "10101";  
        String b = "110101"; 
        String c = "00110";  
        String d = "010111"; 
        String e = "110101"; 

        System.out.printf("a = %s -> C2(a) = %s = %d%n", a, C2(a), sbin2dec(C2(a)));
        System.out.printf("b = %s -> C2(b) = %s = %d%n", b, C2(b), sbin2dec(C2(b)));
        System.out.printf("c = %s -> C2(c) = %s = %d%n", c, C2(c), sbin2dec(C2(c)));
        System.out.printf("d = %s -> C2(d) = %s = %d%n", d, C2(d), sbin2dec(C2(d)));
        System.out.printf("e = %s -> C2(e) = %s = %d%n", e, C2(e), sbin2dec(C2(e)));
    }

    public static String C2(String x) {
        int num = Integer.parseInt(x, 2);
        int nbits = x.length();
        int mask = (1 << nbits) - 1; 
        int complement1 = ~num & mask;
        int complement2 = (complement1 + 1) & mask; 
        return String.format("%" + nbits + "s", Integer.toBinaryString(complement2)).replace(' ', '0');
    }

    public static int sbin2dec(String x) {
        int num = Integer.parseInt(x, 2);
        if (x.charAt(0) == '1') { 
            int mask = (1 << x.length()) - 1;
            num = num - (mask + 1); 
        }
        return num;
    }
}
