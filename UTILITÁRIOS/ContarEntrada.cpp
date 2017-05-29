#include <iostream>
#define Limite 1000
using namespace std;

int main() {
  int contador = 0;
  string entrada;
  string vetor[Limite];
  do{
    getline(cin, entrada);
    contador ++;
  }while(entrada != "~");
  cout << contador << endl;
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
    print 0
    print 1
    print 2
    A
    B

~
*/
