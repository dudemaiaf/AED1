#include <iostream>

using namespace std;

class Pedra {
public:
  int dir, esq;
  Pedra() {
    dir = 0;
    esq = 0;
  }
  void printPedra() {
    cout << "[" << esq << "|" << dir << "]" << endl;
  }
};

int main() {
  Pedra pedra;
  pedra.printPedra();
  pedra.dir = 6;
  pedra.esq = 1;
  pedra.printPedra();
  return 0;
}
