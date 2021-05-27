#pragma once
#include "Comanda.h"
#include "Producte.h"
#include <forward_list>

class Empresa
{
public:
	void llegeixProductes(const string& nomFitxer);
	bool afegeixComanda(const string& nomFitxer);
	bool importComanda(const string& nomClient, const string& data, float &import);
	bool DetallProducteComanda(const string& nomClient, const string& data, const string&codiProducte,
									int& nUnitats, float& preu);
private:
	std::forward_list<Comanda> m_comandes;
	std::forward_list<Producte> m_productes;

	bool cercaProducte(const string& nomProducte, string& codi, float& preuUnitari);
	bool cercaComanda(const string& nomClient, const string& data, Comanda& c);
};