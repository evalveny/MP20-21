#include <stdio.h>
#include <iostream>
#include "Unir.h"

using namespace std;

void mostraVector(int v[], int longitud)
{
	cout << "Comment :=>>" << "[";
	if (longitud > 0)
	{
		cout << v[0];
	}
	for (int i = 1; i < longitud; i++)
		cout << "," << v[i];
	cout << "]" << endl;
}

bool comparaVector(int v1[], int v2[], int longitud)
{
	bool iguals = true;
	int i = 0;
	while ((iguals) && (i < longitud))
	{
		if (v1[i] != v2[i])
			iguals = false;
		i++;
	}
	return iguals;
}

float testUnirOrdenadament()
{
	float reduccio = 0.0;

	const int MAXV = 5;
	const int MAXELV1 = 5;
	const int MAXELV2 = 6;
	const int O = 11;

	int vector1[MAXV][MAXELV1] = { { 1, 3, 5, 6, 9 },{ 1, 2, 3, 4, 5 },{ 7, 8, 9, 10, 11 },{ 1, 3, 5, 7, 9 },{10,17,25,29,32} };
	int vector2[MAXV][MAXELV2] = { { 2, 4, 6, 7, 8, 13 },{ 6, 7, 8, 9, 10, 11 },{ 1, 2, 3, 4, 5, 6 },{ 2, 4, 6, 8, 10, 12 },{1,4,6,45,46,47} };
	int vectorUnio[MAXV][O];
	int vectorUnioCalculat[MAXV][O] = {
		{ 1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 13 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 },
		{ 1, 4, 6,10,17,25,29,32,45, 46, 47 } };

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test Uneix Ordenadament" << endl;
	cout << "Comment :=>> ================================" << endl;
	for (int v = 0; v < MAXV; v++)
	{
		cout << "Comment :=>> TEST " << v + 1 << endl;
		cout << "Comment :=>> Vector1: " << endl;
		mostraVector(vector1[v], MAXELV1);
		cout << "Comment :=>> Vector2: " << endl;
		mostraVector(vector2[v], MAXELV2);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat:" << endl;
		mostraVector(vectorUnioCalculat[v], MAXELV1 + MAXELV2);
		uneixOrdenadament(vector1[v], MAXELV1, vector2[v], MAXELV2, vectorUnio[v], O);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut:" << endl;
		mostraVector(vectorUnio[v], MAXELV1+MAXELV2);
		if (comparaVector(vectorUnio[v], vectorUnioCalculat[v], MAXELV1 + MAXELV2))
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2;
		}	
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	return reduccio;
}

float testUnirOrdenadament2()
{
	float reduccio = 0.0;

	const int MAXV = 5;
	const int MAXELV1 = 5;
	const int MAXELV2 = 6;
	const int O = 11;

	int vector1[MAXV][MAXELV1] = { { 1, 3, 5, 6, 9 },{ 1, 2, 3, 4, 5 },{ 7, 8, 9, 10, 11 },{ 1, 3, 5, 7, 9 },{10,17,25,29,32} };
	int vector2[MAXV][MAXELV2] = { { 4, 2, 8, 7, 6, 13 },{ 11, 10, 9, 8, 7, 6 },{ 6, 5, 3, 4, 2, 1 },{ 2, 4, 6, 8, 10, 12 },{47,4,46,45,6,1} };
	int vectorUnio[MAXV][O];
	int vectorUnioCalculat[MAXV][O] = {
		{ 1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 13 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12 },
		{ 1, 4, 6,10,17,25,29,32,45, 46, 47 } };

	cout << endl << endl;
	cout << "Comment :=>> Iniciant test Uneix Ordenadament versio 2" << endl;
	cout << "Comment :=>> =========================================" << endl;
	for (int v = 0; v < MAXV; v++)
	{
		cout << "Comment :=>> TEST " << v + 1 << endl;
		cout << "Comment :=>> Vector1: " << endl;
		mostraVector(vector1[v], MAXELV1);
		cout << "Comment :=>> Vector2: " << endl;
		mostraVector(vector2[v], MAXELV2);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat:" << endl;
		mostraVector(vectorUnioCalculat[v], MAXELV1 + MAXELV2);
		uneixOrdenadament2(vector1[v], MAXELV1, vector2[v], MAXELV2, vectorUnio[v], O);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut:" << endl;
		mostraVector(vectorUnio[v], MAXELV1 + MAXELV2);
		if (comparaVector(vectorUnio[v], vectorUnioCalculat[v], MAXELV1 + MAXELV2))
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 2;
		}

		cout << "Comment :=>> -----------------------------------------------" << endl;
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
	float reduccio = testUnirOrdenadament();
	if (reduccio > 6.0)
		reduccio = 6.0;
	grade = grade + (4 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testUnirOrdenadament2();
	if (reduccio > 8.0)
		reduccio = 8.0;
	grade = grade + (6 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}