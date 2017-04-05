#include <iostream>
#define TAM 10
#define NIL -1

using namespace std;

int obterMaximo(int vetor[], int tamanho){
	int maximo = 0, indice = 0;
	for(int i = 0; i < tamanho; i ++){
		if(vetor[i] > maximo){
			maximo = vetor[i];
			indice = i;
		}
	}
	return indice;
}

int ordenarVetor(int vetor[], int comeco, int tamanho){
	if(tamanho == 0){
		return 0;
	}else{
		int maximo = obterMaximo(vetor, tamanho), temp = vetor[tamanho-1];
		vetor[tamanho - 1] = vetor[maximo];
		vetor[maximo] = temp;
		return ordenarVetor(vetor, comeco, tamanho-1);
	}
}
void imprimirVetor(int vetor[]) {
	for(int i = 0; i < TAM; i ++){
		cout << vetor[i] << " ";
	}
	cout << endl;
}
int main(){
	int vetor[TAM] = {9, 5, 3, 2, 4, 6, 7, 0, 1, 8};
	int comeco = 0, fim = TAM;
	imprimirVetor(vetor);
	ordenarVetor(vetor, comeco, fim);
	imprimirVetor(vetor);

	return 0;
}
