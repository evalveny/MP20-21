#include <iostream>
using namespace std;
#include "Complex.h"


ostream& operator<<(ostream& out, const Complex& c)
{
	out << c.getReal() << " + " << c.getImg() << "i";
	return out;
}

Complex *llegeixComplex()
{
	Complex *c = new Complex;
	float real, img;

	cout << "Introdueix part real: ";
	cin >> real;
	c->setReal(real);
	cout << "Introdueix part imaginaria: ";
	cin >> img;
	c->setImg(img);
	return c;
}


int main()
{
	Complex *c1 = llegeixComplex();
	Complex *c2 = llegeixComplex();

	cout << "Suma: " << *c1 + *c2 << endl;

	delete c1;
	delete c2;
	return 0;

}
