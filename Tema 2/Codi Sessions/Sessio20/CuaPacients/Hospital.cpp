#include "Hospital.h"

int Hospital::registraPacient(const string &nom)
{
	int minConsulta = 0;
	for (int i = 1; i<N_CONSULTES; i++)
		if (m_consultes[i].size() < m_consultes[minConsulta].size())
			minConsulta = i;
	m_consultes[minConsulta].push(nom);
	return minConsulta;
}

string Hospital::atendrePacient(int nConsulta)
{
	string nom = "";
	if (!m_consultes[nConsulta].empty())
	{
		nom = m_consultes[nConsulta].front();
		m_consultes[nConsulta].pop();
	}
	return nom;
}
