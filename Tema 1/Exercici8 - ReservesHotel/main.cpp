#include "ReservesHotel.h"
#include <iostream>
#include <math.h>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

float testNReservesDia(ReservesHotel& reserves)
{
	float reduccio = 0.0;
	const int NPROVES = 7;

	Data dataTest[NPROVES] =
	{
		{ 1, 1, 2018 },
		{ 2, 1, 2018 },
		{ 3, 1, 2018 },
		{ 4, 1, 2018 },
		{ 5, 1, 2018 },
		{ 6, 1, 2018 },
		{ 31, 12, 2017 },
	};

	int nHabitacionsTest[NPROVES] = { 2, 3, 8, 8, 2, 0, 0 };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode NRESERVESDIA" << endl;
	cout << "Comment :=>> =================================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Data: " << dataTest[p].getDia() << "/" << dataTest[p].getMes() << "/" << dataTest[p].getAny() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " << nHabitacionsTest[p] << endl;
		cout << "Comment :=>> ---" << endl;
		int nHabitacions = reserves.nReservesDia(dataTest[p]);
		cout << "Comment :=>> Valor retorn obtingut: " << nHabitacions << endl;
		if (nHabitacions == nHabitacionsTest[p])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


float testAfegeixReserva(ReservesHotel& reserves)
{
	float reduccio = 0.0;
	const int NPROVES = 5;

	string nomTest[NPROVES] = { "client_a", "client_b", "client_c", "client_d", "client_e" };
	Data dataTest[NPROVES] =
	{
		{ 1, 1, 2018 },
		{ 2, 1, 2018 },
		{ 3, 1, 2018 },
		{ 4, 1, 2018 },
		{ 5, 1, 2018 },
	};
	int nDiesTest[NPROVES] = { 2, 3, 2, 4, 2 };
	int nHabitacionsTest[NPROVES] = { 2, 3, 1, 3, 2 };
	bool validTest[NPROVES] = { true, false, true, false, true };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode AFEGEIXRESERVA" << endl;
	cout << "Comment :=>> ===================================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Nom Client: " << nomTest[p] << endl;
		cout << "Comment :=>> Data Entrada: " << dataTest[p].getDia() << "/" << dataTest[p].getMes() << "/" << dataTest[p].getAny() << endl;
		cout << "Comment :=>> Num. dies: " << nDiesTest[p] << endl;
		cout << "Comment :=>> Num. habitacions: " << nHabitacionsTest[p] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(validTest[p]); cout << endl;
		cout << "Comment :=>> ---" << endl;
		bool valid = reserves.afegeixReserva(nomTest[p], dataTest[p], nDiesTest[p], nHabitacionsTest[p]);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(valid); cout << endl;
		if (valid == validTest[p])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testConsultaReserva(ReservesHotel& reserves)
{
	float reduccio = 0.0;
	const int NPROVES = 7;

	string nomTest[NPROVES] = { "CLIENT_2", "client_a", "CLIENT_7", "client_b", "CLIENT_8", "CLIENT_9", "CLIENT_2"};
	Data dataEntradaTest[NPROVES] =
	{
		{ 2, 1, 2018 },
		{ 1, 1, 2018 },
		{ 1, 12, 2018 },
		{ 2, 1, 2018 },
		{ 1, 6, 2018 },
		{ 1, 6, 2018 },
		{ 1, 6, 2018 },
	};
	Data dataSortidaTest[NPROVES] = 
	{
		{ 3, 1, 2018 },
		{ 3, 1, 2018 },
		{ 3, 12, 2018 },
		{ 1, 1, 2018 },
		{ 1, 1, 2018 },
		{ 1, 1, 2018 },
		{ 1, 1, 2018 }
	};
	int nHabitacionsTest[NPROVES] = { 1, 2, 6, 0, 0, 0, 0 };
	float preuTest[NPROVES] = {100.0, 400.0, 1200.0, 0, 0, 0, 0};
	bool validTest[NPROVES] = { true, true, true, false, false, false, false };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode CONSULTARESERVA" << endl;
	cout << "Comment :=>> (Assumeix funcionament correcte de llegir reserves i afegir reserves)" << endl;
	cout << "Comment :=>> =====================================================================" << endl;

	for (int p = 0; p < NPROVES; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << p + 1 << endl;
		cout << "Comment :=>> Nom Client: " << nomTest[p] << endl;
		cout << "Comment :=>> Data Entrada: " << dataEntradaTest[p].getDia() << "/" << dataEntradaTest[p].getMes() << "/" << dataEntradaTest[p].getAny() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(validTest[p]); cout << endl;
		if (validTest[p])
		{
			cout << "Comment :=>> Data sortida esperada: " << dataSortidaTest[p].getDia() << "/" << dataSortidaTest[p].getMes() << "/" << dataSortidaTest[p].getAny() << endl;
			cout << "Comment :=>> Num. habitacions esperat: " << nHabitacionsTest[p] << endl;
			cout << "Comment :=>> Preu esperat: " << preuTest[p] << endl;
		}
		cout << "Comment :=>> ---" << endl;
		Data dataSortida;
		int nHabitacions;
		float preu;
		bool valid = reserves.consultaReserva(nomTest[p], dataEntradaTest[p], dataSortida, nHabitacions, preu);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(valid); cout << endl;
		if (valid)
		{
			cout << "Comment :=>> Data sortida obtingutda: " << dataSortida.getDia() << "/" << dataSortida.getMes() << "/" << dataSortida.getAny() << endl;
			cout << "Comment :=>> Num. habitacions obtingut: " << nHabitacions << endl;
			cout << "Comment :=>> Preu obtingut: " << preu << endl;
		}
		if (valid == validTest[p])
		{
			if (valid)
				if ((dataSortida == dataSortidaTest[p]) && (nHabitacions == nHabitacionsTest[p]) &&
					(fabs(preu - preuTest[p]) < 0.1))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
		}
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

int main()
{
	float grade = 10.0;

	ReservesHotel reserves("hotel_1", 100.0, 10);

	cout << endl;
	cout << "Comment :=>> Cridant al constructor de ReservesHotel per inicialitzar dades de l'hotel....." << endl;
	cout << "Comment :=>> ==============================================================================" << endl;
	cout << "Comment :=>> Nom de l'hotel: hotel_1" << endl;
	cout << "Comment :=>> Preu per dia: 100.0" << endl;
	cout << "Comment :=>> Num. habitacions: 10" << endl;

	cout << "Comment :=>> Llegint reserves del fitxer 'reserves1.txt'....." << endl;
	cout << "Comment :=>> ================================================" << endl;

	reserves.llegeixReserves("reserves1.txt");

	grade -= testNReservesDia(reserves);
	cout << "Grade :=>> " << grade << endl; 
	grade -= testAfegeixReserva(reserves);
	cout << "Grade :=>> " << grade << endl;

	cout << "Comment :=>> Llegint reserves del fitxer 'reserves2.txt'....." << endl;
	cout << "Comment :=>> ================================================" << endl;

	reserves.llegeixReserves("reserves2.txt");

	grade -= testConsultaReserva(reserves);

	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}