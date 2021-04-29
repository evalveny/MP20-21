#pragma once
#include "Estudiant.h"
const int MAX_ESTUDIANTS = 300;

class Titulacio
{
public:
	Titulacio(): m_nom(""), m_nEstudiants(0), m_nMaxAssignatures(0) {}
	Titulacio(const string& nom, int maxAssignatures): m_nom(nom), m_nEstudiants(0), m_nMaxAssignatures(maxAssignatures) {}
	void afegeixEstudiant(const string& niu, const string& nom);
	bool eliminaEstudiant(const string& niu);
	bool consultaEstudiant(const string& niu, Estudiant& e);
	Estudiant getEstudiant(int posicio) { return m_estudiants[posicio]; }
private:
	string m_nom;
	int m_nMaxAssignatures;
	Estudiant m_estudiants[MAX_ESTUDIANTS];
	int m_nEstudiants;
};
