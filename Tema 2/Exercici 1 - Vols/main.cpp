#include "vol.h"
#include <iostream>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

void mostraPassatger(Passatger* p)
{
	if (p == nullptr)
		cout << "nullptr";
	else
		if (p->getDni() == "")
			cout << "nullptr";
		else
			cout << p->getDni() << ", " << p->getNom();
}


bool igualsPassatgers(Passatger* pObtingut, Passatger* pEsperat)
{
	bool iguals = false;
	if (pObtingut == nullptr)
	{
		if (pEsperat == nullptr)
			iguals = true;
		else
			if (pEsperat->getDni() == "")
				iguals = true;
	}
	else
		if (pEsperat != nullptr)
			iguals = (pObtingut->getDni() == pEsperat->getDni()) && (pObtingut->getNom() == pEsperat->getNom());
	return iguals;
}

float testSeient()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la classe Seient" << endl;
	cout << "Comment :=>> =================================" << endl;
	const int N_PROVES = 4;
	Passatger valorEsperat[N_PROVES] =
	{
		{ "dni_1", "nom_1" },
		{ "dni_1", "nom_1" },
		{ "", "" },
		{ "", "" }
	};
	bool resultatEsperat[N_PROVES] = { true, false, true, false };

	char operacio[N_PROVES] = { 'A', 'A', 'E', 'E' };
	Passatger dadesPassatger[N_PROVES] =
	{
		{ "dni_1", "nom_1" },
		{ "dni_2", "nom_2" },
		{ "", "" },
		{ "", "" }
	};

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant un seient amb codi 1A" << endl;
	Seient s("1A");

	cout << "Comment :=>> ---" << endl;
	cout << "Comment :=>> Valor esperat del passatger despres d'inicialitzar: ";
	mostraPassatger(nullptr);
	cout << endl;
	cout << "Comment :=>> ---" << endl;
	cout << "Comment :=>> Valor obtingut del passatger despres d'inicialitzar: ";
	Passatger* p = s.getPassatger();
	mostraPassatger(p);
	cout << endl; 
	if (!igualsPassatgers(p, nullptr))
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;


	for (int i = 0; i < N_PROVES; i++)
	{
		bool resultat;
		Passatger* p;
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		if (operacio[i] == 'A')
		{
			cout << "Comment :=>> Afegint passatger al seient..." << endl;
			cout << "Comment :=>> Dades del passatger: "; mostraPassatger(&dadesPassatger[i]); cout << endl;
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
			cout << "Comment :=>> Passatger esperat: "; mostraPassatger(&valorEsperat[i]); cout << endl;
			cout << "Comment :=>> ---" << endl;
			resultat = s.assignaPassatger(dadesPassatger[i].getDni(), dadesPassatger[i].getNom());
			p = s.getPassatger();
			cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
			cout << "Comment :=>> Passatger obtingut: "; mostraPassatger(p); cout << endl;
		}
		else
		{
			cout << "Comment :=>> Eliminant el passatger del seient..." << endl;
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
			cout << "Comment :=>> Passatger esperat: "; mostraPassatger(&valorEsperat[i]); cout << endl;
			cout << "Comment :=>> ---" << endl;
			resultat = s.eliminaPassatger();
			p = s.getPassatger();
			cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
			cout << "Comment :=>> Passatger obtingut: "; mostraPassatger(p); cout << endl;
		}

		if ((resultat == resultatEsperat[i]) && igualsPassatgers(p, &valorEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 2.0)
		reduccio = 2.0;
	return reduccio;
}


float testVol()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la classe Vol" << endl;
	cout << "Comment :=>> ==============================" << endl;

	const int N_SEIENTS = 6;
	string codisSeients[N_SEIENTS] = { "1A", "1B", "1C", "2A", "2B", "2C" };


	const int N_PROVES = 12;
	char operacio[N_PROVES] = { 'A', 'A', 'A', 'A', 'A', 'C', 'C', 'C', 'M', 'M', 'M', 'M' };
	Passatger dadesPassatger[N_PROVES] =
	{
		{ "dni_1", "nom_1" },
		{ "dni_2", "nom_2" },
		{ "dni_3", "nom_3" },
		{ "dni_4", "nom_4" },
		{ "dni_4", "nom_4" },
		{ "", "" },
		{ "", "" },
		{ "", "" },
		{ "", "" },
		{ "", "" },
		{ "", "" },
		{ "", "" }
	};
	string codiSeient[N_PROVES] = { "1A", "2C", "2A", "1A", "3A", "1A", "1B", "3C", "2C", "2A", "2B", "4A" };

	Passatger valorEsperat[N_PROVES] =
	{
		{ "dni_1", "nom_1" },
		{ "dni_2", "nom_2" },
		{ "dni_3", "nom_3" },
		{ "dni_1", "nom_1" },
		{ "", "" },
		{ "", "" },
		{ "", "" },
		{ "", "" },
		{ "", "" },
		{ "dni_3", "nom_3" },
		{ "", "" },
		{ "", "" }
	};
	bool resultatEsperat[N_PROVES] = { true, true, true, false, false, true, false, false, true, false, false, false };

	const int N_MODIFICACIONS = 4;
	string codiSeient2[N_MODIFICACIONS] = { "1B", "1B", "1B", "4B" };
	Passatger valorEsperat2[N_MODIFICACIONS] =
	{
		{ "dni_2", "nom_2" },
		{ "dni_2", "nom_2" },
		{ "dni_2", "nom_2" },
		{ "", "" }
	};

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant els seients del vol (codis 1A, 1B, 1C, 2A, 2B, 2C)" << endl;
	cout << "Comment :=>>" << endl;
	Vol v;
	v.afegeixSeients(codisSeients, N_SEIENTS);

	int nModificacio = 0;
	for (int i = 0; i < N_PROVES; i++)
	{
		bool resultat;
		Passatger* p;
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		if (operacio[i] == 'A')
		{
			cout << "Comment :=>> Afegint passatger a seient..." << endl;
			cout << "Comment :=>> Codi del seient: " << codiSeient[i] << endl;
			cout << "Comment :=>> Dades del passatger: "; mostraPassatger(&dadesPassatger[i]); cout << endl;
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
			cout << "Comment :=>> Passatger esperat al seient: "; mostraPassatger(&valorEsperat[i]); cout << endl;
			cout << "Comment :=>> ---" << endl;
			resultat = v.afegeixPassatger(codiSeient[i], dadesPassatger[i].getDni(), dadesPassatger[i].getNom());
			p = v.recuperaPassatger(codiSeient[i]);
			cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
			cout << "Comment :=>> Passatger obtingut al seient: "; mostraPassatger(p); cout << endl;
			if ((resultat == resultatEsperat[i]) && igualsPassatgers(p, &valorEsperat[i]))
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}
		else
		{
			if (operacio[i] == 'C')
			{
				cout << "Comment :=>> Eliminant passatger de seient..." << endl;
				cout << "Comment :=>> Codi del seient: " << codiSeient[i] << endl;
				cout << "Comment :=>> ---" << endl;
				cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
				cout << "Comment :=>> Passatger esperat al seient: "; mostraPassatger(&valorEsperat[i]); cout << endl;
				cout << "Comment :=>> ---" << endl;
				resultat = v.cancelaReserva(codiSeient[i]);
				p = v.recuperaPassatger(codiSeient[i]);
				cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
				cout << "Comment :=>> Passatger obtingut al seient: "; mostraPassatger(p); cout << endl;
				if ((resultat == resultatEsperat[i]) && igualsPassatgers(p, &valorEsperat[i]))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			}
			else
			{
				cout << "Comment :=>> Modificant assignacio de seient..." << endl;
				cout << "Comment :=>> Codi del seient original: " << codiSeient[i] << endl;
				cout << "Comment :=>> Codi del seient nou: " << codiSeient2[nModificacio] << endl;
				cout << "Comment :=>> ---" << endl;
				cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
				cout << "Comment :=>> Passatger esperat al seient original: "; mostraPassatger(&valorEsperat[i]); cout << endl;
				cout << "Comment :=>> Passatger esperat al seient nou: "; mostraPassatger(&valorEsperat2[nModificacio]); cout << endl;
				cout << "Comment :=>> ---" << endl;
				resultat = v.modificaReserva(codiSeient[i], codiSeient2[nModificacio]);
				p = v.recuperaPassatger(codiSeient[i]);
				Passatger* p2 = v.recuperaPassatger(codiSeient2[nModificacio]);
				cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
				cout << "Comment :=>> Passatger obtingut al seient original: "; mostraPassatger(p); cout << endl;
				cout << "Comment :=>> Passatger obtingut al seient nou: "; mostraPassatger(p2); cout << endl;
				if ((resultat == resultatEsperat[i]) && igualsPassatgers(p, &valorEsperat[i]) && igualsPassatgers(p2, &valorEsperat2[nModificacio]))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
				nModificacio++;
			}
		}
	}
	if (reduccio > 10.0)
		reduccio = 10.0;
	return reduccio;
}







int main()
{
	float grade = 0.0;
	float reduccio;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Grade :=>> " << grade << endl;
	reduccio = testSeient();
	grade = grade + (2 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testVol();
	grade = grade + (8 - reduccio);

	if (grade < 0)
		grade = 0.0;
	cout << "Grade :=>> " << grade << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	return 0;
}