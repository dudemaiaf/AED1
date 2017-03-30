#include <iostream>
#define TAM 3

using namespace std;

struct Pizza {
  string sabor;
  int modal;
};

void receberPedido(Pizza *pedido) {
  for(int i = 0; i < TAM; i ++){
    bool loop = true;
    cout << "Informe o sabor da pizza " << i + 1 << ": " << endl;
    getline(cin, pedido[i].sabor);
    do{
      cout << "Digite 0- Delivery ou 1- Mesa: " << endl;
      cin >> pedido[i].modal;
      if(pedido[i].modal == 1 || pedido[i].modal == 0){
        loop = false;
      }
    }while(loop);
    cin.ignore();
  }
}

void imprimirPedido(Pizza *pedido) {
  cout << "# ----- PEDIDOS ----- #" << endl;
  for(int i = 0; i < TAM; i++){
    if(pedido[i].modal == 0){
      cout << endl << "Pedido:" << endl << "Sabor: " << pedido[i].sabor << " | Modal: Delivery" << endl;
    }else{
  	cout << endl << "Pedido:" << endl<< "Sabor: " << pedido[i].sabor << " | Modal: Mesa" << endl;
    }
  }
}

int main(){
  Pizza *pedido = new Pizza[TAM];
  receberPedido(pedido);
  imprimirPedido(pedido);
  delete [] pedido;
  return 0;
}
