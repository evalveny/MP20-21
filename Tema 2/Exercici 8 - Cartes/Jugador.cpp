#include "Jugador.h"

void Jugador::afegeixCarta(const Carta& carta)
{
	m_cartes.push_back(carta);
}


bool Jugador::comprovaCarta(const Carta& carta, Carta& cartaATirar)
{
	list<Carta>::iterator aux = m_cartes.begin();
	list<Carta>::iterator itCartaSeleccionada = m_cartes.end();
	cartaATirar = carta;
	bool trobat = false;
	while (aux != m_cartes.end())
	{
		if (((aux->getColor() == carta.getColor()) || (carta.getColor() == -1)) &&
			((aux->getValor() == carta.getValor()) || (carta.getValor() == -1)))
		{
			trobat = true;
			m_haPogutTirar = true;
			if (carta.getValor() == -1)
			{
				if ((itCartaSeleccionada == m_cartes.end()) || (aux->getValor() < cartaATirar.getValor()))
				{
					cartaATirar = *aux;
					itCartaSeleccionada = aux;
				}
			}
			else
				if (carta.getColor() == -1)
				{
					if ((itCartaSeleccionada == m_cartes.end()) || (aux->getColor() < cartaATirar.getColor()))
					{
						cartaATirar = *aux;
						itCartaSeleccionada = aux;
					}
				}
				else
				{
					cartaATirar = *aux;
					itCartaSeleccionada = aux;
				}
		}
		aux++;
	}
	if (trobat)
		m_cartes.erase(itCartaSeleccionada);
	return trobat;
}

bool Jugador::tiraCarta(const Carta& cartaPila, Carta& cartaATirar)
{
	m_haPogutTirar = false;
	Carta carta;
	carta.setColor(cartaPila.getColor());
	carta.setValor(ROBA_DOS);
	bool potTirar = comprovaCarta(carta, cartaATirar);
	if (!potTirar)
	{
		carta.setValor(CANVI_TORN);
		potTirar = comprovaCarta(carta, cartaATirar);
		if (!potTirar)
		{
			carta.setValor(SALTA_TORN);
			potTirar = comprovaCarta(carta, cartaATirar);
			if (!potTirar)
			{
				carta.setValor(-1);
				potTirar = comprovaCarta(carta, cartaATirar);
				if (!potTirar)
				{
					carta.setColor(-1);
					carta.setValor(cartaPila.getValor());
					potTirar = comprovaCarta(carta, cartaATirar);
				}
			}
		}
	}
	return m_haPogutTirar;
}