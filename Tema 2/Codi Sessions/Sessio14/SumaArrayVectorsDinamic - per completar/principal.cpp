#include <iostream>
using namespace std;

const int MAX = 3;

void sumaVectors(int* p1, int* p2, int* pSuma, int nElements)
{
	for (int i = 0; i < nElements; i++)
		pSuma[i] = p1[i] + p2[i];
}

void llegeixVector(int *v, int nElements)
{
	for (int i = 0; i < nElements; i++)
	{
		cout << "Introdueix valor " <<
			i + 1 << " del vector: ";
		cin >> v[i];
	}
}


void mostraVector(int* v, int nElements)
{
	for (int i = 0; i < nElements; i++)
		cout << v[i] << " ";
	cout << endl;
}

void creaVectors(int* v[], int nElements)
{
	for (int i = 0; i < MAX; i++)
		// PER COMPLETAR
}

void alliberaVectors(int* v[])
{
	for (int i = 0; i < MAX; i++)
		// PER COMPLETAR
}

int main()
{
	int* v1[MAX];
	int* v2[MAX];
	int* vSuma[MAX];
	int nElements;

	cout << "Quants elements han de tenir els vectors ? ";
	cin >> nElements;

	// CREACIO DELS VECTORS DINAMICS
	creaVectors(v1, nElements);
	creaVectors(v2, nElements);
	creaVectors(vSuma, nElements);

	// LLEGEIX VALORS PER V1 I V2
	for (int i = 0; i < MAX; i++)
		// PER COMPLETAR
	for (int i = 0; i < MAX; i++)
		// PER COMPLETAR

	// CALCULA LA SUMA
	for (int i = 0; i < MAX; i++)
		// PER COMPLETAR	

	cout << "Suma dels vectors: ";
	for (int i = 0; i < MAX; i++)
		mostraVector(vSuma[i], nElements);

	// ALLIBERA VECTORS DINAMICS
	alliberaVectors(v1);
	alliberaVectors(v2);
	alliberaVectors(vSuma);

	return 0;
}

