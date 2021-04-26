#include "Titulacio.h"
#include <iostream>
#include <string>
using namespace std;

// MAIN COMPLET: ESTUDIANT + TITULACIO
/*
int main()
{
	Titulacio titulacio ("nom_titulacio", 10);
	string niu, nom;
	Estudiant estudiant;
	int opcio;
	int test;
	float grade;

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
		cout << "Grade :=>> " << grade << endl;
		cout << endl << endl;
		cout << "Comment :=>> INICIANT TEST" << endl;
		cout << "Comment :=>> =============" << endl;
		cout << "Comment :=>> " << endl;


		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST afegir estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> Afegint estudiant: '333', 'pep' " << endl;
		titulacio.afegeixEstudiant("333", "pep");
		cout << "Comment :=>> Afegint estudiant: '444', 'jan' " << endl;
		titulacio.afegeixEstudiant("444", "jan");
		cout << "Comment :=>> ------" << endl;		
		cout << "Comment :=>> Comprovant estudiant: '333'" << endl;
		bool resposta = titulacio.consultaEstudiant("333", estudiant);
		if (resposta == true) {
			grade += 2.5;
			cout << "Comment :=>> Test correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Comment :=>> Test erroni. L'estudiant no esta a l'array" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
			grade = 0;
		}
		cout << "Comment :=>> Comprovant estudiant: '444'" << endl;
		 resposta = titulacio.consultaEstudiant("444", estudiant);
		if (resposta == true) {
			grade += 2.5;
			cout << "Comment :=>> Test correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Comment :=>> Test erroni. L'estudiant no esta a l'array" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
			grade = 0;
		}
		cout << "Grade :=>> " << grade << endl;


		cout << "Comment :=>> TEST afegir assignatura a estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> Afegint assignatura: 'metodologia de la programacio'" << endl;
		estudiant.afegeixAssignatura("metodologia de la programacio");
		cout << "Comment :=>> Afegint assignatura: 'algebra'" << endl;
		estudiant.afegeixAssignatura("algebra");
		cout << "Comment :=>> ------" << endl;
		cout << "Comment :=>> Comprovant assignatura: 'metodologia de la programacio'" << endl;		cout << "Comment :=>> ------" << endl;
		string assignatura = estudiant.getAssignatura(0);
		if (assignatura == "metodologia de la programacio") {
			grade = grade + 1.0;
			cout << "Comment :=>> Test correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Test erroni. L'assignatura no esta a l'array" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		cout << "Comment :=>> Comprovant assignatura: 'algebra'" << endl;		cout << "Comment :=>> ------" << endl;
		assignatura = estudiant.getAssignatura(1);
		if (assignatura == "algebra") {
			grade = grade + 1.0;
			cout << "Comment :=>> Test correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Test erroni. L'assignatura no esta a l'array" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		cout << "Grade :=>> " << grade << endl;


		cout << "Comment :=>> TEST eliminar estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> Eliminant estudiant: '333' " << endl;
		titulacio.eliminaEstudiant("333");
		cout << "Comment :=>> ------" << endl;
		cout << "Comment :=>> Comprovant estudiant: '333'" << endl;
		resposta = titulacio.consultaEstudiant("333", estudiant);
		if (resposta == false) {
			grade = grade + 1.5;
			cout << "Comment :=>> TEST correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Comment :=>> Test erroni. L'estudiant encara esta a l'array" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		cout << "Comment :=>> Comprovant estudiant: '444'" << endl;
		resposta = titulacio.consultaEstudiant("444", estudiant);
		if (resposta == true) {
			grade = grade + 1.5;
			cout << "Comment :=>> TEST correcte" << endl;
			cout << "Comment :=>> ------------------------------------------" << endl;
		}
		else {
			cout << "Comment :=>> Test erroni. L'estudiant no esta a l'array" << endl;
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
*/


// MAIN PARCIAL: NOMES ESTUDIANT

int main()
{
	string niu, nom;
	Estudiant estudiant("333", "pep", 10);
	float grade;


	grade = 0;
	cout << "Grade :=>> " << grade << endl;
	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;


	cout << "Comment :=>> TEST afegir assignatura a estudiant" << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Afegint assignatura: 'metodologia de la programacio'" << endl;
	estudiant.afegeixAssignatura("metodologia de la programacio");
	cout << "Comment :=>> Afegint assignatura: 'algebra'" << endl;
	estudiant.afegeixAssignatura("algebra");
	cout << "Comment :=>> ------" << endl;
	cout << "Comment :=>> Comprovant assignatura: 'metodologia de la programacio'" << endl;		cout << "Comment :=>> ------" << endl;
	string assignatura = estudiant.getAssignatura(0);
	if (assignatura == "metodologia de la programacio") {
		grade = grade + 5.0;
		cout << "Comment :=>> Test correcte" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	else {
		cout << "Test erroni. L'assignatura no esta a l'array" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	cout << "Comment :=>> Comprovant assignatura: 'algebra'" << endl;		cout << "Comment :=>> ------" << endl;
	assignatura = estudiant.getAssignatura(1);
	if (assignatura == "algebra") {
		grade = grade + 5.0;
		cout << "Comment :=>> Test correcte" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	else {
		cout << "Test erroni. L'assignatura no esta a l'array" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
	}

	if (grade < 0)
		grade = 0;
	cout << "Grade :=>> " << grade << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;



	return 0;
}

