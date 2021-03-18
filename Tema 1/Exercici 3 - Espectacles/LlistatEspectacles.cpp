#include "LlistatEspectacles.h"



/*
LlistatEspectacles::~LlistatEspectacles()
{
	
}
*/

bool LlistatEspectacles::afegeixEspectacle(Espectacle& e)
{
	bool correcte = false;

	if (m_NEspectacles < MAXESPECTACLES)
	{
		correcte = true;
		m_espectacles[m_NEspectacles].setNom(e.getNom());
		m_espectacles[m_NEspectacles].setTeatre(e.getTeatre());
		m_espectacles[m_NEspectacles].setDia(e.getDia());
		m_espectacles[m_NEspectacles].setHora(e.getHora());
		m_espectacles[m_NEspectacles].setEntradesTotals(e.getEntradesTotals());
		m_espectacles[m_NEspectacles].setPreu(e.getPreu());
		m_NEspectacles++;
	}
	return correcte;
}

int LlistatEspectacles::buscaEspectacle(string nom, string dia)
{
	int i = 0;
	bool trobat = false;
	while (!trobat && (i < m_NEspectacles))
	{
		if ((m_espectacles[i].getNom() == nom) && (m_espectacles[i].getDia() == dia))
			trobat = true;
		else
			i++;
	}
	if (trobat)
		return i;
	else return -1;
}

int LlistatEspectacles::compraEntrades(string nom, string dia, int nEntrades, float& preu)
{
	int resultat = 0;
	int nEspectacle = buscaEspectacle(nom, dia);

	if (nEspectacle == -1)
		resultat = -2;
	else
	{
		if (m_espectacles[nEspectacle].getEntradesLliures() >= nEntrades)
		{
			m_espectacles[nEspectacle].reservaEntrades(nEntrades);
			preu = m_espectacles[nEspectacle].getPreu() * nEntrades;
		}
		else resultat = -1;
	}
	return resultat;
}


