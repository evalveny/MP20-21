#include "domino.h"

void inicialitzaFitxa(Fitxa& fitxa, int valor1, int valor2)
{
	fitxa.valor1 = valor1;
	fitxa.valor2 = valor2;
}

void valorsFitxa(Fitxa& fitxa, int& valor1, int& valor2)
{
	valor1 = fitxa.valor1;
	valor2 = fitxa.valor2;
}

int jugadorActual(Partida& partida)
{
	return partida.jugadorActual + 1;
}

int extremEsquerra(Partida& partida)
{
	return partida.valorEsq;
}

int extremDret(Partida& partida)
{
	return partida.valorDreta;
}

int nFitxesJugador(Jugador& jugador)
{
	return jugador.nFitxes;
}


void inicialitzaPartida(Partida& partida, Fitxa fitxesInicials[])
{
	int nFitxa = 0;
	for (int i = 0; i < MAX_JUGADORS; i++)
	{
		for (int j = 0; j < MAX_FITXES; j++)
			partida.jugadors[i].fitxes[j] = fitxesInicials[nFitxa++];
		partida.jugadors[i].nFitxes = MAX_FITXES;
	}
	partida.valorEsq = -1;
	partida.valorDreta = -1;
	partida.jugadorActual = 0;
	partida.nTornsPassant = 0;
}

bool coincideixValor(Fitxa& fitxa, int valor)
{
	return ((valor == -1) || (valor == fitxa.valor1) || (valor == fitxa.valor2));
}

void actualitzaPartida(Partida& partida, Fitxa& fitxa)
{
	if (fitxa.valor1 != -1)
	{
		if ((partida.valorDreta == -1) && (partida.valorEsq == -1))
		{
			partida.valorEsq = fitxa.valor1;
			partida.valorDreta = fitxa.valor2;
		}
		if (coincideixValor(fitxa, partida.valorEsq))
		{
			if (fitxa.valor1 == partida.valorEsq)
				partida.valorEsq = fitxa.valor2;
			else
				partida.valorEsq = fitxa.valor1;
		}
		else
		{
			if (fitxa.valor1 == partida.valorDreta)
				partida.valorDreta = fitxa.valor2;
			else
				partida.valorDreta = fitxa.valor1;
		}
	}
}

void seleccionaFitxa(Partida& partida, Fitxa& fitxa)
{
	bool potTirar = false;
	int pos = 0;
	Jugador& jugador = partida.jugadors[partida.jugadorActual];
	while (!potTirar && (pos < jugador.nFitxes))
	{
		if (coincideixValor(jugador.fitxes[pos], partida.valorEsq) ||
			coincideixValor(jugador.fitxes[pos], partida.valorDreta))
			potTirar = true;
		else
			pos++;
	}
	if (potTirar)
	{
		partida.nTornsPassant = 0;
		fitxa = jugador.fitxes[pos];
		for (int i = pos; i < jugador.nFitxes - 1; i++)
			jugador.fitxes[i] = jugador.fitxes[i + 1];
		jugador.nFitxes--;
	}
	else
	{
		fitxa.valor1 = -1;
		fitxa.valor2 = -1;
		partida.nTornsPassant++;
	}
}

int guanyador(Partida& p)
{
	if (p.jugadors[p.jugadorActual].nFitxes == 0)
		return (p.jugadorActual + 1);
	else return -1;
}

bool partidaBloquejada(Partida& p)
{
	return (p.nTornsPassant == MAX_JUGADORS);
}

void canviaTorn(Partida& p)
{
	p.jugadorActual = (p.jugadorActual + 1) % MAX_JUGADORS;
}

int jugaDomino(Fitxa fitxesInicials[MAX_FITXES], Fitxa fitxesJugades[MAX_FITXES], int& nFitxesJugades)
{
	nFitxesJugades = 0;
	int hiHaGuanyador = -1;
	bool bloquejada = false;
	Partida p;
	inicialitzaPartida(p, fitxesInicials);
	while ((hiHaGuanyador == -1) && (!bloquejada))
	{
		Fitxa f;
		seleccionaFitxa(p, f);
		fitxesJugades[nFitxesJugades++] = f;
		if (f.valor1 != -1)
		{
			actualitzaPartida(p, f);
			hiHaGuanyador = guanyador(p);
		}
		else
			bloquejada = partidaBloquejada(p);
		canviaTorn(p);
	}
	return hiHaGuanyador;
}