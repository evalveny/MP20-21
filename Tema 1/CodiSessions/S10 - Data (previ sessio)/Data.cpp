#include "Data.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& input, Data& d)
{
	int dia, mes, any;

	cout << "Entra el dia: ";
	input >> dia;
	cout << "Entra el mes: ";
	input >> mes;
	cout << "Entra l'any: ";
	input >> any;
	d.setDia(dia);
	d.setMes(mes);
	d.setAny(any);
	return input;
}

ostream& operator<<(ostream& output, Data& d)
{
	output << d.getDia() << "/" << d.getMes() << "/" << d.getAny();
	return output;
}


Data Data::operator+(int nDies) const
{
	Data dataNova(*this);
	while (nDies > 0)
	{
		int diaAux = dataNova.m_dia + nDies;
		if (diaAux > nDiesMes[dataNova.m_mes-1])
		{
			nDies -= (nDiesMes[dataNova.m_mes-1] - dataNova.m_dia + 1);
			dataNova.m_dia = 1;
			dataNova.m_mes++;
			if (dataNova.m_mes > N_MESOS)
			{
				dataNova.m_any++;
				dataNova.m_mes = 1;
			}
		}
		else
		{
			dataNova.m_dia = diaAux;
			nDies = 0;
		}
	}
	return dataNova;
}


bool Data::operator<(const Data& data) const
{
	return ((m_any < data.m_any) || ((m_any == data.m_any) && (m_mes < data.m_mes)) ||
		((m_any == data.m_any) && (m_mes == data.m_mes) && (m_dia < data.m_dia)));
}

bool Data::operator==(const Data& data) const
{
	return ((m_dia == data.m_dia) && (m_mes == data.m_mes) && (m_any == data.m_any));
}