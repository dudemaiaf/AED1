#include <iostream>
#include <cstdlib>

using namespace std;

struct Pizza {
  string sabor;
  int modal;
};

void receberPedido(Pizza *pedido) {
  bool loop = true;
  cout << "Informe o sabor da pizza: " << endl;
  getline(cin, pedido->sabor);
  do{
    cout << "Digite 0- Delivery ou 1- Mesa: " << endl;
    cin >> pedido->modal;
    if(pedido->modal == 1 || pedido->modal == 0){
      loop = false;
    }
  }while(loop);
}

void imprimirPedido(Pizza *pedido) {
  if(pedido->modal == 0){
    cout << endl << "Pedido:" << endl << "Sabor: " << pedido->sabor << " | Modal: Delivery" << endl;
  }else{
	cout << endl << "Pedido:" << endl<< "Sabor: " << pedido->sabor << " | Modal: Mesa" << endl;
  }
}

int main(){
  Pizza *pedido;
  pedido = (Pizza *)malloc(sizeof(Pizza));
  receberPedido(&pedido);
  imprimirPedido(&pedido);
  free(pedido);
  pedido = NULL;
  return 0;
}
