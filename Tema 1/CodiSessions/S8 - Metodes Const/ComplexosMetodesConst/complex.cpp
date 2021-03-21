#include "complex.h"
#include <iostream>
using namespace std;

void Complex::llegeix() const
{
	cin >> m_real;
	cin >> m_img;
}

void Complex::mostra() const
{
	cout << m_real << "+" << m_img << "i";
}

Complex Complex::suma(Complex &c)
{
	Complex resultat;

	resultat.m_real = m_real + c.m_real;
	resultat.m_img = m_img + c.m_img;
	return resultat;
}

Complex Complex::resta(Complex &c) 
{
	Complex resultat;

	resultat.m_real = m_real - c.m_real;
	resultat.m_img = m_img - c.m_img;
	return resultat;
}

Complex Complex::multiplica(Complex &c)
{
	Complex resultat;

	resultat.m_real = (m_real*c.m_real) - (m_img*c.m_img);
	resultat.m_img = (m_real*c.m_img) + (m_img*c.m_real);
	return resultat;
}