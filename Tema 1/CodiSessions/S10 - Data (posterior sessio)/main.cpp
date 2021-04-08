#include "Data.h"
#include "operacions_data.h"
#include <iostream>
#include <fstream>
#include <sstream>
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

float testOperadors()
{
	float reduccio = 0.0;

	Data data = { 10, 1, 2018 };

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de l'operador >>" << endl;
	cout << "Comment :=>> ==========================================" << endl;
	cout << "Comment :=>> Llegint del fitxer 'data_in.txt' la data: "; escriuData(data); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	ifstream fitxerIn;
	fitxerIn.open("data_in.txt");
	Data dataIn;
	fitxerIn >> dataIn;
	fitxerIn.close();
	cout << "Comment :=>> Data llegida del fitxer: "; escriuData(dataIn); cout << endl;
	if (dataIn == data)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de l'operador <<" << endl;
	cout << "Comment :=>> ============================================" << endl;
	cout << "Comment :=>> Escrivint al fitxer 'data_out.txt' la data: "; escriuData(data); cout << endl;
	ofstream fitxerOut;
	fitxerOut.open("data_out.txt");
	fitxerOut << data;
	fitxerOut.close();	
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Comprovant data al fitxer... " << endl;
	ifstream fitxer;
	fitxer.open("data_out.txt");
	string data_out;
	fitxer >> data_out;
	fitxer.close();
	cout << "Comment :=>> Resultat obtingut al fitxer: " << data_out << endl;
	if (data_out == "10/1/2018")
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	if (reduccio > 2.0)
		reduccio = 2.0;
	return reduccio;
}

float testOrdenaDates()
{
	float reduccio = 0.0;

	const int N_DATES = 5;
	Data datesInicial[N_DATES] =
	{
		{ 10, 1, 2018 },
		{ 10, 2, 2018 },
		{ 10, 3, 2017 },
		{ 10, 5, 2017 },
		{ 10, 1, 2017 }
	};
	Data datesFinal[N_DATES] =
	{
		{ 10, 1, 2017 },
		{ 10, 3, 2017 },
		{ 10, 5, 2017 },
		{ 10, 1, 2018 },
		{ 10, 2, 2018 }
	};
	string nomFitxerIn = "dates_input.txt";
	string nomFitxerOut = "dates_output.txt";


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio ordenaDates" << endl;
	cout << "Comment :=>> ==========================================" << endl;
	cout << "Comment :=>> Fitxer d'entrada: " << nomFitxerIn << endl;
	cout << "Comment :=>> Fitxer de sortida: " << nomFitxerOut << endl;
	cout << "Comment :=>> Dates al fitxer d'entrada: " << endl;
	for (int i = 0; i < N_DATES; i++)
	{
		cout << "Comment :=>> ";
		escriuData(datesInicial[i]);
		cout << endl;
	}
	cout << "Comment :=>> ----------" << endl;
	ordenaDates(nomFitxerIn, nomFitxerOut);
	cout << "Comment :=>> Dates escrites al fitxer de sortida: " << endl; 
	ifstream fitxer;
	fitxer.open(nomFitxerOut);
	bool correcte = true;
	for (int i = 0; i < N_DATES; i++)
	{
		string dataObtinguda;
		fitxer >> dataObtinguda;
		cout << "Comment :=>> " << dataObtinguda << endl;
		stringstream dataEsperada;
		dataEsperada << datesFinal[i];
		if (dataEsperada.str() != dataObtinguda)
			correcte = false;
	}
	fitxer.close();

	if (correcte)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 8.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	if (reduccio > 8.0)
		reduccio = 8.0;
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

	float reduccio = testOperadors();
	grade = grade + (2.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testOrdenaDates();
	grade = grade + (8.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;


	return 0;
}