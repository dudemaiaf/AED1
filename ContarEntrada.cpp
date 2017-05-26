#include <iostream>
#define Limite 1000
using namespace std;

int main() {
  int contador = 0;
  string entrada;
  string vetor[Limite];
  while(getline(cin, entrada)){
    if(entrada == "~"){
      break;
    }
    vetor[contador] = entrada;
    contador ++;
  }
  cout << contador << endl;
  for(int i = 0; i < contador+1; i ++){
    cout << vetor[i] << "_";
  }
  return 0;
}

/*
A :
    print 1
    print 2
    print 3

B :
    A
    print 4
    print 5
    print 6

Z :
    B
~
*/
