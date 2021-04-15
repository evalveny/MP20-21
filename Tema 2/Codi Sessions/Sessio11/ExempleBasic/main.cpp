#include <iostream>
using namespace std;

int main()
{
	int x, y;
	int *p, *q;

	x = 5;
	y = 0;

	p = &x;
	q = p;
	y = *p;
	*p = 10;
	p = &y;
	*p = *q + 2;
//	q = nullptr;

	cout << "x: " << x << ", &x: " << &x << endl;
	cout <<	"y: " << y << ", &y: " << &y << endl; 
	cout << "*p: " << *p << ", p: " << p << endl;
	cout << "*q: " << *q << ", q: " << q << endl;
	return 0;

}