#pragma once
#include <string>
#include "Data.h"
using namespace std;

class Reserva
{
public:
	void setNom(const string &nomClient) { m_nom = nomClient; }
	void setDataEntrada(const Data& data) { m_dataInici = data; }
	void setDataSortida(const Data& data) { m_dataFinal = data; }
	void setNHabitacions(int nHabitacions) { m_nHabitacions = nHabitacions; }
	void setPreu(float preu) { m_preu = preu; }
	string getNom() const { return m_nom; }
	Data getDataEntrada() const { return m_dataInici; }
	Data getDataSortida() const { return m_dataFinal; }
	int getNHabitacions() const { return m_nHabitacions; }
	float getPreu() const { return m_preu; }
private:
	string m_nom;
	Data m_dataInici, m_dataFinal;
	int m_nHabitacions;
	float m_preu;
};
