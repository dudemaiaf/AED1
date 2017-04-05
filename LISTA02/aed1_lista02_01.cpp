#include <iostream>

using namespace std;

class Pedra {
public:
	int esquerda;
	int direita;

};


int main(){
	Pedra pedra;
	pedra.esquerda = 1;
	pedra.direita = 5;

	cout << "[" << pedra.esquerda << "|" << pedra.direita << "]" << endl;

	return 0;
}

