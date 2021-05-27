#include "ReservesHotel.h"
#include <fstream>
using namespace std;

ReservesHotel::ReservesHotel(const ReservesHotel &reserves)
{
	m_nom = reserves.m_nom;
	m_preuDia = reserves.m_preuDia;
	m_nHabitacions = reserves.m_nHabitacions;
	m_nReserves = reserves.m_nReserves;
	m_maxReserves = reserves.m_maxReserves;
	m_reserves = new Reserva[m_maxReserves];
	for (int i = 0; i < m_nReserves; i++)
		m_reserves[i] = reserves.m_reserves[i];
}

ReservesHotel &ReservesHotel::operator=(const ReservesHotel& reserves)
{
	if (m_reserves !=NULL)
		delete[] m_reserves;
	m_nom = reserves.m_nom;
	m_preuDia = reserves.m_preuDia;
	m_nHabitacions = reserves.m_nHabitacions;
	m_nReserves = reserves.m_nReserves;
	m_maxReserves = reserves.m_maxReserves;
	m_reserves = new Reserva[m_maxReserves];
	for (int i = 0; i < m_nReserves; i++)
		m_reserves[i] = reserves.m_reserves[i];
	return *this;
}

void ReservesHotel::llegeixReserves(const string &nomFitxer)
{
	ifstream fitxer;

	fitxer.open(nomFitxer);
	string nomClient;
	int diaEntrada, mesEntrada, anyEntrada, nHabitacions, nDies;
	char separador;
	if (fitxer.is_open())
	{
		fitxer >> nomClient;
		while ((!fitxer.eof()) && (m_nReserves < m_maxReserves))
		{
			fitxer >> diaEntrada >> separador >> mesEntrada >> separador >> anyEntrada;
			fitxer >> nHabitacions;
			fitxer >> nDies;
			m_reserves[m_nReserves].setNom(nomClient);
			m_reserves[m_nReserves].setDataEntrada(Data(diaEntrada, mesEntrada, anyEntrada));
			m_reserves[m_nReserves].setDataSortida(m_reserves[m_nReserves].getDataEntrada() + nDies);
			m_reserves[m_nReserves].setNHabitacions(nHabitacions);
			m_reserves[m_nReserves].setPreu(m_preuDia * nDies * nHabitacions);
			m_nReserves++;
			fitxer >> nomClient;
		}
	}
}

int ReservesHotel::nReservesDia(const Data& dia)
{
	int nReserves = 0;
	for (int i = 0; i < m_nReserves; i++)
	{
		if (((m_reserves[i].getDataEntrada() == dia) || (m_reserves[i].getDataEntrada() < dia)) &&
			(dia < m_reserves[i].getDataSortida()))
			nReserves += m_reserves[i].getNHabitacions();
	}
	return nReserves;
}

bool ReservesHotel::afegeixReserva(const string &nomClient, const Data &entrada, int nDies, int nHabitacions)
{
	bool possible = (m_nReserves < m_maxReserves);
	int i = 0;
	while (possible && (i < nDies))
	{
		if ((nReservesDia(entrada + i) + nHabitacions) >= m_nHabitacions)
			possible = false;
		else
			i++;
	}
	if (possible)
	{
		m_reserves[m_nReserves].setNom(nomClient);
		m_reserves[m_nReserves].setDataEntrada(entrada);
		m_reserves[m_nReserves].setDataSortida(entrada + nDies);
		m_reserves[m_nReserves].setNHabitacions(nHabitacions);
		m_reserves[m_nReserves].setPreu(m_preuDia * nDies * nHabitacions);
		m_nReserves++;
	}
	return possible;
}


bool ReservesHotel::consultaReserva(const string &nomClient, const Data &entrada, Data &sortida, int &nHabitacions, float &preu)
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nReserves))
	{
		if ((m_reserves[i].getNom() == nomClient) && (m_reserves[i].getDataEntrada() == entrada))
		{
			trobat = true;
			sortida = m_reserves[i].getDataSortida();
			nHabitacions = m_reserves[i].getNHabitacions();
			preu = m_reserves[i].getPreu();
		}
		else
			i++;
	}
	return trobat;
}
