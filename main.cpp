#include <iostream>
#include "Lista.hpp"
#define TAM 10

using namespace std;

int main() {
	Lista l(TAM);
	l.insere(0);
	l.insere(1);
	l.insere(2);
	l.insere(3);
	l.insere(4);
	l.insere(5);
	l.insere(6);
	l.insere(7);
	l.insere(8);


	l.mostra();

	int* a = l.busca(5);
	if(a != NULL){
		cout << "\nO elemento " << *a << " foi encontrado no Vetor" << endl;
	}else{
		cout << "\nNao foi encontrado" << endl;
	}

	int MEM;
	l.remove(2, MEM);
	l.mostra();



	return 0;
}

