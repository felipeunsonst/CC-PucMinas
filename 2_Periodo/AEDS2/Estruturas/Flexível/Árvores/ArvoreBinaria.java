public class ArvoreBinaria{
	class No{
		int elemento;
		No esq;
		No dir;

		No(int elemento){
			this(elemento, null, null);
		}

		 No(int elemento, No esq, No dir) {
			 this.elemento = elemento;
			 this.esq = esq;
			 this.dir = dir;
		 }
	}

	No raiz;
	ArvoreBinara(){
		raiz = null;
	}

	void inserir(int x) throws Exception{
		raiz = inserir(x, raiz);
	}

	No inerir(int x, No i){
		if (i == null) {
			i = new No(x);
		}else if (x < i.elemento) {
			i.esq = inserir(x, i.esq);
		}else if (x > i.elemento) {
			i.dir = inserir(x, i.dir);
		}else {
			throw new Exception("Erro!");
		}
		return i;

	}
	
	void inserirPai(int x)throws Exception{
		if (raiz == null) {
			raiz = new No(x);
		}else if (x < raiz.elemento) {
			inserirPai(x, raiz.esq, raiz);
		}else if (x > raiz.elemento) {
			inserirPai(x, raiz.dir, raiz);
		}else {
			throw new Exception("Erro!");
		}
	}

	void inserirPai(int x, No i, No pai) throws Exception {
		if (i == null) {
			if (x < pai.elemento){
				pai.esq = new No(x);
			}else {
				pai.dir = new No(x);
			}
		}else if (x < i.elemento) {
			inserirPai(x, i.esq, i);
		}else if (x > i.elemento) {
			inserirPai(x, i.dir, i);
		}else {
			throw new Exception("Erro!");
		}
	}
	
	boolean pesquisar(int x) {
		return pesquisar(x, raiz);
	}
	
	boolean pesquisar(int x, No i) {
		boolean resp;
		if(i == null) {
			resp = false;
		}else if(x == i.elemento) {
			resp = true;
		}else if(x < i.elemento) {
			resp = pesquisar(x, i.esq);
		}else{
			resp = pesquisar(x, i.dir);
		}
		return resp;
	}

	int getAltura(No i, int altura){
		if(i==null){
			altura--;
		}else{
			int alturaEsq = getAltura(i.esq, altura++);
			int alturaDir = getAltura(i.dir, altura++);
			altura = (alturaEsq > alturaDir) ? alturaEsq : alturaDir;
		}
		return altura;
		
	}

	int getMaior(){
		int resp =-1;
		if(raiz!=null){
			for(No i =raiz; i.dir!=null; i=i.dir);
			resp =i.elemento;
		}
		return resp;
	}

	int getMenor(){
		int resp =-1;
		if(raiz!=null){
			for(No i = raiz; i.esq!=null; i= i.esq);
			resp = i.elemento;
		}
		return resp;
	}
	
	void caminharCentral(No i) {//printa na ordem crescente
		if (i != null) {
			caminharCentral(i.esq); 
			System.out.print(i.elemento + " "); //caso quisesse um metodo de pegar a soma de todos, substituiria aqui por um contador mas q seja uma variavel global
			caminharCentral(i.dir); 
		}
	}


	/*
	int soma(){
		s = 0;
		soma(raiz);
		return s;
	}

	private void soma(No i) {
        if (i == null) return;

        soma(i.esquerda);
        s = s + i.valor;
        soma(i.direita);
	}
	
	*/
	
	void caminharPre(No i){
		if(i!=null){
			System.out.print(i.elemento + " ");
			caminharPre(i.esq);
			caminharPre(i.dir)
		}
	}
	
	void caminharPos(No i){
		if(i!=null){
			caminharPos(i.esq);
			caminharPos(i.dir);
			System.out.print(i.elemento + " ");
		}
		
	}
	
	void remover(int x) throws Exception {
		raiz = remover(x, raiz);
	}
	
	No remover(int x, No i) throws Exception {
		if (i == null) { 
			throw new Exception("Erro!");
		}else if(x < i.elemento){
			i.esq = remover(x, i.esq);
		}else if(x > i.elemento){
			i.dir = remover(x, i.dir);
		}else if(i.dir == null){
			i = i.esq;
		}else if(i.esq == null){ 
			i = i.dir;
		}else{ 
			i.esq = maiorEsq(i, i.esq); 
		}
		return i;
	}
	
	No maiorEsq(No i, No j) {
		if (j.dir == null){
			i.elemento=j.elemento; j=j.esq; 
		}else{
			j.dir = maiorEsq(i, j.dir); 
		}
		return j;
	}

	public int somar(No raiz) {
        if (raiz == null) {
            return 0;
        }
        return raiz.valor + somar(raiz.esq) + somar(raiz.dir);
    }

	public boolean saoIguais(No a, No b) {
	    if (a == null && b == null) return true;         // Ambos nulos
	    if (a == null || b == null) return false;        // Um só é nulo
	    if (a.valor != b.valor) return false;            // Valores diferentes
	
	    // Caminha à esquerda, compara os nós
	    boolean esquerdaIguais = saoIguais(a.esq, b.esq);
	    if (!esquerdaIguais) return false;
	
	    // Caminha à direita, compara os nós
	    boolean direitaIguais = saoIguais(a.dir, b.dir);
	    return direitaIguais;
	}



}
