#include <iostream>

using namespace std;

class Pedra {
public:
  int dir, esq;
};

int main() {
  Pedra pedra;
  pedra.dir = 0;
  pedra.esq = 1;

  cout << "[" << pedra.esq << "|" << pedra.dir << "]" << endl;
  
  return 0;
}
