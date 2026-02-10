import java.util.Scanner;

public class Senha{
	public static boolean sen(String s){
		int tam = s.length();
		if(tam<8){
			return false;
		}
		
		int maiusculas =0;
		int minusculas =0;
		int simbolo =0;
		int numero =0;

		for(int i=0; i<tam; i++){
			char c= s.charAt(i);
			if(c>='0' && c<='9'){
				numero++;
			}

			if(c>='A' && c<='Z'){
				maiusculas++;
			}

			if(c>='a' && c<='z'){
				minusculas++;
			}

			if(!(c>='0' && c<='9' || c>='A' && c<='Z' || c>='a' && c<='z')){
				simbolo++;
			}
		}

		if(numero==0 || maiusculas ==0 || minusculas==0||simbolo==0){
			return false;
		}

		return true;
	}


	public static void main(String[] args){
		Scanner entrada = new Scanner(System.in);
		do{
			String codigo = entrada.nextLine();

			if(codigo.equals("FIM")){
				break;
			}

			if(sen(codigo)){
				System.out.println("SIM");
			}else{
				System.out.println("NAO");
			}

		}while(true);

		entrada.close();
	}
}
