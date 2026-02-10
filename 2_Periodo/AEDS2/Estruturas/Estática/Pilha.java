import java.util.Scanner;

public class Pilha{
	Pilha(){
		array = new int[6];
		n = 0;//contador para saber o numero de termos preenchidos 
	}

	void inserirFim(int x){ // 0 1 2 3 4 5
		                    // 9 8 7 5
		if(n>=array.length()){
			System.out.println("o array ja esta com a quantidade maxima de termos");
		}

		array[n] = x;
		n++.
	}

	int removerFim(){
		if(n==0){
			System.out.println("sem termos a serem removidos");
		}

		int resp = array[n-1];
		n--;

		return resp;
	}
}
