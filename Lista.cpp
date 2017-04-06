#include "Lista.h"

Chave Questao::getID(){
	return ID;
}
void Questao::setID(Chave chave){
	this->ID = chave;
}
void Questao::setEnunciado(Enunciado enunciado){
	this->enunciado = enunciado;
}
void Questao::setPopularidade(Popularidade popularidade){
	this->popularidade = popularidade;
}
void Questao::setDificuldade(Dificuldade dificuldade){
	this->dificuldade = dificuldade;
}
void Questao::imprimir(){
	cout << ID << " - " << enunciado << " - " << popularidade << " - " << dificuldade << endl;
}
