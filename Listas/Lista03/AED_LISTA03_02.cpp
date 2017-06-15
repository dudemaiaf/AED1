#include <iostream>

using namespace std;

void imprimirInteiros(int comeco) {
  if(comeco == 0) {
    cout << comeco;
  }else {
    cout << comeco << " ";
    return imprimirInteiros(comeco - 1);
  }
}

int main() {
  int comeco = 10;
  imprimirInteiros(comeco);
  return 0;
}
