public class Agenda{
	private No raiz;
	
	class Contato{
		public String nome;
		public int telefone;
		public String email;
		public int CPF;

		Contato(String nome, int telefone, String email; int CPF){
			this.nome = nome;
			this.telefone = telefone;
			this.email = email;
			this.CPF = CPF;
		}
	}

	class No{
		char letra;
		No dir;
		No esq;
		No prox;
		Contato contato;

		No(char letra, No dir, No esq, No prox){
			this.letra = letra;
			this.dir = null;
			this.esq = null;
			this.prox = null;
		}

		No(Contato contato){
	        this.contato = contato;
	        this.dir = null;
	        this.esq = null;
	    }
	}

	public Agenda() {
		raiz = new No ('M');
		raiz.esq = new No ('G');
		raiz.dir = new No ('T');
		raiz.esq.esq = new No ('A');
		raiz.esq.dir = new No ('I');

		inserir(raiz, 'B');
	    inserir(raiz, 'C');
	    inserir(raiz, 'D');
	    inserir(raiz, 'E');
	    inserir(raiz, 'F');
	    inserir(raiz, 'H');
	    inserir(raiz, 'J');
	    inserir(raiz, 'K');
	    inserir(raiz, 'L');
	    inserir(raiz, 'N');
	    inserir(raiz, 'O');
	    inserir(raiz, 'P');
	    inserir(raiz, 'Q');
	    inserir(raiz, 'R');
	    inserir(raiz, 'S');
	    inserir(raiz, 'U');
	    inserir(raiz, 'V');
	    inserir(raiz, 'W');
	    inserir(raiz, 'X');
	    inserir(raiz, 'Y');
	    inserir(raiz, 'Z');
		
	}

	private void inserir(No no, char valor) {//inserir as letras na arove principal
	    if (valor < no.letra) {
	        if (no.esq == null) {
	            no.esq = new No(valor);
	        } else {
	            inserir(no.esq, valor);
	        }
	    } else if (valor > no.letra) {
	        if (no.dir == null) {
	            no.dir = new No(valor);
	        } else {
	            inserir(no.dir, valor);
	        }
	    }
	}

	private boolean pesquisarNome(No no, String nome) {
		if (no == null){
			return false;
		}
		char primeiraLetra = Character.toUpperCase(nome.charAt(0));
		
		if (primeiraLetra == no.letra) {
			return pesquisarNaSubArvore(no.prox, nome);
		} else if (primeiraLetra < no.letra) {
			return pesquisarNome(no.esq, nome);
		} else {
			return pesquisarNome(no.dir, nome);
		}
	}
		
	private boolean pesquisarNaSubArvore(No subNo, String nome) {
		if (subNo == null) return false;
		
		int cmp = subNo.contato.nome.compareTo(nome);
		
		if (cmp == 0) return true;
		else if (cmp > 0) return pesquisarNaSubArvore(subNo.esq, nome);
		else return pesquisarNaSubArvore(subNo.dir, nome);
	}


	private No inserirNome(No no, Contato contato) throws Exception {
		char primeiraLetra = Character.toUpperCase(contato.nome.charAt(0));
	
		if (no == null) return no;
	
		if (primeiraLetra == no.letra) {
			no.prox = inserirNaSubArvore(no.prox, contato);
		} else if (primeiraLetra < no.letra) {
			no.esq = inserirNome(no.esq, contato);
		} else {
			no.dir = inserirNome(no.dir, contato);
		}
		return no;
	}
	
	private No inserirNaSubArvore(No subNo, Contato contato) throws Exception {
		if (subNo == null) {
			No novo = new No(contato);
			novo.contato = contato;
			return novo;
		}
	
		int cmp = contato.nome.compareTo(subNo.contato.nome);
	
		if (cmp < 0) {
			subNo.esq = inserirNaSubArvore(subNo.esq, contato);
		} else if (cmp > 0) {
			subNo.dir = inserirNaSubArvore(subNo.dir, contato);
		} else {
			throw new Exception("Contato já existe!");
		}
		return subNo;
	}


	
	void mostrarPrincipal(No i){
		if (i != null) {
			System.out.print(i.letra + " ");
			mostrarSecundaria(i.prox);
			mostrarPrincipal(i.esq); 
			mostrarPrincipal(i.dir); 
		}
	}

	void mostrarSecundaria(No j){
		if(j!=null){
			mostrarSecundaria(j.esq); 
			System.out.print(j.contato.nome + " "); 
			mostrarSecundaria(j.dir); 
		}
	}

	boolean hasStringTam10(No i){
		if (i != null) {
			if (hasStringTam10d(i.prox)){
				return true;
			}
			if (hasStringTam10(i.esq)) {
				return true;
			}
			if (hasStringTam10(i.dir)) {
				return true;
			}
		}
		return false;
	}
	
	boolean hasStringTam10d(No j){
		if (j != null) {
			if (hasStringTam10d(j.esq)) {
				return true;
			}
			if (j.contato.nome.length() == 10) {
				return true;
			}
			if (hasStringTam10d(j.dir)){
				return true;
			}
		}
		return false;
	}
	
	boolean hasStringC(No i, char c){
		if (i != null) {
			if (i.letra == c && hasStringC2(i.prox)) {
				return true;
			}
			if (hasStringC(i.esq, c)) {
				return true;
			}
			if (hasStringC(i.dir, c)){
				return true;
			}
		}
		return false;
	}
	
	boolean hasStringC2(No j){
		if (j != null) {
			if (hasStringC2(j.esq)) {
				return true;
			}
			if (j.contato.nome.length() == 10) {
				return true;
			}
			if (hasStringC2(j.dir)) {
				return true;
			}
		}
		return false;
	}

	
}
