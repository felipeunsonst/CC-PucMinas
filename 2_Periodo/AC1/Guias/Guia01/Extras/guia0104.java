//FELIPE COSTA UNSONST
//854155

public class Guia_0104 {
    public static int bin2dec(String bin) {
        return Integer.parseInt(bin, 2);
    }

    public static void main(String[] args) {
        String bin1 = "10110"; 
        String bin2 = "11011"; 
        String bin3 = "100100"; 
        String bin4 = "101011"; 
        String bin5 = "101100"; 

        int dec1 = bin2dec(bin1);
        int dec2 = bin2dec(bin2);
        int dec3 = bin2dec(bin3);
        int dec4 = bin2dec(bin4);
        int dec5 = bin2dec(bin5);

        System.out.println("Guia_0101 - Tests");

        System.out.println("10110(2) = " + Integer.toString(dec1, 4) + " (4)");
        System.out.println("11011(2) = " + Integer.toString(dec2, 8) + " (8)");
        System.out.println("100100(2) = " + Integer.toString(dec3, 16) + " (16)");
        System.out.println("101011(2) = " + Integer.toString(dec4, 8) + " (8)");
        System.out.println("101100(2) = " + Integer.toString(dec5, 4) + " (4)");
    }
}
