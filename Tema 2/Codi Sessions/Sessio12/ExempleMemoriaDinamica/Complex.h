#pragma once

class Complex
{
public:
	Complex() {};
	Complex(float real, float img) : m_real(real), m_img(img) {}
	void setReal(float real) { m_real = real; }
	void setImg(float img) { m_img = img; }
	float getReal() const { return m_real; }
	float getImg() const { return m_img; }
	Complex operator+(const Complex& c) { return Complex(m_real + c.m_real, m_img + c.m_img);  }
	Complex operator-(const Complex& c) { return Complex(m_real - c.m_real, m_img - c.m_img); }
private:
	float m_real;
	float m_img;
};
