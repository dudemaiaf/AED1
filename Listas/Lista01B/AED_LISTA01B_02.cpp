#include <iostream>

using namespace std;

class Pedra {
public:
  int dir, esq;
  void printPedra() {
    cout << "[" << esq << "|" << dir << "]" << endl;
  }
};

int main() {
  Pedra pedra;
  pedra.dir = 6;
  pedra.esq = 1;
  pedra.printPedra();
  return 0;
}
