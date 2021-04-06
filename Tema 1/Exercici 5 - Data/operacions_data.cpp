#include "operacions_data.h"

bool terminiValid(Data& diaOriginal, int nDies, Data& dataActual)
{
	bool valid = false;
	Data diaTermini = diaOriginal + nDies;
	if ((dataActual < diaTermini) || (diaTermini == dataActual))
		valid = true;
	return valid;
}