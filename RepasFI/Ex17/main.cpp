
#include "data.h"
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

void mostraVector(int v[], int longitud)
{
	cout << "[";
	if (longitud > 0)
	{
		cout << v[0];
	}
	for (int i = 1; i < longitud; i++)
		cout << "," << v[i];
	cout << "]";
}

bool igualVectors(int v1[], int v2[], int longitud)
{
	bool iguals = true;
	int i = 0;
	while ((iguals) && (i < longitud))
	{
		if (v1[i] != v2[i])
			iguals = false;
		i++;
	}
	return iguals;
}

void escriuData(Data& diaG)
{
	cout << diaG.dia << "/" << diaG.mes << "/" << diaG.any;
}

bool igualDies(Data& dia1, Data& dia2)
{
	return ((dia1.dia == dia2.dia) && (dia1.mes == dia2.mes) && (dia1.any == dia2.any));
}

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}

float testLlegeixDia()
{
	float reduccio = 0.0;

	Data resultat;
	streambuf* orig = std::cin.rdbuf();
	istringstream input("13\n9\n2014");
	Data resultatEsperat;
	resultatEsperat.dia = 13;
	resultatEsperat.mes = 9;
	resultatEsperat.any = 2014;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio llegeixDia" << endl;
	cout << "Comment :=>> =====================================" << endl;

	cout << "Comment :=>> Llegint valors de l'entrada" << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Resultat esperat: "; escriuData(resultatEsperat); cout << endl;
	cin.rdbuf(input.rdbuf());
	llegeixDia(resultat);
	cin.rdbuf(orig);
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Resultat obtingut: "; escriuData(resultat); cout << endl;
	if (igualDies(resultat, resultatEsperat))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	return reduccio;
}


float testEsValida()
{
	float reduccio = 0.0;

	const int N_PROVES = 8;
	Data dates[N_PROVES] = { { 29, 2, 1996 },{ 29, 2, 1900 },{ 0, 1, 2000 },{ 31, 12, 1997 },{ 1, 1, 2004 },{ 31, 4, 1997 },{ 30,4,2003 },{ 0,3,1703 } };
	bool valid[N_PROVES] = { true, false, false, true, true, false, true,false };


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio esValid" << endl;
	cout << "Comment :=>> ==================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data: "; escriuData(dates[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(valid[i]); cout << endl;
		bool resultat = esValida(dates[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == valid[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	if (reduccio > 4.0)
		reduccio = 4.0;
	return reduccio;
}


float testComparaDates()
{
	float reduccio = 0.0;

	const int N_PROVES = 9;
	Data dates1[N_PROVES] = { { 1, 1, 1996 },{ 1, 1, 1900 },{ 2, 1, 1900 },{ 1, 1, 2000 },{ 31, 12, 1999 },{ 1, 1, 1997 },{ 1, 2, 1997 },{ 1, 1, 2006 },{ 1, 1, 2004 } };
	Data dates2[N_PROVES] = { { 1, 1, 1996 },{ 2, 1, 1900 },{ 1, 1, 1900 },{ 31, 12, 1999 },{ 1, 1, 2000 },{ 1, 2, 1997 },{ 1, 1, 1997 },{ 1, 1, 2004 }, { 1, 1, 2006 } };
	int iguals[N_PROVES] = { 0, -1, 1, 1, -1, -1, 1, 1, -1};

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio comparaDates" << endl;
	cout << "Comment :=>> =======================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data 1: "; escriuData(dates1[i]); cout << endl;
		cout << "Comment :=>> Data 2: "; escriuData(dates2[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << iguals[i] << endl;
		int resultat = comparaDates(dates1[i], dates2[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		if (resultat == iguals[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}



float testSumaDies()
{
	float reduccio = 0.0;

	const int N_PROVES = 8;
	Data dates[N_PROVES] =
	{
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 20, 12, 2018 },
		{ 10, 1, 2018 }
	};

	int nDies[N_PROVES] = { 0, 1, 21, 31, 59, 90, 31, 365 };

	Data resultatEsperat[N_PROVES] =
	{
		{ 10, 1, 2018 },
		{ 11, 1, 2018 },
		{ 31, 1, 2018 },
		{ 10, 2, 2018 },
		{ 10, 3, 2018 },
		{ 10, 4, 2018 },
		{ 20, 1, 2019 },
		{ 10, 1, 2019 }
	};


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio sumaDies" << endl;
	cout << "Comment :=>> ===================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data inicial: "; escriuData(dates[i]); cout << endl;
		cout << "Comment :=>> N. dies a sumar: " << nDies[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; escriuData(resultatEsperat[i]); cout << endl;
		Data resultat = sumaDies(dates[i], nDies[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: "; escriuData(resultat); cout << endl;
		if (igualDies(resultat, resultatEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	if (reduccio > 4.0)
		reduccio = 4.0;
	return reduccio;
}


float testTerminiValid()
{
	float reduccio = 0.0;

	const int N_PROVES = 5;
	Data dates[N_PROVES] =
	{
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 }
	};
	int nDiesTermini[N_PROVES] = { 90, 90, 365, 365, 365 };
	Data dataActual[N_PROVES] =
	{
		{ 10, 4, 2018 },
		{ 11, 4, 2018 },
		{ 31, 12, 2018 },
		{ 10, 2, 2019 },
		{ 10, 1, 2020}
	};
	bool resultatEsperat[N_PROVES] = { true, false, true, false, false };

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio terminiValid" << endl;
	cout << "Comment :=>> =======================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data inicial: "; escriuData(dates[i]); cout << endl;
		cout << "Comment :=>> N. dies termini: " << nDiesTermini[i] << endl;
		cout << "Comment :=>> Data actual: "; escriuData(dataActual[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		bool resultat = terminiValid(dates[i], nDiesTermini[i], dataActual[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == resultatEsperat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	if (reduccio > 4.0)
		reduccio = 4.0;
	return reduccio;
}

float testRestaDates()
{
	float reduccio = 0.0;

	const int N_PROVES = 8;
	Data dates1[N_PROVES] =
	{
		{ 10, 1, 2018 },
	{ 10, 1, 2018 },
	{ 10, 1, 2018 },
	{ 10, 1, 2018 },
	{ 10, 1, 2018 },
	{ 10, 1, 2018 },
	{ 20, 12, 2018 },
	{ 10, 1, 2018 }
	};

	Data dates2[N_PROVES] =
	{
		{ 10, 1, 2018 },
	{ 11, 1, 2018 },
	{ 31, 1, 2018 },
	{ 10, 2, 2018 },
	{ 10, 3, 2018 },
	{ 10, 4, 2018 },
	{ 20, 1, 2019 },
	{ 10, 1, 2019 }
	};


	int nDiesEsperat[N_PROVES] = { 0, 1, 21, 31, 59, 90, 31, 365 };
	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio restaDates" << endl;
	cout << "Comment :=>> =====================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data 1: "; escriuData(dates1[i]); cout << endl;
		cout << "Comment :=>> Data 2: "; escriuData(dates2[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << nDiesEsperat[i] << endl;
		int resultat = restaDates(dates1[i], dates2[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		if (resultat == nDiesEsperat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	if (reduccio > 4.0)
		reduccio = 4.0;
	return reduccio;
}

int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	float reduccio = testLlegeixDia();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testEsValida();
	grade = grade + (2.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testComparaDates();
	grade = grade + (1.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testSumaDies();
	grade = grade + (2.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testRestaDates();
	grade = grade + (2.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testTerminiValid();
	grade = grade + (2.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}