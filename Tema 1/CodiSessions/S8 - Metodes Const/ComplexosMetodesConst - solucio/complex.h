#pragma once

class Complex
{
public:
	void setReal(float real) { m_real = real; }
	void setImg(float img) { m_img = img; }
	void llegeix();
	void mostra() const;
	float getReal() const { return m_real; }
	float getImg() const { return m_img; }
	Complex suma(const Complex &c) const;
	Complex resta(const Complex &c) const;
	Complex multiplica(const Complex &c) const;
private:
	float m_real, m_img;
};

