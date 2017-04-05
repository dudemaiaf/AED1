#include <iostream>
#define TAM 2

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

Pedra criarVetor(Pedra *vetor){
	int direita, esquerda;
	Pedra pedra;
	for(int i = 0; i < TAM; i ++){
		cout << "\nPedra #" << i + 1 << ":" << endl;
		cout << "Lado esquerdo: ";
		cin >> esquerda;
		cout << "Lado direito: ";
		cin >> direita;
		pedra.setEsquerda(esquerda);
		pedra.setDireita(direita);
		vetor[i] = pedra;
	}
}

void imprimirVetor(Pedra *vetor){
	for(int i = 0; i < TAM; i ++){
		vetor[i].print();
	}
}

int main(){
	Pedra *pedras = new Pedra[TAM];
	criarVetor(pedras);
	imprimirVetor(pedras);

	return 0;
}

