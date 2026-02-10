import java.util.Scanner;

public class Lista{
	public Lista() {
       
    }

	public Lista () {
		array = new int[6];
		n = 0;//contador para saber o numero de termos preenchidos 
	}
	
	public Lista (int tamanho){
		array = new int[tamanho];
		n = 0;//contador para saber o numero de termos preenchidos 
	}

	void inserirNoInicio(int x){ // 0 1 2 3 4 5
		                         // 5 3 1
		if(n>=array.length){
			System.out.println("O array ja teve seu limite atingido");
			break;
		}

		for(int i=n; i>0; i--){
			array[i] = array[i-1];
		}

		array[0] = x;
		n++;
	}

	void inserirFim(int x){ // 0 1 2 3 4 5
		                    // 5 3 1
		if(n>=array.length){
			System.out.println("o array ja teve seu limite atingido");
			break;
		}

		array[n] = x;
		n++;
	}

				//8        2
	void inserir(int x, int pos){// 0 1 2 3 4 5
		                         // 5 3 8 1 
		if(n>=array.length || pos<0 || pos>n){
			System.out.println("erro");
			break;
		}

		for(int i = n; i>pos; i--){
			array[i] = array[i-1];//fazendo isso ele desloca os termos para a direita
		}

		array[pos] = x;
		n++
	}

	int removerInicio(){// 0 1 2 3 4 5
		                // 5 3 8 1 
		/* a solução abaixo foi feita por mim imaginando que era apenas para remover e alterar o array

		void removerInicio(){
		if(n==0){
			System.out.println("o array nao tem termos para serem removidos");
			break;
		}

		for(int i=0; i<n; i++){
			array[i] = array[i+1];
			if(i=n){
				array[i] = 0;
			}
		}

		n--;
		}
		*/

		if(n==0){
			System.out.println("o array nao tem termos para serem removidos");
			break;
		}

		int resp = array[0];
		n--;
		
		for(int i=0; i<n; i++){
			array[i] = array[i+1];
		}

		return resp;
		
	}

	int removerFim(){// 0 1 2 3 4 5
		             // 5 3 8 1 
		if(n==0){
			System.out.println("o array nao tem termos para serem removidos");
			break;
		}

		int resp = array[n-1];
		n--;

		return resp;
		
	}

	int remover(int pos){
		if(n==0 || pos<0 || pos>=n){
			System.out.println("o array nao tem termos para serem removidos");
			break;
		}

		int resp = array[pos];
		n--;

		for(int i=pos; i<n; i++){
			array[i] = array[i+1];
		}
	}

	void mostrar(){
		for(int i=0; i<n; i++){
			System.out.print(" "+ array[i]);
		}
	}

	int soma(){
		int s=0;
		for(int i=0; i<n; i++){
			s = s + array[i];
		}

		return soma;
	}

	int maior(){
		int m=0;
		for(int i=0; i<n; i++){
			if(array[i] > m){
				m = array[i];
			}
		}

		return m;
	}

	// 0 1 2 3 4 
	// 1 2 3 4 5
	// 5 4 3 2 1
	void inverte(){
	    for (int i = 0; i < n; i++) { 
	        for (int j = i + 1; j < n; j++) {  
	            int temp = array[i];
	            array[i] = array[j];
	            array[j] = temp;
	        }
	    }
	}

	int elementos(){
		int parCinco =0;
		for(int i=0; i<n; i++){
			if(array[i]%2==0 && array[i]%5==0){
				parCinco++;
			}
		}

		return parCinco;
	}
	
}

	

	
