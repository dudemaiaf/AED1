#include <iostream>

using namespace std;

int main() {
  string nome = "MATEUS MOTA";
  int i = 0;
  do{
    cout << nome[i];
    i++;
  }while(nome[i] != '\0');
  return 0;

}
