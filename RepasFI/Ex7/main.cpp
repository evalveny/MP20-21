#include <iostream>
#include <math.h>
using namespace std;

void normalitzaValors(float vector[], int nValors);

void mostraVector(float v[], int longitud)
{
	cout << "[";
	if (longitud > 0)
	{
		cout << v[0];
	}
	for (int i = 1; i < longitud; i++)
		cout << "," << v[i];
	cout << "]" << endl;
}

bool igualVectors(float v1[], float v2[], int longitud)
{
	const int EPSILON = 0.001;
	bool iguals = true;
	int i = 0;
	while ((iguals) && (i < longitud))
	{
		if (fabs(v1[i] - v2[i]) > EPSILON)
			iguals = false;
		else
			i++;
	}
	return iguals;
}


int main()
{
	float grade = 0.0;

	float reduccio = 0.0;

	const int N_PROVES = 5;
	const int MAX_PROVA = 5;
	float vector[N_PROVES][MAX_PROVA] =
	{
		{ 0, 5, 3, 4, 2},
		{ -5, -2, 0, 2, 5},
		{ -5, -2, 0, -3, -4},
		{ 0, 0, 0, 0, 0},
		{ 2, 2, 2, 2, 2}
	};
	int nValors[N_PROVES] = { 5, 5, 5, 0, 5 };
	float resultatEsperat[N_PROVES][MAX_PROVA] =
	{
		{ 0, 1, 0.6, 0.8, 0.4},
		{ 0, 0.3, 0.5, 0.7, 1.0},
		{ 0.0, 0.6, 1, 0.4, 0.2},
		{},
		{2, 2, 2, 2, 2}
	};

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test funcio normalitzaValors" << endl;
	cout << "Comment :=>> =====================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Vector a normalitzar: ";
		mostraVector(vector[i], nValors[i]);
		cout << "Comment :=>> N. valors del vector: " << nValors[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: ";
		mostraVector(resultatEsperat[i], nValors[i]);
		normalitzaValors(vector[i], nValors[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: ";
		mostraVector(vector[i], nValors[i]);
		if (igualVectors(vector[i], resultatEsperat[i], nValors[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
		grade += (2.0 - reduccio);
		cout << "Grade :=>> " << grade << endl;
	}

	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}