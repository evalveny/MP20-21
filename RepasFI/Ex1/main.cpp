﻿/*

Test set:
5
9
7
###
1
2
3
###
9
5
6
*/

#include <iostream>

using namespace std;

void ordena (int& num1, int& num2, int& num3)
{
    int temp;

	if(num2 > num3)
	{
		temp = num2;
		num2 = num3;
		num3 = temp;
	}
	if(num1 > num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	if(num2 > num3){
		temp = num2;
		num2 = num3;
		num3 = temp;
	}

}


int main()
{
	int num1, num2, num3, temp;

    cout << "Introdueix tres numeros: ";
	cin >> num1;
	cin >> num2;
	cin >> num3;
	ordena(num1,num2,num3);
	cout << "Els numeros ordenats son: " << num1 << endl << num2 << endl << num3 << endl;
	return 0;
}
