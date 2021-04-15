#include "Llista.h"
#include <time.h>


Llista llista;

int main()
{
	clock_t timeAfegeix;
	timeAfegeix = clock();
	for (int i = 0; i < 10000; i++)
	{
		Data d(1, 1, 2010);
		llista.insereix(d, 0);
	}
	timeAfegeix = clock() - timeAfegeix;
	float tempsAfegeix = (float)timeAfegeix / CLOCKS_PER_SEC;


 	return 0;
}