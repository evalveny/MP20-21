#include "Llibre.h"


Llibre::Llibre(const string& titol, const string& autor, int nExemplars)
{
	m_titol = titol;
	m_autor = autor;
	m_nExemplars = nExemplars;
	for (int i = 0; i < m_nExemplars; i++)
		m_exemplars[i] = false;
}
void Llibre::setNExemplars(int nExemplars)
{
	m_nExemplars = nExemplars;
	for (int i = 0; i < m_nExemplars; i++)
		m_exemplars[i] = false;
}

bool Llibre::presta(int &codiExemplar)
{
	bool disponible = false;
	int i = 0;
	while (!disponible && (i < m_nExemplars))
	{
		if (!m_exemplars[i])
			disponible = true;
		else
			i++;
	}
	if (disponible)
	{
		codiExemplar = i;
		m_exemplars[i] = true;
	}
	return disponible;

}

bool Llibre::retorna(int codiExemplar)
{
	bool retornat = false;
	if ((codiExemplar >= 0) && (codiExemplar < m_nExemplars))
		if (m_exemplars[codiExemplar])
		{
			retornat = true;
			m_exemplars[codiExemplar] = false;
		}
	return retornat;

}
