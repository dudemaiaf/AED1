#include <iostream>

using namespace std;

int main() {
  int contador = 0;
  int fim = 0;
  string entrada;
  while(getline(cin, entrada)){
    if(entrada == "~"){
      break;
    }
    contador ++;
  }
  cout << contador << endl;
  return 0;
}
