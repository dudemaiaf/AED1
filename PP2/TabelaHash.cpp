#include <iostream>
#include <cstdlib>
#include <fstream>

#define TAM 787
#define base 128

using namespace std;

void quickSort(int *array, int esq, int dir);
int interpretarString(string num);
string acrescentarZero(string numero);
int pow(int baze, int expoente);

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
  int calculoHash(int chave) {return chave%TAM;}
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

int main() {
  TabelaHash<string> hashTable(TAM);

  /* ----- PARTE DE PREENCHER TABELA HASH */
  string linha;
  ifstream chaves ("chaves.txt");
  if(chaves.is_open()) {
    while(getline(chaves,linha)) {
      // int numero;
      // numero = atoi(linha.c_str());
      hashTable.inserir(linha);
    }
    chaves.close();
  }
  hashTable.mostrar();

  /* ----- PARTE DE CAPTURAR A LINHA INFORMADA E IMPPRIMIR ----- */

  // bool flag = false;
  // int numeroEscolhido;
  // cin >> numeroEscolhido;
  // int *linhaHash;
  // linhaHash = new int[hashTable.getLista(numeroEscolhido%TAM).getTamanho()];
  // No<int> *p = hashTable.getLista(numeroEscolhido%TAM).getPrim()->getProx();
  // int i = 0;
  // while(p != NULL) {
  //   if(numeroEscolhido == p->getChave()) {
  //     flag = true;
  //   }
  //   linhaHash[i] = p->getChave();
  //   i ++;
  //   p = p->getProx();
  // }
  // if(flag) {
  //   quickSort(linhaHash, 0, hashTable.getLista(numeroEscolhido%TAM).getTamanho()-1);
  //   for(int i = 0; i < hashTable.getLista(numeroEscolhido%TAM).getTamanho()-1; i ++) {
  //     cout << linhaHash[i] << " ";
  //   }
  // } else {
  //   cout << "Chave não encontrada.";
  // }
  //
  // delete[] linhaHash;
  // cout << endl;

  return 0;
}

/* ----- SUB-ROTINA DE ORDENAÇÃO DE VETORES quickSort */

void quickSort(int *array, int esq, int dir) {
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

/* ----- SUB-ROTINA QUE PEGA UMA STRING NUMÉRICA E CALCULA SEU EQUIVALENTE EM INTEIRO ----- */

int interpretarString(string num) {
  int numero = atoi(num.c_str());
  int dividendo = 1000, jaUsado = 0, valorInterpretado = 0;
  int vetor[num.size()];
  for(int i = 0; i < num.size(); i ++) {
    if(i == 0) {
      vetor[i] = numero / dividendo;
    } else {
      jaUsado = jaUsado + (vetor[i-1]*dividendo*10);
      vetor[i] = (numero - jaUsado)/dividendo;
    }
    dividendo = dividendo / 10;
  }
  int j = 0;
  for(int i = num.size()-1; i >= 0; i --) {
    valorInterpretado += vetor[j] * pow(base,i);
    j++;
  }
  return valorInterpretado;
}

/* ----- SUB-ROTINA QUE ACRESCENTE ZEROS EM NÚMEROS 'INCOMPLETOS' ----- */

string acrescentarZero(string numero) {
  if(numero.size() < 4) {
    while(numero.size() != 4) {
      numero = "0" + numero;
    }
  }
  return numero;
}

/* ----- SUB-ROTINA QUE CALCULA A POTENCIA DE UM NUMERO ----- */

int pow(int baze, int expoente) {
  if(expoente == 0) {
    return 1;
  }else {
    return baze * pow(baze, expoente-1);
  }
}

/* ----- MÉTODOS DO NÓ ----- */

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

/* ----- MÉTODOS DA LISTA DUPLAMENTE ENCADEADA ----- */

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
    if(p->getChave() == chave) {
      break;
    }
    p = p->getProx();
  }
  return p;
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

/* ----- MÉTODOS DA TABELA HASH ----- */

template <class T>
void TabelaHash<T>::inserir(T chave) {
  int valorConvertido = interpretarString(chave);
  int posicaoCalculada = calculoHash(valorConvertido);
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
