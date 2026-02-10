import java.io.*;
import java.util.Scanner;

public class Arquivo {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        
        try {//fecha automatico pós uso(boa pratica começar a usar)
            int quantidade = entrada.nextInt();
            File arquivo = new File("dados.bin");
            RandomAccessFile acessoAleatorio = new RandomAccessFile(arquivo, "rw");
            
            for (int i = 0; i < quantidade; i++) {
                acessoAleatorio.writeDouble(entrada.nextDouble());
            }
            acessoAleatorio.close();
            
            acessoAleatorio = new RandomAccessFile(arquivo, "r");
            for (int i = quantidade - 1; i >= 0; i--) {
                acessoAleatorio.seek(i * 8); 
                double valor = acessoAleatorio.readDouble();
                
                if (valor == Math.floor(valor)) {
                    System.out.println((int) valor);
                } else {
                    System.out.println(valor);
                }
            }
            acessoAleatorio.close();
            
            arquivo.delete();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            entrada.close();
        }
    }
}
