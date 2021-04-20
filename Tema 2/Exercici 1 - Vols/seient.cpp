#include "seient.h"

bool Seient::assignaPassatger(const string& dni, const string& nom)
{
	bool afegit = false;
	if (m_passatger == nullptr)
	{
		m_passatger = new Passatger(dni, nom);
		afegit = true;
	}
	return afegit;
}

bool Seient::eliminaPassatger()
{
	bool eliminat = false;
	if (m_passatger != nullptr)
	{
		delete m_passatger;
		m_passatger = nullptr;
		eliminat = true;
	}
	return eliminat;
}