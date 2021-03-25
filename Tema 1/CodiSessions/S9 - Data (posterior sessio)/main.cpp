#include "Data.h"
#include "operacions_data.h"
#include <iostream>
#include <fstream>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

void escriuData(Data& dia)
{
	cout << dia.getDia() << "/" << dia.getMes() << "/" << dia.getAny();
}


float testSumaDies()
{
	float reduccio = 0.0;
	const int NPROVES = 8;

	Data dataTest[NPROVES] =
	{
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 20, 12, 2018},
		{ 10, 1, 2018 }
	};

	int nDiesTest[NPROVES] = { 0, 1, 21, 31, 59, 90, 31, 365 };

	Data resultatTest[NPROVES] =
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

	cout << endl;
	cout << "Comment :=>> Iniciant test OPERADOR SUMA +" << endl;
	cout << "Comment :=>> =============================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Data: " << dataTest[p].getDia() << "/" << dataTest[p].getMes() << "/" << dataTest[p].getAny() << endl;
		cout << "Comment :=>> Numero de dies: " << nDiesTest[p] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " << resultatTest[p].getDia() << "/" << resultatTest[p].getMes() << "/" << resultatTest[p].getAny() << endl;
		cout << "Comment :=>> ---" << endl;
		Data resultat = dataTest[p] + nDiesTest[p];
		cout << "Comment :=>> Valor retorn obtingut: " << resultat.getDia() << "/" << resultat.getMes() << "/" << resultat.getAny() << endl;
		cout << "Comment :=>> Comparant dates amb la implementacio de l'operador == ..........." <<  endl;
		if (resultat == resultatTest[p])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 5.0)
		reduccio = 5.0;
	return reduccio;
}

float testComparacioDatesMenor()
{
	float reduccio = 0.0;
	const int NPROVES = 8;

	Data dataTest1[NPROVES] =
	{
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 },
		{ 10, 6, 2018 }
	};

	Data dataTest2[NPROVES] =
	{
		{ 10, 6, 2018 },
		{ 11, 6, 2018 },
		{ 9, 6, 2018 },
		{ 10, 7, 2018 },
		{ 9, 7, 2018 },
		{ 11, 5, 2018 },
		{ 1, 1, 2019 },
		{ 12, 7, 2017 },
	};


	int resultatTest[NPROVES] = { false, true, false, true, true, false, true, false};


	cout << endl;
	cout << "Comment :=>> Iniciant test OPERADOR COMPARACIO <" << endl;
	cout << "Comment :=>> ===================================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Data 1: " << dataTest1[p].getDia() << "/" << dataTest1[p].getMes() << "/" << dataTest1[p].getAny() << endl;
		cout << "Comment :=>> Data 2: " << dataTest2[p].getDia() << "/" << dataTest2[p].getMes() << "/" << dataTest2[p].getAny() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: ";  mostraBool(resultatTest[p]); cout << endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = dataTest1[p] < dataTest2[p];
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == resultatTest[p])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
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
		{ 10, 1, 2020 }
	};
	bool resultatEsperat[N_PROVES] = { true, false, true, false, false };

	ifstream fitxerTest;
	fitxerTest.open("dates_input.txt");
	streambuf* buffer_cin = cin.rdbuf(fitxerTest.rdbuf());

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio comprovaTermini" << endl;
	cout << "Comment :=>> ==========================================" << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data inicial: "; escriuData(dates[i]); cout << endl;
		cout << "Comment :=>> Data actual: "; escriuData(dataActual[i]); cout << endl;
		cout << "Comment :=>> N. dies termini: " << nDiesTermini[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		bool resultat = comprovaTermini();
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

	cin.rdbuf(buffer_cin);
	fitxerTest.close();

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

	float reduccio = testSumaDies();
	grade = grade + (4.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testComparacioDatesMenor();
	grade = grade + (3.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testTerminiValid();
	grade = grade + (3.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;


	return 0;
}