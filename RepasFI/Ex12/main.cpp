
#include "MultMatriu.h"
#include <iostream>
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

bool comparaMatriu(int m1[N][N], int m2[N][N])
{
	bool iguals = true;
	int i = 0;
	while ((iguals) && (i < N))
	{
		int j = 0;
		while ((iguals) && (j < N))
		{
			if (m1[i][j] != m2[i][j])
				iguals = false;
			j++;
		}
		i++;
	}
	return iguals;
}

float testMultMatriu()
{
	const int NPROVES = 2;
	const int NMATRIUS = 2;


	int ParamsMatriu[NPROVES][NMATRIUS][N][N] =
	{
		{ {{0, 1, 2},{3,4,5},{6,7,8}},{ { 0, 1, 2 },{ 3,4,5 },{ 6,7,8 } } },
		{ {{2, 3, 5},{3,4,9},{6,7,3}},{ { 2, 3, 5 },{ 4,9,2 },{ 2,3,6 } } },
	};

	int resultat[NPROVES][N][N] =
	{
		{ {15, 18, 21},{42, 54, 66},{69, 90,111}},
		{ {26, 48, 46},{40, 72, 77},{46, 90, 62}}
	};

	int matriuResultat[N][N];

	float reduccio = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio multiplicaMatriu" << endl;
	cout << "Comment :=>> ===========================================" << endl;

	for (int i = 0; i < NPROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Matrius a multiplicar: " << endl;
		cout << "Comment :=>> Matriu1: " << endl;
		mostraMatriu(ParamsMatriu[i][0]);
		cout << "Comment :=>> Matriu2: " << endl;
		mostraMatriu(ParamsMatriu[i][1]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << endl;
		mostraMatriu(resultat[i]);
		multiplicaMatriu(ParamsMatriu[i][0], ParamsMatriu[i][1], matriuResultat);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << endl;
		mostraMatriu(matriuResultat);
		if (comparaMatriu(matriuResultat, resultat[i]))
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
	float reduccio = testMultMatriu();
	grade = grade + (10.0 - reduccio);

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}