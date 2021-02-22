#include "quatre_ratlla.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}

void mostraMatriu(int v[N_FILES][N_COLUMNES])
{
	for (int i = 0; i < N_FILES; i++)
	{
		cout << "Comment :=>> ";
		for (int j = 0; j < N_COLUMNES; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}


bool comparaMatrius(int v1[N_FILES][N_COLUMNES], int v2[N_FILES][N_COLUMNES])
{
	bool iguals = true;
	int i = 0;
	int j;
	while ((i < N_FILES) && iguals)
	{
		j = 0;
		while ((j < N_COLUMNES) && iguals)
		{
			if (v1[i][j] != v2[i][j])
				iguals = false;
			else j++;
		}
		i++;
	}
	return iguals;
}


float testPosaFitxa()
{
	const int N_PROVES = 5;
	int taulerInicial[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0 }
		}
	};
	int columna[N_PROVES] = { 2, 0, 1, 6, 3 };
	int jugador[N_PROVES] = { 1, 2, 1, 2, 2 };
	int taulerFinal[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0, 0, 0 }
		},
		{
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 },
			{ 1, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 2 },
			{ 0, 0, 0, 0, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 0, 0, 1, 0, 0, 0 }
		}
	};
	int resultat[N_PROVES] = {5, -1, 0, 4, 3};

	float reduccio = 0.0;
	int resultatObtingut;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio posaFitxa" << endl;
	cout << "Comment :=>> ====================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Tauler inicial: " << endl; mostraMatriu(taulerInicial[i]);
		resultatObtingut = posaFitxa(taulerInicial[i], columna[i], jugador[i]);
		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Tauler final esperat: " << endl; mostraMatriu(taulerFinal[i]);
		cout << "Comment :=>> Resultat final esperat: " << resultat[i] << endl;
		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Tauler final obtingut: " << endl; mostraMatriu(taulerInicial[i]);
		cout << "Comment :=>> Resultat final obtingut: " << resultatObtingut << endl;
		if ((resultatObtingut == resultat[i]) && comparaMatrius(taulerInicial[i], taulerFinal[i]))
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

float testQuatreRatlla()
{
	const int N_PROVES = 12;
	int taulerInicial[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 2, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 2, 2, 2, 2, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 2, 2, 2, 2, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 2, 1, 0, 0, 0, 0, 0 },
			{ 2, 1, 0, 0, 0, 0, 0 },
			{ 2, 1, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 1, 0 },
			{ 0, 2, 1, 0, 1, 1, 0 },
			{ 0, 2, 2, 1, 2, 2, 0 },
			{ 0, 1, 1, 1, 2, 2, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 1, 0 },
			{ 0, 2, 1, 0, 1, 1, 0 },
			{ 0, 2, 2, 1, 2, 2, 0 },
			{ 0, 1, 1, 1, 2, 2, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 0, 0, 0, 0 },
			{ 0, 2, 1, 2, 1, 1, 0 },
			{ 0, 2, 2, 1, 2, 2, 0 },
			{ 0, 1, 1, 1, 2, 2, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 0, 0, 0, 0 },
			{ 0, 2, 1, 2, 1, 1, 0 },
			{ 0, 2, 2, 1, 2, 2, 0 },
			{ 0, 1, 1, 1, 2, 2, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 0, 0, 1 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 2, 0, 0, 0 },
			{ 0, 2, 2, 2, 1, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 2, 0, 2, 0, 0, 0 },
			{ 0, 2, 2, 2, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0 },
			{ 0, 2, 0, 2, 1, 1, 1 }
		}
	};
	int fila[N_PROVES] = { 2, 5, 5, 5, 5, 4, 2, 4, 3, 4, 5, 5 };
	int columna[N_PROVES] = { 1, 1, 2, 1, 2, 3, 2, 4, 1, 1, 1, 1 };
	bool resultat[N_PROVES] = { true, true, true, true, true, true, true, true, false, false, false, false};

	float reduccio = 0.0;
	bool resultatObtingut;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio quatreRatlla" << endl;
	cout << "Comment :=>> ========================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Tauler: " << endl; mostraMatriu(taulerInicial[i]);
		cout << "Comment :=>> Posicio a comprovar. Fila: " << fila[i] << ", Columna: " << columna[i] << endl;
		resultatObtingut = quatreRatlla(taulerInicial[i], fila[i], columna[i]);
		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultat[i]); cout << endl;
		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultatObtingut); cout << endl;

		if (resultatObtingut == resultat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
	return reduccio;
}


float testJugaQuatreRatlla()
{
	const int N_PROVES = 2;
	int taulerInicial[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 }
		},
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0 }
		}
	};
	int taulerFinal[N_PROVES][N_FILES][N_COLUMNES] =
	{
		{
			{ 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 0, 1, 0, 0 },
			{ 1, 1, 1, 2, 1, 0, 0 },
			{ 2, 2, 1, 1, 2, 0, 0 },
			{ 1, 1, 1, 2, 2, 2, 0 },
			{ 1, 2, 2, 1, 2, 2, 0 }
		},
		{
			{ 2, 1, 2, 1, 2, 1, 2 },
			{ 1, 1, 2, 1, 2, 1, 2 },
			{ 2, 1, 2, 1, 2, 1, 2 },
			{ 1, 2, 1, 2, 1, 2, 1 },
			{ 2, 2, 1, 2, 1, 2, 1 },
			{ 1, 2, 1, 2, 1, 2, 1 }
		}
	};
	int resultat[N_PROVES] = { 2, -1 };

	ifstream fitxerTest;
	string nomFitxer;
	float reduccio = 0.0;
	int resultatObtingut;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de la funcio jugaQuatreRatlla" << endl;
	cout << "Comment :=>> ===========================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>>" << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> -----------------------------------------------" << endl;
		cout << "Comment :=>> Tauler inicial: " << endl; mostraMatriu(taulerInicial[i]);
		cout << "Comment :=>> -----" << endl;

		nomFitxer = "prova" + to_string(i + 1) + ".txt";
		int columna;
		int jugador = 1;
		fitxerTest.open(nomFitxer);
		fitxerTest >> columna;
		while (!fitxerTest.eof())
		{
			cout << "Comment :=>> Torn del jugador: " << jugador << " Columna: " << columna << endl;
			jugador = 3 - jugador;
			fitxerTest >> columna;
		}
		fitxerTest.close();

		fitxerTest.open(nomFitxer);
		streambuf* buffer_cin = cin.rdbuf(fitxerTest.rdbuf());

		resultatObtingut = jugaQuatreRatlla(taulerInicial[i]);

		cin.rdbuf(buffer_cin);
		fitxerTest.close();


		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Tauler final esperat: " << endl; mostraMatriu(taulerFinal[i]);
		cout << "Comment :=>> Resultat final esperat: " << resultat[i] << endl;
		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Tauler final obtingut: " << endl; mostraMatriu(taulerInicial[i]);
		cout << "Comment :=>> Resultat final obtingut: " << resultatObtingut << endl;
		if ((resultatObtingut == resultat[i]) && comparaMatrius(taulerInicial[i], taulerFinal[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 4.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	if (reduccio > 6.0)
		reduccio = 6.0;
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

	float reduccio = testPosaFitxa();
	grade = grade + (2.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testQuatreRatlla();
	grade = grade + (4.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testJugaQuatreRatlla();
	grade = grade + (4.0 - reduccio);

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}