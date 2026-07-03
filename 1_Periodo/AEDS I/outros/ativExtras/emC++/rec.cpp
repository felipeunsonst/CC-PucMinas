//FELIPE COSTA UNSONST
//1523384

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream> 
#include <vector>
using namespace std;

int decrescente(vector<int> arr, int q){
	for(int i = 0; i<q; i++){
		if(i<q){
			if(arr[i]<arr[i+1]){
				return 1;
			}
		}
	}

	return 0;
}

void exercicio01(){
	ifstream arquivo;
	arquivo.open("DADOS1.txt");

	vector<int> array;
    int numero;
	int quantidade = 0;

    while (arquivo >> numero) {
        array.push_back(numero);
		quantidade++;
    }

    arquivo.close();

	int c = decrescente(array, quantidade);
	if(c==1){
		ofstream arq;
		arq.open("CRESCENTE.txt");

		arq<<quantidade<<end;
		for(int i=0; i<quantidade; i++){
			arq<<array[i] ;
		}
		
		int temp;
		for(int i=0; i<quantidade; i++){
			for(int j=0; j<quantidade-i-1; j++){
				if(array[j]<array[j+1]){
					temp = array[j];
	                array[j] = array[j+1];
	                array[j+1] = temp;
				}
			}
		}

		cout<<"arranjo decrescente"<<endl;
		for(int i=0; i<quantidade; i++){
			cout<<array[i];
		}

		arq.close;
	}else if(c==0){
		cout<<"o array esta decrescente"<<endl;
	}

	
}

int inverter(vector<int> arr, int q){
	 int i = 0, j = q - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return arr; 
}

void exercicio02(){
	ifstream arquivo;
	arquivo.open("CRESCENTE.txt");

	vector<int> array;
    int numero;
	int quantidade = 0;

    while (arquivo >> numero) {
        array.push_back(numero);
		quantidade++;
    }

	vector<int> *invertido = inverter(array, quantidade);

	ofstream arq;
	arq.open("INVERTIDOS.txt");

	arq<<quantidade<<endl;
	for(int i=0; i<quantidade; i++){
		arq<<invertido[i]<<" ";
	}

	arq.close;
    arquivo.close();
}

int mediana(vector<int> arr, int q){
	int soma= 0;
	if(q%2==0){
		soma = soma + arr[q/2] + arr[q/2-1];
		int media = soma/2;
		return media1;
	}else{
		for(int i=0; i<q; i++){
			soma += arr[i];
		}

		int media1 = soma/q;
		return media1;
	}
}


void exercicio03() {
    ifstream arquivo;
	arquivo.open("DADOS1.txt");

	vector<int> array;
    int numero;
	int quantidade = 0;

    while (arquivo >> numero) {
        array.push_back(numero);
		quantidade++;
    }

	int m = mediana(array, quantidade);
	cout<<"mediana: "<<m<<endl;

	
    arquivo.close();
}

void exercicio04(){
	ifstream arquivo1;
	arquivo.open("DADOS1.txt");

	vector<int> array1;
    int numero1;
	int quantidade1 = 0;

    while (arquivo1 >> numero1) {
        array1.push_back(numero1);
		quantidade1++;
    }

	ifstream arquivo2;
	arquivo.open("DADOS2.txt");

	vector<int> array2;
    int numero2;
	int quantidade2 = 0;

    while (arquivo2 >> numero2) {
        array2.push_back(numero2);
		quantidade2++;
    }

	vector<int> array3;
	int quantidade3 = 0;

	for(int i = 0; i<quantidade1; i++){
		for(int j=0; j<quantidade2; j++){
			if(array1[i] == array2[j]){
				array3[i] = array1[i];
				quantidade3++;
			}
		}
	}

	ofstream arq;
	arq.open("FILTRADOS.txt");

	for(int i=0; i<quantidade3; i++){
		arq<<array3[i] << " ";
	}



	arquivo1.close();
	arquivo2.close();
	arquivo3.close();
}


int converterBinarioParaDecimal(vector<int> bits) {
    int valorDecimal = 0;
    int tamanho = bits.size();
    for (int posicao = 0; posicao < tamanho; posicao++) {
        valorDecimal += bits[posicao] * pow(2, tamanho - posicao - 1);
    }
    return valorDecimal;
}

void questao5() {
    ifstream arquivo("BINARIOS1.TXT");

    string conteudoLinha;
    while (getline(entrada, conteudoLinha)) {
        vector<int> sequenciaBits;
        bool ehValida = true;

        for (char caractere : conteudoLinha) {
            if (caractere == '0' || caractere == '1') {
                sequenciaBits.push_back(caractere - '0');
            } else {
                ehValida = false;
                break;
            }
        }

        if (ehValida) {
            int valorDecimal = converterBinarioParaDecimal(sequenciaBits);
            cout << " Decimal: " << valorDecimal << endl;
        } else {
            cout << "linha inválida"<< endl;
        }
    }

    arquivo.close();
}

int matriz(){
	ifstream arquivo("MATRIZ1.TXT"); 

	int N; 
	arquivo >> N; 
	arquivo.close(); 
	vector<vector<int>> matriz(N, vector<int>(N, 0));
	int valor = 1; 
	for (int i = 0; i < N; i++) { 
		if (i > 0) { 
			matriz[i][i-1] = valor++;
		} 
		matriz[i][i] = valor++; 
		if (i < N - 1) { 
			matriz[i][i+1] = valor++;
		} 
	
	}
	ofstream arq("MATRIZ2.TXT");
	 for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) { 
			arq << matriz[i][j] << " "; } 
		arq << endl; 
	}
	arq.close(); 
	return 0;
}

void exercicio06(){
	int resultado = matriz(); 
	if (resultado == 0) { 
		cout << "matriz gerada e gravada com sucesso em MATRIZ2.TXT!" << endl; 
	} else { 
		cout << "ocorreu um erro durante a execução." << endl;
	}
}

int matriz2() { 
	ifstream arquivo("MATRIZ1.TXT"); 
	
	int N;
	arquivo >> N; 
	arquivo.close(); 
	vector<vector<int>> matriz(N, vector<int>(N, 0));
	int valor = 1; 
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N - i; j++) { 
			if (j == 0) { 
				matriz[i][i] = valor++;
			} else { 
				matriz[i][i + j] = valor++;
				if (i + j < N) { 
					matriz[i + j][i] = valor++; 
				} 
			}
		} 
	} 
	ofstream arq("MATRIZ2.TXT");
	
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			arq << matriz[i][j] << " ";
		} 
		arq << endl; 
	} arq.close(); 
	return 0
}

void exercicio07(){
	int resultado = matriz2();
	if (resultado == 0) {
		cout << "matriz gerada e gravada com sucesso em MATRIZ2.TXT!" << endl; 
	}else {
		cout << "ocorreu um erro durante a execução." << endl; 
	}
}

bool verificaPotenciasPorLinha(vector<vector<int>>& matriz) { 
	for (int i = 0; i < matriz.size(); i++) { 
		for (int j = 1; j < matriz[i].size(); j++) { 
			if (matriz[i][j] != pow(matriz[i][0], j)) { 
				return false; 
			} 
		} 
	} 
	return true; 
}

int matriz3() { 
	ifstream arquivo("MATRIZ3.TXT");
	
	int N;
	arquivo >> N; 
	vector<vector<int>> matriz(N, vector<int>(N, 0)); 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) {
			arquivo >> matriz[i][j]; 
		} 
	} 
	arquivo.close(); 
	bool resultado = verificaPotenciasPorLinha(matriz); 
	cout << "a matriz apresenta potências por linha? " << (resultado ? "Sim" : "Não") << endl; 
	return 0; 
}
	
void exercicio08(){
	int resultado = matriz3();
	if (resultado == 0) { 
		cout << "verificação de matriz concluída com sucesso." << endl; 
	} else { 
		cout << "ocorreu um erro durante a execução." << endl;
	}

bool verificaPotenciasPorColuna(vector<vector<int>>& matriz) { 
	for (int j = 0; j < matriz[0].size(); j++) {
		for (int i = 1; i < matriz.size(); i++) { 
			if (matriz[i][j] != pow(matriz[0][j], i)) {
				return false; 
			} 
		} 
	} return true; 
}

int matriz4() {
	ifstream arquivo("MATRIZ4.TXT"); 
	
	int N;
	arquivo >> N; 
	vector<vector<int>> matriz(N, vector<int>(N, 0)); 
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < N; j++) { 
			arquivo >> matriz[i][j]; 
		} 
	} 
	arquivo.close(); 
	bool resultado = verificaPotenciasPorColuna(matriz); 
	cout << "a matriz apresenta potências por coluna? " << (resultado ? "Sim" : "Não") << endl; 
	return 0; 
}

void exercicio09() {
  int resultado = matriz4();
	if (resultado == 0) {
		cout << "verificação de matriz concluída com sucesso." << endl;
	} else {
		cout << "ocorreu um erro durante a execução." << endl; }
}


void exercicio10() {
   
}

int main(){
int opcao;


    do{
    cout<<"digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-exercicio01\n2-exercicio02\n3-exercicio03\n4-exercicio04\n5-exercicio05\n6-exercicio06\n7-exercicio07\n8-exercicio08\n9-exercicio09\n10-exercicio10"<<endl;
    cin>>opcao;
	getchar();


    switch(opcao){
        case 1:
        exercicio01();
        break;
        
        case 2:
        exercicio02();
        break;
        
        case 3:
        exercicio03();
        break;
        
        case 4:
       exercicio04();
        break;
        
        case 5:
        exercicio05();
        break;
        
        case 6:
        exercicio06();
        break;
        
        case 7:
        exercicio07();
        break;
        
        case 8:
        exercicio08();
        break;
        
        case 9:
        exercicio09();
        break;
        
        case 10:
        exercicio10();
        break;
    
    }

    }while(opcao !=0);

    return 0;
}
