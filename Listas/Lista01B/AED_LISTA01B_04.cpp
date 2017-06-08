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
};

int main() {
  Pedra pedra(0,2);
  pedra.printPedra();
  pedra.dir = 6;
  pedra.esq = 1;
  pedra.printPedra();
  return 0;
}
