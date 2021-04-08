#include "operacions_data.h"
#include <fstream>
using namespace std;

bool comprovaTermini(const string& nomFitxerIn, const string& nomFitxerOut)
{
	int nDies, dia, mes, any;

	ifstream fitxerEntrada;
	fitxerEntrada.open(nomFitxerIn);
	fitxerEntrada >> dia >> mes >> any;
	Data diaOriginal(dia, mes, any);
	fitxerEntrada >> dia >> mes >> any;
	Data dataActual(dia, mes, any);
	fitxerEntrada >> nDies;
	fitxerEntrada.close();

	bool valid = false;
	Data diaTermini = diaOriginal + nDies;

	ofstream fitxerSortida;
	fitxerSortida.open(nomFitxerOut, ofstream::app);
	fitxerSortida << diaTermini.getDia() << " " << diaTermini.getMes() << " " << diaTermini.getAny();
	fitxerSortida.close();

	if ((dataActual < diaTermini) || (diaTermini == dataActual))
		valid = true;
	return valid;
}