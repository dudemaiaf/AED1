class LE{
private:
  string *vetor;
  int tamanho;
  int ultimo;
public:
  LE(int tamanho) {
    this->tamanho = tamanho+1;
    vetor = new string[this->tamanho];
    ultimo = 0;
  }

  void insere(string Chave) {
    if(ultimo < tamanho){
      ultimo ++;
      vetor[ultimo] = Chave;
    }else{
      cout << "\nLista cheia! \n";
    }
  }

  void mostra() {
    for(int i = 0; i <= ultimo; i++) {
      cout << vetor[i] << " ";
    }
    cout << endl;
  }

  string busca(string Chave){
    vetor[0] = Chave;
    int i = ultimo;
    while(Chave != vetor[i]) {
      i --;
    }if(i > 0){
      return vetor[i];
    }else{
      return "";
    }
  }
};

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

class Ni{
private:
  LE entradaPrograma;
  Pilha pilhaExecucao;
public:

};

int main() {

  return 0;
}
