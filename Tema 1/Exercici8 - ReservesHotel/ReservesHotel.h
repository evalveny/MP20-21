#pragma once
#include "Reserva.h"

class ReservesHotel
{
public:
	ReservesHotel() : m_nReserves(0), m_nHabitacions(0), m_nom(""), m_preuDia(0.0) {}
	ReservesHotel(const string &nom, float preu, int nHabitacions) : m_nom(nom), m_preuDia(preu),
		m_nHabitacions(nHabitacions), m_nReserves(0) {}
	void llegeixReserves(const string &nomFitxer);
	int nReservesDia(const Data& dia);
	bool afegeixReserva(const string &nomClient, const Data &entrada, int nDies, int nHabitacions);
	bool consultaReserva(const string &nomClient, const Data &entrada, Data &sortida, int &nHabitacions, float &preu);
private:
	const static int MAX_RESERVES = 10;
	string m_nom;
	float m_preuDia;
	int m_nHabitacions;
	Reserva m_reserves[MAX_RESERVES];
	int m_nReserves;
};
