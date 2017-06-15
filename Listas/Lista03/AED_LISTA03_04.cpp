#include <iostream>

using namespace std;

template <class T>
int buscaSequencial(T *vetor, T chave, int comeco, int fim) {
  if(vetor[comeco] == chave) {
    return comeco;
  }else{
    if(comeco == (fim - 1)) {
      return -1;
    }else {
      return buscaSequencial(vetor, chave, comeco + 1, fim);
    }
  }
}
int main() {
  string vetor[] = {"Oi", "tudo", "bem", "?"};
  int comeco = 0, fim = 4;
  string chave = "tudo";
  cout << buscaSequencial(vetor, chave, comeco, fim);
  return 0;
}
