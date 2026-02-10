import java.util.*;

public class ListaSimples{
	class Celula{
		public int elemento;
		public Celula prox;

		Celula(){
			this(0);
		}

		Celula(int x){
			this.elemento = x;
			this.prox = null;
		}
	}

	public Celula primeiro;
	public Celula ultimo;

	ListaSimples(){
		primeiro = new Celula();
		ultimo = primeiro;
	}

	public void inserirInicio(int x){
		Celula tmp = new Celula(x);
	    tmp.prox = primeiro.prox;
		primeiro.prox = tmp;
		if (primeiro == ultimo) {
			ultimo = tmp;
		}
		tmp = null;
	}

	public void inserirFim(int x){
		Celula tmp = new Celula(x);
		ultimo.prox = tmp;
		ultimo = tmp;
	}

	public void inserir(int pos, int x){
		int tamanho = tamanho();
		if(pos<0 || pos>tamanho){
			throw new Exception("Erro!");
		}else if(pos==0){
			inserirInicio(x);
		}else if(pos==tamanho){
			inserirFim(x);
		}

		Celula i =primeiro;
		for(int j=0; j<pos; j++, i=i.prox);
		Celula tmp = new Celula(x);
		tmp.prox = i.prox;
		i.prox = tmp;
		tmp =null;
		i==null;
	
	}

	public int removerInicio(){
		/* não remove a celula cabeça
		if (primeiro == ultimo){
			 throw new Exception("Erro!");
		}
		 Celula tmp = primeiro.prox;
		 primeiro.prox = primeiro.prox.prox;
		 int elemento = tmp.elemento;
		 tmp.prox = null;
		 tmp = null;
		 return elemento;
		*/

		if (primeiro == ultimo){
			throw new Exception("Erro!");
		}
		 Celula tmp = primeiro;
		 primeiro = primeiro.prox;
		 int elemento = primeiro.elemento;
		 tmp.prox = null;
		 tmp = null;
		 return elemento;

		
	}

	public int removerFim(){
		int elemento = ultimo.elemento;
		Celula i = primeiro;
		for(i=primeiro; i.prox!=ultimo; i=i.prox);
		ultimo = i;
		ultimo.prox=null;
		i=null;
		return elemento;
		
	}

	public int remover(int pos){
		int tamanho = tamanho();
		if(pos<0 || pos>tamanho){
			throw new Exception("Erro");
		}else if(pos==0){
			removerInicio();
		}else if(pos==tamanho){
			removerFim();
		}

		Celula i=primeiro;
		for(int j=0; j<pos; j++, i=i.prox);
		Celula tmp = i.prox;
		int elemento = tmp.elemento;
		i.prox = tmp.prox;
		tmp.prox=null;
		tmp=null;
		i=null;
		return elemento;

	}

	public void mostrar(){
		for(Celula i = primeiro; i!=null; i=i.prox;){
			System.out.print(" " + i.elemento);
		}
	}

	public int tamanho() {
      int tamanho = 0; 
      for(Celula i = primeiro; i != ultimo; i = i.prox){
	      tamanho++;
	  }

		return tamanho;
   }

	//daqui para baixo é exercicios do slide
	public int removeSegunda(){
		int tamanho = tamanho();
		if(tamanho<3){
			throw new Exception("Erro");
		}

		Celula i = primeiro.prox;
		Celula tmp = i.prox;
		i.prox = tmp.prox;
		tmp.prox = null;
		i=null;
		tmp.prox=null;
	}

	public void inserirCabeca(int x){
		primeiro.elemento = x;
		Celula tmp = new Celula();
		tmp.prox = primeiro;
		primeiro = tmp;
		tmp=null;
	}

	public void ordenaLista(){
	    for(Celula i = primeiro.prox; i != null; i = i.prox){
	        for(Celula j = primeiro.prox; j.prox != null; j = j.prox){
	            if(j.elemento > j.prox.elemento){
	                int temp = j.elemento;
	                j.elemento = j.prox.elemento;
	                j.prox.elemento = temp;
	            }
	        }
	    }
	}


	public void inverter(){
		Celula i = primeiro.prox;Celula j = ultimo;
		Celula k;
		while (i != j && j.prox != i){
		int tmp = i.elemento;
		i.elemento = j.elemento;
		j.elemento = tmp;
		i = i.prox;
		for (k = primeiro; k.prox != j; k = k.prox);
		 j = k;
		}
	}
	
}

 class TesteLista {
    public static void main(String[] args) {
        ListaSimples lista = new ListaSimples();
        
        lista.inserirInicio(3);
        lista.inserirInicio(2);
        lista.inserirFim(5);
        lista.inserir(1, 4); // insere 4 na posição 1

        lista.mostrar(); // Deveria imprimir: 2 4 3 5

        System.out.println("\nRemovendo início: " + lista.removerInicio());
        lista.mostrar(); // Deveria imprimir: 4 3 5

        System.out.println("\nRemovendo fim: " + lista.removerFim());
        lista.mostrar(); // Deveria imprimir: 4 3

        lista.inserirCabeca(10); // novo elemento na cabeça
        lista.mostrar(); // Deveria imprimir: 10 4 3

        lista.ordenaLista(); // ordenar
        lista.mostrar(); // Deveria imprimir: 3 4 10
    }
}
