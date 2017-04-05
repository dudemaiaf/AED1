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
	Pedra pedra(2, 6);
	pedra.print();
	pedra.esquerda = 0;
	pedra.direita = 0;
	pedra.print();
	return 0;
}

