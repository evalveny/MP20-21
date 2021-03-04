#pragma once

class Complex
{
public:
	Complex() { m_real = 0; m_img = 0; }
	float getReal(); //TO VALIDATE TEST
	float getImg(); //TO VALIDATE TEST
	void setReal(float pReal); //TO VALIDATE TEST
	void setImg(float PImg); //TO VALIDATE TEST
	void mostra() const;
	Complex suma(const Complex &c) const;
	Complex resta(const Complex &c) const;
	Complex multiplica(const Complex &c) const;
	Complex avaluaOperacio(const char operacio, const Complex& c2) const;
	
	float m_real, m_img;
};
