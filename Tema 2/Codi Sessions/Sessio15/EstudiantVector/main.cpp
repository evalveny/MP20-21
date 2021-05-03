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


 	return 0;
}