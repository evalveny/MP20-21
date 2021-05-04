#include "Titulacio.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Titulacio titulacio ("nom_titulacio", 10);
	string assignatura;
	Estudiant estudiant;
	int test;

	cout << "Introdueix opcio (1: Test Manual, 2: Test Automatic)";
	cin >> test;
	if (test == 1) {

		int opcio;
		cout << "Introdueix opcio (1: afegir, 2: eliminar, 3: consultar, 0: sortir): ";
		cin >> opcio;
		while (opcio != 0)
		{
			switch (opcio)
			{
			case 1:
				cout << "Nom assignatura: ";
				cin >> assignatura;
				estudiant.insereixAssignatura(assignatura);
				break;
			case 2:
				cout << "Nom assignatura: ";
				cin >> assignatura;
				estudiant.eliminaAssignatura(assignatura);
				break;
			case 3:
				cout << endl << "Mostrant assignatures:  " << endl;
				estudiant.mostraAssignatures();
				break;
			}
			cout << "Introdueix opcio (1: afegir, 2: eliminar, 3: consultar, 0: sortir): ";
			cin >> opcio;
		}
	}
	else {

		int grade;

		grade = 0;
		cout << endl << endl;
		cout << "Comment :=>> INICIANT TEST" << endl;
		cout << "Comment :=>> =============" << endl;
		cout << "Comment :=>> " << endl;



		cout << "Comment :=>> TEST afegir assignatura alfabeticament a estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		estudiant.insereixAssignatura("Metodologia de la Programacio");
		estudiant.insereixAssignatura("Fonaments de informatica");
		assignatura = estudiant.getAssignatura(1);
		if (assignatura == "Metodologia de la Programacio") {
			cout << "Assignatura Metodologia correcte";
			grade = 5;
		}
		else {
			cout << "Error al afegir assignatura";
		}

		cout << "Comment :=>> TEST eliminar assignatura a estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		estudiant.eliminaAssignatura("Fonaments de informatica");
		assignatura = estudiant.getAssignatura(0);
		if (assignatura == "Fonaments de informatica" || assignatura != "Metodologia de la Programacio") {

			cout << "Error al eliminar assignatura";
		}
		else {
			cout << "Eliminar assignatura correcte";
			grade = grade +5;
		}
		

		cout << "Comment :=>> TEST mostrar assignatures estudiant" << endl;
		cout << "Comment :=>> ------------------------------------------" << endl;
		estudiant.mostraAssignatures();
		cout << grade;
	

	}


 	return 0;
}