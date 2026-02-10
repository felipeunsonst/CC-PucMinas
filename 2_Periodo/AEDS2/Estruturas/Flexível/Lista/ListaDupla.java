public class ListaDupla{
	class CelulaDupla{
		public int elemento;
		public CelulaDupla ant;
		public CelulaDupla prox;
	
		public CelulaDupla() {
			this(0);
		}
	
		public CelulaDupla(int elemento) {
			this.elemento = elemento;
			this.ant = this.prox = null;
		}
	}

	public CelulaDupla primeiro;
	public CelulaDupla ultimo;

	public void inserirInicio(int x){
		CelulaDupla tmp = new CelulaDupla(x);
		tmp.ant = primeiro;
		tmp.prox = primeiro.prox;
		primeiro.prox = tmp;
		if (primeiro == ultimo) {
			ultimo = tmp;
		} else {
			tmp.prox.ant = tmp;
		}
		tmp=null;
	}

	public void inserirFim(int x){
		ultimo.prox = new CelulaDupla(x);
		ultimo.prox.ant = ultimo;
		ultimo = ultimo.prox;
	}

	public void inserir(int pos, int x) throws Exception {
	    int tamanho = tamanho();
	    if (pos < 0 || pos > tamanho) {
	        throw new Exception("Erro!");
	    } else if (pos == 0) {
	        inserirInicio(x);
	    } else if (pos == tamanho) {
	        inserirFim(x);
	    } else {
	        CelulaDupla i = primeiro;
	        for (int j = 0; j < pos; j++, i = i.prox);
	        
	        CelulaDupla tmp = new CelulaDupla(x);
	        tmp.prox = i.prox;
	        tmp.ant = i;
	        i.prox.ant = tmp;
	        i.prox = tmp;
	    }
	}


	public int removerInicio(){
		int elemento = primeiro.prox.elemento;
		CelulaDupla tmp = primeiro.prox;
		primeiro.prox = tmp.prox;
		tmp.prox.ant = primeiro;
		tmp.prox = null;
		tmp.ant = null;
		tmp = null;
		return elemento;
	}

	public int removerFim() throws Exception {
	    if (primeiro == ultimo) throw new Exception("Lista vazia!");
	
	    int elemento = ultimo.elemento;
	    ultimo = ultimo.ant;
	    ultimo.prox.ant = null; // Se necessário
	    ultimo.prox = null;
	    return elemento;
	}


	public int remover(int pos) throws Exception {
	    int tamanho = tamanho();
	    if (pos < 0 || pos >= tamanho) {
	        throw new Exception("Erro!");
	    } else if (pos == 0) {
	        return removerInicio();
	    } else if (pos == tamanho - 1) {
	        return removerFim();
	    } else {
	        CelulaDupla i = primeiro.prox;
	        for (int j = 0; j < pos; j++, i = i.prox);
	        
	        int elemento = i.elemento;
	        i.ant.prox = i.prox;
	        i.prox.ant = i.ant;
	        return elemento;
	    }
	}


	public int tamanho(){
		int tamanho = 0;
		for(CelulaDupla i =primeiro; i!=null; i=i.prox){
			tamanho++;
		}
		return tamanho;
	}

	public void mostrar(){
		System.out.print("[");
		for(CelulaDupla i =primeiro; i!=null; i=i.prox){
			System.out.print(" "+i.elemento);
		}
		System.out.print("]");
	}

	public void inverter(){
	    if (primeiro == null || primeiro.prox == null) {
	        return; 
	    }
	
	    CelulaDupla i = primeiro.prox;  
	    CelulaDupla j = ultimo;  
	
	    // Troca os elementos até que i e j se cruzem
	    while (i != j && i != j.prox) {  // Condição para garantir que não troque elementos repetidos
	        int temp = i.elemento;
	        i.elemento = j.elemento;
	        j.elemento = temp;
	
	        i = i.prox;
	        j = j.ant;
	    }
	}

	
}
