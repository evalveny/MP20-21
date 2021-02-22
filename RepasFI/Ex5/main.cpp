/*
Test set:
10
###
50
###
500
###
*/

#include <iostream>
#include <math.h>

using namespace std;

bool esPerfecte(int num)
{
	bool perfecte = false;
	int suma = 0;
	int j;

    //for(j = num /2 ; j > 0; j--)
    for(j = sqrt(num); j > 1; j--)
	{
		if(num % j == 0)
		{
			suma = suma + j + (num / j);
		//	if (num == 6) cout << "j:" << j <<"suma:" << suma <<"\n";
			//suma += j;
		}
	}
    suma +=1;
	//if (num == 6) cout << "res final:" << suma <<"\n";

	if(suma == num)
	{
		perfecte = true;
	}
	return perfecte;
}

int main()
{
	int maxim, i, j, suma;

    cout << "Introdueix un numero:" <<endl;
	cin >> maxim;
	cout << "Els numeros perfectes menors son:"<<endl;//1500
	
	for(i = 2; i <= maxim; i++)
	{
		if(esPerfecte(i))
		{
			cout << i << endl;
		}
	}
	return 0;
}
