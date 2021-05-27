#pragma once
#include "Reserva.h"

class ReservesHotel
{
public:
	ReservesHotel() : m_nReserves(0), m_nHabitacions(0), m_nom(""), m_preuDia(0.0), m_maxReserves(0), m_reserves(NULL) {}
	ReservesHotel(const string &nom, float preu, int nHabitacions, int nMaxReserves) : m_nom(nom), m_preuDia(preu),
		m_nHabitacions(nHabitacions), m_nReserves(0), m_maxReserves(nMaxReserves) { m_reserves = new Reserva[m_maxReserves]; }
	ReservesHotel(const ReservesHotel &reserves);
	~ReservesHotel() { delete[] m_reserves; }

	ReservesHotel &operator=(const ReservesHotel& reserves);
	void llegeixReserves(const string &nomFitxer);
	int nReservesDia(const Data& dia);
	bool afegeixReserva(const string &nomClient, const Data &entrada, int nDies, int nHabitacions);
	bool consultaReserva(const string &nomClient, const Data &entrada, Data &sortida, int &nHabitacions, float &preu);
private:
	string m_nom;
	float m_preuDia;
	int m_nHabitacions;
	Reserva *m_reserves;
	int m_nReserves;
	int m_maxReserves;
};
