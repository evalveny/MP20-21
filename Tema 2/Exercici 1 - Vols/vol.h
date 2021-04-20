#ifndef VOL_H
#define VOL_H

#include "seient.h"
#include <string>
using namespace std;

class Vol
{
public:
	Vol() { m_nSeients = 0; }
	Vol(const string& codi, const string& origen, const string& desti,
		const string& data, const string& hora) :
		m_codi(codi), m_origen(origen), m_desti(desti), m_data(data), m_hora(hora) 
		{ m_nSeients = 0; }

	void afegeixSeients(string* codiSeients, int nSeients);

	bool afegeixPassatger(const string& codiSeient, const string& dni, const string& nom);
	Passatger* recuperaPassatger(const string& codiSeient);
	bool cancelaReserva(const string& codiSeient);
	bool modificaReserva(const string& codiSeientOriginal, const string& codiSeientNou);
private:
	static const int MAX_SEIENTS = 100;
	string m_codi;
	string m_origen;
	string m_desti;
	string m_data;
	string m_hora;
	Seient m_seients[MAX_SEIENTS];
	int m_nSeients;

	int buscaSeient(const string& codiSeient);
};

#endif
