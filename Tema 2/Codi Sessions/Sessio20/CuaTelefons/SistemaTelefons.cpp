#include "SistemaTelefons.h"

SistemaTelefons::SistemaTelefons()
{

}

void SistemaTelefons::introduirTelefon(const string& telf)
{
	m_cuaTelefons.push(telf);
}

string SistemaTelefons::servirTelefon()
{
	string tlf = "";
	if (!m_cuaTelefons.empty())
	{
		tlf = m_cuaTelefons.front();
		m_cuaTelefons.pop();
	}
	return tlf;
}

void SistemaTelefons::eliminarTot()
{
	while (!m_cuaTelefons.empty())
		m_cuaTelefons.pop();
}