#include <iostream>
#include <cstdlib>

#define TAM 1000

using namespace std;

template <class T>
class LE{
private:
  T *array;
  int limite;
  int ultimaPosicao;
public:
  LE() {
    this->limite = TAM;
    array = new T[this->limite];
    ultimaPosicao = 0;
  }

  LE(int limite) {
    this->limite = limite+1;
    array = new T[this->limite];
    ultimaPosicao = 0;
  }
  int getLimite() {
    return limite;
  }
  int getUltimaPosicao() {
    return ultimaPosicao;
  }
  T getELemento(int posicaoEscolhida){
    return array[posicaoEscolhida];
  }
  void inserir(T Chave) {
    if(ultimaPosicao < limite){
      ultimaPosicao ++;
      array[ultimaPosicao] = Chave;
    }else{
      cout << "\nLista cheia! \n";
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

template <class T>
class Ni{
private:
  LE <T> entradaPrograma;
  Pilha pilhaExecucao;
  string resultado;
  bool verificarPrint(string linhaExecucao) {
    return linhaExecucao[4] == 'P' && linhaExecucao[5] == 'R' && linhaExecucao[6] == 'I' && linhaExecucao[7] == 'N' && linhaExecucao[8] == 'T';
  }
  bool verificarChamadaFuncao(string linhaExecucao) {
    return linhaExecucao[4] == 'A' || linhaExecucao[4] == 'B' || linhaExecucao[4] == 'C' || linhaExecucao[4] == 'D' || linhaExecucao[4] == 'E' || linhaExecucao[4] == 'F' || linhaExecucao[4] == 'G' || linhaExecucao[4] == 'H' || linhaExecucao[4] == 'I' || linhaExecucao[4] == 'J'
           || linhaExecucao[4] == 'K' || linhaExecucao[4] == 'L' || linhaExecucao[4] == 'M' || linhaExecucao[4] == 'N' || linhaExecucao[4] == 'O' || linhaExecucao[4] == 'P' || linhaExecucao[4] == 'Q' || linhaExecucao[4] == 'R' || linhaExecucao[4] == 'S' || linhaExecucao[4] == 'T'
           || linhaExecucao[4] == 'U' || linhaExecucao[4] == 'V' || linhaExecucao[4] == 'X' || linhaExecucao[4] == 'W' || linhaExecucao[4] == 'Y' || linhaExecucao[4] == 'Z';
  }
public:
  Ni(LE <T> entradaPrograma, Pilha pilhaExecucao) {
    this->entradaPrograma = entradaPrograma;
    this->pilhaExecucao = pilhaExecucao;
    resultado = "";
  }

  LE <T> getEntradaPrograma() {
    return entradaPrograma;
  }

  void preencherEntradaPrograma() {
    string linhaLida;
    while(getline(cin, linhaLida)){
      if(linhaLida == "~"){
        entradaPrograma.inserir(linhaLida);
        break;
      }else{
        if(linhaLida.size() != 0){
          entradaPrograma.inserir(linhaLida);
        }
      }
    }
  }

  void empilharMain() {
    int flag = 0;
    int ultimaLinhaMain;
    for(int i = 1; i <= entradaPrograma.getUltimaPosicao(); i ++){
      if(entradaPrograma.getELemento(i) == "Z :"){
        flag ++;
      }if((flag == 1) && ((entradaPrograma.getELemento(i).size() == 3 && entradaPrograma.getELemento(i) != "Z :") || entradaPrograma.getELemento(i) == "~")){
        i --;
        ultimaLinhaMain = i;
        break;
      }
    }

    while(entradaPrograma.getELemento(ultimaLinhaMain) != "Z :"){
      pilhaExecucao.empilhar(entradaPrograma.getELemento(ultimaLinhaMain));
      ultimaLinhaMain --;
    }

    while(!pilhaExecucao.vazia()){
      string linhaExecucao;
      pilhaExecucao.desempilhar(linhaExecucao);
      if(verificarPrint(linhaExecucao)) {
        if(linhaExecucao.size() == 11){
          resultado = resultado + linhaExecucao[10] + ' ';
        }if(linhaExecucao.size() == 12){
          resultado = resultado + linhaExecucao[10] + linhaExecucao[11] + ' ';
        }
      }
      if(verificarChamadaFuncao(linhaExecucao) && linhaExecucao.size() == 5) {
        int comecoFuncao, fimFuncao, flag = 0;
        for(int i = 1; i <= entradaPrograma.getUltimaPosicao(); i ++){
          if(entradaPrograma.getELemento(i)[0] == linhaExecucao[4]){
            comecoFuncao = i+1;
            flag ++;
          }if((flag == 1) && ((entradaPrograma.getELemento(i).size() == 3 && entradaPrograma.getELemento(i)[0] != linhaExecucao[4]) || (entradaPrograma.getELemento(i) == "~"))){
            fimFuncao = i;
            break;
          }
        }
        while(fimFuncao >= comecoFuncao){
          fimFuncao --;
          pilhaExecucao.empilhar(entradaPrograma.getELemento(fimFuncao));
        }
      }
    }
  }
  void imprimirResultado() {
    cout << resultado;
  }
};

int main() {
  LE <string> entradaPrograma(TAM);
  Pilha pilhaExecucao;
  Ni <string> linguagemNi(entradaPrograma, pilhaExecucao);
  linguagemNi.preencherEntradaPrograma();
  linguagemNi.empilharMain();
  linguagemNi.imprimirResultado();
  return 0;
}
