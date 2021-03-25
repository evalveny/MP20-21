#include "tauler.h"
#include <fstream>
using namespace std;

void Tauler::inicialitza(int tipusCaselles[], int nCaselles, const int& nJugadors)
{
	m_nCaselles = 0;
	for (int i = 0; i < nCaselles; i++)
	{
		m_caselles[m_nCaselles].setPosicio(i + 1);
		m_caselles[m_nCaselles].setTipus(tipusCaselles[i]);
		m_nCaselles++;
	}
	m_nJugadors = nJugadors;
	m_torn = 0;
}


void Tauler::tornJoc(int valorDau)
{
	bool esOca = false;
	bool calMantenirTorn = false;

	if (m_jugadors[m_torn].potTirar())
	{
		const int casellaActual = m_jugadors[m_torn].getPosicio();
		const int casellaDesti = casellaActual + valorDau;

		if (casellaDesti <= m_nCaselles)
		{
			esOca = m_caselles[casellaDesti - 1].executaAccio(m_jugadors[m_torn]);
			if (esOca)
			{
				bool ocaTrobada = false;
				for (int i = casellaDesti; i < m_nCaselles && !ocaTrobada; i++)
				{
					if (m_caselles[i].esOca())
					{
						ocaTrobada = true;
						calMantenirTorn = true;
						m_jugadors[m_torn].setPosicio(m_caselles[i].getPosicio());
					}
				}
			}

		}
	}
	else
		m_jugadors[m_torn].setTornsInactiu(m_jugadors[m_torn].getTornsInactiu() - 1);

	if (!calMantenirTorn)
	{
		m_torn++;
		if (m_torn >= m_nJugadors)
		{
			m_torn = 0;
		}
	}
}

void Tauler::getEstatJugador(int nJugador, int& posicio, bool& potTirar, int& nTornsInactiu, bool& guanyador)
{
	posicio = m_jugadors[nJugador - 1].getPosicio();
	potTirar = m_jugadors[nJugador - 1].potTirar();
	nTornsInactiu = m_jugadors[nJugador - 1].getTornsInactiu();
	guanyador = m_jugadors[nJugador - 1].esGuanyador();
}