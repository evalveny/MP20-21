#include <fstream>
#include <iostream>
#include <string>
#include "sudoku.h"

using namespace std;

void mostraResultat(bool resultat)
{
	if (resultat)
		cout << "VALID";
	else
		cout << "NO VALID";
}

void mostraFinal(bool resultat)
{
	if (resultat)
		cout << "PARTIDA FINALITZADA";
	else
		cout << "PARTIDA NO FINALITZADA";
}

void mostraTauler(int tauler[N_FILES][N_COLUMNES])
{
	int i, j, k;

	cout << "Comment :=>> Valors inicials del sudoku" << endl;
	cout << "Comment :=>>" << endl;
	for (i = 0; i < N_FILES; i++)
	{
		if (i % 3 == 0)
		{
			cout << "Comment :=>>";
			for (k = 0; k < (N_COLUMNES * 2) + 1; k++)
				cout << "=";
			cout << "\n";
		}
		cout << "Comment :=>>";
		for (j = 0; j < N_COLUMNES; j++)
		{
			if (j % 3 == 0)
				cout << "|";
			else
				cout << " ";
			if (tauler[i][j] != 0)
				cout << tauler[i][j];
			else
				cout << " ";
		}
		cout << "|\n";
	}
	cout << "Comment :=>>";
	for (k = 0; k < (N_COLUMNES * 2) + 1; k++)
		cout << "=";
	cout << "\n";
	cout << "Comment :=>>" << endl;
}



float testSudoku()
{
	float reduccio = 0.0;
	const int N_PROVES = 2;
	int tauler[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 2, 3, 4, 5, 6, 7, 8, 0 },
			{ 4, 5, 6, 7, 8, 9, 1, 2, 3 },
			{ 7, 8, 9, 1, 2, 3, 4, 5, 6 },
			{ 2, 3, 4, 5, 6, 7, 8, 9, 1 },
			{ 5, 6, 7, 8, 9, 1, 2, 3, 4 },
			{ 8, 9, 1, 2, 3, 4, 5, 6, 7 },
			{ 3, 4, 5, 6, 7, 8, 9, 1, 2 },
			{ 6, 7, 8, 9, 1, 2, 3, 4, 5 },
			{ 9, 1, 2, 3, 4, 5, 6, 7, 8 },
		},
		{
			{ 0, 0, 3, 4, 5, 6, 7, 8, 0 },
			{ 4, 5, 6, 7, 8, 9, 1, 2, 3 },
			{ 7, 8, 0, 1, 2, 3, 0, 5, 6 },
			{ 2, 3, 4, 5, 6, 7, 8, 9, 1 },
			{ 5, 6, 7, 8, 9, 1, 2, 3, 4 },
			{ 8, 0, 1, 2, 3, 4, 5, 6, 7 },
			{ 3, 4, 5, 6, 7, 8, 9, 1, 0 },
			{ 6, 7, 0, 0, 1, 2, 3, 4, 5 },
			{ 9, 1, 2, 3, 4, 5, 6, 7, 8 },
		}
	};
	int nLliures[N_PROVES] = { 2, 9 };
	bool resultatEsperat[N_PROVES][MAX_MOVIMENTS] = 
	{
		{ false, false, true, false},
		{ false, false, false, true, true, false, true, true, true, true, true, true, true}
	};
	bool finalEsperat[N_PROVES] = { false, true };
	int nMovimentsEsperat[N_PROVES] = { 4, 13 };

	ifstream fitxerTest;
	string nomFitxer;
	int nMoviments;
	bool resultat[MAX_MOVIMENTS];

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;

		nomFitxer = "test" + to_string(i+1) + ".txt";
		fitxerTest.open(nomFitxer);
		streambuf* buffer_cin = cin.rdbuf(fitxerTest.rdbuf());

		mostraTauler(tauler[i]);

		bool final = jugaSudoku(tauler[i], nLliures[i], resultat, nMoviments);

		cin.rdbuf(buffer_cin);
		fitxerTest.close();

		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> N. de moviments esperat: " << nMovimentsEsperat[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> N. de moviments processat: " << nMoviments << endl;
		if (nMovimentsEsperat[i] == nMoviments)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2;
		}
		cout << "Comment :=>> --------------------" << endl;


		fitxerTest.open(nomFitxer);
		if (fitxerTest.is_open())
		{
			for (int j = 0; j < nMovimentsEsperat[i]; j++)
			{
				int numero, fila, columna;
				fitxerTest >> numero >> fila >> columna;
				cout << "Comment :=>> Numero: " << numero << endl;
				cout << "Comment :=>> Fila: " << fila << endl;
				cout << "Comment :=>> Columna: " << columna << endl;
				cout << "Comment :=>> ----------" << endl;
				cout << "Comment :=>> Resultat esperat: "; mostraResultat(resultatEsperat[i][j]); cout << endl;
				cout << "Comment :=>> ----------" << endl;
				cout << "Comment :=>> Resultat obtingut: "; mostraResultat(resultat[j]); cout << endl;
				if (resultatEsperat[i][j] == resultat[j])
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 2;
				}
				cout << "Comment :=>> --------------------" << endl;
			}
			fitxerTest.close();
		}
		else
			reduccio = 10.0;

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
	float reduccio = testSudoku();
	grade = grade + (10 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}