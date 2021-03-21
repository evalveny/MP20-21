#pragma once

class Complex
{
public:
	void setReal(float real) { m_real = real; }
	void setImg(float img) { m_img = img; }
	void llegeix() const;
	void mostra() const;
	float getReal() const { return m_real; }
	float getImg() const { return m_img; }
	Complex suma(Complex &c);
	Complex resta(Complex &c);
	Complex multiplica(Complex &c);
private:
	float m_real, m_img;
};

