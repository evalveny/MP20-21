#pragma once
#include "jugador.h"

const int NORMAL = 1;
const int OCA = 2;
const int POU = 3;
const int MORT = 4;
const int FINAL = 5;

class Casella
{
public:
	Casella() : m_posicio(0), m_tipus(NORMAL) {}
	void setPosicio(int posicio) { m_posicio = posicio; }
	void setTipus(int tipus) { m_tipus = tipus; }
	int getPosicio() const { return m_posicio; }
	int getTipus() const { return m_tipus; }
	bool esOca() const { return (m_tipus == OCA); }
	bool executaAccio(Jugador& j);
private:
	int m_posicio;
	int m_tipus;
};