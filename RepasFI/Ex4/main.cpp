/*
Test set:
4
###
10
###
12
###
*/

#include <iostream>

using namespace std;

int main()
{
	int maxim, num1, num2, suma, i;

    cout << "Introdueix fins quin numero de fibonacci vols:" <<endl;
	cin >> maxim;
	num1 = 1;
	num2 = 1;
	cout << "F(0)=1" <<endl << "F(1)=1" << endl;
	for(i = 2; i < maxim; i++)
	{
		suma = num1 + num2;
		cout << "F(" <<i <<")=" <<suma << endl;
		num1 = num2;
		num2 = suma;
	}
	return 0;
}
