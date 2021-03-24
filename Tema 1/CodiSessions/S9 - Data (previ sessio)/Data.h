#pragma once

class Data
{
public:
	Data() { m_dia = 0; m_mes = 0; m_any = 0; }
	Data(int dia, int mes, int any) : m_dia(dia), m_mes(mes), m_any(any) { }
	void setDia(int dia) { m_dia = dia; }
	void setMes(int mes) { m_mes = mes; }
	void setAny(int any) { m_any = any; }
	void llegeix();
	int getDia() const { return m_dia; }
	int getMes() const { return m_mes; }
	int getAny() const { return m_any; }
	bool operator<(const Data& data) const;
private:
	int m_dia, m_mes, m_any;
};
