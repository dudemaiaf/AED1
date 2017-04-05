#include <iostream>
#define TAM 11

using namespace std;

int imprimirVetor(int posicao, int vetor[]) {
	if(posicao == (TAM-1)){
		cout << vetor[posicao] << endl;
		return 0;
	}else{
		cout << vetor[posicao] << " ";
		return imprimirVetor(posicao + 1, vetor);
	}
}

int main(){
	int vetor[TAM] = {0 , 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	imprimirVetor(0, vetor);

	return 0;
}

