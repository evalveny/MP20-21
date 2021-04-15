#include <iostream>
using namespace std;

class Complex
{
public:
	void setReal(float real) { m_real = real; }
	void setImg(float img) { m_img = img; }
	float getReal() const { return m_real; }
	float getImg() const { return m_img; }
private:
	float m_real;
	float m_img;
};

ostream& operator<<(ostream& out, const Complex& c)
{
	out << c.getReal() << " + " << c.getImg() << "i";
	return out;
}

Complex llegeixComplex()
{
	Complex c;
	float real, img;

	cout << "Introdueix part real: ";
	cin >> real;
	c.setReal(real);
	cout << "Introdueix part imaginaria: ";
	cin >> img;
	c.setImg(img);
	return c;
}


/*Complex* llegeixComplex()
{
	Complex c;
	float real, img;

	cout << "Introdueix part real: ";
	cin >> real;
	c.setReal(real);
	cout << "Introdueix part imaginaria: ";
	cin >> img;
	c.setImg(img);
	Complex* p = &c;
	return p;
}*/

int main()
{
	Complex c1 = llegeixComplex();

	cout << "c1: " << c1 << endl;

	int* p;

	p = &c1;
	p->setReal(c1.getReal() * 2);
	p->setImg(c1.getImg() * 2);

	cout << "c1: " << c1 << endl;
	cout << "* p: " << *p << endl;
}

/*int main()
{
	Complex c1 = llegeixComplex();

	cout << "c1: " << c1 << endl;

	Complex* p;

	p->setReal(c1.getReal() * 2);
	p->setImg(c1.getImg() * 2);

	cout << "c1: " << c1 << endl;
	cout << "* p: " << *p << endl;
}*/

/*int main()
{
	Complex* c1 = llegeixComplex();

	cout << "c1: " << c1 << endl;

	Complex* p = c1;

	p->setReal(c1->getReal() * 2);
	p->setImg(c1->getImg() * 2);

	cout << "c1: " << *c1 << endl;
	cout << "* p: " << *p << endl;
}*/

/*int main()
{
	Complex c1 = llegeixComplex();
	Complex c2 = llegeixComplex();

	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;

	Complex tmp;
	Complex* p_c1 = &c1;
	Complex* p_c2 = &c2;
	Complex* p_tmp = &tmp;

	*p_tmp = *p_c1;
	p_c1 = p_c2;
	*p_c2 = *p_tmp;

	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
}*/
