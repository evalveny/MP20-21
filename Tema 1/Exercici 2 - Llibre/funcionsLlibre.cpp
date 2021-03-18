#include "funcionsLlibre.h"

int cercaLlibre(Llibre llibres[], int nLlibres, const string &titol)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < nLlibres))
	{
		if (titol == llibres[i].getTitol())
			trobat = true;
		else
			i++;
	}
	if (trobat)
		return i;
	else 
		return -1;
}


int prestaLlibre(Llibre llibres[], int nLlibres, const string &titol, int &codiExemplar)
{
	int resultat;
	int posLlibre = cercaLlibre(llibres, nLlibres, titol);
	if (posLlibre == -1)
		resultat = -2;
	else
		if (llibres[posLlibre].presta(codiExemplar))
			resultat = 0;
		else
			resultat = -1;
	return resultat;
}

int retornaLlibre(Llibre llibres[], int nLlibres, const string &titol, int codiExemplar)
{
	int resultat;
	int posLlibre = cercaLlibre(llibres, nLlibres, titol);
	if (posLlibre == -1)
		resultat = -2;
	else
		if (llibres[posLlibre].retorna(codiExemplar))
			resultat = 0;
		else
			resultat = -1;
	return resultat;
}