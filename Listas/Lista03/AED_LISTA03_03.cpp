#include <iostream>
#define TAM 10

using namespace std;

void preencherVetor(int *vetor) {
  for(int i = 0; i < TAM; i++) {
    vetor[i] = i;
  }
}

void imprimirVetor(int *vetor, int comeco, int fim) {
  if(comeco == (fim - 1)) {
    cout << vetor[comeco];
  }else {
    cout << vetor[comeco] << " ";
    return imprimirVetor(vetor, comeco + 1, fim);
  }
}

int main() {
  int vetor[TAM];
  preencherVetor(vetor);
  int comeco = 0;
  imprimirVetor(vetor, comeco, TAM);
  return 0;
}
