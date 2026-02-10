//lista
public class Hash{
	int tabela[];
	int m;
	final int NULO = -1;
	Celula celula;

	Hash(){
		this(12);
	}

	Hash(int m){
		this.m = m;
		celula = new Celula();
		this.tabela = new int[this.m];
		for(int i =0; i<m; i++){
			tabela[i]=NULO;
		}
	}

	class Celula{
		int elemento;
		Celula prox;

		Celula(int elemento){
			this.elemento = elemento;
			this.prox = null;
		}	
	}

	class Lista{
		Celula primeiro;
		Celula ultimo;

		Lista(){
			this.primeiro = null;
			this.ultimo = null;
		}

		public void mostrar() {
			System.out.print("[ "); 
			for (Celula i = primeiro.prox; i != null; i = i.prox) {
				System.out.print(i.elemento + " ");
			}
			System.out.println("] "); 
		}

		public boolean pesquisar(int x) {
			boolean retorno = false;
			for (Celula i = primeiro.prox; i != null; i = i.prox) {
		         if(i.elemento == x){
		            retorno = true;
		            i = ultimo;
		         }
			}
			return retorno;
		}
	

		public void inserirInicio(int elemento) {
		   Celula tmp = new Celula(elemento);
	       tmp.prox = primeiro.prox;
			primeiro.prox = tmp;
			if (primeiro == ultimo) {
				ultimo = tmp;
			}
	      tmp = null;
		}
	
		public void inserirFim(int elemento) {
			Celula tmp = new Celula(elemento);
			ultimo.prox = tmp;
			ultimo = ultimo.prox;
	      tmp = null;
		}
	
	   public void inserirMeio(int x, int posicao) throws Exception {
	      Celula i;
	      int cont;
	
	      for(i = primeiro, cont = 0; (i.prox != ultimo && cont < posicao); i = i.prox, cont++);
			if (posicao < 0 || posicao > cont + 1) {
				throw new Exception("Erro ao inserir (posicao " + posicao + "(cont = " + cont + ") invalida)!");
	
	      } else if (posicao == cont + 1) {
	         inserirFim(x);
			}else{
	         Celula tmp = new Celula(x);
	         tmp.prox = i.prox;
	         i.prox = tmp;
	         tmp = i = null;
	      }
	   }
	
		public int removerInicio() throws Exception {
	      int resp = -1;
	
			if (primeiro == ultimo) {
				throw new Exception("Erro ao remover (vazia)!");
			}else{
	         primeiro = primeiro.prox;
	         resp = primeiro.elemento;
	      }
	
			return resp;
		}
	
		public int removerFim() throws Exception {
	      int resp =  -1;
	      Celula i = null;
	
			if (primeiro == ultimo) {
				throw new Exception("Erro ao remover (vazia)!");
			} else {
	
	         resp = ultimo.elemento;
	
	         for(i = primeiro; i.prox != ultimo; i = i.prox);
	
	         ultimo = i;
	         i = ultimo.prox = null;
	      }
	
			return resp;
		}
	
		public int removerMeio(int posicao) throws Exception {
	      Celula i;
	      int resp = -1, cont;
	
			if (primeiro == ultimo){
				throw new Exception("Erro ao remover (vazia)!");
	      }else{
	         for(i = primeiro, cont = 0; (i.prox != ultimo && cont < posicao); i = i.prox, cont++);
			   if (posicao < 0 || posicao > cont + 1) {
	            throw new Exception("Erro ao remover (posicao " + posicao + " invalida)!");
	
	         } else if (posicao == cont + 1) {
	            resp = removerFim();
	         }else{
	            Celula tmp = i.prox;
	            resp = tmp.elemento;
	            i.prox = tmp.prox;
	            tmp.prox = null;
	            i = tmp = null;
	         }
	      }
	
			return resp;
		}
	}

	public int h(int elemento){
		return elemento % m;
	}

	public void inserir(int elemento){
		if(elemento!=NULO){
			int pos = h(elemento);
			if(tabela[pos]==NULO){
				tabela[pos] = elemento;
			}else if(tabela[pos]!=NULO){
				tabela[pos].inserirInicio(elemento);
			}
		}
	}

	public boolean pesquisar(int elemento){
		if(elemento!=NULO){
			int pos = h(elemento);
			if(tabela[pos]==elemento){
				return true;
			}else if(tabela[pos]!=NULO){
				return tabela[pos].pesquisar(elemento);
			}
		}
	}

	public int remover(int elemento) {
	      int resp = NULO;
	      if (pesquisar(elemento) == false) {
	         throw new Exception("Erro ao remover!");
	      } else {
	         int pos = h(elemento);
	         resp = tabela[pos].remover(elemento);
	      }
	      return resp;
    }



	
}
