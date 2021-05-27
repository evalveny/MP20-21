#pragma once
#include "ProducteComanda.h"
#include <string>
#include <vector>
using namespace std;

class Comanda
{
public:
	Comanda(const string &nomClient, const string &data);
	Comanda(const Comanda &c);
	~Comanda();
	Comanda& operator=(const Comanda &c);
	string getClient() const { return m_nomClient; }
	string getData() const { return m_data; }
	float getImport() const { return m_importTotal; }
	void afegeixProducte(const string &codiProducte, int nUnitats, float preuUnitari);
	bool consultaProducte(const string &codiProducte, int &nUnitats, float &preuUnitari);
	bool eliminaProducte(const string &codiProducte);
private:
	string m_nomClient;
	string m_data;
	float m_importTotal;
	vector<ProducteComanda> m_productes;
};
