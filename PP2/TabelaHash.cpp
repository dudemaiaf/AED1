#include <iostream>
#include <cstdlib>
#include <cstdio>

#define TAM 787

using namespace std;

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

template <class T>
class TabelaHash {
private:
  LDE<T> *listaEncadeada;
protected:
  int calculoHash(T chave) {return chave%TAM;}
public:
  TabelaHash(int tamanho) {
    listaEncadeada = new LDE<T>[tamanho];
  }
  void inserir(T chave);
  void mostrar();
  int verificarRepeticao(T chave);
};

template <class T>
int TabelaHash<T>::verificarRepeticao(T chave) {
  int posicaoCalculada = calculoHash(chave);
  No<T> *validar = listaEncadeada[posicaoCalculada].buscar(chave);
  if(validar == NULL) {
    return 0;
  } else {
    return 1;
  }
}

int main() {
  TabelaHash<int> hashTable(TAM);
  FILE *arquivo;
  arquivo = fopen("chaves.txt", "rt");
  char linha[100], *result;
  int i = 1;
  while(!feof(arquivo)) {
    int numero;
    result = fgets(linha, 100, arquivo);
    if(result) {
      numero = atoi(linha);
      hashTable.inserir(numero);
    }
    i++;
  }
  fclose(arquivo);
  hashTable.mostrar();
  return 0;
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


template <class T>
void TabelaHash<T>::inserir(T chave) {
  int posicaoCalculada = calculoHash(chave);
  if(verificarRepeticao(chave) == 0) {
    listaEncadeada[posicaoCalculada].inserir(chave);
  }
}

template <class T>
void TabelaHash<T>::mostrar() {
  for(int i = 0; i < TAM; i ++) {
    cout << "[" << (i+1) << "] ";
    listaEncadeada[i].mostrar();
  }
}
