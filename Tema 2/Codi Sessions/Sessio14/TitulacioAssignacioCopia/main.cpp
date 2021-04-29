#include "Titulacio.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	float grade = 0;
	cout << "Grade :=>> " << grade << endl;
	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	Titulacio titulacio ("nom_titulacio", 10, 10);
	titulacio.afegeixEstudiant("NIU_1", "NOM_1");
	titulacio.afegeixEstudiant("NIU_2", "NOM_2");
	Estudiant* e = titulacio.consultaEstudiant("NIU_1");
	e->afegeixAssignatura("ASSIG_1");
	e->afegeixAssignatura("ASSIG_2");

	cout << "Comment :=>> Inicialitzant dades d'una titulacio ..." << endl;
	cout << "Comment :=>> ----" << endl;
	cout << "Comment :=>> Fent copia de la titulacio amb constructor de copia ..." << endl;
	Titulacio titulacioCopia(titulacio);
	cout << "Comment :=>> ----" << endl;
	cout << "Comment :=>> Comprovant copia ..." << endl;
	bool correcte = true;
	correcte = correcte && (titulacioCopia.getNom() == "nom_titulacio")
		&& (titulacioCopia.getMaxAssignatures() == 10) && (titulacioCopia.getMaxEstudiants() == 10)
		&& (titulacioCopia.getNEstudiants() == 2);
	e = titulacioCopia.consultaEstudiant("NIU_1");
	correcte = correcte && (e != nullptr) && (e->getNAssignatures() == 2)
		&& (e->getAssignatura(0) == "ASSIG_1") && (e->getAssignatura(1) == "ASSIG_2");
	e = titulacioCopia.consultaEstudiant("NIU_2");
	correcte = correcte && (e != nullptr) && (e->getNAssignatures() == 0);
	if (correcte)
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 5.0;
	}
	else
		cout << "Comment :=>> ERROR" << endl;
	cout << "Comment :=>> ---------------------------" << endl;
	cout << "Grade :=>> " << grade << endl;
	cout << "Comment :=>> Fent copia de la titulacio amb operador d'assignacio ..." << endl;
	Titulacio titulacioAssignacio;
	titulacioAssignacio = titulacio;
	cout << "Comment :=>> ----" << endl;
	cout << "Comment :=>> Comprovant copia ..." << endl;
	correcte = true;
	correcte = correcte && (titulacioAssignacio.getNom() == "nom_titulacio")
		&& (titulacioAssignacio.getMaxAssignatures() == 10) && (titulacioAssignacio.getMaxEstudiants() == 10)
		&& (titulacioAssignacio.getNEstudiants() == 2);
	e = titulacioAssignacio.consultaEstudiant("NIU_1");
	correcte = correcte && (e != nullptr) && (e->getNAssignatures() == 2)
		&& (e->getAssignatura(0) == "ASSIG_1") && (e->getAssignatura(1) == "ASSIG_2");
	e = titulacioAssignacio.consultaEstudiant("NIU_2");
	correcte = correcte && (e != nullptr) && (e->getNAssignatures() == 0);
	if (correcte)
	{
		cout << "Comment :=>> CORRECTE" << endl;
		grade += 5.0;
	}
	else
		cout << "Comment :=>> ERROR" << endl;
	cout << "Comment :=>> ---------------------------" << endl;
	cout << "Grade :=>> " << grade << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;

 	return 0;
}