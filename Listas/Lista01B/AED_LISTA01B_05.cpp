#include <iostream>

using namespace std;

class Pedra {
public:
  int dir, esq;
  Pedra() {
    dir = 0;
    esq = 0;
  }
  Pedra(int esq, int dir) {
    this->esq = esq;
    this->dir = dir;
  }
  void printPedra() {
    cout << "[" << esq << "|" << dir << "]" << endl;
  }
  bool validarPedra() {
    return (dir < 7 && esq < 7 && dir > - 1 && esq > -1);
  }
};

int main() {
  Pedra pedra(0,2);
  if(pedra.validarPedra()){
    pedra.printPedra();
  }else{
    cout << "\nInválida\n";
  }
  pedra.dir = 7;
  pedra.esq = 7;
  if(pedra.validarPedra()){
    pedra.printPedra();
  }else{
    cout << "\nInválida\n";
  }
  return 0;
}
