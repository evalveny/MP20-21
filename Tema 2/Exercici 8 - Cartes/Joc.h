#pragma once
#include "Carta.h"
#include "Jugador.h"
#include "Moviment.h"
#include <stack>
#include <vector>
#include <queue>



const int N_CARTES_JUGADOR = 7;

class Joc
{
public:
	Joc(): m_torn(-1), m_sentitTorn(1), m_nJugadors(0) {};
	~Joc() {};

	void inicialitza(const string& nomFitxer, int nJugadors);
	void fesMoviment();
	bool final();
	void guarda(const string& nomFitxer);
private:
	vector<Jugador> m_jugadors;
	stack<Carta> m_cartesJugades;
	stack<Carta> m_cartesBaralla;
	queue<Moviment> m_moviments;
	int m_nJugadors;
	int m_torn;
	int m_sentitTorn;
	
	void canviTorn();
	bool agafaCarta(Carta& carta, bool guardaMoviment);
	void tiraCarta();
};

