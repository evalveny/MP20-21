#include "Punt.h"
#include "Poligon.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

float testEntradaSortidaPunt()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------------" << endl;
	cout << "Comment :=>> Test d'entrada/sortida per pantalla de la classe Punt" <<  endl;
	cout << "Comment :=>> -----------------------------------------------------" << endl;

	ifstream fitxerTestIn;
	string nomFitxerIn = "test_punt.txt";
	fitxerTestIn.open(nomFitxerIn);
	streambuf* buffer_cin = cin.rdbuf(fitxerTestIn.rdbuf());


	string resultatEsperat = "(1,1)";
	Punt pt;
	cin >> pt;
	cin.rdbuf(buffer_cin);
	fitxerTestIn.close();

	cout << endl;
	cout << "Comment :=>> Llegint el punt de l'entrada estàndard cin...." << endl;
	cout << "Comment :=>> -----" << endl;
	ofstream fitxerTestOut;
	string nomFitxerOut = "test_punt_output.txt";
	fitxerTestOut.open(nomFitxerOut);
	streambuf* buffer_cout = cout.rdbuf(fitxerTestOut.rdbuf());
	cout << pt;
	cout.rdbuf(buffer_cout);
	fitxerTestOut.close();

	cout << "Comment :=>> Escrivint el punt a la sortida estàndard cout ...." << endl;
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat esperat: " << resultatEsperat << endl;

	ifstream fitxerTestResultat;
	fitxerTestResultat.open(nomFitxerOut);
	string resultat;
	getline(fitxerTestResultat, resultat);
	fitxerTestResultat.close();
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat obtingut: " << resultat << endl;

	if (resultat == resultatEsperat)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2;
	}


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------------" << endl;
	cout << "Comment :=>> Test d'entrada/sortida per fitxer de la classe Punt" << endl;
	cout << "Comment :=>> -----------------------------------------------------" << endl;

	fitxerTestIn.open(nomFitxerIn);

	fitxerTestOut.open(nomFitxerOut);

	fitxerTestIn >> pt;
	cout << "Comment :=>> Llegint el punt del fixer 'test_punt'...." << endl;
	cout << "Comment :=>> -----" << endl;
	fitxerTestOut << pt;
	cout << "Comment :=>> Escrivint el punt al fitxer 'test_punt_output'...." << endl;
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat esperat: " << resultatEsperat << endl;
	fitxerTestIn.close();
	fitxerTestOut.close();

	fitxerTestResultat.open(nomFitxerOut);
	getline(fitxerTestResultat, resultat);
	fitxerTestResultat.close();
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat obtingut: " << resultat << endl;

	if (resultat == resultatEsperat)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2;
	}

	return reduccio;
}

float testEntradaSortidaPoligon()
{
	float reduccio = 0.0;


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> --------------------------------------------------------" << endl;
	cout << "Comment :=>> Test d'entrada/sortida per pantalla de la classe Poligon" << endl;
	cout << "Comment :=>> --------------------------------------------------------" << endl;

	ifstream fitxerTestIn;
	string nomFitxerIn = "test_poligon_cin.txt";
	fitxerTestIn.open(nomFitxerIn);
	streambuf* buffer_cin = cin.rdbuf(fitxerTestIn.rdbuf());

	const int N_LINIES_CIN = 5;
	string resultatEsperat_cin[N_LINIES_CIN] = { "4", "(0,0)", "(0,1)", "(1,1)", "(1,0)" };
	Poligon p1;
	cin >> p1;
	cin.rdbuf(buffer_cin);
	fitxerTestIn.close();

	cout << endl;
	cout << "Comment :=>> Llegint el poligon de l'entrada estàndard cin...." << endl;
	cout << "Comment :=>> -----" << endl;
	ofstream fitxerTestOut;
	string nomFitxerOut = "test_poligon_cout.txt";
	fitxerTestOut.open(nomFitxerOut);
	streambuf* buffer_cout = cout.rdbuf(fitxerTestOut.rdbuf());
	cout << p1;
	cout.rdbuf(buffer_cout);
	fitxerTestOut.close();

	cout << "Comment :=>> Escrivint el poligon a la sortida estàndard cout ...." << endl;
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat esperat: " << endl;
	for (int i = 0; i < N_LINIES_CIN; i++)
		cout << "Comment :=>> " << resultatEsperat_cin[i] << endl;

	ifstream fitxerTestResultat;
	fitxerTestResultat.open(nomFitxerOut);
	string resultat;
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	bool error = false;
	for (int i = 0; i < N_LINIES_CIN; i++)
	{
		getline(fitxerTestResultat, resultat);
		cout << "Comment :=>> " << resultat << endl;
		if (resultat != resultatEsperat_cin[i])
			error = true;
	}
	fitxerTestResultat.close();

	if (!error)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 3;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> ------------------------------------------------------" << endl;
	cout << "Comment :=>> Test d'entrada/sortida per fitxer de la classe Poligon" << endl;
	cout << "Comment :=>> ------------------------------------------------------" << endl;

	nomFitxerIn = "test_poligon.txt";
	fitxerTestIn.open(nomFitxerIn);

	const int N_LINIES = 4;
	string resultatEsperat[N_LINIES] = { "(0,0)", "(0,1)", "(1,1)", "(1,0)" };
	Poligon p2;
	fitxerTestIn >> p2;
	fitxerTestIn.close();

	cout << endl;
	cout << "Comment :=>> Llegint el poligon del fitxer 'test_poligon'...." << endl;
	cout << "Comment :=>> -----" << endl;
	nomFitxerOut = "test_poligon_output.txt";
	fitxerTestOut.open(nomFitxerOut);
	fitxerTestOut << p2;
	fitxerTestOut.close();

	cout << "Comment :=>> Escrivint el poligon al fitxer 'test_poligon_output'...." << endl;
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat esperat: " << endl;
	for (int i = 0; i < N_LINIES; i++)
		cout << "Comment :=>> " << resultatEsperat[i] << endl;
	
	cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
	fitxerTestResultat.open(nomFitxerOut);
	cout << "Comment :=>> -----" << endl;
	error = false;
	for (int i = 0; i < N_LINIES; i++)
	{
		getline(fitxerTestResultat, resultat);
		cout << "Comment :=>> " << resultat << endl;
		if (resultat != resultatEsperat[i])
			error = true;
	}
	fitxerTestResultat.close();

	if (!error)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 3;
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

	cout << "Grade :=>> " << grade << endl;

	float reduccio = testEntradaSortidaPunt();
	grade = grade + (4 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testEntradaSortidaPoligon();
	grade = grade + (6 - reduccio);

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}
