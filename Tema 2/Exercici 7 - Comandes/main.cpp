#include "Empresa.h"
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

float testDadesComanda(Empresa& e)
{
	float reduccio = 0.0;
	const int NPROVES_COMANDA = 5;
	const int NPROVES_PRODUCTE = 3;

	string nomClientTest[NPROVES_COMANDA] = { "NOM_CLIENT_1", "NOM_CLIENT_1", "NOM_CLIENT_2", "NOM_CLIENT_3", "NOM_CLIENT_4" };
	string dataTest[NPROVES_COMANDA] = 
	{
		"01/01/2018",
		"01/02/2018",
		"01/02/2018",
		"01/03/2018",
		"01/01/2018" 
	};
	float importTest[NPROVES_COMANDA] = { 5000, 0.0, 1400, 0.0, 0.0 };
	int nProvesProducteTest[NPROVES_COMANDA] = { 3, 1, 3, 0, 0 };
	string codiProducteTest[NPROVES_COMANDA][NPROVES_PRODUCTE] = 
	{
		{ "CODI_PROD_1", "CODI_PROD_2", "CODI_PROD_3" },
		{ "CODI_PROD_1" },
		{ "CODI_PROD_1", "CODI_PROD_2", "CODI_PROD_4" },
		{},
		{}
	};
	int nUnitatsTest[NPROVES_COMANDA][NPROVES_PRODUCTE] =
	{
		{10, 20, 0},
		{10},
		{1, 2, 0},
		{},
		{}
	};
	float preuTest[NPROVES_COMANDA][NPROVES_PRODUCTE] =
	{
		{ 100, 200, 0 },
		{ 100 },
		{ 100, 200, 0 },
		{},
		{}
	};
	bool validTestComanda[NPROVES_COMANDA] = { true, false, true, false, false };
	bool validTestProducte[NPROVES_COMANDA][NPROVES_PRODUCTE] =
	{
		{true, true, false},
		{false},
		{ true, true, false },
		{},
		{}
	};

	
	cout << endl;
	cout << "Comment :=>> Iniciant test metodes CONSULTA_COMANDA" << endl;
	cout << "Comment :=>> (Assumeix funcionament correcte de llegir productes i afegir comanda)" << endl;
	cout << "Comment :=>> =====================================================================" << endl;

	for (int p = 0; p < NPROVES_COMANDA; p++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST IMPORT COMANDA " << p + 1 << endl;
		cout << "Comment :=>> Nom Client: " << nomClientTest[p] << endl;
		cout << "Comment :=>> DataComanda: " << dataTest[p] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(validTestComanda[p]); cout << endl;
		if (validTestComanda[p])
			cout << "Comment :=>> Import esperat: " << importTest[p] << endl;
		cout << "Comment :=>> ---" << endl;
		float import;
		bool valid = e.importComanda(nomClientTest[p], dataTest[p], import);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(valid); cout << endl;
		if (valid)
			cout << "Comment :=>> Import obtingut: " << import << endl;
		if (valid == validTestComanda[p])
		{
			if (valid)
				if (fabs(import- importTest[p]) < 0.1)
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		for (int i = 0; i < nProvesProducteTest[p]; i++)
		{
			cout << "Comment :=>> ------------------------------------------" << endl;
			cout << "Comment :=>> TEST DETALL PRODUCTE COMANDA " << i + 1 << endl;
			cout << "Comment :=>> Codi Producte: " << codiProducteTest[p][i] << endl;
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valor retorn esperat: "; mostraBool(validTestProducte[p][i]); cout << endl;
			if (validTestProducte[p][i])
			{
				cout << "Comment :=>> Num. unitats esperat: " << nUnitatsTest[p][i] << endl;
				cout << "Comment :=>> Preu esperat: " << preuTest[p][i] << endl;
			}
			cout << "Comment :=>> ---" << endl;
			float preu;
			int nUnitats;
			bool valid = e.DetallProducteComanda(nomClientTest[p], dataTest[p], codiProducteTest[p][i], nUnitats, preu);
			cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(valid); cout << endl;
			if (valid)
			{
				cout << "Comment :=>> Num. unitats obtingut: " << nUnitats << endl;
				cout << "Comment :=>> Preu obtingut: " << preu << endl;
			}
			if (valid == validTestProducte[p][i])
			{
				if (valid)
					if ((nUnitats == nUnitatsTest[p][i]) && (fabs(preu - preuTest[p][i]) < 0.1))
					cout << "Comment :=>> CORRECTE" << endl;
					else
					{
						cout << "Comment :=>> ERROR" << endl;
						reduccio += 1.0;
					}
				else
					cout << "Comment :=>> CORRECTE" << endl;
			}
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}

		}
	}
	return reduccio;
}




int main()
{
	float grade = 0.0;
	float reduccio;


	Empresa e;

	cout << endl;
	cout << "Comment :=>> Iniciant test " << endl;
	cout << "Comment :=>> ==============" << endl;

	cout << endl << "Grade :=>> " << grade << endl << endl;

	cout << endl;
	cout << "Comment :=>> Llegint fitxer 'productes.txt' per inicialitzar dades dels productes..........." << endl;
	cout << "Comment :=>> ===============================================================================" << endl;
	e.llegeixProductes("productes.txt");

	cout << endl;
	cout << "Comment :=>> Afegint comanda del fitxer 'comanda_1.txt..................................." << endl;
	cout << "Comment :=>> ============================================================================" << endl;
	e.afegeixComanda("comanda_1.txt");

	cout << endl;
	cout << "Comment :=>> Afegint comanda del fitxer 'comanda_2.txt..................................." << endl;
	cout << "Comment :=>> ============================================================================" << endl;
	e.afegeixComanda("comanda_2.txt");

	cout << endl;
	cout << "Comment :=>> Afegint comanda del fitxer 'comanda_3.txt..................................." << endl;
	cout << "Comment :=>> ============================================================================" << endl;
	e.afegeixComanda("comanda_3.txt");

	reduccio = testDadesComanda(e);

	grade += (10.0 - reduccio);

	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}