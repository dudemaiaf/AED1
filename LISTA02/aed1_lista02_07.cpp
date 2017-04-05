#include <iostream>

using namespace std;

class Pedra {
private:
	int esquerda;
	int direita;
public:
	Pedra();
	Pedra(int, int);
	void print();
	bool validarPedra();
	void setEsquerda(int);
	void setDireita(int);
};

bool Pedra::validarPedra(){
	if((esquerda < 0 || esquerda > 6) || (direita < 0 || direita > 6)){
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

void Pedra::setEsquerda(int esquerda){
	this->esquerda = esquerda;
}

void Pedra::setDireita(int direita){
	this->direita = direita;
}

Pedra::Pedra():Pedra(0,0){};

Pedra::Pedra(int esquerda, int direita){
	this->esquerda = esquerda;
	this->direita = direita;
}

int main(){
	Pedra pedra;
	pedra.setEsquerda(1);
	pedra.setDireita(1);
	pedra.print();
	return 0;
}

