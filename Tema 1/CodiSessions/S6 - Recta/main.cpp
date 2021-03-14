#include "Recta.h"
#include <iostream>

using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}




float testInterseccions()
{
	float reduccio = 0.0;
	const int N_PROVES = 7;

	float valors_recta1[N_PROVES][3] =
	{
		{ 0, 1, 0 },{ 1, 0, 0 },{ 1, -1, 0 }, { 1, 0, -1 } , {1, 0, 1},{ 0, 1, -2 }, {1, -1, 0}
	};

	Recta recta1[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		recta1[i].setA(valors_recta1[i][0]);
		recta1[i].setB(valors_recta1[i][1]);
		recta1[i].setC(valors_recta1[i][2]);
	}

	float valors_recta2[N_PROVES][3] =
	{
		{ 0, 1, 2 },{ 1, 0, 1 },{ 1, -1, 2 }, {0 , 1, -2}, {1, -1, 0}, {1, -1, 0}, {1, 1, 0}
	};
	Recta recta2[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		recta2[i].setA(valors_recta2[i][0]);
		recta2[i].setB(valors_recta2[i][1]);
		recta2[i].setC(valors_recta2[i][2]);
	}



	bool resultatInterseccio[N_PROVES] = { false, false, false, true, true, true, true };
	float valors_resultatPunt[N_PROVES][2] = { {0, 0}, {0, 0}, {0, 0}, {1, 2}, {-1, -1}, {2, 2} , {0, 0} };
	Punt resultatPunt[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		resultatPunt[i].setX(valors_resultatPunt[i][0]);
		resultatPunt[i].setY(valors_resultatPunt[i][1]);
	}

	cout << endl;
	cout << "Comment :=>> Iniciant test comprovacio interseccio entre rectes" << endl;
	cout << "Comment :=>> ==================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Recta 1: a = " << recta1[i].getA() << ", b = " << recta1[i].getB() << ", c = " << recta1[i].getC() << endl;
		cout << "Comment :=>> Recta 2: a = " << recta2[i].getA() << ", b = " << recta2[i].getB() << ", c = " << recta2[i].getC() << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatInterseccio[i]); cout << endl;
		if (resultatInterseccio[i])
			cout << "Comment :=>> Punt esperat: (" << resultatPunt[i].getX() << ", " << resultatPunt[i].getY() << ")" << endl;
		cout << "Comment :=>> ---" << endl;
		Punt pt;
		bool interseccio = recta1[i].interseccio(recta2[i], pt);
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(interseccio); cout << endl;
		if (interseccio)
			cout << "Comment :=>> Punt obtingut: (" << pt.getX() << ", " << pt.getY() << ")" << endl;
		if (interseccio == resultatInterseccio[i])
			if (interseccio)
			{
				if ((pt.getX() == resultatPunt[i].getX()) && (pt.getY() == resultatPunt[i].getY()))
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR" << endl;
					reduccio += 1.0;
				}
			}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	return reduccio;
}


float testDistancies()
{
	float reduccio = 0.0;
	const int N_PROVES = 6;

	float valors_recta[N_PROVES][3] =
	{
		{ 0, 1, 1 },{ 0, 1, 1 },{ 1, 0, 1 },{ 3, 4, -5 } ,{ -3, -4, 5 },{ 4, 3, -5 }
	};

	Recta recta[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		recta[i].setA(valors_recta[i][0]);
		recta[i].setB(valors_recta[i][1]);
		recta[i].setC(valors_recta[i][2]);
	}
	float valors_punt[N_PROVES][2] =
	{
		{ 0, 0 },{ 1, -1 },{ 0, 0},{ 5, 5 },{ 5, -5 },{ 5, -5 }
	};
	Punt punt[N_PROVES];
	for (int i = 0; i < N_PROVES; i++)
	{
		punt[i].setX(valors_punt[i][0]);
		punt[i].setY(valors_punt[i][1]);
	}


	float distanciaResultat[N_PROVES] = { 1, 0, 1, 6, 2, 0};

	cout << endl;
	cout << "Comment :=>> Iniciant test comprovacio distancia punt a recta" << endl;
	cout << "Comment :=>> ================================================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Recta: a = " << recta[i].getA() << ", b = " << recta[i].getB() << ", c = " << recta[i].getC() << endl;
		cout << "Comment :=>> Punt: (" << punt[i].getX() << ", " << punt[i].getY() << ")" << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Resultat esperat distancia: " << distanciaResultat[i] << endl;
		cout << "Comment :=>> ---" << endl;
		float distancia = recta[i].distancia(punt[i]);
		cout << "Comment :=>> Resultat obtingut distancia: " << distancia << endl;
		if (distancia  == distanciaResultat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> ------------------------------------------" << endl;
	}
	return reduccio;
}

int main()
{
	float grade = 0;
	float reduccio;


	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testDistancies();
	if (reduccio > 6.0)
		reduccio = 6.0;
	grade += (5.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testInterseccions();
	if (reduccio > 6.0)
		reduccio = 6.0;
	grade += (5.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;


	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}