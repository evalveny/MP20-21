#include "Empresa.h"
#include <fstream>

void Empresa::llegeixProductes(const string& nomFitxer)
{
	std::ifstream fitxer;

	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		string nom, codi;
		float preu;
		fitxer >> nom;
		while (!fitxer.eof())
		{
			fitxer >> codi;
			fitxer >> preu;
			Producte prod(nom, codi, preu);
			m_productes.push_front(prod);
			fitxer >> nom;
		}
		fitxer.close();
	}
}

bool Empresa::afegeixComanda(const string& nomFitxer)
{
	std::ifstream fitxer;
	bool correcte = true;

	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		string nom, data;
		int nProductes;
		char separador;
		fitxer >> nom;
		fitxer >> data;
		fitxer >> nProductes;
		if (!fitxer.eof())
		{
			Comanda c(nom, data);
			string nomProducte;
			string codi;
			int nUnitats;
			float preuUnitari;
			fitxer >> nomProducte;
			correcte = cercaProducte(nomProducte, codi, preuUnitari);
			while (correcte && (!fitxer.eof()))
			{
				fitxer >> nUnitats;
				c.afegeixProducte(codi, nUnitats, preuUnitari);
				fitxer >> nomProducte;
				correcte = cercaProducte(nomProducte, codi, preuUnitari);
			}
			if (correcte)
				m_comandes.push_front(c);
		}
		fitxer.close();
	}
	return correcte;
}

bool Empresa::importComanda(const string& nomClient, const string& data, float &import)
{
	Comanda c(nomClient, data);

	bool trobat = cercaComanda(nomClient, data, c);
	import = c.getImport();
	return trobat;
}

bool Empresa::DetallProducteComanda(const string& nomClient, const string& data, const string&codiProducte,
	int& nUnitats, float& preu)
{
	Comanda c(nomClient, data);
	bool trobat = cercaComanda(nomClient, data, c);
	if (trobat)
	{
		trobat = c.consultaProducte(codiProducte, nUnitats, preu);
	}
	return trobat;
}


bool Empresa::cercaProducte(const string& nomProducte, string& codi, float& preuUnitari)
{
	std::forward_list<Producte>::iterator it;
	it = m_productes.begin();
	bool trobat = false;
	while (!trobat && (it != m_productes.end()))
	{
		if (it->getNom() == nomProducte)
		{
			trobat = true;
			codi = it->getCodi();
			preuUnitari = it->getPreu();
		}
		else
			it++;
	}
	return trobat;
}

bool Empresa::cercaComanda(const string& nomClient, const string& data, Comanda& c)
{
	std::forward_list<Comanda>::iterator it;
	it = m_comandes.begin();
	bool trobat = false;
	while (!trobat && (it != m_comandes.end()))
	{
		if ((it->getClient() == nomClient) && (it->getData() == data))
		{
			trobat = true;
			c = *it;
		}
		else
			it++;
	}
	return trobat;
}
