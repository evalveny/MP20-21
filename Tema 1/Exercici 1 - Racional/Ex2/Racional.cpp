
#include "Racional.h"

int NombreRacional::maximComuDivisor()
{
	int n1 = m_numerador;
	int n2 = m_denominador;
	int tmp;
	if (n2 > n1)
	{
		tmp = n2;
		n2 = n1;
		n1 = tmp;
	}
	while (n2 != 0)
	{
		tmp = n2;
		n2 = n1 % n2;
		n1 = tmp;
	}
	return n1;
}

void NombreRacional::simplifica()
{
	int mcd = maximComuDivisor();

	m_numerador /= mcd;
	m_denominador /= mcd;
}


void NombreRacional::setNumerador(int numerador)
{
	m_numerador = numerador;
}

void NombreRacional::setDenominador(int denominador)
{
	m_denominador = denominador;
}

int NombreRacional::getNumerador() const
{
	return m_numerador;
}

int NombreRacional::getDenominador() const
{
	return m_denominador;
}

bool NombreRacional::esValid() const
{
	return (m_denominador != 0);
}

NombreRacional NombreRacional::suma(const NombreRacional b) const
{
	NombreRacional resultat;
	resultat.m_numerador = (m_numerador * b.m_denominador) + (m_denominador * b.m_numerador);
	resultat.m_denominador = m_denominador * b.m_denominador;
	resultat.simplifica();
	return resultat;
}

NombreRacional NombreRacional::multiplica(const NombreRacional b) const
{
	NombreRacional resultat;
	resultat.m_numerador = m_numerador * b.m_numerador;
	resultat.m_denominador = m_denominador * b.m_denominador;
	resultat.simplifica();
	return resultat;
}

NombreRacional NombreRacional::resta(const NombreRacional b) const
{
	NombreRacional resultat;
	resultat.m_numerador = (m_numerador * b.m_denominador) - (m_denominador * b.m_numerador);
	resultat.m_denominador = m_denominador * b.m_denominador;
	resultat.simplifica();
	return resultat;
}

NombreRacional NombreRacional::divideix(const NombreRacional b) const
{
	NombreRacional resultat;
	resultat.m_numerador = m_numerador * b.m_denominador;
	resultat.m_denominador = m_denominador * b.m_numerador;
	resultat.simplifica();
	return resultat;
}

