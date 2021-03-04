#include "poligon.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	Poligon pol;

	llegeixPoligon(pol);
	mostraPoligon(pol);
	cout << calculaPerimetre(pol);

}