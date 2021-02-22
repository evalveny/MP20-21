#include <iostream>
#include "substring.h"

using namespace std;


int main()
{
	int posicio;
	char str[MAX_STRING];
	char subStr[MAX_STRING];

	cout << "Introdueix un string: ";
	cin.getline(str, MAX_STRING);
	cout << "Introdueix un possible substring: ";
	cin.getline(subStr, MAX_STRING);
	bool resultat = esSubString(str, subStr, posicio);
	if (resultat)
		cout << subStr << " SI es substring de " << str << " a la posicio " << posicio << endl;
	else
		cout << subStr << " NO es substring de " << str << endl;
}