#include <iostream>

using namespace std;

struct Pizza {
  string sabor;
  int modal;
};

void receberPedido(Pizza &pedido) {
  bool loop = true;
  cout << "Informe o sabor de pizza desejado: " << endl;
  getline(cin, pedido.sabor);
  do{
    cout << "Digite 0- Delivery e 1- Mesa: " << endl;
    cin >> pedido.modal;
    if(pedido.modal == 0 || pedido.modal == 1){
      loop = false;
    }
  }while(loop);
}

void imprimirPedido(Pizza pedido) {
  if(pedido.modal == 0){
    cout << endl << "Pedido:" << endl << "Sabor: " << pedido.sabor << " | Modal: Delivery" << endl;
  }else{
    cout << endl << "Pedido:" << endl<< "Sabor: " << pedido.sabor << " | Modal: Mesa" << endl;
  }
}

int main(){
  Pizza pedido;
  receberPedido(pedido);
  imprimirPedido(pedido);
  return 0;
}
