#include <iostream>

using namespace std;

class Pedra {
private:
  int dir, esq;
  bool validarPedra() {
    return (dir < 7 && esq < 7 && dir > - 1 && esq > -1);
  }
public:
  Pedra() {
    dir = 0;
    esq = 0;
  }
  Pedra(int esq, int dir) {
    this->esq = esq;
    this->dir = dir;
  }
  void printPedra() {
    if(validarPedra()) {
      cout << "[" << esq << "|" << dir << "]" << endl;
    }else{
      cout << "\nPedra inválida\n";
    }
  }
  void setDir(int dir) {
    this->dir = dir;
  }
  int getDir() {
    return dir;
  }
  void setEsq(int esq) {
    this->esq = esq;
  }
  int getEsq() {
    return esq;
  }
};

int main() {
  Pedra **arrayPedra = new Pedra*[49];
  int pos = 0;
  for(int i = 0; i < 7; i ++) {
    for(int j = 0; j < 7; j ++) {
      int esq = i;
      int dir = j;
      Pedra *aux = new Pedra();
      aux->setEsq(esq);
      aux->setDir(dir);
      arrayPedra[pos] = aux;
      pos ++;
    }
  }
  for(int i = 0; i < 49; i ++){
    arrayPedra[i]->printPedra();
  }
  delete[] arrayPedra;
  return 0;
}
