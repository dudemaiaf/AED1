#ifndef Lista_h
#define Lista_h

#include <iostream>
using namespace std;

class Lista {
private:
	int *vetor;
	int TAM;
	int n;
public:
	Lista(){}
	Lista(int TAM) {
		n = 0;
		this->TAM = TAM;
		vetor = new int[TAM];
	}
	void insere(int numero);
	void mostra();
	int* busca(int Chave);
	void remove(int Pos, int &Mem);
};

#endif
