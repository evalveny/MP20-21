#include "jugador.h"

void Jugador::setTornsInactiu(int nTorns)
{
	m_nTornsInactiu = nTorns;
	if (nTorns > 0)
		m_potTirar = false;
	else
		m_potTirar = true;
}

