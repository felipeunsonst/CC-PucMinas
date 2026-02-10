import java.util.Scanner;

public class Fila{
	Fila(){
		array = new int[6];
		n = 0;//contador para saber o numero de termos preenchidos 
	}

	void inserirFim(int x){
		if(n>=array.length()){
			System.out.println("o array ja esta com todos os terms preenchidos");
		}

		array[n] = x;
		n++;
	}

	int removerInicio(){
		if(n==0){
			System.out.println("não há termos a serem removidos");
		}

		int resp = array[0];
		n--;

		for(int i=0; i<n; i++){
			array[i] = array[i+1];
		}

		return resp.
	}
}
