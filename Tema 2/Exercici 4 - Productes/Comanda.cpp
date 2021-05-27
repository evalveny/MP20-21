#include "Comanda.h"

Comanda::Comanda(const string &nomClient, const string &data)
{
	m_nomClient = nomClient;
	m_data = data;
	m_importTotal = 0.0;
}

Comanda::Comanda(const Comanda &c)
{
	m_nomClient = c.m_nomClient;
	m_data = c.m_data;
	m_importTotal = c.m_importTotal;
	m_productes = c.m_productes;
}

Comanda::~Comanda()
{
}

Comanda& Comanda::operator=(const Comanda &c)
{
	m_nomClient = c.m_nomClient;
	m_data = c.m_data;
	m_importTotal = c.m_importTotal;
	m_productes = c.m_productes;
	return *this;
}

void Comanda::afegeixProducte(const string& codiProducte, int nUnitats, float preuUnitari)
{
	ProducteComanda pc(codiProducte, nUnitats, preuUnitari);
	m_productes.push_back(pc);
	m_importTotal += nUnitats * preuUnitari;
}

bool Comanda::consultaProducte(const string& codiProducte, int& nUnitats, float& preuUnitari)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_productes.size()))
	{
		if (codiProducte == m_productes[i].getCodi())
		{
			trobat = true;
			nUnitats = m_productes[i].getNUnitats();
			preuUnitari = m_productes[i].getPreu();
		}
		else
			i++;
	}
	return trobat;
}

bool Comanda::eliminaProducte(const string& codiProducte)
{
	bool trobat = false;
	vector<ProducteComanda>::iterator actual;
	actual = m_productes.begin();
	while (!trobat && (actual != m_productes.end()))
	{
		if (codiProducte == actual->getCodi())
		{
			trobat = true;
			m_productes.erase(actual);
		}
		else
			actual++;
	}
	return trobat;
}
