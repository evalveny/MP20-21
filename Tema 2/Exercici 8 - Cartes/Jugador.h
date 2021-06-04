#pragma once

#include "Carta.h"
#include <list>
using namespace std;

class Jugador
{
public:
	Jugador(): m_haPogutTirar(true) {}
	~Jugador() {}

	void afegeixCarta(const Carta& carta);
	bool tiraCarta(const Carta& cartaPila, Carta& cartaATirar);
	int getNCartes() const { return m_cartes.size(); }
	bool potTirar() const { return m_haPogutTirar; }
private:
	list<Carta> m_cartes;
	bool m_haPogutTirar;

	bool comprovaCarta(const Carta& carta, Carta& cartaATirar);
};