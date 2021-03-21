#include "Llibre.h"
#include "funcionsLlibre.h"
#include <iostream>
#include <string>
using namespace std;

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}


float  testFuncionsLlibre()
{
	float reduccio = 0.0;
	const int MAX_LLIBRES = 4;
	string titol[MAX_LLIBRES] = {
		"Data Structures and Data Analysis in C++",
		"Thinking in C++",
		"Programacion en C++ para ingenieros",
		"The C++ Programming Language"
	};
	string autor[MAX_LLIBRES] = { "Weiss", "Eckel", "Xhafa", "Stroustrup" };
	int nExemplars[MAX_LLIBRES] = { 3, 4, 2, 1 };

	Llibre llibres[MAX_LLIBRES];

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de les funcions prestaLlibre i retornaLlibre" << endl;
	cout << "Comment :=>> ==========================================================" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant l'array de llibres pel test" << endl;
	for (int i = 0; i < MAX_LLIBRES; i++)
	{
		cout << "Comment :=>> llibre " << i+1 << ": " << titol[i] << ", " << autor[i] << ", " << nExemplars[i] << endl;
		Llibre l(titol[i], autor[i], nExemplars[i]);
		llibres[i] = l;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de les funcio prestaLlibre" << endl;
	cout << "Comment :=>> ========================================" << endl;

	const int N_PROVES_PRESTAR = 5;
	int resultatPrestar[N_PROVES_PRESTAR] = { -2, 0, -1, 0, 0};
	string titolPrestar[N_PROVES_PRESTAR] = {
		"Introduction to Databases",
		"The C++ Programming Language",
		"The C++ Programming Language",
		"Thinking in C++",
		"Thinking in C++"
	};
	for (int i = 0; i < N_PROVES_PRESTAR; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Realitzant prestec de llibre : " << titolPrestar[i] << endl;
		int codiExemplar;
		int resultat = prestaLlibre(llibres, MAX_LLIBRES, titolPrestar[i], codiExemplar);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatPrestar[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		if (resultat == resultatPrestar[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR";
			reduccio += 2;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de les funcio prestaLlibre (despres dels prestecs anteriors)" << endl;
	cout << "Comment :=>> ==========================================================================" << endl;

	const int N_PROVES_RETORNAR = 5;
	int resultatRetornar[N_PROVES_RETORNAR] = { -2, 0, -1, -1, 0 };
	int codiExemplarRetornar[N_PROVES_RETORNAR] = { 0, 0, 0, 3, 1 };
	string titolRetornar[N_PROVES_RETORNAR] = {
		"Introduction to Databases",
		"The C++ Programming Language",
		"Data Structures and Data Analysis in C++",
		"Thinking in C++",
		"Thinking in C++"
	};
	for (int i = 0; i < N_PROVES_RETORNAR; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Realitzant retorn de llibre : " << titolRetornar[i] << ", exemplar: " << codiExemplarRetornar[i] <<  endl;
		int resultat = retornaLlibre(llibres, MAX_LLIBRES, titolPrestar[i], codiExemplarRetornar[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatRetornar[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		if (resultat == resultatRetornar[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 10)
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

	float reduccio = testFuncionsLlibre();
	grade = grade + (10 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}