#ifndef RECTA_H
#define RECTA_H
#include "Punt.h"

class Recta
{
public:
	void setA(float a) { m_a = a; }
	void setB(float b) { m_b = b; }
	void setC(float c) { m_c = c; }
	float getA() { return m_a; }
	float getB() { return m_b; }
	float getC() { return m_c; }
	bool interseccio(Recta& r, Punt& pt);
	float distancia(Punt &pt);
private:
	float m_a;
	float m_b;
	float m_c;
};

#endif