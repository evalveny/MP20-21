// Ex20.cpp: define el punto de entrada de la aplicación de consola.
//

#include <iostream>
#include "MatSimetrica.h"

using namespace std;

void mostraMatriu(int m[N][N])
{
	for (int i = 0; i < N; i++)
	{
		cout << "Comment :=>> [";
		for (int j = 0; j < N; j++)
		{
			cout << " " << m[i][j];
		}
		cout << "]" << endl;
	}
}

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}

float testEsSimetrica()
{
	float reduccio = 0.0;

	const int L = 2;
	int matriu[L][N][N] = {
		{ { 1, 2, 8, 3 },{ 2, 0, 5, 7 },{ 8, 5, 0, 1 },{ 3, 7, 1, 7 } },
		{ { 1, 2, 8, 3 },{ 2, 0, 5, 7 },{ 8, 5, 0, 1 },{ 3, 7, 3, 7 } } };
	bool simetrica[L] = { true, false };
	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio esSimetrica" << endl;
	cout << "Comment :=>> ======================================" << endl;
	for (int l = 0; l < L; l++)
	{
		cout << "Comment :=>> TEST " << l + 1 << endl;
		cout << "Comment :=>> Matriu inicial: " << endl;
		mostraMatriu(matriu[l]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(simetrica[l]); cout << endl;
		bool resultat = esSimetrica(matriu[l]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: ";  mostraBool(resultat); cout << endl;
		if (resultat == simetrica[l])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 5.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;	
	}
	return reduccio;
}

int main()
{
	float grade = 0.0;

	cout << "Grade :=>> " << grade << endl;
	float reduccio = testEsSimetrica();
	grade = grade + (10.0 - reduccio);

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}
