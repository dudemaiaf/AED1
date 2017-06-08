#include <iostream>

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
  Pizza pedido;
  Pizza *ptr;
  ptr = &pedido;
  pedido.sabor = "Mussarela";
  pedido.delivery = false;
  imprimirPedido(pedido);
  ptr->sabor = "Calabresa";
  ptr->delivery = true;
  imprimirPedido(pedido);
  return 0;
}
