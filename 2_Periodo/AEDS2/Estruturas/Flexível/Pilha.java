import java.util.*;

public class Pilha {

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

    private Celula topo;

    public Pilha() {
        topo = null;
    }

	//FILO
	public void inserir(int x){
		Celula tmp = new Celula(x);
		tmp.prox = topo;
		topo = temp;
		tmp = null;
	}

	public int remover(){
		int elemento = topo.elemento;
		Celula tmp = topo;
		topo = topo.prox;
		tmp.prox=null;
		tmp = null;
		return elemento;
	}

	public void mostrar(){
		System.out.print("[");
		for(Celula i = topo; i!=null; i=i.prox){
			System.out.print(" " + i.elemento);
		}
		System.out.print("]");
	}

	//exercicios slides
	public int soma(){
		int soma=0;
		for(Celula i =topo; i!=null; i=i.prox){
			soma+=i.elemento;
		}
		return soma;
	}

	public int somaRec(int soma, Celula i){
		if(i==null){
			return soma;
		}

		return somaRec(soma+1, i.prox);
	}

	public int maior(){
		int ma=0;
		for(Celula i =topo; i!=null; i=i.prox){
			if(i.elemento>ma){
				ma = elemento;
			}
		}
	}

	public int maiorRec(int maior, Celula i){
		if(i==null){
			return maior;
		}

		if(i.elemento>maior){
			return maiorRec(i.elemento, i.prox);
		}else{
			return maiorRec(maior, i.prox);
		}
	}

	void imprimirRec(Celula i) {
	    if (i == null) {
	        return;
	    }
	    System.out.println(i.elemento);
	    imprimir(i.prox);
	}

	void imprimirRecInv(Celula i) {
	    if (i == null) {
	        return;
	    }
	   imprimirInverso(i.prox); // Primeiro vai até o final
	   System.out.println(i.elemento); // Depois imprime na volta da recursão
	}

}

