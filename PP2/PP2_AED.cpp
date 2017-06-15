#include <iostream>
#include <cstdlib>

#define TAM 787 /* Tamanho padrão definido pelo professor p/ tabela hash */

using namespace std;

template <class T>
class LE{
private:
  T *array;
  int limite;
  int ultimaPosicao;
public:
  LE() {
    this->limite = TAM;
    array = new T[this->limite];
    ultimaPosicao = 0;
  }

  LE(int limite) {
    this->limite = limite+1;
    array = new T[this->limite];
    ultimaPosicao = 0;
  }
  int getLimite();
  int getUltimaPosicao();
  T getELemento(int posicaoEscolhida);
  void inserir(T Chave);
};

int main() {




  /* MAIN */





  return 0;
}

template <class T>
int LE<T>::getLimite() {
  return limite;
}

template <class T>
int LE<T>::getUltimaPosicao() {
  return ultimaPosicao;
}

template <class T>
T LE<T>::getELemento(int posicaoEscolhida){
  return array[posicaoEscolhida];
}

template <class T>
void LE<T>::inserir(T Chave) {
  if(ultimaPosicao < limite){
    ultimaPosicao ++;
    array[ultimaPosicao] = Chave;
  }else{
    cout << "\nLista cheia! \n";
  }
}
