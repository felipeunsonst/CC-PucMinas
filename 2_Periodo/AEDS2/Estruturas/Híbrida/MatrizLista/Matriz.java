class Celula {
	public int elemento;
	public Celula inf, sup, esq, dir;
	public CelulaLista prox; // lista de contatos
	public int linha, coluna;

	public Celula() { 
		this(0, 0, 0); 
	}
	public Celula(int elemento) { 
		this(0, 0, elemento); 
	}
	public Celula(int linha, int coluna, int elemento) {
	    this.linha = linha;
	    this.coluna = coluna;
	    this.elemento = elemento;
	    inf = sup = esq = dir = null;
	    prox = null;
	}
}

class CelulaLista {
	public Contato contato;
	public CelulaLista prox;

	public CelulaLista(Contato contato) {
		this.contato = contato;
		this.prox = null;
	}
}

class Contato {
	public String nome;
	public int telefone;
	public String email;
	public int CPF;

	Contato(String nome, int telefone, String email, int CPF) {
	    this.nome = nome;
	    this.telefone = telefone;
	    this.email = email;
	    this.CPF = CPF;
	}
}

public class Matriz {
	private Celula inicio;
	private int linha, coluna;

	public Matriz() { this(3, 3); }

	public Matriz(int linha, int coluna) {
	    this.linha = linha;
	    this.coluna = coluna;
	    Celula anterior = null;
	    Celula linhaAnterior = null;
	    for (int i = 0; i < linha; i++) {
		Celula atual = null;
	    anterior = null;
	    Celula temp = linhaAnterior;

	    for (int j = 0; j < coluna; j++) {
		    Celula nova = new Celula(i, j, 0);

	        if (j == 0) {
	          atual = nova;
	          if (i == 0) {
	            this.inicio = nova;
	          }
	        } else {
	          anterior.dir = nova;
	          nova.esq = anterior;
	        }

	        if (temp != null) {
	          temp.inf = nova;
	          nova.sup = temp;
	          temp = temp.dir;
	        }

	        anterior = nova;
	      }
	      linhaAnterior = atual;
	    }
	  }

	Celula buscarCelula(int linha, int coluna) {
	    Celula atual = inicio;
	    for (int i = 0; i < linha && atual != null; i++) {
	      atual = atual.inf;
	    }
	    for (int j = 0; j < coluna && atual != null; j++) {
	      atual = atual.dir;
	    }
	    return atual;
	  }

  void inserirContatoNaCelula(int linha, int coluna, Contato contato) {
	    Celula celula = buscarCelula(linha, coluna);
	    if (celula == null) {
		    System.out.println("Célula não existe!");
		    return;
		}

		CelulaLista nova = new CelulaLista(contato);
	    nova.prox = celula.prox;
	    celula.prox = nova;
  }

  boolean pesquisarContatoPorNome(String nome) {
		for (Celula i = inicio; i != null; i = i.inf) {
			for (Celula j = i; j != null; j = j.dir) {
		        for (CelulaLista c = j.prox; c != null; c = c.prox) {
			        if (c.contato.nome.equals(nome)) {
				        return true;
			        }
		        }
		    }
	    }
	    return false;
	  }

	void mostrarTudo() {
	    for (Celula i = inicio; i != null; i = i.inf) {
	      for (Celula j = i; j != null; j = j.dir) {
	        System.out.print("[" + j.linha + "," + j.coluna + "] -> ");
	
	        CelulaLista atual = j.prox;
	        if (atual == null) {
	          System.out.print("sem contatos");
	        } else {
	          while (atual != null) {
	            System.out.print("{" + atual.contato.nome + ", " + atual.contato.telefone + ", " + atual.contato.email + ", " + atual.contato.CPF + "} ");
	            atual = atual.prox;
	          }
	        }
	        System.out.print(" | ");
	      }
	      System.out.println();
	    }
	  }
}
