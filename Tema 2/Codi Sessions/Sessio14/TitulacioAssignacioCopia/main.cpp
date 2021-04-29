#include "Titulacio.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Titulacio titulacio ("nom_titulacio", 10);
	Estudiant estudiant;
	string niu, nom;
	int opcio;
	cout << "Introdueix opcio (1: afegir, 2: eliminar, 3: consultar (niu), 4: consultar (posicio), 0: sortir): ";
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
			titulacio.consultaEstudiant(niu, estudiant);
			{
				cout << "Niu: " << estudiant.getNiu() << endl;
				cout << "Nom: " << estudiant.getNom() << endl;
			}
			break;
		case 4:
			cout << "Posicio: ";
			int posicio;
			cin >> posicio;
			Estudiant e = titulacio.getEstudiant(posicio);
			{
				cout << "Niu: " << e.getNiu() << endl;
				cout << "Nom: " << e.getNom() << endl;
			}
			break;
		}
		cout << "Introdueix opcio (1: afegir, 2: eliminar, 3: consultar (niu), 4: consultar (posicio), 0: sortir): ";
		cin >> opcio;
	}


 	return 0;
}