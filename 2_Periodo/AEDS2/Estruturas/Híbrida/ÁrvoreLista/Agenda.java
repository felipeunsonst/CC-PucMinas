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
		Celula primeiro;
		Celula ultimo;

		No(char letra, No dir, No esq, Celula primeiro, Celula ultimo){
			this.letra = letra;
			this.dir = null;
			this.esq = null;
			this.primeiro = null;
			this.ultimo = null;
		}
	}

	class Celula{
		Contato contato;
		Celula prox;

		Celula(Contato contato, Celula prox){

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

	private void inserir(No no, char valor) {
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

	public boolean pesquisarNome(String nome) {
		return pesquisarNome(raiz, nome);
	}

	private boolean pesquisarNome(No no, String nome) {
      boolean resp;
		if (no == null) { 
         resp = false;
      } else if (Char.toUpper(nome.charAt(0)) == no.letra) { 
         resp = false;
         for(Celula i = no.primeiro.prox; (!resp && i != null); i = i.prox){
            if(i.contato.nome.equals(nome) == true){
               resp = true;
            }
         }
      } else if (Char.toUpper(nome.charAt(0)) < no.letra) { 
         resp = pesquisarNome(no.esq, nome); 

      } else { 
         resp = pesquisarNome(no.dir, nome); 
      }
      return resp;
	}

	public void inserirContato(Contato contato) throws Exception {
		if(Character.isLetter(contato.nome.charAt(0))){
			raiz = inserirContato(raiz, contato);	
		} else {
			throw new Exception("Erro ao inserir!");
		}
	}

	private No inserirContato(No no, Contato contato) throws Exception {
		// insere o nó com a letra
		if (no == null) {
			no = new no(Character.toUpperCase(contato.nome.charAt(0)));
			no.ultimo.prox = new Celula(contato);
			no.ultimo = no.ultimo.prox;	
		
		// insere o contatinho
		} else if (Character.toUpperCase(contato.nome.charAt(0)) == no.letra) { 
			no.ultimo.prox = new Celula(contato);
			no.ultimo = no.ultimo.prox;
		
		// letra menor, caminha para a esquerda
		} else if (Character.toUpperCase(contato.nome.charAt(0)) < no.letra) { 
			no.esq = inserir(no.esq, contato);

		// letra maior, caminha para a direita
		} else { 
			no.dir = inserir(no.dir, contato);
		}
		return no;
	}
	
	public boolean pesquisar(int cpf) {
		return pesquisar(raiz, cpf);
	}

	private boolean pesquisar(No no, int cpf) {
		boolean resp = false;
		if (no != null) {
			resp = pesquisar(no.primeiro.prox, cpf);
			if(resp == false){
				resp = pesquisar(no.esq, cpf);
				if(resp == false){
					resp = pesquisar(no.dir, cpf);
				}
			}
		}
		return resp;
	}

	private boolean pesquisar(Celula i, int cpf){
		//efeuar a pesquisa na lista a partir do i
	}


}
