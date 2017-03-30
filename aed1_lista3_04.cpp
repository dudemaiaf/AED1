#include <iostream>
#define TAM 3
using namespace std;

struct Disciplina {
	string nomeDisciplina;
	string codigoDisciplina;
	int cargaHoraria;
};

int buscaSequencial(string chave, Disciplina vetor[]){
	int pos = 0;
	vetor[TAM].nomeDisciplina = chave;
	while(chave != vetor[pos].nomeDisciplina){
		pos ++;
	}
	if(pos < 3){
		return pos;
	}else{
		return -1;
	}
}

void matricular(Disciplina matricula[]){
	for(int i = 0; i < TAM; i ++){
		cout << endl;
		cout << "Informe o nome da materia a ser realizada: ";
		getline(cin, matricula[i].nomeDisciplina);
		cout << "Informe o codigo da materia: ";
		getline(cin, matricula[i].codigoDisciplina);
		cout << "Informe a carga horaria: ";
		cin >> matricula[i].cargaHoraria;
		cin.ignore();
	}
}

void imprimirMatricula(Disciplina matricula[], int i){
	cout << endl << "Materia matriculada: " << matricula[i].nomeDisciplina << endl << "Codigo da materia: " << matricula[i].codigoDisciplina << endl << "Carga horaria da materia: " << matricula[i].cargaHoraria << endl;
}

int main(){
	string chave = "FTC";
	Disciplina matricula[TAM];
	matricular(matricula);
	cout << buscaSequencial(chave, matricula);
	cout << buscaSequencial(chave, matricula);
	if(buscaSequencial(chave, matricula) != -1){
		cout << "\n# Disciplina encontrada! #" << endl;
		imprimirMatricula(matricula, buscaSequencial(chave, matricula));
	}else{
		cout << "Nao foi encontrada nenhuma materia! " << endl;
	}

	return 0;
}
