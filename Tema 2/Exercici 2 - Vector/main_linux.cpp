#include "Vector.h"
#include <iostream>
#include "memcount.hpp"
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

	Punt valors[MAX_PROVES] = { { 0, 0 },{ 9,9 },{ 8,8 },{ 7,7 },{ 6,6 },{ 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 },{ 12,12 },{ 11,11 },{ 10,10 },{ 0, 0 },{ 0, 0 } };
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
	Punt contingutEsperat[N_ELEMENTS_FINAL] = { { 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 },{ 6,6 },{ 7,7 },{ 8,8 },{ 9,9 },{ 10,10 },{ 11,11 },{ 12,12 } };
	cout << "Comment :=>> Contingut final del vector esperat: " << endl;
	mostraArray(contingutEsperat, N_ELEMENTS_FINAL);
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
	int maxElementsEsperat[MAX_PROVES] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 10, 10, 10, 5, 5 };


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


float testAcces()
{
	float reduccio = 0.0;

	const int N_ELEMENTS = 12;
	const int MAX_PROVES = 5;

	Punt valors[N_ELEMENTS] = { { 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 },{ 6,6 },{ 7,7 },{ 8,8 },{ 9,9 },{ 10,10 },{ 11,11 },{ 12,12 } };


	int posicio[MAX_PROVES] = { 0, 11, 5, -1, 12 };
	Punt resultatEsperat[MAX_PROVES] = { { 1,1 },{ 12, 12 },{ 6, 6 },{ 0,0 },{ 0,0 } };

	Vector v;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de l'operador d'acces al vector []" << endl;
	cout << "Comment :=>> =================================================" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant el vector amb valors:" << endl;
	mostraArray(valors, N_ELEMENTS);
	for (int i = 0; i < N_ELEMENTS; i++)
		v.insereix(valors[i], i);
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	for (int i = 0; i < MAX_PROVES; i++)
	{
		cout << "Comment :=>> Accedint al valor de la posicio:  " << posicio[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatEsperat[i] << endl;
		Punt resultat = v[posicio[i]];
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		if (resultat == resultatEsperat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 0.5;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	const int MAX_PROVES_MODIFICAR = 3;
	int posicioModificar[MAX_PROVES_MODIFICAR] = { 0, 11, 5 };
	Punt valorModificar[MAX_PROVES_MODIFICAR] = { { 13,13 },{ 14, 14 },{ 15, 15 } };

	for (int i = 0; i < MAX_PROVES_MODIFICAR; i++)
	{
		cout << "Comment :=>> Modificant amb l'operador [] el valor de la posicio:  " << posicioModificar[i] << endl;
		cout << "Comment :=>> Nou valor:  " << valorModificar[i] << endl;
		v[posicioModificar[i]] = valorModificar[i];
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	const int N_ELEMENTS_FINAL = 12;
	Punt contingutEsperat[N_ELEMENTS_FINAL] = { { 13,13 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 },{ 15,15 },{ 7,7 },{ 8,8 },{ 9,9 },{ 10,10 },{ 11,11 },{ 14,14 } };
	cout << "Comment :=>> Contingut final del vector esperat: " << endl;
	mostraArray(contingutEsperat, N_ELEMENTS_FINAL);
	cout << "Comment :=>> Contingut final del vector obtingut: " << endl;
	mostraVector(v, N_ELEMENTS_FINAL);
	if (comparaVector(v, contingutEsperat, N_ELEMENTS_FINAL))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	if (reduccio > 5.0)
		reduccio = 5.0;
	return reduccio;
}


float testConstructorCopia()
{
	float reduccio = 0.0;

	Vector vOriginal;

	const int N_ELEMENTS = 12;
	Punt valors[N_ELEMENTS] = { { 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 },{ 6,6 },{ 7,7 },{ 8,8 },{ 9,9 },{ 10,10 },{ 11,11 },{ 12,12 } };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del constructor de copia" << endl;
	cout << "Comment :=>> ======================================" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant el vector original amb valors:" << endl;
	mostraArray(valors, N_ELEMENTS);
	for (int i = 0; i < N_ELEMENTS; i++)
		vOriginal.insereix(valors[i], i);
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	cout << "Comment :=>> Inicialitzant el vector copia amb el constructor de copia:" << endl;
	Vector vResultat(vOriginal);
	cout << "Comment :=>> -----------------------------------------------" << endl;

	cout << "Comment :=>> Contingut final del vector esperat: " << endl;
	mostraArray(valors, N_ELEMENTS);
	cout << "Comment :=>> Contingut final del vector copia: " << endl;
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

float testMemoria()
{
	float reduccio = 0.0;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de creacio/destruccio de memoria" << endl;
	cout << "Comment :=>> ==============================================" << endl;
	cout << "Comment :=>>" << endl;

	Vector v;
	Punt p(1, 1);

	int memoriaInicial = mem_total() * 1024;
	cout << "Comment :=>> Memoria inicial (Kbs): " << memoriaInicial / 1024 << endl;

	cout << "Comment :=>> Afegint 100.000 punts... " << endl;
	for (int i = 0; i < 100000; i++)
		v.insereix(p, i);
	int memoriaAfegir = mem_total() * 1024;
	cout << "Comment :=>> Memoria despres afegir punts (Kbs): " << memoriaAfegir / 1024 << endl;

	if (memoriaAfegir < (memoriaInicial + (90000 * sizeof(Punt))))
	{
		cout << "Comment :=>> ERROR. Memoria ocupada inferior a l'esperada" << endl;
		reduccio += 2.5;
	}
	else
		if (memoriaAfegir > (memoriaInicial + (200000 * sizeof(Punt))))
		{
			cout << "Comment :=>> ERROR. Memoria ocupada superior a l'esperada" << endl;
			reduccio += 2.5;
		}
		else cout << "Comment :=>> CORRECTE" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	cout << "Comment :=>> Eliminant els 100.000 punts... " << endl;
	for (int i = 99999; i >= 0; i--)
		v.elimina(i);
	int memoriaEliminar = mem_total() * 1024;
	cout << "Comment :=>> Memoria despres eliminar punts (Kbs): " << memoriaEliminar / 1024 << endl;

	if (memoriaEliminar > (memoriaInicial + 150000 * sizeof(Punt)))
	{
		cout << "Comment :=>> ERROR. Memoria ocupada superior a l'esperada" << endl;
		reduccio += 2.5;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	if (reduccio > 5.0)
		reduccio = 5.0;

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
	grade = grade + (2.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testElimina(v);
	grade = grade + (2.5 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testAcces();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testConstructorCopia();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testOperadorAssignacio();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;
	reduccio = testMemoria();
	grade = grade + (2 - reduccio);


	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}