#include <iostream>
#define TAM 1000
using namespace std;

class LE{
private:
  string *vetor;
  int tamanho;
  int ultimo;
public:
  LE() {
    this->tamanho = TAM;
    vetor = new string[this->tamanho];
    ultimo = 0;
  }

  LE(int tamanho) {
    this->tamanho = tamanho+1;
    vetor = new string[this->tamanho];
    ultimo = 0;
  }

  void setTamanho(int tamanho) {
    this->tamanho = tamanho;
  }

  void setUltimo(int ultimo) {
    this->ultimo = ultimo;
  }

  int getTamanho() {
    return tamanho;
  }

  int getUltimo() {
    return ultimo;
  }
  string getELemento(int i){
    return vetor[i];
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
      cout << vetor[i] << "\n";
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
  bool vazia() {
    return topo == fundo;
  }
};

// class Ni{
// private:
//   LE entradaPrograma;
//   Pilha pilhaExecucao;
// public:
//   Ni(LE entradaPrograma, Pilha pilhaExecucao) {
//     this->entradaPrograma = entradaPrograma;
//     this->pilhaExecucao = pilhaExecucao;
//   }
// };

void preencherEntradaPrograma(LE &entradaPrograma) {
  string entrada;
  while(getline(cin, entrada)){
    if(entrada == "~"){
      break;
    }else{
      entradaPrograma.insere(entrada);
    }
  }
}

int main() {
  LE entradaPrograma(TAM);
  Pilha pilhaExecucao;
  preencherEntradaPrograma(entradaPrograma);
  int ultimo = entradaPrograma.getUltimo();
  while(entradaPrograma.getELemento(ultimo) != "Z :"){
    pilhaExecucao.empilhar(entradaPrograma.getELemento(ultimo));
    ultimo --;
  }

  while(!pilhaExecucao.vazia()){

    string funcao;
    pilhaExecucao.desempilhar(funcao);
    if(funcao.size() == 11) {
      cout << funcao[10] << " ";
    }if(funcao.size() == 12) {
      cout << funcao[10] << funcao[11] << " ";
    }
    if(funcao.size() == 5) {
      int comeco, fim;
      for(int i = 0; i < entradaPrograma.getUltimo(); i ++){
        if(entradaPrograma.getELemento(i)[0] == funcao[4]){
          comeco = i+1;
          break;
        }
      }
      for(int i = comeco+1; i < entradaPrograma.getUltimo(); i ++){
        if(entradaPrograma.getELemento(i).size() != 11 && entradaPrograma.getELemento(i).size() != 12 && entradaPrograma.getELemento(i).size() != 5){
          fim = i;
          break;
        }
      }
      while(fim > comeco){
        fim--;
        pilhaExecucao.empilhar(entradaPrograma.getELemento(fim));
      }
    }
  }
  return 0;
}
