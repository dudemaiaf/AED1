#include <iostream>


using namespace std;

struct Disciplina {
	string nomeDisciplina;
	string codigoDisciplina;
	int cargaHoraria;
};

void matricular(Disciplina &matricula){
	cout << "Informe o nome da materia a ser realizada: ";
	getline(cin, matricula.nomeDisciplina);
	cout << "Informe o codigo da materia: ";
	getline(cin, matricula.codigoDisciplina);
	cout << "Informe a carga horaria: ";
	cin >> matricula.cargaHoraria;
	cin.ignore();
}

void imprimirMatricula(Disciplina matricula){
	cout << endl << "Materia matriculada: " << matricula.nomeDisciplina << endl << "Codigo da materia: " << matricula.codigoDisciplina << endl << "Carga horaria da materia: " << matricula.cargaHoraria << endl;
}

int main(){
	Disciplina matricula;
	matricular(matricula);
	imprimirMatricula(matricula);
	return 0;
}

