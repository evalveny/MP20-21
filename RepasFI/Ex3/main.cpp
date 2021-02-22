/*
Test set:
3
###
6
###
1
###
*/

#include <iostream>

using namespace std;

int main()
{
	int maxim, suma;

	cin >> maxim;
	cout << "#";
	for(int i = 1; i <= maxim; i++)
	{
		suma = 0;
		for(int j = 1; j < i; j++)
		{
			cout << j << "+";
			suma += j;
		}
		cout << i << "=" << (i + suma) << "#";
	}
	return 0;
}

