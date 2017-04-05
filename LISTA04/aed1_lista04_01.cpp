#include <iostream>

using namespace std;

int imprimirInteiros(int comeco, int fim){
	if(comeco == fim){
		cout << fim << endl;
		return 0;
	}else{
		cout << comeco << " ";
		return imprimirInteiros(comeco + 1, fim);
	}
}

int main(){
	int comeco, fim;
	fim = 100;
	comeco = fim - (fim - 1);
	imprimirInteiros(comeco, fim);

	return 0;
}

