#include <iostream>
#include <cstdlib>


#define TAM 1000

using namespace std;

template <class T>
class LE{
private:
  T *vetor;
  int tamanho;
  int ultimo;
public:
  LE() {
    this->tamanho = TAM;
    vetor = new T[this->tamanho];
    ultimo = 0;
  }

  LE(int tamanho) {
    this->tamanho = tamanho+1;
    vetor = new T[this->tamanho];
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

  T getELemento(int i){
    return vetor[i];
  }

  void inserir(T Chave) {
    if(ultimo < tamanho){
      ultimo ++;
      vetor[ultimo] = Chave;
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
  bool verificarPrint(string funcao) {
    return funcao[4] == 'P' && funcao[5] == 'R' && funcao[6] == 'I' && funcao[7] == 'N' && funcao[8] == 'T';
  }
  bool verificarChamadaFuncao(string funcao) {
    return funcao[4] == 'A' || funcao[4] == 'B' || funcao[4] == 'C' || funcao[4] == 'D' || funcao[4] == 'E' || funcao[4] == 'F' || funcao[4] == 'G' || funcao[4] == 'H' || funcao[4] == 'I' || funcao[4] == 'J'
           || funcao[4] == 'K' || funcao[4] == 'L' || funcao[4] == 'M' || funcao[4] == 'N' || funcao[4] == 'O' || funcao[4] == 'P' || funcao[4] == 'Q' || funcao[4] == 'R' || funcao[4] == 'S' || funcao[4] == 'T'
           || funcao[4] == 'U' || funcao[4] == 'V' || funcao[4] == 'X' || funcao[4] == 'W' || funcao[4] == 'Y' || funcao[4] == 'Z';
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
    string entrada;
    while(getline(cin, entrada)){
      if(entrada == "~"){
        entradaPrograma.inserir("~");
        break;
      }else{
        if(entrada.size() != 0){
          entradaPrograma.inserir(entrada);
        }
      }
    }
  }

  void interpretarEntrada() {
    int flag = 0;
    int ultimo;
    for(int i = 0; i < entradaPrograma.getTamanho(); i ++){
      if(entradaPrograma.getELemento(i) == "Z :"){
        flag ++;
      }if((flag == 1) && ((entradaPrograma.getELemento(i).size() == 3 && entradaPrograma.getELemento(i) != "Z :") || entradaPrograma.getELemento(i) == "~")){
        i --;
        ultimo = i;
        break;
      }
    }

    while(entradaPrograma.getELemento(ultimo) != "Z :"){
      pilhaExecucao.empilhar(entradaPrograma.getELemento(ultimo));
      ultimo --;
    }

    while(!pilhaExecucao.vazia()){
      string funcao;
      pilhaExecucao.desempilhar(funcao);
      if(verificarPrint(funcao)) {
        if(funcao.size() == 11){
          resultado = resultado + funcao[10] + ' ';
        }if(funcao.size() == 12){
          resultado = resultado + funcao[10] + funcao[11] + ' ';
        }
      }
      if(verificarChamadaFuncao(funcao) && funcao.size() == 5) {
        int comeco, fim, flag = 0;
        for(int i = 1; i <= entradaPrograma.getUltimo(); i ++){
          if(entradaPrograma.getELemento(i)[0] == funcao[4]){
            comeco = i+1;
            flag ++;
          }if((flag == 1) && ((entradaPrograma.getELemento(i).size() == 3 && entradaPrograma.getELemento(i)[0] != funcao[4]) || (entradaPrograma.getELemento(i) == "~"))){
            fim = i;
            break;
          }
        }
        while(fim >= comeco){
          fim--;
          pilhaExecucao.empilhar(entradaPrograma.getELemento(fim));
        }
      }
    }
  }
  void imprimirResultado() {
    cout << resultado << endl;
  }
};

int main() {
  LE <string> entradaPrograma(TAM);
  Pilha pilhaExecucao;
  Ni <string> linguagemNi(entradaPrograma, pilhaExecucao);
  linguagemNi.preencherEntradaPrograma();
  linguagemNi.interpretarEntrada();
  linguagemNi.imprimirResultado();
  return 0;
}
