#include "vol.h"

void Vol::afegeixSeients(string* codiSeients, int nSeients)
{
	for (int i = 0; i < nSeients; i++)
	{
		m_seients[m_nSeients] = codiSeients[i];
		m_nSeients++;
	}
}

int Vol::buscaSeient(const string& codiSeient)
{
	bool trobat = false;
	int posicio = -1;
	int i = 0;
	while (!trobat && (i < m_nSeients))
	{
		if (m_seients[i].getCodi() == codiSeient)
		{
			trobat = true;
			posicio = i;
		}
		else
			i++;
	}
	return posicio;
}

bool Vol::afegeixPassatger(const string& codiSeient, const string& dni, const string& nom)
{
	bool correcte = false;
	int pos = buscaSeient(codiSeient);
	if (pos != -1)
		correcte = m_seients[pos].assignaPassatger(dni, nom);
	return correcte;
}

bool Vol::cancelaReserva(const string& codiSeient)
{
	bool correcte = false;
	int pos = buscaSeient(codiSeient);
	if (pos != -1)
		correcte = m_seients[pos].eliminaPassatger();
	return correcte;
}

Passatger* Vol::recuperaPassatger(const string& codiSeient)
{
	Passatger* p = nullptr;
	int pos = buscaSeient(codiSeient);
	if (pos != -1)
		p = m_seients[pos].getPassatger();
	return p;
}

bool Vol::modificaReserva(const string& codiSeientOriginal, const string& codiSeientNou)
{
	bool correcte = false;
	int posOriginal = buscaSeient(codiSeientOriginal);
	int posNova = buscaSeient(codiSeientNou);
	if ((posOriginal != -1) && (posNova != -1))
	{
		Passatger* passatgerOriginal = m_seients[posOriginal].getPassatger();
		Passatger* passatgerNou = m_seients[posNova].getPassatger();
		if ((passatgerOriginal != nullptr) && (passatgerNou == nullptr))
		{
			correcte = true;
			m_seients[posNova].setPassatger(passatgerOriginal);
			m_seients[posOriginal].setPassatger(nullptr);
		}
	}
	return correcte;
}