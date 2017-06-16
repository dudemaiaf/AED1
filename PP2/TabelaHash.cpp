#include <iostream>
#include <cstdlib>
#define TAM 10

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
    this->limite = limite;
    array = new T[this->limite];
    ultimaPosicao = 0;
  }
  int getLimite();
  int getUltimaPosicao();
  T getELemento(int posicaoEscolhida);
  void inserir(T Chave);
};

template <class T>
class No {
private:
  T chave;
  No <T> *prox;
  No <T> *pred;
public:
  No() {
	  prox = NULL;
    pred = prox;
  }
  void setChave(T chave);
  T getChave();
  void setProx(No <T> *prox);
  void setPred(No <T> *pred);
  No* getProx();
  No* getPred();
};

template <class T>
class LDE {
private:
  No <T> *prim, *ult;
public:
  LDE() {
    prim = new No<T>();
    prim->setProx(NULL);
    prim->setPred(NULL);
    ult = prim;
  }
  void inserir(T chave);
  void remover(No<T>* removido, T &retorno);
  No<T>* buscar(T chave);
  void mostrar();
};

// template <class T>
// class TabelaHash {
// private:
//   LE<T>** tabelaHash;
//   int calculoHash(int chave) {
//     return chave % TAM;
//   }
// public:
//   TabelaHash() {
//     tabelaHash = new LE<T>*();
//     for(int i = 0; i < TAM; i ++) {
//       tabelaHash[i].inserir(new LDE<int>());
//     }
//   }
//   void inserir(int chave);
//   void mostrar();
// };
//
// template <class T>
// void TabelaHash<T>::inserir(int chave) {
//   int posicao = calculoHash(chave);
//   tabelaHash[posicao]->inserir(chave);
// }
//
// template <class T>
// void TabelaHash<T>::mostrar() {
//   for(int i = 0; i < TAM; i ++) {
//     cout << "[" << (i+1) << "] ";
//     tabelaHash[i]->mostrar();
//     cout << endl;
//   }
// }

int main() {
  LDE<int> *listaEncadeada;
  listaEncadeada = new LDE<int>[3];
  listaEncadeada[0].inserir(0);
  listaEncadeada[0].inserir(1);
  listaEncadeada[0].inserir(2);
  listaEncadeada[0].mostrar();
  listaEncadeada[1].inserir(3);
  listaEncadeada[1].inserir(4);
  listaEncadeada[1].inserir(5);
  listaEncadeada[1].mostrar();
  listaEncadeada[2].inserir(6);
  listaEncadeada[2].inserir(7);
  listaEncadeada[2].inserir(8);
  listaEncadeada[2].mostrar();


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
    array[ultimaPosicao] = Chave;
    ultimaPosicao ++;
  }else{
    cout << "\nLista cheia! \n";
  }
}

template <class T>
void No<T>::setChave(T chave){
  this->chave = chave;
}

template <class T>
T No<T>::getChave() {
  return chave;
}

template <class T>
void No<T>::setProx(No <T> *prox) {
  this->prox = prox;
}

template <class T>
void No<T>::setPred(No <T> *pred) {
  this->pred = pred;
}

template <class T>
No<T>* No<T>::getProx() {
  return prox;
}

template <class T>
No<T>* No<T>::getPred() {
  return pred;
}

template <class T>
void LDE<T>::inserir(T chave) {
  ult->setProx(new No<T>());
  ult->getProx()->setPred(ult);
  ult = ult->getProx();
  ult->setProx(NULL);
  ult->setChave(chave);
}

template <class T>
void LDE<T>::remover(No<T>* removido, T &retorno) {
  if(prim == ult || removido == NULL) {
      cout << "\nImpossível remover\n";
  }else{
    retorno = removido->getChave();
    removido->getPred()->setProx(removido->getProx());
    if(removido->getProx() == NULL) {
      ult = removido->getPred();
    }
  }
}

template <class T>
No<T>* LDE<T>::buscar(T chave) {
  No <T> *p = prim->getProx();
  while(p != NULL){
    if(p->getChave() == chave) {return p;}
    p = p->getProx();
  }
  if(p == NULL){return p;}
}

template <class T>
void LDE<T>::mostrar() {
  No <T> *p = prim->getProx();
  while(p != NULL) {
    cout << p->getChave() << " -> ";
    p = p->getProx();
  }
  cout << endl;
}
