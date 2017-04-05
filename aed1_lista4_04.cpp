#include <iostream>
#define TAM 10
#define NIL -1

using namespace std;

int buscaBinaria(int chave, int vetor[], int i, int j) {
	if(i <= j){
		int m = (i + j)/2;
		if(chave == vetor[m]){
			return m;
		}if(chave < vetor[m]){
			return buscaBinaria(chave, vetor, i, m-1);
		}else{
			return buscaBinaria(chave, vetor, m + 1, j);
		}
	}else{
		return NIL;
	}
	return 0;
}

void validarBusca(int chave, int vetor[], int i, int j){
	if(buscaBinaria(chave, vetor, i, j) != NIL){
		cout << "\nVetor[" << buscaBinaria(chave, vetor, i, j) << "] = " << chave << endl;
	}else{
		cout << "\nNao houve exito na busca" << endl;
	}
}

int main(){
	int vetor[TAM] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int chave = 0;
	int i = 0;
	int j = TAM-1;
	validarBusca(chave, vetor, i, j);

	return 0;
}
