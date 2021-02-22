#include <iostream>

using namespace std;

float potencia(float x, int n)
{
	float resultat = 1; 

	if (n < 0)
	{
		n = -n; 
		x = 1 / x;
	}
	resultat = 1;
	for (int i = 1; i <= n; i++)
		resultat *= x;

	return resultat;
}

int main()
{
	int n;
	float x;

	cout << "Introdueix un numero: ";
	cin >> x;
	cout << "Introdueix exponent: ";
	cin >> n;
	float resultat = potencia(x, n);
	cout << "El resultat es " << resultat << endl;
}