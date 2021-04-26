#include "Estudiant.h"

Estudiant::Estudiant(const string& niu, const string& nom, int nAssignatures)
{
	m_NIU = niu;
	m_nom = nom;
	m_maxAssignatures = nAssignatures;
	m_assignatures = new string[m_maxAssignatures];
	m_nAssignatures = 0;
}

Estudiant::~Estudiant()
{
	if (m_assignatures != nullptr)
	{
		delete[] m_assignatures;
		m_assignatures = nullptr;
		m_maxAssignatures = 0;
		m_nAssignatures = 0;
	}
}

void Estudiant::inicialitza(const string& niu, const string& nom, int nAssignatures)
{
	// Inicialitza.
	m_NIU = niu;
	m_nom = nom;
	m_maxAssignatures = nAssignatures;
	m_assignatures = new string[m_maxAssignatures];
	m_nAssignatures = 0;
}

void Estudiant::allibera()
{
	if (m_assignatures != nullptr)
	{
		// Allibera.
		delete[] m_assignatures;
		m_assignatures = nullptr;
		m_maxAssignatures = 0;
		m_nAssignatures = 0;
	}
}

void Estudiant::afegeixAssignatura(const string& assignatura)
{ 
	// Afegeix assignatura
	if (m_assignatures != nullptr)
		m_assignatures[m_nAssignatures++] = assignatura;
}

string Estudiant::getAssignatura(int posicio) const
{
	if (m_assignatures != nullptr)
		return m_assignatures[posicio];
	else return "";
}


