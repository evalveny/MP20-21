#include "operacions_data.h"
#include <fstream>
using namespace std;

void ordenaDates(const string& nomFitxerIn, const string& nomFitxerOut)
{
	Data d;
	Data dates[MAX_DATES];
	int nDates = 0;

	ifstream fitxerEntrada;
	fitxerEntrada.open(nomFitxerIn);
	if (fitxerEntrada.is_open())
	{
		fitxerEntrada >> d;
		while (!fitxerEntrada.eof())
		{
			int pos = 0;
			bool trobat = false;
			while ((pos < nDates) && !trobat)
			{
				if (d < dates[pos])
					trobat = true;
				else
					pos++;
			}
			for (int i = nDates; i > pos; i--)
				dates[i] = dates[i - 1];
			dates[pos] = d;
			nDates++;
			fitxerEntrada >> d;
		}
		fitxerEntrada.close();
	}
	ofstream fitxerSortida;
	fitxerSortida.open(nomFitxerOut);
	for (int i = 0; i < nDates; i++)
		fitxerSortida << dates[i] << endl;
	fitxerSortida.close();
}