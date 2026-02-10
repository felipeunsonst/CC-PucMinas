// FELIPE COSTA UNSONST
// 854155

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream> 
#include <vector>
using namespace std;

class Guia {
private:
    int a;
    float b;
    double c;
    string d;

public:
    
    void setInt() {
       //caso necessario eu preencho 
    }

    void setFloat() {
       //caso necessario eu preencho 
    }

    void setDouble() {
       //caso necessario eu preencho 
    }

    void setString1(string conteudo) {
        d = conteudo;
    }

    void setString2(string conteudo2) {
        d = conteudo2;
    }

    int getInt() {
        int valorInt = static_cast<int>(c);
        return valorInt;
    }

    double getDouble() {
        double valorDouble = static_cast<double>(a);
        return valorDouble;
    }

    bool getBoolean() {
        if (a == 1 || a == 0) return static_cast<bool>(a);
        if (b == 1.0 || b == 0.0) return static_cast<bool>(b);
        if (c == 1.0 || c == 0.0) return static_cast<bool>(c);
        return false;
    }

    string replace(char um, char dois) {
        string resultado = d;
        for (int i = 0; i < resultado.length(); i++) {
            if (resultado[i] == um) {
                resultado[i] = dois;
            }
        }
        return resultado;
    }

    string toUpperCase() {
        string resultado = d;
        for (int i = 0; i < resultado.length(); i++) {
            resultado[i] = toupper(resultado[i]);
        }
        return resultado;
    }

    string toLowerCase() {
        string resultado = d;
        for (int i = 0; i < resultado.length(); i++) {
            resultado[i] = tolower(resultado[i]);
        }
        return resultado;
    }

    bool contains(string texto) {
        return d.find(texto) != string::npos;
    }

	string cifraDeCesar(){
		string resultado = d;
		for(int i=0; i<resultado.length(); i++){
			resultado[i] = resultado[i] + 3;
		}
		return resultado;
	}

	string decodificandoCifra(){
		string resultado = d;
		for(int i=0; i<resultado.length(); i++){
			resultado[i] = resultado[i] - 3;
		}
		return resultado;
	}

	int split(vector<string>& sequencia) {
        string palavra = d;
        int contador = 0;
        for (int i = 0; i <= palavra.length(); i++) {
            if (d[i] == ' ' || i == palavra.length()) {
                if (!palavra.empty()) {
                    sequencia.push_back(palavra);
                    palavra.clear();
                    contador++;
                }
            } else {
                palavra += d[i];
            }
        }
        return contador;
    }

	int splitDelimitador(vector<string>& sequencia, char delimitador) {
        string palavra=d;
        int contador = 0;
        for (int i = 0; i <= d.length(); i++) {
            if (d[i] == delimitador || i == d.length()) {
                if (!palavra.empty()) {
                    sequencia.push_back(palavra);
                    palavra.clear();
                    contador++;
                }
            } else {
                palavra += d[i];
            }
        }
        return contador;
    }

    string inverter() {
        string invertido = d;
        int n = invertido.length();
        for (int i = 0; i < n / 2; i++) {
            swap(invertido[i], invertido[n - i - 1]);
        }
        return invertido;
    }

    void metodo1411() {
        cout << "digite um numero double para fazer a conversão" << endl;
        cin >> c;
        int resultado = getInt();
        cout << "o numero convertido é: " << resultado << endl;
    }

    void metodo1412() {
        cout << "digite um numero inteiro para fazer a conversão" << endl;
        cin >> a;
        double resultado = getDouble();
        cout << "o numero convertido é: " << resultado << endl;
    }

    void metodo1413() {
        int escolha;
        cout << "escolha se quer converter um numero inteiro ou double, 1 para inteiro, 2 para double" << endl;
        cin >> escolha;
        if (escolha == 1) {
            cout << "digite um numero inteiro para fazer a conversão" << endl;
            cin >> a;
        } else if (escolha == 2) {
            cout << "digite um numero double para fazer a conversão" << endl;
            cin >> c;
        } else {
            cout << "opção inválida!" << endl;
            return;
        }
        bool resultado = getBoolean();
        cout << "o numero convertido é: " << resultado << endl;
    }

    void metodo1414() {
        setString1("exemplo de cadeia");
        string texto;
        cout << "digite uma sequencia de caracteres para verificar se está no texto" << endl;
        getline(cin, texto);
        if (contains(texto)) {
            cout << "o texto está presente na sequencia" << endl;
        } else {
            cout << "o texto não está presente na sequencia" << endl;
        }
    }

    void metodo1415() {
        cout << "digite uma sequencia de caracteres" << endl;
        getline(cin, d);
        cout << "resultado em maiúsculas: " << toUpperCase() << endl;
    }

    void metodo1416() {
        cout << "digite uma sequencia de caracteres" << endl;
        getline(cin, d);
        cout << "resultado em minúsculas: " << toLowerCase() << endl;
    }

    void metodo1417() {
        char x, y;
        cout << "digite dois caracteres, o primeiro para ser identificado e o segundo para a troca" << endl;
        cin >> x >> y;
        cout << "resultado após substituição: " << replace(x, y) << endl;
    }

	void metodo1418() {
        cout << "digite uma sequencia de caracteres" << endl;
        getline(cin, d);
        cout << "resultado com a cifra: " << cifraDeCesar() << endl;
    }

    void metodo1419() {
        cout << "digite uma sequencia de caracteres" << endl;
        getline(cin, d);
        cout << "resultado sem a cifra: " << decodificandoCifra() << endl;
    }

    void metodo1420() {
        cout << "digite uma sequencia de caracteres: "<<endl;
        getline(cin, d);

        vector<string> sequencia;
        int quantidade = split(sequencia);
        
        cout << "quantidade de palavras: " << quantidade << endl;
        cout << "palavras identificadas:" << endl;
        for (int i = 0; i < quantidade; i++) {
            cout << sequencia[i] << endl;
        }
    }

    void metodo14E1() {
       char delimitador;
        cout << "digite um delimitador para fragmentar a sequencia: ";
        cin >> delimitador;
        getchar();  
        cout << "digite uma sequencia de caracteres: ";
        getline(cin, d);

        vector<string> sequencia;
        int quantidade = splitDelimitador(sequencia, delimitador);

        cout << "quantidade de fragmentos: " << quantidade << endl;
        cout << "fragmentos identificados:" << endl;
        for (int i = 0; i < quantidade; i++) {
            cout << sequencia[i] << endl;
        }
    }

    void metodo14E2() {
        cout << "digite uma sequencia de caracteres: ";
        getline(cin, d);
        cout << "sequencia invertida: " << inverter() << endl;
    }
};

int main() {
    int opcao;
    Guia guia;

    do {
       cout<<"digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo1411\n2-metodo1412\n3-metodo1413\n4-metodo1414\n5-metodo1415\n6-metodo1416\n7-metodo1417\n8-metodo1418\n9-metodo1419\n10-metodo1420\n11-metodo14E1\n12-metodo14E2\n"<<endl;
	    cin>>opcao;
		getchar();

        switch(opcao) {
            case 1:
                guia.metodo1411();
                break;
            case 2:
                guia.metodo1412();
                break;
            case 3:
                guia.metodo1413();
                break;
            case 4:
                guia.metodo1414();
                break;
            case 5:
                guia.metodo1415();
                break;
            case 6:
                guia.metodo1416();
                break;
            case 7:
                guia.metodo1417();
                break;
			case 8:
				guia.metodo1418();
				break;
			case 9:
				guia.metodo1419();
				break;
			case 10:
				guia.metodo1420();
				break;
			case 11:
				guia.metodo14E1();
				break;
			case 12:
				guia.metodo14E2();
				break;
        }

    } while (opcao != 0);

    return 0;
}
