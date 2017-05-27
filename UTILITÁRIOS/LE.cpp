#include <iostream>

using namespace std;

class LE{
private:
  string *vetor;
  int tamanho;
  int ultimo;
public:
  LE(int tamanho) {
    this->tamanho = tamanho+1;
    vetor = new string[this->tamanho];
    ultimo = 0;
  }

  void insere(string Chave) {
    if(ultimo < tamanho){
      ultimo ++;
      vetor[ultimo] = Chave;
    }else{
      cout << "\nLista cheia! \n";
    }
  }

  void mostra() {
    for(int i = 0; i <= ultimo; i++) {
      cout << vetor[i] << " ";
    }
    cout << endl;
  }

  string busca(string Chave){
    vetor[0] = Chave;
    int i = ultimo;
    while(Chave != vetor[i]) {
      i --;
    }if(i > 0){
      return vetor[i];
    }else{
      return "";
    }
  }
};
