//FELIPE COSTA UNSONST
//1523384

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream> //biblioteca para operar com arquivo em c++
#include <vector>
using namespace std;

void metodo1211(){
	//ofstream -- saida, saindo do programa e indo para o arquivo
	//ifstream --entrada, entrando do arquivo e indo para o programa

	ofstream arq; 
	arq.open("DADOS.txt");
	
	int linha;
	int coluna;
	cout<<"digite a quantidade de linhas e colunas respectivamente"<<endl;
	cin>>linha>>coluna;

	int matriz[linha][coluna];
	srand(time(0));
	int n = linha*coluna;

	arq<<n<<endl;
	for(int i = 0; i<linha; i++){
		for(int j=0; j<coluna; j++){
			matriz[i][j]= rand() % 100;
		}
	}

	for(int i = 0; i<linha; i++){
		for(int j=0; j<coluna; j++){
			arq<<matriz[i][j]<<endl;
		}
	}
	

	arq.close();
}

int lerMatriz(ifstream& arq, vector<vector<int>>& m, int l, int c) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            arq >> m[i][j]; 
        }
    }
    return 1;
}

void multiplicarMatriz(int l, int c, vector<vector<int>>& m, int co) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << m[i][j] * co << " "; 
        }
        cout << endl;
    }
}

void metodo1212() {
    ifstream arquivo("DADOS1.txt");
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

	//int int **matriz = (int **)malloc(linha * sizeof(int *));
    //for (int i = 0; i < linha; i++) {
    //    matriz[i] = (int *)malloc(coluna * sizeof(int));
    // }
    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

    cout << "Digite agora o valor da constante a ser multiplicada pela matriz" << endl;
    int constante;
    cin >> constante;

    multiplicarMatriz(linhas, colunas, matriz, constante);
}

bool identidade(int l, int c, vector<vector<int>>& m){
	for(int i = 0; i<l; i++){
		for(int j=0; j<c; j++){
			if(i!=j){
				if(m[i][j]!=0){
					return false;
				}
			}
		}
	}
	return true;
	
}

void metodo1213(){
	 ifstream arquivo("DADOS2.txt");//fazer um arquivo com matriz identidade
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

    if(identidade(linhas, colunas, matriz)){
		cout<<"a matriz e identidade"<<endl;
	}else{
		cout<<"a matriz nao e identidade"<<endl;
	}
}

bool igual(int l1, int c1, vector<vector<int>>& m1, int l2, int c2, vector<vector<int>>& m2){
	if(l1 != l2 || c1 != c2){
		return false;
	}

	for(int i=0; i<l1; i++){
		for(int j=0; j<c1; j++){
			if(m1[i][j] != m2[i][j]){
				return false;
			}
		}
	}
	return true;
}

void metodo1214(){
	ifstream arquivo1("DADOS1.txt");
    int linhas1, colunas1;

    arquivo1 >> linhas1 >> colunas1; 

    vector<vector<int>> matriz1(linhas1, vector<int>(colunas1));
    lerMatriz(arquivo1, matriz1, linhas1, colunas1);
    arquivo1.close();

	ifstream arquivo2("DADOS3.txt");
    int linhas2, colunas2;

    arquivo2 >> linhas2 >> colunas2; 

    vector<vector<int>> matriz2(linhas2, vector<int>(colunas2));
    lerMatriz(arquivo2, matriz2, linhas2, colunas2);
    arquivo2.close();

    if(igual(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2)){
		cout<<"as matrizes sao iguais"<<endl;
	}else{
		cout<<"a matriz nao sao iguais"<<endl;
	}
}

void somaMatrizes(int l1, int c1, vector<vector<int>>& m1, int l2, int c2, vector<vector<int>>& m2){
	if(l1 != l2 || c1 != c2){
		cout<<"nao e possivel realizar a soma das matrizes"<<endl;
		return;
	}
	int l3 =l1;
	int c3= c1;
	vector<vector<int>> m3(l3, vector<int>(c3));

	for(int i=0; i<l1; i++){
		for(int j =0; j<c1; j++){
			m3[i][j] = m1[i][j] + m2[i][j];
		}
	}

	for(int i=0; i<l1; i++){
		for(int j =0; j<c1; j++){
			cout<<m3[i][j]<<" ";
		}
		cout<<endl;
	}
}

void metodo1215(){
	ifstream arquivo1("DADOS1.txt");
    int linhas1, colunas1;

    arquivo1 >> linhas1 >> colunas1; 

    vector<vector<int>> matriz1(linhas1, vector<int>(colunas1));
    lerMatriz(arquivo1, matriz1, linhas1, colunas1);
    arquivo1.close();

	ifstream arquivo2("DADOS3.txt");
    int linhas2, colunas2;

    arquivo2 >> linhas2 >> colunas2; 

    vector<vector<int>> matriz2(linhas2, vector<int>(colunas2));
    lerMatriz(arquivo2, matriz2, linhas2, colunas2);
    arquivo2.close();

	somaMatrizes(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2);

}

void somaLinhas(vector<vector<int>>& m, int l1, int l2, int c, int c1) {
    for (int j = 0; j < m[l1].size(); j++) {
        m[l1][j] = (m[l1][j] + matriz[l2][j]) * c;
    }

	for(int i=0; i<l1; i++){
		for(int j =0; j<c1; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}

void metodo1216(){
	 ifstream arquivo("DADOS1.txt");
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

    cout << "informe as duas linhas que deseja operar (0 a " << linhas - 1 << "): "<<endl;
    cin >> linha1 >> linha2;
    cout << "Informe a constante: "<<endl;
    cin >> constante;
    
    operacaoLinhas(matriz, linha1, linha2, constante);
}

void subtracaoLinhas(vector<vector<int>>& m, int l1, int l2, int c, int c1) {
    for (int j = 0; j < m[l1].size(); j++) {
        m[l1][j] = (m[l1][j] - matriz[l2][j]) * c;
    }

	for(int i=0; i<l1; i++){
		for(int j =0; j<c1; j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
}

void metodo1217(){
	ifstream arquivo("DADOS1.txt");
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

    cout << "informe as duas linhas que deseja operar (0 a " << linhas - 1 << "): "<<endl;
    cin >> linha1 >> linha2;
    cout << "Informe a constante: "<<endl;
    cin >> constante;
    
    subtracaoLinhas(matriz, linha1, linha2, constante);
}

int valorOuN1(vector<vector<int>>& m, int l, int c, int v){
	for(int i =0; i<l; i++){
		for(int j= 0; j<c; j++){
			if(m[i][j] == v){
				return i;
			}
		}
	}
	return 100;
}

void metodo1218(){
	ifstream arquivo("DADOS1.txt");
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

	int valor;

    cout << "informe o valor que deseja encontrar "<<endl;
    cin >> valor;

	int resultado = valorOuN1(matriz, linhas, colunas, valor);

	if(resultado==100){
		cout<<"o valor nao foi encontrado na matriz"<<endl;
	}else{
		cout<<"o valor foi encontrado na matriz na linha "<<resultado<<"."<<endl
	}
}

int valorOuN2(vector<vector<int>>& m, int l, int c, int v){
	for(int i =0; i<l; i++){
		for(int j= 0; j<c; j++){
			if(m[i][j] == v){
				return j;
			}
		}
	}
	return 100;
}


void metodo1219(){
	ifstream arquivo("DADOS1.txt");
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

	int valor;

    cout << "informe o valor que deseja encontrar "<<endl;
    cin >> valor;

	int resultado = valorOuN2(matriz, linhas, colunas, valor);

	if(resultado==100){
		cout<<"o valor nao foi encontrado na matriz"<<endl;
	}else{
		cout<<"o valor foi encontrado na matriz na coluna "<<resultado<<"."<<endl
	}
}

vector<vector<int>> transporMatriz(const vector<vector<int>>& matriz, int l, int c) {
    vector<vector<int>> transposta(c, vector<int>(l));
    
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            transposta[j][i] = matriz[i][j];  
        }
    }
    
    return transposta;  
}



void metodo1220() {
    ifstream arquivo("DADOS1.txt");
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

	vector<vector<int>> transposta = transporMatriz(matriz, linhas, colunas);
	  for(int i = 0; i < colunas; i++) {  
        for(int j = 0; j < linhas; j++) {
            cout << transposta[i][j] << " ";
        }
        cout << endl;
    }
}

bool condicao(vector<vector<int>>& m, int l, int c){
	for(int i = 0; i<l-1; i++){
		for(int j =0; j<c-1; j++){
			if(m[i][j]>m[i+1][j+1]){
				return true;
			}
		}
	}
	return false;
}


void metodo12E1() {
 ifstream arquivo("DADOS1.txt");
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

	if(condicao(matriz, linhas, colunas)){
		cout<<"a matriz tem essa condicao"<<endl;
	}else{
		cout<<"a matriz nao tem essa condicao"<<endl;
	}
}

void condicao2(vector<vector<int>>& m, int l, int c){
	for(int i = l; i>0; i--){
		for(int j =c; j>0; j--){
			cout<<m[i][j]<<" ";
		}
	}
	cout<<endl;
	
}

void metodo12E2() {
     ifstream arquivo("DADOS1.txt");
    int linhas, colunas;

    arquivo >> linhas >> colunas; 

    vector<vector<int>> matriz(linhas, vector<int>(colunas));
    lerMatriz(arquivo, matriz, linhas, colunas);
    arquivo.close();

	condicao2(matriz, linhas, colunas);
}


int main(){
	int opcao;


    do{
	    printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo1211\n2-metodo1212\n3-metodo1213\n4-metodo1214\n5-metodo1215\n6-metodo1216\n7-metodo1217\n8-metodo1218\n9-metodo1219\n10-metodo1220\n11-metodo12E1\n12-metodo12E2\n");
	    scanf("%d", &opcao);
		getchar();
	
	
	    switch(opcao){
	        case 1:
	        metodo1211();
	        break;
	        
	        case 2:
	        metodo1212();
	        break;
	        
	        case 3:
	        metodo1213();
	        break;
	        
	        case 4:
	        metodo1214();
	        break;
	        
	        case 5:
	        metodo1215();
	        break;
	        
	        case 6:
	        metodo1216();
	        break;
	        
	        case 7:
	        metodo1217();
	        break;
	        
	        case 8:
	        metodo1218();
	        break;
	        
	        case 9:
	        metodo1219();
	        break;
	        
	        case 10:
	        metodo1220();
	        break;
	        
	        case 11:
	        metodo12E1();
	        break;
	        
	        case 12:
	        metodo12E2();
	        break;
	
	    }

    }while(opcao !=0);

    return 0;
}
