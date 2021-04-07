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

float testTerminiValid()
{
	float reduccio = 0.0;

	Data dataInicial = { 10, 1, 2018 };
	int nDiesTermini = 90;
	Data dataActual = { 10, 4, 2018 };
	bool resultatEsperat = true;
	Data dataFinal = { 10, 4, 2018 };


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio comprovaTermini" << endl;
	cout << "Comment :=>> Llegint del fitxer 'dates_input.txt'" << endl;
	cout << "Comment :=>> Escrivint al fitxer 'dates_output.txt'" << endl;
	cout << "Comment :=>> ==========================================" << endl;
	cout << "Comment :=>> Data inicial al fitxer: "; escriuData(dataInicial); cout << endl;
	cout << "Comment :=>> Data actual al fitxer: "; escriuData(dataActual); cout << endl;
	cout << "Comment :=>> N. dies termini al fitxer: " << nDiesTermini << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat); cout << endl;
	bool resultat = comprovaTermini("dates_input.txt", "dates_output.txt");
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
	if (resultat == resultatEsperat)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 6.0;
	}
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Comprovant sortida al fitxer 'dates_output.txt'" << endl;
	ifstream fitxer;
	fitxer.open("dates_output.txt");
	int dia, mes, any;
	fitxer >> dia >> mes >> any;
	Data dataObtinguda(dia, mes, any);
	fitxer.close();
	cout << "Comment :=>> Resultat esperat al fitxer: "; escriuData(dataFinal); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Resultat obtingut al fitxer: "; escriuData(dataObtinguda); cout << endl;
	if ((dia == dataFinal.getDia()) && (mes == dataFinal.getMes()) && (any == dataFinal.getAny()))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
			reduccio += 6.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	if (reduccio > 10.0)
		reduccio = 10.0;
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

	float reduccio = testTerminiValid();
	grade = grade + (10.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;


	return 0;
}