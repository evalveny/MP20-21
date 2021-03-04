#include "complex.h"
#include <iostream>
using namespace std;

void Complex::setReal(float pReal)
{
	m_real=pReal;
}

void Complex::setImg(float pImg)
{
	m_img=pImg;
}

float Complex::getReal()
{
	return m_real;
}

float Complex::getImg()
{
	return m_img;
}

void Complex::mostra() const
{
	cout << m_real << "+" << m_img << "i";
}

Complex Complex::avaluaOperacio(const char operacio, const Complex& c2) const
{
	Complex resultat;

	switch (operacio)
	{
	case '1':
		resultat = suma(c2);
		break;
	case '2':
		resultat = resta(c2);
		break;
	case '3':
		resultat = multiplica(c2);
		break;
	}
	return resultat;
};

Complex Complex::suma(const Complex &c) const
{
	Complex resultat;

	resultat.m_real = m_real + c.m_real;
	resultat.m_img = m_img + c.m_img;
	return resultat;
}

Complex Complex::resta(const Complex &c) const
{
	Complex resultat;

	resultat.m_real = m_real - c.m_real;
	resultat.m_img = m_img - c.m_img;
	return resultat;
}

Complex Complex::multiplica(const Complex &c) const
{
	Complex resultat;

	resultat.m_real = (m_real*c.m_real) - (m_img*c.m_img);
	resultat.m_img = (m_real*c.m_img) + (m_img*c.m_real);
	return resultat;
}