#pragma once
#include "casella.h"
#include <string>
using namespace std;

const int NUMERO_CASELLES = 63;
const int NUMERO_JUGADORS = 4;
class Tauler
{
public:
	Tauler() : m_nCaselles(0), m_nJugadors(0) {}
	void inicialitza(int tipusCaselles[], int nCaselles, const int& nJugadors);
	void tornJoc(int valorDau);
	int getTipusCasella(int nCasella) const { return m_caselles[nCasella - 1].getTipus(); }
	void getEstatJugador(int nJugador, int& posicio, bool& potTirar, int& nTornsInactiu, bool& guanyador);
private:
	Casella m_caselles[NUMERO_CASELLES];
	int 	m_nCaselles;
	Jugador m_jugadors[NUMERO_JUGADORS];
	int 	m_nJugadors;

	int m_torn;
};