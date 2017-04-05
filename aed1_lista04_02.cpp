#include <iostream>

using namespace std;

int imprimirInteiros(int numero){
	if(numero == 1){
		cout << numero << endl;
		return 0;
	}else{
		cout << numero << " ";
		return imprimirInteiros(numero - 1);
	}
}

int main(){
	int numero;
	numero = 100;
	imprimirInteiros(numero);

	return 0;
}

