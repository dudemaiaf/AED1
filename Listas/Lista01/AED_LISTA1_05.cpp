#include <iostream>
#define TAMANHO 2

using namespace std;

struct Pizza {
  string sabor;
  bool delivery;
};

void imprimirPedido(Pizza pedido) {
  if(pedido.delivery) {
    cout << "Pedido: " << pedido.sabor << " - delivery\n";
  }else{
    cout << "Pedido: " << pedido.sabor << " - mesa\n";
  }
}

int main() {
  Pizza *pedido = new Pizza[TAMANHO];
  for(int i = 0; i < TAMANHO; i ++) {
    int boolean;
    cout << "Qual o sabor do pedido " << (i + 1) << ": ";
    getline(cin, pedido[i].sabor);
    cout << "Qual a modalidade de entrega: ";
    cin >> boolean;
    if(boolean == 0){
      pedido[i].delivery = false;
    }else{
      pedido[i].delivery = true;
    }
    cout << endl;
    cin.ignore();
  }
  for(int i = 0; i < TAMANHO; i ++) {
    imprimirPedido(pedido[i]);
  }
  return 0;
}
