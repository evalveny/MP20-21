#include "SistemaTelefons.h"

#include <iostream>
using namespace std;


float testSistemaTelfs()
{
	float punts = 0;
	const int MAXTELFS = 10;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------" << endl;
	cout << "Comment :=>> Iniciant test Sistema Telefons" << endl;
	cout << "Comment :=>> ------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	string telefons[MAXTELFS] = { "000000000","111111111","222222222","333333333","444444444","555555555","666666666","777777777","888888888","999999999" };
	SistemaTelefons sT;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>> Test Sistema Telefons: Afegint Telefons:" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < MAXTELFS; i++)
	{
		cout << "Comment :=>> Afegint num. tlf: " << telefons[i] << endl;
		sT.introduirTelefon(telefons[i]);
	}

	int numTelfs= sT.getNumTelefons();
	cout << "Comment :=>> Num total telefons al sistema despres d'afegir: " <<numTelfs <<endl;

	if (numTelfs==MAXTELFS)
	{
		cout << "Comment :=>> OK Num Telefons" << endl;
		punts += 0.5;
	}
	else
	{
		cout << "Comment :=>> ERROR Num Telefons, esperavem tenir: " <<MAXTELFS << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>> Test Sistema Telefons: Afegint Telefons:" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < MAXTELFS; i++)
	{
		cout << "Comment :=>> Afegint num. tlf: " << telefons[i] << endl;
		sT.introduirTelefon(telefons[i]);
	}

	numTelfs = sT.getNumTelefons();
	cout << "Comment :=>> Num total telefons al sistema despres d'afegir: " << numTelfs << endl;
	if (numTelfs == MAXTELFS*2)
	{
		cout << "Comment :=>> OK Num Telefons" << endl;
		punts += 0.5;
	}
	else
	{
		cout << "Comment :=>> ERROR Num Telefons, esperavem tenir: " << MAXTELFS*2 << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>> Test Sistema Telefons: Servint Telefons:" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < (MAXTELFS/2); i++)
	{
		string tf=sT.servirTelefon();
		cout << "Comment :=>> NumTelefon servit a pos: "<< i <<" Es: " << tf << endl;

		if (tf == telefons[i])
		{
			cout << "Comment :=>> OK Telefon Servit" << endl;
			punts += 0.5;
		}
		else
		{
			cout << "Comment :=>> ERROR Telefon esperat: " << telefons[i] << endl;
		}
	}

	numTelfs = sT.getNumTelefons();
	cout << "Comment :=>> Num Telefons al sistema: " << numTelfs << endl;
	if (numTelfs == (MAXTELFS * 2)-(MAXTELFS/2))
	{
		cout << "Comment :=>> OK Num Telefons" << endl;
		punts += 0.5;
	}
	else
	{
		cout << "Comment :=>> ERROR Num Telefons, esperavem tenir: " << (MAXTELFS * 2) - (MAXTELFS / 2) << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>> Test Sistema Telefons: Afegint Telefons:" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < MAXTELFS; i++)
	{
		cout << "Comment :=>> Afegint num. tlf: " << telefons[i] << endl;
		sT.introduirTelefon(telefons[i]);
	}

	numTelfs = sT.getNumTelefons();
	cout << "Comment :=>> Num Telefons totals al sistema: " << numTelfs << endl;
	if (numTelfs == (MAXTELFS * 3) - (MAXTELFS / 2))
	{
		cout << "Comment :=>> OK Num Telefons" << endl;
		punts += 0.5;
	}
	else
	{
		cout << "Comment :=>> ERROR Num Telefons, esperavem tenir: " << (MAXTELFS * 3) - (MAXTELFS / 2) << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>> Test Sistema Telefons: Servint Telefons:" << endl;
	cout << "Comment :=>> -------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < MAXTELFS; i++)
	{
		string tf = sT.servirTelefon();
		cout << "Comment :=>> NumTelefon servit a pos: " << i << " Es: " << tf << endl;

		if (tf == telefons[(i+(MAXTELFS/2))%MAXTELFS])
		{
			cout << "Comment :=>> OK Telefon Servit" << endl;
			punts += 0.5;
		}
		else
		{
			cout << "Comment :=>> ERROR Telefon esperat: " << telefons[(i + (MAXTELFS / 2)) % MAXTELFS] << endl;
		}
	}

	numTelfs = sT.getNumTelefons();
	cout << "Comment :=>> Num Telefons total al sistema: " << numTelfs << endl;
	if (numTelfs == (MAXTELFS * 2) - (MAXTELFS / 2))
	{
		cout << "Comment :=>> OK Num Telefons" << endl;
		punts += 0.25;
	}
	else
	{
		cout << "Comment :=>> ERROR Num Telefons, esperavem tenir: " << (MAXTELFS * 2) - (MAXTELFS / 2) << endl;
	}


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------------------------------------------------" << endl;
	cout << "Comment :=>> Test Sistema Telefons: Eliminant tots els telefons del sistema:" << endl;
	cout << "Comment :=>> --------------------------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	sT.eliminarTot();
	numTelfs = sT.getNumTelefons();
	cout << "Comment :=>> Num Telefons total del sistema: " << numTelfs << endl;
	if (numTelfs == 0)
	{
		cout << "Comment :=>> OK Num Telefons" << endl;
		punts += 0.25;
	}
	else
	{
		cout << "Comment :=>> ERROR Num Telefons, esperavem tenir: " << 0 << endl;
	}
	return punts;
}

int main()
{
	float grade = 0;

	grade += testSistemaTelfs();

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;

}