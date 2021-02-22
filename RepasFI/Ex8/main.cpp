#include "binari.h"
#include <iostream>

using namespace std;

void mostraBinari(int v[], int longitud)
{
	for (int i = 0; i < longitud; i++)
		cout << v[i];
	cout << endl;
}

int testConversio()
{
	const int N_PROVES = 8;
	const int MAX_BINARI = 16;
	int binari[N_PROVES][MAX_BINARI] =
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 1, 0 },
		{ 1, 0, 0, 0, 1, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 }
	};
	int longitud[N_PROVES] = { 4, 4, 8, 8, 8, 8, 16, 16 };
	int resultat[N_PROVES] = { 0, -1, 85, 42, -86, -117, -32513, 255 };

	float reduccio = 0.0;
	int valor;

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test de conversio amb signe" << endl;
	cout << "Comment :=>> ======================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Numero binari a convertir: ";
		mostraBinari(binari[i], longitud[i]);
		valor = BinariADecimal(binari[i], longitud[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultat[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << valor << endl;
		if (valor == resultat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR " << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}

int main()
{
	float grade = 0.0;
	float reduccio;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Grade :=>> " << grade << endl;
	reduccio = testConversio();
	if (reduccio > 10)
		reduccio = 10.0;
	grade = grade + (10 - reduccio);

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}