#include "domino.h"
#include <iostream>
using namespace std;

void mostraFitxa(Fitxa& fitxa)
{
	int valor1, valor2;
		cout << "(" << fitxa.valor1 << "," << fitxa.valor2 << ") ";
}


void mostraFitxes(Fitxa fitxes[], int nFitxes)
{
	for (int i = 0; i < nFitxes; i++)
		mostraFitxa(fitxes[i]);
}

bool igualFitxa(Fitxa& fitxa1, Fitxa& fitxa2)
{
	int valorEsq1, valorDreta1, valorEsq2, valorDreta2;
	valorEsq1 = fitxa1.valor1;
	valorDreta1 = fitxa1.valor2;
	valorEsq2 = fitxa2.valor1;
	valorDreta2 = fitxa2.valor2;
	return (((valorEsq1 == valorEsq2) && (valorDreta1 == valorDreta2)) ||
		((valorEsq1 == valorDreta2) && (valorDreta1 == valorEsq2)));
}

bool igualsArray(Fitxa resultatEsperat[], int nFitxesResultatEsperat, Fitxa fitxesJugades[], int nFitxesJugades)
{
	bool iguals = (nFitxesResultatEsperat == nFitxesJugades);
	int i = 0;
	while (iguals && (i < nFitxesResultatEsperat))
	{
		if (!igualFitxa(resultatEsperat[i],  fitxesJugades[i]))
			iguals = false;
		else
			i++;
	}
	return iguals;
}

float testDomino()
{
	float grade = 0.0;
	const int N_PROVES = 2;
	Fitxa resultatEsperat[N_PROVES][MAX_FITXES*MAX_JUGADORS*2] = 
	{
		{{0, 0}, {-1, -1}, {-1, -1}, {-1, -1}, {0, 1}, {1, 1}, {-1, -1}, {-1, -1}, {0, 2}, {1, 2}, {2, 3}, {3, 6}, {0, 6}, {2, 2}, {2, 4}, {4, 4}, {0, 3}, {1, 3}, {3, 4}, {-1, -1}, {-1, -1}, {1, 4}, {3, 3}, {4, 5}, {0, 5}, {-1, -1}, {3, 5}, {5, 5}, {0, 4} },
		{{0, 0}, {0, 1}, {0, 2}, {1, 1}, {1, 2}, {2, 2}, {2, 3}, {0, 3}, {0, 4}, {2, 6}, {0, 6}, {2, 4}, {2, 5}, {0, 5}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}}
	};
	int nFitxesResultatEsperat[N_PROVES] = { 29, 18 };
	int valorsPartidaEsperat[N_PROVES] = { 1, -1 };

	Fitxa fitxesInicials[N_PROVES][MAX_JUGADORS * MAX_FITXES];
	int nFitxa = 0;
	for (int i = 0; i < 7; i++)
		for (int j = i; j < 7; j++)
		{
			fitxesInicials[0][nFitxa].valor1 = i;
			fitxesInicials[0][nFitxa].valor2 = j;
			nFitxa++;
		}
	nFitxa = 0;
	for (int jugador = 0; jugador < 4; jugador++)
		for (int j = 0; j < 7; j++)
			fitxesInicials[1][nFitxa++] = fitxesInicials[0][(j * 4) + jugador];

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Iniciant test PARTIDA" << i + 1 << endl;
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> Fitxes inicials per la partida... " << endl;
		cout << "Comment :=>>";
		mostraFitxes(fitxesInicials[i], MAX_FITXES * MAX_JUGADORS);
		cout << endl;

		cout << "Comment :=>> ------------------------------" << endl;
		cout << "Comment :=>> Jugant la partida cridant a la funcio jugaDomino ..." << endl;
		cout << "Comment :=>>" << endl;

		Fitxa fitxesJugades[MAX_FITXES * MAX_JUGADORS * 2];
		int nFitxesJugades;
		int resultat = jugaDomino(fitxesInicials[i], fitxesJugades, nFitxesJugades);

		cout << "Comment :=>> ------------------------------" << endl;
		cout << "Comment :=>> Jugador guanyador esperat: " << valorsPartidaEsperat[i] << endl;
		cout << "Comment :=>> -------" << endl;
		cout << "Comment :=>> Jugador guanyador esperat: " << resultat << endl;
		if (valorsPartidaEsperat[i] == resultat)
		{
			cout << "Comment :=>> CORRECTE" << endl;
			grade += 2.5;
		}
		else
			cout << "Comment :=>> ERROR" << endl;
		cout << "Comment :=>> ------------------------------" << endl;

		cout << "Grade :=>> " << grade << endl;

		cout << "Comment :=>> Fitxes jugades esperades: " << endl;
		cout << "Comment :=>>";
		mostraFitxes(resultatEsperat[i], nFitxesResultatEsperat[i]);
		cout << endl;
		cout << "Comment :=>> -------" << endl;
		cout << "Comment :=>> Jugador jugades obtingudes: " << endl;
		cout << "Comment :=>>";
		mostraFitxes(fitxesJugades, nFitxesJugades);
		cout << endl;

		if (igualsArray(resultatEsperat[i], nFitxesResultatEsperat[i], fitxesJugades, nFitxesJugades))
		{
			cout << "Comment :=>> CORRECTE" << endl;
			grade += 2.5;
		}
		else
			cout << "Comment :=>> ERROR" << endl;
		cout << "Comment :=>> ------------------------------" << endl;

		cout << "Grade :=>> " << grade << endl;
	}

	return grade;
}



int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Grade :=>> " << grade << endl;
	grade = testDomino();
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}