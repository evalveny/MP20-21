#include <iostream>
using namespace std;

int **creaMatriu(int nFiles, int nColumnes)
{
	int **m;

	m = new int*[nFiles];
	for (int i = 0; i < nFiles; i++)
		m[i] = new int[nColumnes];
	return m;
}

void destrueixMatriu(int **m, int nFiles)
{
	for (int i = 0; i < nFiles; i++)
		delete[] m[i];
	delete[] m;
}

void llegeixMatriu(int **m, int nFiles, int nColumnes)
{
	for (int i = 0; i < nFiles; i++)
		for (int j = 0; j < nColumnes; j++)
		{
			cout << "Introdueix valor " << i + 1
				<< " " << j + 1 << " de la matriu: ";
			cin >> m[i][j];
		}
}

void sumaMatrius(int **m1, int **m2, int **suma, int nFiles, int nColumnes)
{
	for (int i = 0; i < nFiles; i++)
		for (int j = 0; j < nColumnes; j++)
			suma[i][j] = m1[i][j] + m2[i][j];
}

void main()
{
	int **m1, **m2, **suma;
	int nFiles, nColumnes;

	cout << "Files i columnes de les matrius: ";
	cin >> nFiles >> nColumnes;

	m1 = creaMatriu(nFiles, nColumnes);
	m2 = creaMatriu(nFiles, nColumnes);
	suma = creaMatriu(nFiles, nColumnes);
	
	llegeixMatriu(m1, nFiles, nColumnes);
	llegeixMatriu(m2, nFiles, nColumnes);
	
	sumaMatrius(m1, m2, suma, nFiles, nColumnes);
	
	cout << "Suma de les matrius: ";
	for (int i = 0; i < nFiles; i++)
	{
		for (int j = 0; j < nColumnes; j++)
			cout << suma[i][j] << " ";
		cout << "\n";
	}
	
	destrueixMatriu(m1, nFiles);
	destrueixMatriu(m2, nFiles);
	destrueixMatriu(suma, nFiles);
}
