#pragma once
#include "NodeEstudiant.h"
const int MAX_ESTUDIANTS = 300;

class Titulacio
{
public:
	Titulacio(): m_nom(""), m_nEstudiants(0) {}
	Titulacio(const string& nom, int maxAssignatures): m_nom(nom), m_nEstudiants(0) {}
	void eliminaPrimerEstudiant();
	void afegeixEstudiant(const string& niu, const string& nom);
	bool eliminaEstudiant(const string& niu);
	bool consultaEstudiant(const string& niu, Estudiant& e);
private:
	string m_nom;
	NodeEstudiant* m_estudiants;
	int m_nEstudiants;
};
