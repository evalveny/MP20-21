#include "Titulacio.h"


Titulacio& Titulacio::operator=(const Titulacio& t)
{
	if (this != &t)
	{
		m_nom = t.m_nom;
		m_nMaxAssignatures = t.m_nMaxAssignatures;
		m_nEstudiants = t.m_nEstudiants;
		m_nMaxEstudiants = t.m_nMaxEstudiants;

		if (m_estudiants != nullptr)
			delete[] m_estudiants;

		if (t.m_estudiants != nullptr)
		{
			m_estudiants = new Estudiant[m_nMaxEstudiants];
			for (int i = 0; i < m_nEstudiants; i++)
				m_estudiants[i] = t.m_estudiants[i];
		}
		else
			m_estudiants = nullptr;

	}
	return *this;
}


Titulacio::Titulacio(const Titulacio& t)
{
	m_nom = t.m_nom;
	m_nMaxAssignatures = t.m_nMaxAssignatures;
	m_nEstudiants = t.m_nEstudiants;
	m_nMaxEstudiants = t.m_nMaxEstudiants;

	if (t.m_estudiants != nullptr)
	{
		m_estudiants = new Estudiant[m_nMaxEstudiants];
		for (int i = 0; i < m_nEstudiants; i++)
			m_estudiants[i] = t.m_estudiants[i];
	}
	else
		m_estudiants = nullptr;
}

void Titulacio::afegeixEstudiant(const string& niu, const string& nom)
{
	Estudiant e(niu, nom, m_nMaxAssignatures);
	m_estudiants[m_nEstudiants] = e;
	m_nEstudiants++;
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	int i = 0;
	while ((i < m_nEstudiants) && !trobat)
	{
		if (niu == m_estudiants[i].getNiu())
			trobat = true;
		else
		{
			i++;
		}
	}
	if (trobat)
	{
		m_estudiants[i].allibera();
		for (int j = i; j < (m_nEstudiants - 1); j++)
			m_estudiants[j] = m_estudiants[j + 1];
		m_nEstudiants--;
	}
	return trobat;
}

Estudiant* Titulacio::consultaEstudiant(const string& niu)
{
	Estudiant* estudiant = nullptr;
	bool trobat = false;
	int i = 0;
	while ((i < m_nEstudiants) && !trobat)
	{
		if (niu == m_estudiants[i].getNiu())
			trobat = true;
		else
		{
			i++;
		}
	}
	if (trobat)
		estudiant = &m_estudiants[i];
	return estudiant;
}


