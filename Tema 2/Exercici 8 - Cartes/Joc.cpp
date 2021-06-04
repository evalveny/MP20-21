#include "Joc.h"
#include <fstream>
using namespace std;

void Joc::inicialitza(const string& nomFitxer, int nJugadors)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		int color, valor;
		fitxer >> color >> valor;
		while (!fitxer.eof())
		{
			Carta carta(color, valor);
			m_cartesBaralla.push(carta);
			fitxer >> color >> valor;
		}
		fitxer.close();
		for (int i = 0; i < nJugadors; i++)
		{
			Jugador jugador;
			for (int j = 0; j < N_CARTES_JUGADOR; j++)
			{	
				Carta carta;
				agafaCarta(carta, false);
				jugador.afegeixCarta(carta);
			}
			m_jugadors.push_back(jugador);
			m_nJugadors++;
		}
		Carta primeraCarta;
		agafaCarta(primeraCarta, false);
		m_cartesJugades.push(primeraCarta);
		m_torn = 0;
	}
}

bool Joc::agafaCarta(Carta& carta, bool guardaMoviment)
{
	bool resultat = false;
	if (!m_cartesBaralla.empty())
	{
		resultat = true;
		carta = m_cartesBaralla.top();
		m_cartesBaralla.pop();
		if (guardaMoviment)
		{
			Moviment m(m_torn, ROBA_CARTA, carta);
			m_moviments.push(m);
		}
	}
	return resultat;
}

void Joc::fesMoviment()
{
	Carta carta = m_cartesJugades.top();
	Carta cartaRobar;
	switch (carta.getValor())
	{
	case CANVI_TORN:
		m_sentitTorn = -m_sentitTorn;
		canviTorn();
		canviTorn();
		break;
	case SALTA_TORN:
		canviTorn();
		break;
	case ROBA_DOS:
		if (agafaCarta(cartaRobar, true))
		{
			m_jugadors[m_torn].afegeixCarta(cartaRobar);
			if (agafaCarta(cartaRobar, true))
			{
				m_jugadors[m_torn].afegeixCarta(cartaRobar);
			}
		}
		break;
	}
	tiraCarta();
	canviTorn();
}

void Joc::tiraCarta()
{
	bool potRobar = true;
	bool potTirar = false;
	Carta cartaATirar;
	do
	{
		potTirar = m_jugadors[m_torn].tiraCarta(m_cartesJugades.top(), cartaATirar);
		if (!potTirar)
		{
			Carta cartaARobar;
			potRobar = agafaCarta(cartaARobar, true);
			if (potRobar)
			{
				m_jugadors[m_torn].afegeixCarta(cartaARobar);
			}
		}
	} while ((!potTirar) && (potRobar));
	if (potTirar)
	{
		Moviment m(m_torn, TIRA_CARTA, cartaATirar);
		m_moviments.push(m);
		m_cartesJugades.push(cartaATirar);
	}
}

bool Joc::final()
{
	bool finalPartida = false;
	int i = 0;
	while (!finalPartida && (i < m_nJugadors))
	{
		if (m_jugadors[i].getNCartes() == 0)
			finalPartida = true;
		else
			i++;
	}
	if (!finalPartida)
	{
		finalPartida = true;
		i = 0;
		while (finalPartida && (i < m_nJugadors))
		{
			if (m_jugadors[i].potTirar())
				finalPartida = false;
			else
				i++;
		}
	}
	return finalPartida;
}

void Joc::guarda(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		while (!m_moviments.empty())
		{
			Moviment m = m_moviments.front();
			Carta c = m.getCarta();
			fitxer << m.getJugador() << " " << m.getAccio() << " " << c.getColor() << " " << c.getValor() << endl;
			m_moviments.pop();
		}
		fitxer.close();
	}
}

void Joc::canviTorn()
{
	m_torn += m_sentitTorn;
	if (m_torn < 0)
		m_torn = m_nJugadors - 1;
	if (m_torn >= m_nJugadors)
		m_torn = 0;
}
