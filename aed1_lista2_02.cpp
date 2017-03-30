 #include <iostream>

using namespace std;

class Pedra {
public:
	int esquerda;
	int direita;

	void print();
};

void Pedra::print(){
	cout << "[" << esquerda << "|" << direita << "]" << endl;
}

int main(){
	Pedra pedra;
	pedra.esquerda = 2;
	pedra.direita = 5;
	pedra.print();
	return 0;
}

