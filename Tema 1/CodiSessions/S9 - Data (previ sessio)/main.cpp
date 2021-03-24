#include "Data.h"
#include <iostream>
using namespace std;


int main()
{
	Data data1;
	data1.llegeix();
	Data data2;
	data2.llegeix();

	if (data1 < data2)
		cout << "Data 1 mes petita" << endl;
	else
		cout << "Data 2 mes petita" << endl;

	return 0;
}