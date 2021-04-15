#include <iostream>
using namespace std;

void intercanvia(int* p_x, int* p_y)
{
	int tmp;

	tmp = *p_x;
	*p_x = *p_y;
	*p_y = tmp;
}

void ordena(int* primer, int* segon, int* tercer)
{
	if (*primer > *tercer)
		intercanvia(primer, tercer);
	if (*segon > *tercer)
		intercanvia(segon, tercer);
	if (*primer > *segon)
		intercanvia(primer, segon);
}


int main()
{
	int x, y, z;

	cin >> x >> y >> z;
	ordena(&x, &y, &z);
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;

	return 0;
}
