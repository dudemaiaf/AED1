#include <iostream>
#define TAM 3

using namespace std;

struct Disciplina {
	string nomeDisciplina;
	string codigoDisciplina;
	int cargaHoraria;
};

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

void imprimirMatricula(Disciplina matricula[]){
	for(int i = 0; i < TAM; i ++){
		cout << endl << "Materia matriculada: " << matricula[i].nomeDisciplina << endl << "Codigo da materia: " << matricula[i].codigoDisciplina << endl << "Carga horaria da materia: " << matricula[i].cargaHoraria << endl;
	}
}

int main(){
	Disciplina matricula[TAM];
	matricular(matricula);
	imprimirMatricula(matricula);
	return 0;
}

