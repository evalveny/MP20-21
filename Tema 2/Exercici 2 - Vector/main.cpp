#include "Vector.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, const Punt& pt)
{
	out << "(" << pt.getX() << "," << pt.getY() << ")";
	return out;
}

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}


bool comparaVector(Vector& v, Punt* resultat, int longitud)
{
	bool iguals = (longitud == v.getNElements());
	if (iguals)
	{
		int i = 0;
		while ((i < longitud) && iguals)
		{
			if (!(resultat[i] == v[i]))
				iguals = false;
			else
				i++;
		}
	}
	return iguals;
}

void mostraVector(Vector &v, int nValors)
{
	cout << "Comment :=>> [";
	for (int i = 0; i < nValors - 1; i++)
	{
		cout << v[i] << ",";
	}
	if (nValors > 0)
		cout << v[nValors - 1];
	cout << "]" << endl;
}

void mostraArray(Punt* v, int nValors)
{
	cout << "Comment :=>> [";
	for (int i = 0; i < nValors - 1; i++)
	{
		cout << v[i] << ",";
	}
	if (nValors > 0)
		cout << v[nValors - 1];
	cout << "]" << endl;
}

float testInsereix(Vector& v)
{
	float reduccio = 0.0;

	const int MAX_PROVES = 15;

	Punt valors[MAX_PROVES] = { {0, 0},  {9,9}, {8,8}, {7,7}, {6,6},{ 1,1 },{ 2,2 },{3,3},{ 4,4 },{5,5}, {12,12}, {11,11}, {10,10}, {0, 0}, {0, 0} };
	int posicio[MAX_PROVES] = { 1, 0, 0, 0, 0, 0, 1, 2, 3, 4, 9, 9, 9, 13, -1 };
	bool resultatEsperat[MAX_PROVES] = { false, true, true, true, true, true, true, true, true, true, true, true, true, false, false };
	int nElementsEsperat[MAX_PROVES] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 12 };
	int maxElementsEsperat[MAX_PROVES] = { 0, 5, 5, 5, 5, 5, 10, 10, 10, 10, 10, 20, 20, 20, 20 };


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode insereix" << endl;
	cout << "Comment :=>> =================================" << endl;


	for (int i = 0; i < MAX_PROVES; i++)
	{
		cout << "Comment :=>> Afegint punt " << valors[i] << " a la posicio " << posicio[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat[i]);
		cout << ", N. elements: " << nElementsEsperat[i] << ", Max elements: " << maxElementsEsperat[i] << endl;
		bool resultat = v.insereix(valors[i], posicio[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); 
		cout << ", N. elements: " << v.getNElements() << ", Max elements: " << v.getMaxElements() << endl;
		if ((resultat == resultatEsperat[i]) && (v.getNElements() == nElementsEsperat[i]) && (v.getMaxElements() == maxElementsEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 0.5;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	const int N_ELEMENTS_FINAL = 12;
	Punt contingutEsperat[N_ELEMENTS_FINAL] = {{ 1,1 }, { 2,2 }, { 3,3 }, { 4,4 }, { 5,5 },{ 6,6 },{ 7,7 },{ 8,8 },{ 9,9 },{ 10,10 }, { 11,11 },{ 12,12 }};
	cout << "Comment :=>> Contingut final del vector esperat: " << endl; 
	mostraArray(contingutEsperat,	N_ELEMENTS_FINAL);
	cout << "Comment :=>> Contingut final del vector obtingut: " << endl;
	mostraVector(v, N_ELEMENTS_FINAL);
	if (comparaVector(v, contingutEsperat, N_ELEMENTS_FINAL))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.5;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	if (reduccio > 5.0)		
		reduccio = 5.0;
	return reduccio;
}

float testElimina(Vector& v)
{
	float reduccio = 0.0;

	const int MAX_PROVES = 14;
	const int TEST_CONTINGUT = 11;


	int posicio[MAX_PROVES] = { -1, 12, 0, 10, 1, 7, 2, 6, 3, 2, 0, 0, 0, 0 };
	bool resultatEsperat[MAX_PROVES] = { false, false, true, true, true, true, true, true, true, true, true, true, true, true };
	int nElementsEsperat[MAX_PROVES] = { 12, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int maxElementsEsperat[MAX_PROVES] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 10, 10, 10, 5, 5};


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode elimina" << endl;
	cout << "Comment :=>> ================================" << endl;

	for (int i = 0; i < TEST_CONTINGUT; i++)
	{
		cout << "Comment :=>> Eliminant punt de la posicio " << posicio[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat[i]);
		cout << ", N. elements: " << nElementsEsperat[i] << ", Max elements: " << maxElementsEsperat[i] << endl;
		bool resultat = v.elimina(posicio[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat);
		cout << ", N. elements: " << v.getNElements() << ", Max elements: " << v.getMaxElements() << endl;
		if ((resultat == resultatEsperat[i]) && (v.getNElements() == nElementsEsperat[i]) && (v.getMaxElements() == maxElementsEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 0.5;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	const int N_ELEMENTS_FINAL = 3;
	Punt contingutEsperat[N_ELEMENTS_FINAL] = { { 4,4 },{ 8,8 },{ 9,9 } };
	cout << "Comment :=>> Contingut del vector esperat despres de les eliminacions anteriors: " << endl;
	mostraArray(contingutEsperat, N_ELEMENTS_FINAL);
	cout << "Comment :=>> Contingut del vector obtingut: " << endl;
	mostraVector(v, N_ELEMENTS_FINAL);
	if (comparaVector(v, contingutEsperat, N_ELEMENTS_FINAL))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.5;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	for (int i = TEST_CONTINGUT; i < MAX_PROVES; i++)
	{
		cout << "Comment :=>> Eliminant punt de la posicio " << posicio[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: "; mostraBool(resultatEsperat[i]);
		cout << ", N. elements: " << nElementsEsperat[i] << ", Max elements: " << maxElementsEsperat[i] << endl;
		bool resultat = v.elimina(posicio[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat);
		cout << ", N. elements: " << v.getNElements() << ", Max elements: " << v.getMaxElements() << endl;
		if ((resultat == resultatEsperat[i]) && (v.getNElements() == nElementsEsperat[i]) && (v.getMaxElements() == maxElementsEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 0.5;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}

	if (reduccio > 5.0)
		reduccio = 5.0;
	return reduccio;
}



float testOperadorAssignacio()
{
	float reduccio = 0.0;

	Vector vOriginal, vResultat;

	const int N_ELEMENTS = 12;
	Punt valors[N_ELEMENTS] = { { 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 },{ 6,6 },{ 7,7 },{ 8,8 },{ 9,9 },{ 10,10 },{ 11,11 },{ 12,12 } };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de l'operador d'assignacio" << endl;
	cout << "Comment :=>> ========================================" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant el vector original amb valors:" << endl;
	mostraArray(valors, N_ELEMENTS);
	for (int i = 0; i < N_ELEMENTS; i++)
		vOriginal.insereix(valors[i], i);
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	cout << "Comment :=>> Copiant el vector amb l'operador d'assignacio:" << endl;
	vResultat = vOriginal;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	cout << "Comment :=>> Contingut final del vector esperat: " << endl;
	mostraArray(valors, N_ELEMENTS);
	cout << "Comment :=>> Contingut final del vector copiat amb l'operador d'assignacio: " << endl;
	mostraVector(vResultat, N_ELEMENTS);
	if (comparaVector(vResultat, valors, N_ELEMENTS))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.5;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	return reduccio;
}



int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	Vector v;

	float reduccio = testInsereix(v);
	grade = grade + (4.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testElimina(v);
	grade = grade + (4.0 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testOperadorAssignacio();
	grade = grade + (2.0 - reduccio);


	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}