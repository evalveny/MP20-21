#ifndef DOMINO_H
#define DOMINO_H

const int MAX_FITXES = 7;
const int MAX_JUGADORS = 4;


typedef struct
{
	int valor1;
	int valor2;
} Fitxa;

typedef struct
{
	Fitxa fitxes[MAX_FITXES];
	int nFitxes;
} Jugador;

typedef struct
{
	int valorEsq, valorDreta;
	int jugadorActual;
	Jugador jugadors[MAX_JUGADORS];
	int nTornsPassant;
} Partida;

void inicialitzaFitxa(Fitxa& fitxa, int valor1, int valor2);
void valorsFitxa(Fitxa& fitxa, int& valor1, int& valor2);
int jugadorActual(Partida& partida);
int extremEsquerra(Partida& partida);
int extremDret(Partida& partida);
int nFitxesJugador(Jugador& jugador);
void inicialitzaPartida(Partida& partida, Fitxa fitxesInicials[]);
void seleccionaFitxa(Partida& partida, Fitxa& fitxa);
void actualitzaPartida(Partida& partida, Fitxa& fitxa);
void canviaTorn(Partida& p);
bool partidaBloquejada(Partida& p);
int guanyador(Partida& p);
int jugaDomino(Fitxa fitxesInicials[MAX_FITXES * MAX_JUGADORS], Fitxa fitxesJugades[MAX_FITXES * MAX_JUGADORS * 2], int& nFitxesJugades);

#endif

