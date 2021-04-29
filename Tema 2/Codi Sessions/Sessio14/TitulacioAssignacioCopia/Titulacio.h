#pragma once
#include "Estudiant.h"
const int MAX_ESTUDIANTS = 300;

class Titulacio
{
public:
	Titulacio(): m_nom(""), m_nEstudiants(0), m_nMaxAssignatures(0), m_nMaxEstudiants(0), m_estudiants(nullptr) {}
	Titulacio(const string& nom, int maxAssignatures, int maxEstudiants): m_nom(nom), m_nEstudiants(0), m_nMaxAssignatures(maxAssignatures), 
		m_nMaxEstudiants(maxEstudiants) {
		m_estudiants = new Estudiant[maxEstudiants];
	}
	Titulacio(const Titulacio& t);
	Titulacio& operator=(const Titulacio& t);
	~Titulacio() { if (m_estudiants != nullptr) delete[] m_estudiants; }
	void afegeixEstudiant(const string& niu, const string& nom);
	bool eliminaEstudiant(const string& niu);
	Estudiant* consultaEstudiant(const string& niu);
	Estudiant getEstudiant(int posicio) { return m_estudiants[posicio]; }
	string getNom() const { return m_nom; }
	int getMaxAssignatures() const { return m_nMaxAssignatures; }
	int getMaxEstudiants() const { return m_nMaxEstudiants; }
	int getNEstudiants() const { return m_nEstudiants; }
private:
	string m_nom;
	int m_nMaxAssignatures;
	Estudiant *m_estudiants;
	int m_nMaxEstudiants;
	int m_nEstudiants;
};
