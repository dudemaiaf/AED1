#include <iostream>
#include <cstdlib>
#include <fstream>

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
  int getTamanho();
  No<T>* getPrim() {
    return prim;
  }
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
  LDE<T> getLista(int posicao) {
    return listaEncadeada[posicao];
  }
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

int* quickSort(int *array, int esq, int dir) {
  int i = esq, j = dir;
  int temp;
  int pivot = array[(esq + dir) / 2];
  while(i <= j) {
    while(array[i] < pivot) {
      i ++;
    }
    while(array[j] > pivot) {
      j --;
    }
    if(i <= j) {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i ++;
      j --;
    }
  }
  if(esq < j) {
    quickSort(array, esq, j);
  }if(i < dir) {
    quickSort(array, i, dir);
  }
}

int main() {
  TabelaHash<int> hashTable(TAM);

  /* ----- PARTE DE PREENCHER TABELA HASH */
  string linha;
  ifstream chaves ("chaves.txt");
  if(chaves.is_open()) {
    while(getline(chaves,linha)) {
      int numero;
      numero = atoi(linha.c_str());
      hashTable.inserir(numero);
    }
    chaves.close();
  }

  /* ----------------------------------- */

  /* ----- PARTE DE CAPTURAR A LINHA INFORMADA E IMPPRIMIR ----- */

  int numeroEscolhido;
  cin >> numeroEscolhido;
  int *linhaHash;
  linhaHash = new int[hashTable.getLista(numeroEscolhido%TAM).getTamanho()];
  int *linhaHash2 = new int[hashTable.getLista(numeroEscolhido%TAM).getTamanho()];
  linhaHash2 = linhaHash;
  No<int> *p = hashTable.getLista(numeroEscolhido%TAM).getPrim()->getProx();
  int i = 0;
  while(p != NULL) {
    linhaHash[i] = p->getChave();
    i ++;
    p = p->getProx();
  }
  hashTable.getLista(numeroEscolhido%TAM).mostrar();
  quickSort(linhaHash2, 0, hashTable.getLista(numeroEscolhido%TAM).getTamanho()-1);
  for(int i = 1; i < hashTable.getLista(numeroEscolhido%TAM).getTamanho(); i ++) {
    cout << linhaHash2[i] << " ";
  }
  /* ------------------------------------------------------------ */
  delete[] linhaHash;
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
int LDE<T>::getTamanho() {
  No <T> *p = prim->getProx();
  int tamanho = 0;
  while(p != NULL) {
    tamanho ++;
    p = p->getProx();
  }
  return tamanho+1;
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
