public class Fila {
	class Celula {
        public int elemento;
        public Celula prox;

        public Celula() {
            this(0);
        }

        public Celula(int x) {
            this.elemento = x;
            this.prox = null;
        }
    }

	private Celula primeiro;
	private Celula ultimo;

	public Fila () {
		primeiro = new Celula();
		ultimo = primeiro;
	}

	//FIFO
	public void inserir(int x){
		Celula tmp = new Celula(x);
		ultimo.prox = tmp;
		ultimo = tmp;
		tmp =null;

		//sem ponteiro ultimo
		/*
		for(Celula i =primeiro; i!=null; i=i.prox);
		i.prox = new Celula(x);
		i=null;
		*/
	}

	public int remover(){
		if(primeiro==ultimo){
			throw new Exception("erro");
		}
		int elemento = primeiro.prox.elemento;
		Celula tmp = primeiro.prox;
		primeiro.prox = tmp.prox;
		tmp.prox = null;
		tmp = null;
		return elemento;
	}

	public void mostrar(){
		System.out.print("[");
		for(Celula i = primeiro; i!=null; i=i.prox){
			System.out.print(" " + i.elemento);
		}
		System.out.print("]");
	}

	public int tamanho(){
		int tamanho =0;
		for(Celula i =primeiro; i!=null; i=i.prox){
			tamanho++;
		}
		return tamanho;
	}

	//exercicios slide
	public int maior(){
		int ma = 0;
		for(Celula i =primeiro; i!=null; i=i.prox){
			if(i.elemento>ma){
				ma = i.elemento;
			}
		}
	}

	public int terceiro(){
		if(tamanho<4){
			throw new Exception("erro");
		}

		Celula i = primeiro;
		for(int j=0; j<4; j++, i=i.prox);
		return i.elemento;
	}

	public int soma(){
		int soma = 0;
		for(Celula i = primeiro; i!=null; i=i.prox){
			soma += i.elemento;
		}
		return soma;
	}

	public void inverso(){
		Celula fim = ultimo;
		while (primeiro != fim){
			Celula nova = new Celula (primeiro.prox.elemento);
			nova.prox = fim.prox;
			fim.prox = nova;
			Celula tmp = primeiro.prox;
			primeiro.prox = tmp.prox;
			nova = tmp = tmp.prox = null;
			if (ultimo == fim) {
				ultimo = ultimo.prox; 
			}
		}
		fim = null;
	}

	public int recParesCinco(int qnt, Celula i){
		if(i==null){
			return qnt;
		}

		if(i.elemento%2==0 && i.elemento%5==0){
			return recParesCinco(qnt+1, i.prox);
		}else{
			return recParesCinco(qnt, i.prox);
		}
	}
}


class TesteFila{
	public static void main(String[] args) {
        Fila fila = new Fila();
        
        Fila.inserir(3);
        Fila.inserir(2);
        Fila.inserir(5);

        Fila.mostrar(); 

        System.out.println("\nRemovendo início: " + Fila.remover());
        Fila.mostrar(); 

	}
}
