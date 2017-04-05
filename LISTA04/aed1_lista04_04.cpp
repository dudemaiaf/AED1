#include <iostream>
#define TAM 10
#define posInicial 0
#define NIL -1

using namespace std;

int buscaSequencial(int inicio, int vetor[], int chave){
	if((inicio != (TAM-1)) && (vetor[inicio] == chave)){
		return inicio;
	}if((inicio != (TAM-1)) && (vetor[inicio] != chave)){
		return buscaSequencial(inicio + 1, vetor, chave);
	}else{
		return NIL;
	}
}

void validarBusca(int inicio, int vetor[], int chave){
	if(buscaSequencial(inicio, vetor, chave) != NIL){
		cout << "\nVetor[" << buscaSequencial(inicio, vetor, chave) << "] = " << chave << endl;
	}else{
		cout << "\nElemento nao encontrado" << endl;
	}
}

int main(){
	int vetor[TAM] = {0, 1, 4, 3, 10, 40, 50, 20, 34, 65};
	int chave = 40;
	validarBusca(posInicial, vetor, chave);
	return 0;
}

