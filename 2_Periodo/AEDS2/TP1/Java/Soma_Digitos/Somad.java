import java.util.Scanner;

public class Somad{

	public static int soma(String num, int indice){
		if (indice < 0) {
            return 0;
        }
        return (num.charAt(indice) - '0') + soma(num, indice - 1);
	}

	public static void main(String[] args){
		Scanner entrada = new Scanner(System.in);
		
		do{
			String num = entrada.nextLine();
			if(num.equals("FIM")){
				break;
			}

			int tam = num.length();
			int result = soma(num, tam - 1);
			System.out.println(""+result);

		}while(true);

		entrada.close();
	}
}
