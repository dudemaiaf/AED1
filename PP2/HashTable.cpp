#include <iostream>
#define TAM 6
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
  cout << "NULL";
}

template <class T, class U>
class TabelaHash {
private:
  LE<T> *HashTable;
  int funcaoHash(U chave) {return chave%TAM;}
public:
  TabelaHash() {
    HashTable = new LE<T>(TAM);
  }
  void inserir(U chave);
  void mostrar();
};

template <class T, class U>
void TabelaHash<T,U>::inserir(U chave) {
  int posicao = funcaoHash(chave);
  HashTable->getELemento(posicao).inserir(chave);
}

template <class T, class U>
void TabelaHash<T,U>::mostrar() {
  for(int i = 1; i <= TAM; i ++) {
    HashTable->getELemento(i).mostrar();
    cout << endl;
  }
}

int main() {
  TabelaHash < LDE<int> , int> teste;
  teste.inserir(1);
  teste.inserir(2);
  teste.inserir(3);
  teste.inserir(4);
  teste.inserir(5);
  teste.mostrar();
  teste.inserir(7);
  teste.inserir(8);
  teste.inserir(9);
  teste.inserir(10);
  teste.inserir(11);
  teste.mostrar();

  return 0;
}
