#include <iostream>

using namespace std;

class Pedra {
public:
	int esquerda;
	int direita;

	Pedra();
	Pedra(int, int);
	void print();
	void validarPedra();
};

void Pedra::validarPedra(){
	if((esquerda < 0 || esquerda > 6) && (direita > 0 || direita > 6)){
		cout << "Pedra invalida" << endl;
	}else{
		cout << "Pedra valida" << endl;
	}
}

void Pedra::print(){
	cout << "[" << esquerda << "|" << direita << "]" << endl;

}

Pedra::Pedra():Pedra(0,0){};

Pedra::Pedra(int esquerda, int direita){
	this->esquerda = esquerda;
	this->direita = direita;
}

int main(){
	Pedra pedra(6, 6);
	pedra.validarPedra();
	pedra.print();
	return 0;
}

