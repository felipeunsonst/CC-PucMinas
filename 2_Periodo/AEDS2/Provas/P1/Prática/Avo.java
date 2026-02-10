import java.util.*;

public class Avo {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        while (true) {
            int l = entrada.nextInt();
            int c = entrada.nextInt();

            if (l == 0 || c == 0) break;

            int[] posi = new int[10000]; //cada numero possivel ta aqui
            int[][] matriz = new int[l][c];

            for (int i = 0; i < l; i++) {
                for (int j = 0; j < c; j++) {
                    matriz[i][j] = entrada.nextInt();
                    posi[matriz[i][j]]++;//soma o 0 por padrão do java na posição do vetor posi
                }
            }

            int primeiro = 0;
            int segundo = 0;
            for (int i = 0; i < 10000; i++) {
                if (posi[i] > primeiro) {
                    segundo = primeiro;
                    primeiro = posi[i];
                } else if (posi[i] > segundo && posi[i] < primeiro) {
                    segundo = posi[i];
                }
            }

            for (int i = 0; i < 10000; i++) {
                if (posi[i] == segundo) {
                    System.out.print(i + " ");
                }
            }
            System.out.println();
        }

        entrada.close();
    }
}
