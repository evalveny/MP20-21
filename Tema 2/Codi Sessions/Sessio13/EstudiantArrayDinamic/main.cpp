#include "Titulacio.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Titulacio titulacio ("nom_titulacio", 10);
	string niu, nom;
	Estudiant estudiant;
	int opcio;
	int test;
	int grade;

	cout << "Introdueix opcio (1: Test Manual, 2: Test Automàtic)";
	cin >> test;
	if (test == 1) {
		cout << "Introdueix opcio (1: afegir, 2: eliminar, 3: consultar, 0: sortir): ";
		cin >> opcio;
		while (opcio != 0)
		{
			switch (opcio)
			{
			case 1:
				cout << "Niu: ";
				cin >> niu;
				cout << "Nom: ";
				cin >> nom;
				titulacio.afegeixEstudiant(niu, nom);
				break;
			case 2:
				cout << "Niu: ";
				cin >> niu;
				titulacio.eliminaEstudiant(niu);
				break;
			case 3:
				cout << "Niu: ";
				cin >> niu;
				if (titulacio.consultaEstudiant(niu, estudiant))
				{
					cout << "Niu: " << estudiant.getNiu() << endl;
					cout << "Nom: " << estudiant.getNom() << endl;
				}
				break;
			}
			cout << "Introdueix opcio (1: afegir, 2: eliminar, 3: consultar, 0: sortir): ";
			cin >> opcio;
		}
	}
	else {
		grade = 0;
		cout << endl << endl;
		cout << "Comment :=>> INICIANT TEST" << endl;
		cout << "Comment :=>> =============" << endl;
		cout << "Comment :=>> " << endl;


		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST afegir estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		titulacio.afegeixEstudiant("333", "pep");
		titulacio.afegeixEstudiant("444", "jan");
		bool resposta = titulacio.consultaEstudiant("333", estudiant);
		if (resposta == true) {
			grade = 5;
			cout << "Comment :=>> Test correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Comment :=>> Test erroni" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
			grade = 0;
		}


		cout << "Comment :=>> TEST afegir assignatura a estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		estudiant.afegeixAssignatura("metodologia de la programació");
		string assignatura = estudiant.getAssignatura(0);
		if (assignatura == "metodologia de la programació") {
			grade = grade + 2;
			cout << "Comment :=>> Test correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Test erroni" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}


		cout << "Comment :=>> TEST eliminar estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		titulacio.eliminaEstudiant("333");
		resposta = titulacio.consultaEstudiant(niu, estudiant);
		if (resposta == false) {
			grade = grade + 3;
			cout << "Comment :=>> TEST correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Comment :=>> Test erroni" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}

		if (grade < 0)
		grade = 0;
		   cout << "Grade :=>> " << grade << endl;
		if (grade == 10.0)
			cout << "Comment :=>> Final del test sense errors" << endl;
	}


 	return 0;
}