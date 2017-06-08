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
  Pedra pedra;
  cout << "[" << pedra.getEsq() << "|" << pedra.getDir() << "]" << endl;
  return 0;
}
