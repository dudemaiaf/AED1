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
  int getLimite();
  int getUltimaPosicao();
  T getELemento(int posicaoEscolhida);
  void inserir(T Chave);
};

int LE::getLimite() {
  return limite;
}

int LE::getUltimaPosicao() {
  return ultimaPosicao;
}

template <class T>
T LE::getELemento(int posicaoEscolhida){
  return array[posicaoEscolhida];
}

template <class T>
void LE::inserir(T Chave) {
  if(ultimaPosicao < limite){
    ultimaPosicao ++;
    array[ultimaPosicao] = Chave;
  }else{
    cout << "\nLista cheia! \n";
  }
}

template <class T>
class No {
private:
  T chave;
  No <T> *prox;
public:
  No() {
	  prox = NULL;
  }
  void setChave(T chave);
  T getChave();
  void setNo(No <T> *prox);
  No* getNo();
};

void No::setChave(T chave){
  this->chave = chave;
}

T No::getChave() {
  return chave;
}

void No::setNo(No <T> *prox) {
  this->prox = prox;
}

No* No::getNo() {
  return prox;
}

template <class T>
class Pilha{
private:
	No <T> *fundo, *topo;
public:
	Pilha() {
		fundo = new No<T>();
		fundo->setNo(NULL);
		topo = fundo;
	}
	void empilhar(T chave);
	void desempilhar(T &chave);
	void mostrar();
  bool vazia();
};

void Pilha::empilhar(T chave) {
  No <T> *aux = new No<T>();
  topo->setChave(chave);
  aux->setNo(topo);
  topo = aux;
}

void Pilha::desempilhar(T &chave) {
  No <T> *aux = topo;
  topo = topo->getNo();
  chave = topo->getChave();
  delete aux;
}

void Pilha::mostrar() {
  for(No <T> *nav = topo->getNo(); nav != NULL; nav = nav->getNo()){
    cout << nav->getString() << endl;
  }
}

bool Pilha::vazia() {
  return topo == fundo;
}

template <class T>
class Ni{
private:
  LE <T> entradaPrograma;
  Pilha <T> pilhaExecucao;
  string resultado;
  bool verificarPrint(string linhaExecucao);
  bool verificarChamadaFuncao(string linhaExecucao);
public:
  Ni(LE <T> entradaPrograma, Pilha <T> pilhaExecucao) {
    this->entradaPrograma = entradaPrograma;
    this->pilhaExecucao = pilhaExecucao;
    resultado = "";
  }

  LE <T> getEntradaPrograma();
  void preencherEntradaPrograma();
  void empilharMain();
  void imprimirResultado();
};

bool Ni::verificarPrint(string linhaExecucao) {
  return linhaExecucao[4] == 'P' && linhaExecucao[5] == 'R' && linhaExecucao[6] == 'I' && linhaExecucao[7] == 'N' && linhaExecucao[8] == 'T';
}

bool Ni::verificarChamadaFuncao(string linhaExecucao) {
  return linhaExecucao[4] == 'A' || linhaExecucao[4] == 'B' || linhaExecucao[4] == 'C' || linhaExecucao[4] == 'D' || linhaExecucao[4] == 'E' || linhaExecucao[4] == 'F' || linhaExecucao[4] == 'G' || linhaExecucao[4] == 'H' || linhaExecucao[4] == 'I' || linhaExecucao[4] == 'J'
         || linhaExecucao[4] == 'K' || linhaExecucao[4] == 'L' || linhaExecucao[4] == 'M' || linhaExecucao[4] == 'N' || linhaExecucao[4] == 'O' || linhaExecucao[4] == 'P' || linhaExecucao[4] == 'Q' || linhaExecucao[4] == 'R' || linhaExecucao[4] == 'S' || linhaExecucao[4] == 'T'
         || linhaExecucao[4] == 'U' || linhaExecucao[4] == 'V' || linhaExecucao[4] == 'X' || linhaExecucao[4] == 'W' || linhaExecucao[4] == 'Y' || linhaExecucao[4] == 'Z';
}

LE Ni::getEntradaPrograma() {
  return entradaPrograma;
}

void Ni::preencherEntradaPrograma() {
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

void Ni::empilharMain() {
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

void Ni::imprimirResultado() {
  cout << resultado;
}

int main() {
  LE <string> entradaPrograma(TAM);
  Pilha <string> pilhaExecucao;
  Ni <string> linguagemNi(entradaPrograma, pilhaExecucao);
  linguagemNi.preencherEntradaPrograma();
  linguagemNi.empilharMain();
  linguagemNi.imprimirResultado();
  return 0;
}
