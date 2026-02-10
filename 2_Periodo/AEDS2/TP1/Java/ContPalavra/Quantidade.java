import java.util.Scanner;

public class Quantidade{
	public static int quant(String p){
		int tam = p.length();
		int count =1;

		for(int i=0; i<tam; i++){
			 char c = p.charAt(i);
			if(c==' '){
				count++;
			}
		}

		return count;

	}
	
	public static void main(String[] args){
		Scanner entrada = new Scanner(System.in);
		do{
			String frase = entrada.nextLine();

			if(frase.equals("FIM")){
				break;
			}

			int q = quant(frase);
			System.out.println(""+q);
			
		}while(true);

		entrada.close();
	}

	
}
