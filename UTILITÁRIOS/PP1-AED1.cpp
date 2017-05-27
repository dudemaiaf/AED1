#include <iostream>

using namespace std;

class No {
private:
  string func;
  No *prox;
public:
  No() {
	  prox = NULL;
  }
  void setString(string func){
	  this->func = func;
  }
  string getString() {
	  return func;
  }
  No* getNo() {
	  return prox;
  }
  void setNo(No *prox) {
	  this->prox = prox;
  }

};

class LSE {
private:
	No *prim, *ult;
public:
	LSE() {
		prim = new No();
		prim->setNo(NULL);
		ult = prim;
	}
	void insere(string func) {
		ult->setNo(new No());
		ult = ult->getNo();
		ult->setNo(NULL);
		ult->setString(func);
	}
	void mostra() {
		No *p = prim->getNo();
		while(p != NULL) {
			cout << p->getString() << " ";
			p = p->getNo();
		}
	}
	No* busca(string Func) {
		No *p = prim->getNo();
		while(p != NULL && p->getString() != Func){
			p = p->getNo();
		}
		return p;
	}
};

class Pilha{
private:
	No *fundo, *topo;
public:
	Pilha() {
		fundo = new No();
		fundo->setNo(NULL);
		topo = fundo;
	}
	void empilhar(string Func) {
		No *aux = new No();
		topo->setString(Func);
		aux->setNo(topo);
		topo = aux;
	}
	void desempilhar(string &Func) {
		No *aux = topo;
		topo = topo->getNo();
		Func = topo->getString();
		delete aux;
	}
	void mostrar() {
		for(No *nav = topo->getNo(); nav != NULL; nav = nav->getNo()){
			cout << nav->getString() << endl;
		}
	}
};

int main() {

	return 0;
}
