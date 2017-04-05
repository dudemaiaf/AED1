#include <iostream>
#define TAM 10
#define NIL -1

using namespace std;

int somarRecursivo(int vetor[], int metade1, int metade2){
	if(metade1 == 0 && metade2 == TAM-1){
		return vetor[metade1] + vetor[metade2];
	}else{
		return (vetor[metade1] + vetor[metade2]) + somarRecursivo(vetor, metade1 - 1, metade2 + 1);
	}
}

int main(){
	int vetor[TAM] = {1,2,3,4,5,6,7,8,9,10};
	int metade1 = (TAM/2)-1;
	int metade2 = metade1 + 1;
	cout << somarRecursivo(vetor, metade1, metade2) << endl;

	return 0;
}
