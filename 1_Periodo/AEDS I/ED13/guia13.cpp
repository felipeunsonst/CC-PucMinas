//FELIPE COSTA UNSONST
//1523384

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream> 
#include <vector>
using namespace std;

class Guia{
  private:
	string nome;
	string telefone;
	string telefone2;
	int qtdTelefones;

  public:

	 Guia(string n, string t1, string t2){
      nome=n;
      telefone=t1;
      telefone2=t2;
    }
    ~Guia(){}

	void metodo1311(){
		string teste;
        cout << "digite um nome: ";
        getLine(cin, teste);
        if (!teste.empty()) {
            nome = teste;
        } else {
            cout << "o nome não pode estar vazio." << endl;
        }
	}
	
	void metodo1312() {
        cout << "digite um telefone: ";
        cin >> telefone;
        if (!teste.empty()) {
            nome = teste;
        } else {
            cout << "o telefone não pode estar vazio." << endl;
        }
	}
	
	bool verificarTelefone(){
		int tamanho = strlen(telefone);
		for(int i =0; i<tamanho; i++){
			if(d[i]!= '-' || d[i] != '0' || d[i] != '1' || d[i] != '2' || d[i] != '3' || d[i] != '4' || d[i] != '5' || d[i] != '6' || d[i] != '7' || d[i] != '8' || d[i] != '9' ){
				return true;
			}
		}
		return false;
		
	}

	void metodo1313(){
		if(verificarTelefone()){
			cout<<"o telefone nao e valido"<<endl;
		}else{
			cout<<"o telefone e valido"<<endl
		}
	}
	
	void metodo1314(){
	    ifstream arq; 
		arq.open("DADOS.txt");
	   
	    getline(arq, nome); 
	    arq >> telefone;       
	
	    file.close();
	
	    cout << "dados carregados"<<endl;
	    cout << "Nome: " << nome << "\nIdade: " << idade << endl;
	}
	
	void metodo1315(){
	    ofstream arq; 
		arq.open("DADOS1.txt");
	   
	    arq << nome << endl; 
	    arq << idade << endl; 
	
	    aeq.close();
	    cout << "dados gravados"<< endl;
	}

	 void exibirContato() {
        cout << "nome: " << nome << endl;
        cout << "telefone 1: " << telefone1 << endl;
        if (!telefone2.empty()) {
            cout << "telefone 2: " << telefone2 << endl;
        }
        cout << "total de telefones: " << qtdTelefones << endl;
    }

    int obterQuantidadeTelefones() {
        return qtdTelefones;
    }
	
	void metodo1316(){
        Guia contato1("nome1", "99999-1111", "98888-2222");
        contato1.exibirContato()
	}
	
	void metodo1317(){
        Guia contato2("nome2", "99999-1111");
        cout << "quantidade de telefones para " << contato2.nome << ": " << contato2.obterQuantidadeTelefones() << endl;
	}

	void setPhone2a(string novoTelefone) {
        if (qtdTelefones == 1) {
            char resposta;
            cout << "esse contato possui apenas um telefone, deseja adicionar o segundo telefone? (s/n): ";
            cin >> resposta;
            if (resposta == 's' || resposta == 'S') {
                telefone2 = novoTelefone;
                qtdTelefones = 2;
                cout << "segundo telefone adicionado com sucesso." << endl;
            } else {
                cout << "parando." << endl;
            }
        } else {
            telefone2 = novoTelefone;
            cout << "segundo telefone atualizado com sucesso." << endl;
        }
    }
	void metodo1318(){
        Guia contato3("nome3", "96666-4444");
        contato3.setPhone2a("97777-3333");
        contato3.exibirContato();
	}

	void setPhone2b(string novoTelefone) {
        if (qtdTelefones == 2) {
            telefone2 = novoTelefone;
            cout << "segundo telefone alterado com sucesso." << endl;
        } else {
            cout << "erro: esse contato possui apenas um telefone. não é possível alterar o segundo telefone." << endl;
        }
    }

	void metodo1319(){
        Guia contato4("nome4", "94444-5555", "93333-6666");
        contato4.setPhone2b("97777-3333");
        contato4.exibirContato();
	}

	void setPhone2c() {
        if (qtdTelefones == 2) {
            telefone2 = "";
            qtdTelefones = 1;
            cout << "segundo telefone removido com sucesso." << endl;
        } else {
            cout << "erro: esse contato possui apenas um telefone. Não há segundo telefone para remover." << endl;
        }
    }
	
	void metodo1320() {
        Guia contato5("nome5", "95555-7777", "94444-8888");
        contato5.exibirContato();
        contato5.setPhone2c();
        contato5.exibirContato();
	}

	
	void metodo13E1() {
       
	}
	
	void metodo13E2() {
	    
	}
};

int main(){
	int opcao;
	Guia guia;


    do{
	    printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo1311\n2-metodo1312\n3-metodo1313\n4-metodo1314\n5-metodo1315\n6-metodo1316\n7-metodo1317\n8-metodo1318\n9-metodo1319\n10-metodo1320\n11-metodo13E1\n12-metodo13E2\n");
	    scanf("%d", &opcao);
		getchar();
	
	
	    switch(opcao){
	        case 1:
	        metodo1311();
	        break;
	        
	        case 2:
	        metodo1312();
	        break;
	        
	        case 3:
	        metodo1313();
	        break;
	        
	        case 4:
	        metodo1314();
	        break;
	        
	        case 5:
	        metodo1315();
	        break;
	        
	        case 6:
	        metodo1316();
	        break;
	        
	        case 7:
	        metodo1317();
	        break;
	        
	        case 8:
	        metodo1318();
	        break;
	        
	        case 9:
	        metodo1319();
	        break;
	        
	        case 10:
	        metodo1320();
	        break;
	        
	        case 11:
	        metodo13E1();
	        break;
	        
	        case 12:
	        metodo13E2();
	        break;
	
	    }

    }while(opcao !=0);

    return 0;
}
