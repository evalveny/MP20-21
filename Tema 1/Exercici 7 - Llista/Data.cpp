#include "Data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void Data::llegeix()
{
	cout << "Entra el dia: ";
	cin >> m_dia;
	cout << "Entra el mes: ";
	cin >> m_mes;
	cout << "Entra l'any: ";
	cin >> m_any;
}
bool Data::dataValida() const
{
	bool correcte = false;
	if (m_any > 0)
		if ((m_mes > 0) && (m_mes <= N_MESOS))
		{
			int diesMes = nDiesMes[m_mes - 1];
			if (m_mes == 2)
			{
				bool esTraspas = (m_any % 4) == 0 && ((m_any % 100) != 0 || (m_any % 400) == 0);
				if (esTraspas)
					diesMes++;
			}			
			if ((m_dia > 0) && (m_dia <= diesMes))
				correcte = true;
		}
			
	return correcte;
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


bool Data::operator==(const Data& data) const
{
	return ((m_dia == data.m_dia) && (m_mes == data.m_mes) && (m_any == data.m_any));
}

bool Data::operator<(const Data& data) const
{
	return ((m_any < data.m_any) || ((m_any == data.m_any) && (m_mes < data.m_mes)) ||
		((m_any == data.m_any) && (m_mes == data.m_mes) && (m_dia < data.m_dia)));
}

ostream& operator<<(ostream& output, const Data& data)
{
	output << data.getDia() << "/" << data.getMes() << "/" << data.getAny();
	return output;
}

ofstream& operator<<(ofstream& output, const Data& data)
{
	output << data.getDia() << "/" << data.getMes() << "/" << data.getAny();
	return output;
}

ifstream& operator>>(ifstream& input, Data& data)
{
	string dataString;
	getline(input, dataString);
	istringstream sString(dataString);
	char separador;
	int dia, mes, any;
	sString >> dia >> separador >> mes >> separador >> any;
	data.setDia(dia);
	data.setMes(mes);
	data.setAny(any);
	return input;
}
