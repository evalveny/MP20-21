#include "Operacions.h"

#include <iostream>
using namespace std;


float testSuma()
{
	float reduccio = 0.0;
	const int N_PROVES = 6;

	int numerador[N_PROVES] =	{1, 4, 3, 0, 1, 0};
	int denominador[N_PROVES] = { 2, 12, 2, 2, 0, 0 };
	
	NombreRacional operand(3, 10);

	NombreRacional resultatEsperat[N_PROVES] = 
	{
		{4, 5}, {19, 30}, {9, 5}, {3, 10}, {0, 0}, {0, 0}
	};


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio operar (operacio suma)" << endl;
	cout << "Comment :=>> =================================================" << endl;
	NombreRacional racionals[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		racionals[i].setNumerador(numerador[i]);
		racionals[i].setDenominador(denominador[i]);
	}
	NombreRacional resultat[N_PROVES];
	operar(racionals, N_PROVES, '+', operand, resultat);
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> Posicio de l'array " << i << endl;
		cout << "Comment :=>> Nombre Racional de l'array: " << numerador[i] << "/" << denominador[i] << endl;
		cout << "Comment :=>> Nombre Racional a sumar: " << operand.getNumerador() << "/" << operand.getDenominador() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatEsperat[i].getNumerador() << "/" << resultatEsperat[i].getDenominador() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat[i].getNumerador() << "/" << resultat[i].getDenominador() << endl;
		if ((resultat[i].getNumerador() == resultatEsperat[i].getNumerador()) &&
			(resultat[i].getDenominador() == resultatEsperat[i].getDenominador()))
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


float testResta()
{
	float reduccio = 0.0;
	const int N_PROVES = 6;

	int numerador[N_PROVES] = { 1, 4, 3, 0, 1, 0 };
	int denominador[N_PROVES] = { 2, 12, 2, 2, 0, 0 };

	NombreRacional operand(3, 10);

	NombreRacional resultatEsperat[N_PROVES] =
	{
		{1, 5}, {1, 30}, {6, 5}, {-3, 10}, {0, 0}, {0, 0}
	};


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio operar (operacio resta)" << endl;
	cout << "Comment :=>> ==================================================" << endl;
	NombreRacional racionals[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		racionals[i].setNumerador(numerador[i]);
		racionals[i].setDenominador(denominador[i]);
	}
	NombreRacional resultat[N_PROVES];
	operar(racionals, N_PROVES, '-', operand, resultat);
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> Posicio de l'array " << i << endl;
		cout << "Comment :=>> Nombre Racional de l'array: " << numerador[i] << "/" << denominador[i] << endl;
		cout << "Comment :=>> Nombre Racional a restar: " << operand.getNumerador() << "/" << operand.getDenominador() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatEsperat[i].getNumerador() << "/" << resultatEsperat[i].getDenominador() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat[i].getNumerador() << "/" << resultat[i].getDenominador() << endl;
		if ((resultat[i].getNumerador() == resultatEsperat[i].getNumerador()) &&
			(resultat[i].getDenominador() == resultatEsperat[i].getDenominador()))
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


float testMultiplica()
{
	float reduccio = 0.0;
	const int N_PROVES = 6;

	int numerador[N_PROVES] = { 1, 4, 3, 0, 1, 0 };
	int denominador[N_PROVES] = { 2, 12, 2, 2, 0, 0 };

	NombreRacional operand(3, 10);

	NombreRacional resultatEsperat[N_PROVES] =
	{
		{3, 20}, {1, 10}, {9, 20}, {0, 1}, {0, 0}, {0, 0}
	};


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio operar (operacio multiplica)" << endl;
	cout << "Comment :=>> =======================================================" << endl;
	NombreRacional racionals[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		racionals[i].setNumerador(numerador[i]);
		racionals[i].setDenominador(denominador[i]);
	}
	NombreRacional resultat[N_PROVES];
	operar(racionals, N_PROVES, '*', operand, resultat);
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> Posicio de l'array " << i << endl;
		cout << "Comment :=>> Nombre Racional de l'array: " << numerador[i] << "/" << denominador[i] << endl;
		cout << "Comment :=>> Nombre Racional a multiplicar: " << operand.getNumerador() << "/" << operand.getDenominador() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatEsperat[i].getNumerador() << "/" << resultatEsperat[i].getDenominador() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat[i].getNumerador() << "/" << resultat[i].getDenominador() << endl;
		if ((resultat[i].getNumerador() == resultatEsperat[i].getNumerador()) &&
			(resultat[i].getDenominador() == resultatEsperat[i].getDenominador()))
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


float testDivideix()
{
	float reduccio = 0.0;
	const int N_PROVES = 6;

	int numerador[N_PROVES] = { 1, 4, 3, 0, 1, 0 };
	int denominador[N_PROVES] = { 2, 12, 2, 2, 0, 0 };

	NombreRacional operand(3, 10);

	NombreRacional resultatEsperat[N_PROVES] =
	{
		{5, 3}, {10, 9}, {5, 1}, {0, 1}, {0, 0}, {0, 0}
	};


	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio operar (operacio divideix)" << endl;
	cout << "Comment :=>> =====================================================" << endl;
	NombreRacional racionals[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		racionals[i].setNumerador(numerador[i]);
		racionals[i].setDenominador(denominador[i]);
	}
	NombreRacional resultat[N_PROVES];
	operar(racionals, N_PROVES, '/', operand, resultat);
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> Posicio de l'array " << i << endl;
		cout << "Comment :=>> Nombre Racional de l'array: " << numerador[i] << "/" << denominador[i] << endl;
		cout << "Comment :=>> Nombre Racional a dividir: " << operand.getNumerador() << "/" << operand.getDenominador() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatEsperat[i].getNumerador() << "/" << resultatEsperat[i].getDenominador() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat[i].getNumerador() << "/" << resultat[i].getDenominador() << endl;
		if ((resultat[i].getNumerador() == resultatEsperat[i].getNumerador()) &&
			(resultat[i].getDenominador() == resultatEsperat[i].getDenominador()))
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

	float reduccio = testSuma();
	grade = grade + (2.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testResta();
	grade = grade + (2.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testMultiplica();
	grade = grade + (2.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testDivideix();
	grade = grade + (2.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}

