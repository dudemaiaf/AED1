#ifndef Lista_h
#define Lista_h
#include <iostream>

using namespace std;

typedef int Chave;
typedef string Enunciado;
typedef int Popularidade;
typedef string Dificuldade;
typedef int Posicao;

struct Questao {
private:
	Chave ID;
	Enunciado enunciado;
	Popularidade popularidade;
	Dificuldade dificuldade;
public:
	Questao():Questao(0, "", 0, ""){}
	Questao(Chave ID, Enunciado enunciado, Popularidade popularidade, Dificuldade dificuldade) {
		this->ID = ID;
		this->enunciado = enunciado;
		this->popularidade = popularidade;
		this->dificuldade = dificuldade;
	}
	Chave getID();
	void setID(Chave);
	void setEnunciado(Enunciado);
	void setPopularidade(Popularidade);
	void setDificuldade(Dificuldade);
	void imprimir();
};

class Lista {
private:
	Questao *questao;
	int TAM;
	int n;
	bool posicaoValida(Posicao);
	bool listaVazia();
public:
	Lista():Lista(5){}
	Lista(int tam){
		n = 0;
		TAM = tam;
		questao = new Questao[TAM];
	}
	void mostra();
	void insere(Questao);
	Questao* busca(Chave);
	void remove(Posicao);
	Questao* minimo();
	Questao* maximo();
	Questao* sucessor();
	Questao* predecessor();
};

#endif
