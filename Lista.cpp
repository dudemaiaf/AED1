#include <iostream>
#include "Lista.hpp"

void Lista::insere(int numero) {
	if(n < TAM){
		n ++;
		vetor[n] = numero;
	}else{
		cout << "\nLista cheia!" << endl;
	}
}

void Lista::mostra() {
	if(n > 0){
		for(int i = 1; i <= n; i ++){
			cout << vetor[i] << " ";
		}
	}else{
		cout << "\nLista vazia!" << endl;
	}
}

int* Lista::busca(int Chave) {
	vetor[0] = Chave;
	int i = n;
	while(Chave != vetor[i]) {
		i --;
	}
	if(i > 0){
		return &vetor[i];
	}else{
		return NULL;
	}
}

void Lista::remove(int posicao, int &memoria) {
	if(posicao <= n && posicao > 0){
		memoria = vetor[posicao];
		for(int i = posicao; i < n; i ++){
			vetor[i] = vetor[i + 1];
		}
		n --;
	}else{
		cout << "\nLista vazia ou posicao invalida" << endl;
	}
}
