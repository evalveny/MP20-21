#include "LlistatEspectacles.h"
#include <iostream>
#include <fstream>
using namespace std;

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}

float testAfegeixEspectacle(LlistatEspectacles& le)
{
	float reduccio = 0;
	const int N_PROVES = 6;
	string nomEspectacle[N_PROVES] = { "E1", "E2", "E3", "E4", "E5", "E6" };
	string nomTeatre[N_PROVES] = { "T1", "T2", "T3", "T4", "T5", "T6" };
	string data[N_PROVES] = { "01/01/2017" , "01/02/2017", "01/03/2017", "01/04/2017", "01/05/2017", "01/06/2017" };
	string hora[N_PROVES] = { "20:00" , "21:00" ,"22:00", "20:00" , "21:00" ,"22:00" };
	int nEntrades[N_PROVES] = { 10, 20, 5, 10, 20, 5 };
	float preu[N_PROVES] = { 50.0,40.0,30.0, 50.0,40.0,30.0 };
	bool resultatEsperat[N_PROVES] = { true, true, true, true, true, false };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode afegeixEspectacle" << endl;
	cout << "Comment :=>> ==========================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Afegint espectacle... " << endl;
		cout << "Comment :=>> Nom: " << nomEspectacle[i] << endl;
		cout << "Comment :=>> Teatre: " << nomTeatre[i] << endl;
		cout << "Comment :=>> Data: " << data[i] << endl;
		cout << "Comment :=>> Hora: " << hora[i] << endl;
		cout << "Comment :=>> N. entrades: " << nEntrades[i] << endl;
		cout << "Comment :=>> Preu: " << preu[i] << endl;

		Espectacle e;
		e.setNom(nomEspectacle[i]);
		e.setTeatre(nomTeatre[i]);
		e.setDia(data[i]);
		e.setHora(hora[i]);
		e.setEntradesTotals(nEntrades[i]);
		e.setPreu(preu[i]);
		bool resultatObtingut = le.afegeixEspectacle(e);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultatObtingut); cout << endl;
		if (resultatEsperat[i] == resultatObtingut)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}

float testCompraEntrades(LlistatEspectacles& le)
{
	float reduccio = 0;

	const int N_PROVES = 5;
	string espectacle[N_PROVES] = { "E4", "E2", "E2", "E3", "E1" };
	string data[N_PROVES] = { "01/01/2017" , "01/01/2017", "01/02/2017", "01/03/2017", "01/01/2017" };
	int nEntrades[N_PROVES] = { 10, 10, 10, 20, 10 };
	int resultatEsperat[N_PROVES] = { -2, -2, 0, -1, 0 };
	int preuEsperat[N_PROVES] = { -1, -1, 400, -1, 500 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode compraEntrades" << endl;
	cout << "Comment :=>> =======================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST:" << i + 1 << endl;
		cout << "Comment :=>> Comprant entrades... " << endl;
		cout << "Comment :=>> Nom: " << espectacle[i] << endl;
		cout << "Comment :=>> Data: " << data[i] << endl;
		cout << "Comment :=>> N. entrades: " << nEntrades[i] << endl;
		float preu;
		int resultat = le.compraEntrades(espectacle[i], data[i], nEntrades[i], preu);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatEsperat[i] << endl;
		if (resultatEsperat[i] == 0)
			cout << "Comment :=>> Preu esperat: " << preuEsperat[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		if (resultat == 0)
			cout << "Comment :=>> Preu obtingut: " << preu << endl;
		if (resultatEsperat[i] == resultat)
		{
			if (resultat == 0)
				if (preuEsperat[i] == preu)
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 2.0;
				}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}


int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	LlistatEspectacles l;

	float reduccio = testAfegeixEspectacle(l);
	grade = grade + (2 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testCompraEntrades(l);
	grade = grade + (8 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << "Grade :=>> " << grade << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	return 0;
}