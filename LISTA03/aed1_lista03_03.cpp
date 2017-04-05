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

void imprimirMatricula(Disciplina matricula[], int i){
	cout << endl << "Materia matriculada: " << matricula[i].nomeDisciplina << endl << "Codigo da materia: " << matricula[i].codigoDisciplina << endl << "Carga horaria da materia: " << matricula[i].cargaHoraria << endl;
}

int buscaSequencial(string materia, Disciplina matricula[]){
	for(int i = 0; i < TAM; i ++){
		if(materia == matricula[i].nomeDisciplina){
			return i;
		}
	}
	return -1;
}

int main(){
	Disciplina matricula[TAM];
	matricular(matricula);
	string materia = "FTC";
	if(buscaSequencial(materia, matricula) != -1){
		cout << "#MATERIA ENCONTRADA#" << endl;
		imprimirMatricula(matricula, buscaSequencial(materia, matricula));
	}else{
		cout << endl << "Materia nao encontrada" << endl;
	}
	return 0;
}

