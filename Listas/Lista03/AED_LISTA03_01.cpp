#include <iostream>

using namespace std;

void imprimirInteiros(int comeco, int fim) {
  if(comeco == fim) {
    cout << comeco;
  }else{
    cout << comeco << " ";
    return imprimirInteiros(comeco + 1, fim);
  }
}

int main() {
  int comeco = 0;
  int fim = 10;
  imprimirInteiros(comeco, fim);
  return 0;
}
