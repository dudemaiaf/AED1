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

/*
Classe Ni contém métodos para a interpretação da entrada dada pelo usuário.
A idéia principal é ter uma lista estática que conterá todos as linhas de execução,
e uma pilha que conterá o fluxo de execução do programa (main/'Z'). Ao encontrar uma
instrução de 'print', ele concatena com uma string chamada resultado que terá a
saída final do programa informado, caso identifique uma chamada de função, é buscada a função
na lista estática e ela é empilhada do fim até o começo, após isso, é realizado tudo novamente até que apilha
se encontre vazia.
*/

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

int main() {
  LE <string> entradaPrograma(TAM);
  Pilha <string> pilhaExecucao;
  Ni <string> linguagemNi(entradaPrograma, pilhaExecucao);
  linguagemNi.preencherEntradaPrograma();
  linguagemNi.empilharMain();
  linguagemNi.imprimirResultado();
  return 0;
}

// Métodos da classe LE

template <class T>
int LE<T>::getLimite() {
  return limite;
}

template <class T>
int LE<T>::getUltimaPosicao() {
  return ultimaPosicao;
}

template <class T>
T LE<T>::getELemento(int posicaoEscolhida){
  return array[posicaoEscolhida];
}

template <class T>
void LE<T>::inserir(T Chave) {
  if(ultimaPosicao < limite){
    ultimaPosicao ++;
    array[ultimaPosicao] = Chave;
  }else{
    cout << "\nLista cheia! \n";
  }
}

// Métodos da classe No

template <class T>
void No<T>::setChave(T chave){
  this->chave = chave;
}

template <class T>
T No<T>::getChave() {
  return chave;
}

template <class T>
void No<T>::setNo(No <T> *prox) {
  this->prox = prox;
}

template <class T>
No<T>* No<T>::getNo() {
  return prox;
}

// Métodos da classe Pilha

template <class T>
void Pilha<T>::empilhar(T chave) {
  No <T> *aux = new No<T>();
  topo->setChave(chave);
  aux->setNo(topo);
  topo = aux;
}

template <class T>
void Pilha<T>::desempilhar(T &chave) {
  No <T> *aux = topo;
  topo = topo->getNo();
  chave = topo->getChave();
  delete aux;
}

template <class T>
void Pilha<T>::mostrar() {
  for(No <T> *nav = topo->getNo(); nav != NULL; nav = nav->getNo()){
    cout << nav->getString() << endl;
  }
}

template <class T>
bool Pilha<T>::vazia() {
  return topo == fundo;
}

// Métodos da classe Ni

template <class T>
bool Ni<T>::verificarPrint(string linhaExecucao) {
  return linhaExecucao[4] == 'P' && linhaExecucao[5] == 'R' && linhaExecucao[6] == 'I' && linhaExecucao[7] == 'N' && linhaExecucao[8] == 'T';
}

template <class T>
bool Ni<T>::verificarChamadaFuncao(string linhaExecucao) {
  return linhaExecucao[4] == 'A' || linhaExecucao[4] == 'B' || linhaExecucao[4] == 'C' || linhaExecucao[4] == 'D' || linhaExecucao[4] == 'E' || linhaExecucao[4] == 'F' || linhaExecucao[4] == 'G' || linhaExecucao[4] == 'H' || linhaExecucao[4] == 'I' || linhaExecucao[4] == 'J'
         || linhaExecucao[4] == 'K' || linhaExecucao[4] == 'L' || linhaExecucao[4] == 'M' || linhaExecucao[4] == 'N' || linhaExecucao[4] == 'O' || linhaExecucao[4] == 'P' || linhaExecucao[4] == 'Q' || linhaExecucao[4] == 'R' || linhaExecucao[4] == 'S' || linhaExecucao[4] == 'T'
         || linhaExecucao[4] == 'U' || linhaExecucao[4] == 'V' || linhaExecucao[4] == 'X' || linhaExecucao[4] == 'W' || linhaExecucao[4] == 'Y' || linhaExecucao[4] == 'Z';
}

template <class T>
LE<T> Ni<T>::getEntradaPrograma() {
  return entradaPrograma;
}

template <class T>
void Ni<T>::preencherEntradaPrograma() {
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

template <class T>
void Ni<T>::empilharMain() {
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

template <class T>
void Ni<T>::imprimirResultado() {
  cout << resultado;
}
