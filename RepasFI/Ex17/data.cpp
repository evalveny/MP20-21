#include <stdio.h>
#include <iostream>

#include "data.h"


void llegeixDia(Data& diaCalendari)
{
	cout << "Entra el dia: ";
	cin >> diaCalendari.dia;
	cout << "Entra el mes: ";
	cin >> diaCalendari.mes;
	cout << "Entra l'any: ";
	cin >> diaCalendari.any;
}

bool esTraspas(Data& diaCalendari)
{
	// Recordeu que els anys de traspàs són tots els divisibles per 4,
	// en excepció dels que siguin divisibles per 100, però no els que
	// siguin divisibles per 400.

	return (diaCalendari.any % 4) == 0 && ((diaCalendari.any % 100) != 0 || (diaCalendari.any % 400) == 0);
}

bool esValida(Data& diaCalendari)
{
	unsigned int diesMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (esTraspas(diaCalendari))
	{
		diesMes[1]++;
	}
	return (1 <= diaCalendari.mes && diaCalendari.mes <= 12 && 1 <= diaCalendari.any && 1 <= diaCalendari.dia && diaCalendari.dia <= diesMes[diaCalendari.mes - 1]);
}

int comparaDates(Data& data1, Data& data2)
{
	int resultat = 0;
	if (data1.any < data2.any)
		resultat = -1;
	else
		if (data1.any > data2.any)
			resultat = 1;
		else
			if (data1.mes < data2.mes)
				resultat = -1;
			else
				if (data1.mes > data2.mes)
					resultat = 1;
				else
					if (data1.dia < data2.dia)
						resultat = -1;
					else
						if (data1.dia > data2.dia)
							resultat = 1;
						else
							resultat = 0;
	return resultat;
}

int nDiesMes(Data& dia)
{
	unsigned int diesMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (dia.mes != 2)
		return diesMes[dia.mes - 1];
	else
		if (esTraspas(dia))
			return diesMes[dia.mes - 1] + 1;
		else
			return diesMes[dia.mes - 1];
}

Data sumaDies(Data& diaOriginal, int nDies)
{
	Data resultat = diaOriginal;
	while (nDies > 0)
	{
		int diesMes = nDiesMes(resultat);
		if ((resultat.dia + nDies) > diesMes)
		{
			nDies -= (diesMes - resultat.dia) + 1;
			resultat.dia = 1;
			resultat.mes++;
			if (resultat.mes > 12)
			{
				resultat.mes = 1;
				resultat.any++;
			}
		}
		else
		{
			resultat.dia += nDies;
			nDies = 0;
		}
	}
	return resultat;
}


int totalDies(Data& dia)
{
	int diesMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (esTraspas(dia))
	{
		diesMes[1]++;
	}
	int a = dia.any - 1;
	int acumDiesAnys = (a * 365) + (a / 4) - (a / 100) + (a / 400);
	int acumDiesMes = 0;
	for (unsigned int i = 0; i < dia.mes - 1; i++)
	{
		acumDiesMes += diesMes[i];
	}

	return dia.dia + acumDiesMes + acumDiesAnys;
}

int restaDates(Data& data1, Data& data2)
{
	int nDies = totalDies(data1) - totalDies(data2);
	if (nDies < 0)
		nDies = -nDies;
	return nDies;
}

bool terminiValid(Data& diaOriginal, int nDies, Data& dataActual)
{
	Data diaTermini = sumaDies(diaOriginal, nDies);
	bool valid = true;
	if (dataActual.any > diaTermini.any)
		valid = false;
	else
		if (dataActual.any == diaTermini.any)
			if (dataActual.mes > diaTermini.mes)
				valid = false;
			else
				if (dataActual.mes == diaTermini.mes)
					if (dataActual.dia > diaTermini.dia)
						valid = false;
	return valid;
}

