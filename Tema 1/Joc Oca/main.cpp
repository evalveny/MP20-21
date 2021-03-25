#include "tauler.h"
#include <iostream>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

int main()
{
	Tauler t;

	const int N_CASELLES = 12;
	int estatCaselles[N_CASELLES][2] =
	{
		{1, 1},
		{2, 1},
		{3, 2},
		{4, 1},
		{5, 2},
		{6, 1},
		{7, 3},
		{8, 1},
		{9, 4},
		{10, 2},
		{11, 1},
		{12, 5}
	};
	
	float reduccio = 0;
	float grade = 0.0;

	cout << endl << "Grade :=>> " << grade << endl << endl;
	cout << "Comment : = >> " << endl;
	cout << "Comment :=>> Inicialitzant tauler de joc amb 3 jugadors" << endl;
	cout << "Comment :=>> ==========================================" << endl;
	cout << "Comment :=>> " << endl;
	int tipusCaselles[N_CASELLES];
	for (int i = 0; i < N_CASELLES; i++)
		tipusCaselles[i] = estatCaselles[i][1];
	t.inicialitza(tipusCaselles, N_CASELLES, 3);
	cout << "Comment :=>> Comprovant estat caselles despres inicialitzar" << endl;
	cout << "Comment :=>> ------------------------------------------" << endl; 
	for (int i = 0; i < N_CASELLES; i++)
	{
		cout << "Comment :=>> CASELLA " << i + 1 << endl;
		cout << "Comment :=>> Tipus esperat: " << estatCaselles[i][1] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Tipus obtingut: " << t.getTipusCasella(i + 1) << endl;
		if (estatCaselles[i][1] == t.getTipusCasella(i + 1))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ---" << endl;
	}


	if (reduccio > 4.0)
		reduccio = 4.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	const int N_TORNS = 14;
	const int N_JUGADORS = 3;
	int valorDau[N_TORNS] = { 2, 2, 5, 4, 3, 2, 3, 1, 2, 1, 2, 1, 2, 1 };
	int posicioJugadors[N_TORNS][N_JUGADORS] = 
	{
		{5, 1, 1},
		{7, 1, 1},
		{7, 6, 1},
		{7, 6, 10},
		{7, 6, 10},
		{7, 6, 10},
		{7, 1, 10},
		{7, 1, 11},
		{7, 1, 11},
		{7, 2, 11},
		{7, 2, 11},
		{8, 2, 11},
		{8, 4, 11},
		{8, 4, 12}
	};
	bool potTirarJugadors[N_TORNS][N_JUGADORS] =
	{
		{true, true, true},
		{false, true, true},
		{false, true, true},
		{false, true, true},
		{false, true, true},
		{false, true, true},
		{false, true, true},
		{false, true, true},
		{true, true, true},
		{true, true, true},
		{true, true, true},
		{true, true, true},
		{true, true, true},
		{true, true, true}
	};
	int nTornsInactiuJugadors[N_TORNS][N_JUGADORS] =
	{
		{0, 0, 0},
		{2, 0, 0},
		{2, 0, 0},
		{2, 0, 0},
		{2, 0, 0},
		{1, 0, 0},
		{1, 0, 0},
		{1, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	bool guanyadorJugadors[N_TORNS][N_JUGADORS] =
	{
		{false, false, false},
		{false, false, false},
		{false, false, false},		
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, false},
		{false, false, true}
	};
	cout << "Comment : = >> " << endl;
	cout << "Comment :=>> Comprovant el funcionament del joc amb el metode tornJoc de la classe Tauler" << endl;
	cout << "Comment :=>> ============================================================================" << endl;

	for (int i = 0; i < N_TORNS; i++)
	{
		cout << "Comment :=>> TORN " << i + 1 << endl;
		cout << "Comment :=>> Valor del dau: " << valorDau[i] << endl;
		t.tornJoc(valorDau[i]);
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Estat esperat dels jugadors: " << endl;
		for (int j = 0; j < N_JUGADORS; j++)
		{
			cout << "Comment :=>> Jugador " << j << ": Posicio = " << posicioJugadors[i][j] <<
				", Pot Tirar = "; mostraBool(potTirarJugadors[i][j]);
			cout << ", N. torns sense tirar: " << nTornsInactiuJugadors[i][j] << ", Guanyador: "; mostraBool(guanyadorJugadors[i][j]); cout << endl;
		}
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Estat obtingut dels jugadors: " << endl;
		int posicio, nTornsInactiu;
		bool potTirar, guanyador;
		for (int j = 0; j < N_JUGADORS; j++)
		{
			t.getEstatJugador(j + 1, posicio, potTirar, nTornsInactiu, guanyador);
			cout << "Comment :=>> Jugador " << j << ": Posicio = " << posicio <<
				", Pot Tirar = "; mostraBool(potTirar);
			cout << ", N. torns sense tirar: " << nTornsInactiu << ", Guanyador: "; mostraBool(guanyador); cout << endl;
			if ((posicio == posicioJugadors[i][j]) && (potTirar == potTirarJugadors[i][j]) && 
				(nTornsInactiu == nTornsInactiuJugadors[i][j]) && (guanyador == guanyadorJugadors[i][j]))
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}

		}		
		cout << "Comment :=>> ------------------------------------------" << endl;
	}

	if (reduccio > 10.0)
		reduccio = 10.0;
	grade += (8.0 - reduccio);

	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;


	return 0;
}