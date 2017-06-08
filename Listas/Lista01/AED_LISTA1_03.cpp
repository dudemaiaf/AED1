#include <iostream>
#include <cstdlib>

using namespace std;

struct Pizza {
  string sabor;
  bool delivery;
};

void imprimirPedido(Pizza *pedido) {
  if(pedido->delivery) {
    cout << "Pedido: " << pedido->sabor << " - delivery\n";
  }else{
    cout << "Pedido: " << pedido->sabor << " - mesa\n";
  }
}

int main() {
  Pizza *ptr = (Pizza*)malloc(sizeof(Pizza));
  ptr->sabor = "Chocolate com morangos";
  ptr->delivery = false;
  imprimirPedido(ptr);
  free(ptr);
  return 0;
}
