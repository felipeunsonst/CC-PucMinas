//FELIPE COSTA UNSONST
//1523384

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream> //biblioteca para operar com arquivo em c++
#include <vector>
using namespace std;

void metodo1111(){
	//ofstream -- saida, saindo do programa e indo para o arquivo
	//ifstream --entrada, entrando do arquivo e indo para o programa

	ofstream arq; 
	arq.open("DADOS.txt");
	
	int n;
	cout<<"digite a quantidade de numeros aleatorios a serem gerados"<<endl;
	cin>>n;

	int array[n];
	srand(time(0));

	arq<<n<<endl;
	for(int i = 0; i<n; i++){
		array[i] = rand() % 100;
	}

	for(int i = 0; i<n; i++){
		arq<<array[i]<<endl;
	}

	arq.close();
}

int maiorPar(ifstream& arquivo){
	int maior = 0;
	int numero;
	while(arquivo >> numero){
		if(numero %2==0){
			if(numero>maior){
				maior = numero;
			}
		}
	}

	return maior;
}

void metodo1112(){
	ifstream arquivo;
	arquivo.open("DADOS1.txt");

	int resultado = maiorPar(arquivo);

	if(resultado %2 ==0){
		cout<<"o maior par e "<<resultado<<endl;
	} else{
		cout<<"nao havia par no arquivo" <<endl;
	}
}

int menorPar(ifstream& arquivo){
	int menor =1000;
	int numero;
	while(arquivo >> numero){
		if(numero %2==0 && numero%3==0){
			if(numero<menor){
				menor = numero;
			}
		}
	}

	return menor;
}

void metodo1113(){
	ifstream arquivo;
	arquivo.open("DADOS1.txt");

	int resultado = menorPar(arquivo);
	if(resultado %2 ==0 && resultado %3==0){
		cout<<"o maior par e multiplo de 3 e "<<resultado<<endl;
	} else{
		cout<<"nao havia par multiplo de 3 no arquivo" <<endl;
	}
}

int somaArray(ifstream& arquivo, int p, int u){
	int soma = 0;
    int numero;
    int posicao = 0;

    while (arquivo >> numero) {
        if (posicao > p && posicao < u) {
            soma += numero;
        }
        posicao++; 
    }

    return soma;
}

void metodo1114(){
	ifstream arquivo;
	arquivo.open("DADOS1.txt");

	int x, y;
	cout<<"digite duas posicoes do arquivo"<<endl;
	cin>>x;
	cin>>y;

	int resultado = somaArray(arquivo, x, y);
	cout<<resultado<<endl;
}

int mediaArray(ifstream& arquivo, int p, int u){
	int soma = 0;
    int numero;
    int posicao = 0;
	int media = 0;

    while (arquivo >> numero) {
        if (posicao >= p && posicao < u) {
            soma += numero;
        }
        posicao++; 
    }

	media = soma/(u-p);

    return media;
}

void metodo1115(){
	ifstream arquivo;
	arquivo.open("DADOS1.txt");

	int x, y;
	cout<<"digite duas posicoes do arquivo"<<endl;
	cin>>x;
	cin>>y;

	int resultado = mediaArray(arquivo, x, y);
	cout<<resultado<<endl;
}

int positivosArray(ifstream& arquivo){
	int negativo = 0;
    int numero;
    int posicao = 0;
	int cont = 0;

    while (arquivo >> numero) {
        if (numero<negativo) {
            cont++;
        }
        posicao++; 
    }

    return cont;
}

void metodo1116(){
	ifstream arquivo;
	arquivo.open("DADOS1.txt");

	int resultado = positivosArray(arquivo);

	if(resultado>0){
		cout<<"nao sao todos os valores do aranjo que sao positivos"<<endl;
	} else{
		cout<<"todos os elementos do arranjo sao positivos"<<endl;
	}
	
}

int ordenadoOuN(ifstream& arquivo){
	int negativo = 0;
    int numero;
    int posicao = 0;
	int cont = 0;

    while (arquivo >> numero) {
        if (numero<negativo) {
            cont++;
        }
        posicao++; 
    }

    return cont;
}

void metodo1117(){
	ifstream arquivo;
	arquivo.open("DADOS1.txt");

	int resultado = ordenadoOuN(arquivo);

	if(resultado>0){
		cout<<"nao sao todos os valores do aranjo que sao positivos"<<endl;
	} else{
		cout<<"todos os elementos do arranjo sao positivos"<<endl;
	}
	
}

int acharValor(ifstream& arquivo, int n1, int n2, int b){
	int negativo = 0;
    int numero;
    int posicao = 0;
	int cont = 0;

    while (arquivo >> numero) {
        if (b>n1 && b<n2) {
            cont++;
        }
        posicao++; 
    }

    return cont;
}

void metodo1118(){
	ifstream arquivo;
	arquivo.open("DADOS1.txt");

	int x, p, y;

	cout<<"informe os numeros que definirao o intervalo"<<endl;
	cin>>x;
	cin>>y;

	cout<<"informe o numero a ser encontrado"<<endl;
	cin>>p;

	int resultado = acharValor(arquivo, x, y, p);

	if(resultado>0){
		cout<<"o numero foi encontrado"<<endl;
	}else{
		cout<<"o numero nao foi encontrado"<<endl;
	}
}

void escalar(vector<int>& dados, int inicio, int fim, int constante) {
    for (int i = inicio; i <= fim; i++) {
        arr[i] *= constante;  
    }
}

void metodo1119(){
	ifstream arquivo("DADOS.TXT");  ura
    
    vector<int> dados;  
    int numero;

    while (arquivo >> numero) {
        dados.push_back(numero);
    }

    arquivo.close();  

    int constante, inicio, fim;
    cout << "digite a constante: ";
    cin >> constante;

    cout << "digite a posição inicial (0 a " << tamanho - 1 << "): ";
    cin >> inicio;

    cout << "digite a posição final (0 a " << tamanho - 1 << "): ";
    cin >> fim;

    if (inicio < 0 || fim >= tamanho || inicio > fim) {
        cerr << "intervalo inválido!" << endl;
        return 1;
    }

    escalar(dados, inicio, fim, constante);

	cout << "dados após a multiplicação:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << dados[i] << " ";
    }
    cout << endl;
    
}

void decrescente(ifstream& arquivo) {
    int numero;
    int cont = 0;

    while (arquivo >> numero) {
        cont++;
    }

    arquivo.clear();              // limpa os flags de erro (como EOF)
    arquivo.seekg(0, ios::beg);   // retorna ao início do arquivo

    int arr[cont];  
    int posicao = 0;

    while (arquivo >> numero) {
        arr[posicao] = numero;
        posicao++;
    }

    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {  // troca para ordem decrescente
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < cont; k++) {
        cout << arr[k] << endl;
    }
}

void metodo1120() {
    ifstream arquivo;
    arquivo.open("DADOS1.txt");

    decrescente(arquivo);

    arquivo.close();  
}

bool igual(vector<int>& arr1, vector<int>& arr2, int tam1, int tam2) {
    if (tam1 != tam2) {
        return false;  
    } else {
        for (int i = 0; i < tam1; i++) {
            if (arr1[i] != arr2[i]) {
                return false; 
            }
        }
    }
    return true;  
}

void metodo11E1() {
    vector<int> array1;
    vector<int> array2;
    int num1;
    int num2;

    cout << "digite os elementos do primeiro array (para encerrar, digite um caractere não numérico):" << endl;
    while (cin >> num1) {
        array1.push_back(num1);
    }

    int tamanho1 = array1.size();

    cout << "digite os elementos do segundo array (para encerrar, digite um caractere não numérico):" << endl;
    while (cin >> num2) {
        array2.push_back(num2);
    }

    int tamanho2 = array2.size();

    bool resultado = igual(array1, array2, tamanho1, tamanho2);

    if (!resultado) {
        cout << "os arranjos não são iguais" << endl;
    } else {
        cout << "os arranjos são iguais" << endl;
    }
}

vector<int> diferenca(vector<int>& arr1, vector<int>& arr2, int tam1, int tam2) {
    vector<int> arr3;
    for (int i = 0; i < tam1; i++) {
        arr3.push_back(abs(arr1[i] - arr2[i]));
    }
    return arr3;
}

void metodo11E2() {
    vector<int> array1;
    vector<int> array2;
    int num1;
    int num2;

    cout << "digite os elementos do primeiro array (para encerrar, digite um caractere não numérico):" << endl;
    while (cin >> num1) {
        array1.push_back(num1);
    }
    cin.clear(); // limpa o estado de erro do cin após entrada inválida
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignora o restante da linha

    int tamanho1 = array1.size();

    cout << "digite os elementos do segundo array (para encerrar, digite um caractere não numérico):" << endl;
    while (cin >> num2) {
        array2.push_back(num2);
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    int tamanho2 = array2.size();

    if (tamanho1 == tamanho2) {
        vector<int> resultado = diferenca(array1, array2, tamanho1, tamanho2);
        
        for (int i = 0; i < tamanho1; i++) {
            cout << resultado[i] << " ";
        }
        cout << endl;

    } else {
        cout << "os arrays possuem tamanhos diferentes, logo, não será realizada a diferença." << endl;
    }
}

int main(){
int opcao;


    do{
    printf("digite o numero correspondente ao metodo desejado\n0-encerrar programa\n1-metodo1111\n2-metodo1112\n3-metodo1113\n4-metodo1114\n5-metodo1115\n6-metodo1116\n7-metodo1117\n8-metodo1118\n9-metodo1119\n10-metodo1120\n11-metodo11E1\n12-metodo11E2\n");
    scanf("%d", &opcao);
	getchar();


    switch(opcao){
        case 1:
        metodo1111();
        break;
        
        case 2:
        metodo1112();
        break;
        
        case 3:
        metodo1113();
        break;
        
        case 4:
        metodo1114();
        break;
        
        case 5:
        metodo1115();
        break;
        
        case 6:
        metodo1116();
        break;
        
        case 7:
        metodo1117();
        break;
        
        case 8:
        metodo1118();
        break;
        
        case 9:
        metodo1119();
        break;
        
        case 10:
        metodo1120();
        break;
        
        case 11:
        metodo11E1();
        break;
        
        case 12:
        metodo11E2();
        break;

    }

    }while(opcao !=0);

    return 0;
}

