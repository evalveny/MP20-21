#include "operacions_data.h"

bool comprovaTermini()
{
	Data diaOriginal, dataActual;
	int nDies;

	cin >> diaOriginal;
	cin >> dataActual;
	cout << "Introdueix n. dies: ";
	cin >> nDies;
	bool valid = false;
	Data diaTermini = diaOriginal + nDies;
	if ((dataActual < diaTermini) || (diaTermini == dataActual))
		valid = true;
	return valid;
}