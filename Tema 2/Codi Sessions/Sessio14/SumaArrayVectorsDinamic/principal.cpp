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
		v[i] = new int[nElements];
}

void alliberaVectors(int* v[])
{
	for (int i = 0; i < MAX; i++)
		delete[] v[i];
}

int main()
{
	int* v1[MAX];
	int* v2[MAX];
	int* vSuma[MAX];
	int nElements;

	cout << "Quants elements han de tenir els vectors ? ";
	cin >> nElements;

	creaVectors(v1, nElements);
	creaVectors(v2, nElements);
	creaVectors(vSuma, nElements);

	for (int i = 0; i < MAX; i++)
		llegeixVector(v1[i], nElements);
	for (int i = 0; i < MAX; i++)
		llegeixVector(v2[i], nElements);

	for (int i = 0; i < MAX; i++)
		sumaVectors(v1[i], v2[i], vSuma[i], nElements);	

	cout << "Suma dels vectors: ";
	for (int i = 0; i < MAX; i++)
		mostraVector(vSuma[i], nElements);

	alliberaVectors(v1);
	alliberaVectors(v2);
	alliberaVectors(vSuma);

	return 0;
}

