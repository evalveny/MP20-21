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


int main()
{
	Complex numero1, numero2;
	Complex *pNumero1, *pNumero2;

	pNumero1 = &numero1;
	(*pNumero1).setReal(2.5);
	pNumero1->setImg(1.0);
	pNumero2 = pNumero1;
	pNumero1 = &numero2;
	pNumero1->setReal(pNumero2->getReal() * 2);
	pNumero1->setImg(numero1.getImg() * numero2.getReal());
	cout << "numero1: " << numero1 << endl;
	cout << "pNumero1: " << pNumero1 << endl;
	cout << "&numero1: " << &numero1 << endl;
	cout << "*pNumero1 " << *pNumero1 << endl;
	cout << "numero2: " << numero2 << endl;
	cout << "pNumero2: " << pNumero2 << endl;
	cout << "&numero2: " << &numero2 << endl;
	cout << "*pNumero1 " << *pNumero2 << endl;
	return 0;

	return 0;
}