#pragma once

class Jugador
{
public:
	Jugador() : m_casella(1), m_potTirar(true), m_nTornsInactiu(0),
		m_guanyador(false) {}
	void setPosicio(int casella) { m_casella = casella; }
	void guanya() { m_guanyador = true; }
	void setTornsInactiu(int nTorns);
	int getPosicio() const { return m_casella; }
	bool esGuanyador() const { return m_guanyador; }
	bool potTirar() { return m_potTirar; }
	int getTornsInactiu() { return m_nTornsInactiu; }
private:
	int m_casella;
	bool m_potTirar;
	int m_nTornsInactiu;
	bool m_guanyador;
};

