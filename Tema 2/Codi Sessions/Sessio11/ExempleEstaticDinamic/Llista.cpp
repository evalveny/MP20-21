#include "Llista.h"

Llista::Llista(const Data v[], int mida)
{
	if (mida <= MAX_ELEMENTS)
	{
		for (int i = 0; i < mida; i++)
		{
			m_elements[i].setDia(v[i].getDia());
			m_elements[i].setMes(v[i].getMes());
			m_elements[i].setAny(v[i].getAny());
		}
		m_nElements = mida;
	}
}

bool Llista::pertany(const Data& element) const
{
	bool trobat = false;
	int i = 0;
	while (!trobat && (i < m_nElements))
	{
		if (m_elements[i] == element)
			trobat = true;
		else
			i++;
	}
	return trobat;
}

Data Llista::getElement(int posicio) const
{
	if ((posicio >= 0) && (posicio < m_nElements))
		return m_elements[posicio];
	else
	{
		return Data(0,0,0);
	}
}

bool Llista::insereix(const Data& element, int posicio)
{
	bool resultat = false;
	if ((m_nElements < MAX_ELEMENTS) && (posicio >= 0) && (posicio <= m_nElements))
	{
		resultat = true;
		for (int i = m_nElements; i > posicio; i--)
		{
			m_elements[i].setDia(m_elements[i - 1].getDia());
			m_elements[i].setMes(m_elements[i - 1].getMes());
			m_elements[i].setAny(m_elements[i - 1].getAny());
		}		
		m_elements[posicio].setDia(element.getDia());
		m_elements[posicio].setMes(element.getMes());
		m_elements[posicio].setAny(element.getAny());
		m_nElements++;
	}
	return resultat;
}

bool Llista::elimina(int posicio)
{
	bool resultat = false;
	if ((posicio >= 0) && (posicio < m_nElements))
	{
		resultat = true;
		for (int i = posicio; i < (m_nElements - 1); i++)
		{
			m_elements[i].setDia(m_elements[i + 1].getDia());
			m_elements[i].setMes(m_elements[i + 1].getMes());
			m_elements[i].setAny(m_elements[i + 1].getAny());
		}
		m_nElements--;
	}
	return resultat;
}

bool Llista::operator+(const Data& element)
{
	bool resultat = false;
	if (m_nElements < MAX_ELEMENTS)
	{
		resultat = true;
		m_elements[m_nElements].setDia(element.getDia());
		m_elements[m_nElements].setMes(element.getMes());
		m_elements[m_nElements].setAny(element.getAny());
		m_nElements++;
	}
	return resultat;
}

bool Llista::operator-(const Data& element)
{
	bool trobat = false;
	int posicio = 0;
	while (!trobat && (posicio < m_nElements))
	{
		if (m_elements[posicio] == element)
			trobat = true;
		else
			posicio++;
	}
	if (trobat)
	{
		for (int i = posicio; i < (m_nElements - 1); i++)
		{
			m_elements[i].setDia(m_elements[i + 1].getDia());
			m_elements[i].setMes(m_elements[i + 1].getMes());
			m_elements[i].setAny(m_elements[i + 1].getAny());
		}
		m_nElements--;
	}
	return trobat;
}


ostream& operator<<(ostream& output, const Llista& llista)
{
	for (int i = 0; i < llista.getNumElements(); i++)
		output << llista.getElement(i) << endl;
	return output;
}

ofstream& operator<<(ofstream& output, const Llista& llista)
{
	for (int i = 0; i < llista.getNumElements(); i++)
		output << llista.getElement(i) << endl;
	return output;
}

ifstream& operator>>(ifstream& input, Llista& llista)
{
	Data data;
	input >> data;
	while (!input.eof())
	{
		bool valid = llista + data;
		input >> data;
	}
	return input;
}
