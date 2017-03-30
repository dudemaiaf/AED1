#include <iostream>

using namespace std;

class Pedra {
public:
	int esquerda;
	int direita;

	Pedra();
	Pedra(int, int);
	void print();
};

void Pedra::print(){
	cout << "[" << esquerda << "|" << direita << "]" << endl;
}

Pedra::Pedra():Pedra(0,0){};

Pedra::Pedra(int esquerda, int direita){
	this->esquerda = esquerda;
	this->direita = direita;
}

int main(){
	Pedra pedra;
	pedra.print();
	pedra.esquerda = 2;
	pedra.direita = 5;
	pedra.print();
	return 0;
}

