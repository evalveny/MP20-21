#include "Recta.h"
#include <cmath>

float Recta::distancia(Punt &pt)
{
	return abs(m_a * pt.getX() + m_b * pt.getY() + m_c) / sqrt((m_a * m_a) + (m_b * m_b));
}

bool Recta::interseccio(Recta &r, Punt& pt)
{
	bool interseccio = true;
	float denominador = (r.m_b * m_a) - (m_b * r.m_a);
	if (abs(denominador) < 0.0001)
		interseccio = false;
	else
	{
		pt.setX(((m_b * r.m_c) - (r.m_b * m_c)) / denominador);
		pt.setY(((r.m_a * m_c) - (m_a * r.m_c)) / denominador);
	}
	return interseccio;
}

