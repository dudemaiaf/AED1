#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class No{
private:
  T chave;
  No *dir, *esq;
public:
  No() {
    dir = NULL;
    esq = NULL;
  }
  void setChave(T chave);
  T getChave();
  void setEsq(No <T> *esq);
  void setDir(No <T> *dir);
  No* getEsq();
  No* getDir();
};

template <class T>
class ABB {
private:
  No<T> *raiz;
  void busca(T chave, No<T> *p);
  void percorre(No<T> *p);
  No<T>* insere(T chave, No<T> *p);
  void cria() {raiz = NULL;}
public:
  ABB() { cria(); }
  void inserir(T chave) {
    insere(chave, raiz);
  }
  void remover(T chave);
  void buscar(T chave) {
    busca(chave, raiz);
  }
  void percorrer() {
    percorre(raiz);
  }
  No<T>* getRaiz() {
    return raiz;
  }
};

template <class T>
void ABB<T>::busca(T chave, No<T> *p) {
  if(p == NULL) {
    cout << "\nNão foi encontrado\n";
  } else {
    if(chave > p->getChave()) {
      busca(chave, p->getDir());
    }if(chave < p->getChave()) {
      busca(chave, p->getEsq());
    } else {
      chave = p->getChave();
    }
  }
}

template <class T>
void ABB<T>::percorre(No<T> *p) {
  if(p != NULL) {
    percorre(p->getEsq());
    cout << p->getChave() << " ";
    percorre(p->getDir());
  }
}

template <class T>
No<T>* ABB<T>::insere(T chave, No<T> *p) {
  if(p == NULL) {
    p = new No<T>();
    p->setChave(chave);
    p->setEsq(NULL);
    p->setDir(NULL);
    return p;
  } else {
    if(chave > p->getChave()) {
      insere(chave, p->getDir());
    } if(chave < p->getChave()) {
      insere(chave, p->getEsq());
    } else {
      cout << "\nItem já existente\n";
    }
  }
}

/* ---------------------------------------------------------------------- */

int main() {
  ABB<int> binaryTree;
  binaryTree.inserir(8);
  binaryTree.inserir(5);
  binaryTree.inserir(9);
  binaryTree.percorrer();
  if(binaryTree.getRaiz() == NULL) {
    cout << "\nRaiz nula\n";
  }

  return 0;
}

/* --------------------------------------------------------------------- */

template <class T>
void No<T>::setChave(T chave){
  this->chave = chave;
}

template <class T>
T No<T>::getChave() {
  return chave;
}

template <class T>
void No<T>::setEsq(No <T> *esq) {
  this->esq = esq;
}

template <class T>
void No<T>::setDir(No <T> *dir) {
  this->dir = dir;
}

template <class T>
No<T>* No<T>::getEsq() {
  return esq;
}

template <class T>
No<T>* No<T>::getDir() {
  return dir;
}
