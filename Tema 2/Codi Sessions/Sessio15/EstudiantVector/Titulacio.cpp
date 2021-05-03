#include "Titulacio.h"



void Titulacio::afegeixEstudiant(const string& niu, const string& nom)
{
	m_estudiants[m_nEstudiants].inicialitza(niu, nom);
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

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
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
		e = m_estudiants[i];
	return trobat;
}