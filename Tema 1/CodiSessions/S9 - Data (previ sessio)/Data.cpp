#include "Data.h"
#include <iostream>
using namespace std;

void Data::llegeix()
{
	cout << "Dia: ";
	cin >> m_dia;
	cout << "Mes: ";
	cin >> m_mes;
	cout << "Any: ";
	cin >> m_any;
}

bool Data::operator<(const Data& data) const
{
	return ((m_any < data.m_any) || ((m_any == data.m_any) && (m_mes < data.m_mes)) ||
		((m_any == data.m_any) && (m_mes == data.m_mes) && (m_dia < data.m_dia)));
}
