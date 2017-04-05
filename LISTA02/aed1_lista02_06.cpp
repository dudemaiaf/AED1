#include <iostream>

using namespace std;

class Pedra {
public:
	int esquerda;
	int direita;

	Pedra();
	Pedra(int, int);
	void print();
	bool validarPedra();
};

bool Pedra::validarPedra(){
	if((esquerda < 0 || esquerda > 6) && (direita > 0 || direita > 6)){
		return false;
	}else{
		return true;
	}
}

void Pedra::print(){
	if(validarPedra()){
		cout << "[" << esquerda << "|" << direita << "]" << endl;
	}else{
		cout << "Pedra invalida" << endl;
	}

}

Pedra::Pedra():Pedra(0,0){};

Pedra::Pedra(int esquerda, int direita){
	this->esquerda = esquerda;
	this->direita = direita;
}

int main(){
	Pedra pedra(6, 6);
	pedra.print();
	return 0;
}

