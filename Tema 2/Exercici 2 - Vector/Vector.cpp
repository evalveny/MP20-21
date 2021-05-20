
#include"Vector.h"

Vector::Vector()
{
	m_array = nullptr;
	m_nElements = 0;
	m_maxElements = 0;
}

Vector::Vector(const Vector& v)
{
	m_array = nullptr;
	m_maxElements = v.m_maxElements;
	m_nElements = v.m_nElements;
	if (v.m_array != nullptr)
	{
		m_array = new Punt[m_maxElements];
		for (int i = 0; i < v.m_nElements; i++)
		{
			m_array[i] = v.m_array[i];
		}
	}
}

Vector& Vector::operator = (const Vector& v)
{
	if (this != &v)
	{
		m_maxElements = v.m_maxElements;
		m_nElements = v.m_nElements;
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
		if (v.m_array != nullptr)
		{
			m_array = new Punt[m_maxElements];
			for (int i = 0; i < v.m_nElements; i++)
			{
				m_array[i] = v.m_array[i];
			}
		}
	}
	return *this;
}


Vector::~Vector()
{
	if (m_array != nullptr)
	{
		delete[] m_array;
		m_array = nullptr;
	}
	m_maxElements = 0;
	m_nElements = 0;
}


void Vector::redimensiona(int dimensio)
{
	Punt *arrayAux = new Punt[dimensio];
	for (int i = 0; i < m_nElements; i++)
		arrayAux[i] = m_array[i];
	delete[] m_array;
	m_array = arrayAux;
	m_maxElements = dimensio;
}

bool Vector::insereix(const Punt& pt, int posicio)
{
	bool resultat = false;
	if ((posicio >= 0) && (posicio <= m_nElements))
	{
		resultat = true;
		if (m_nElements == m_maxElements)
		{
			if (m_maxElements == 0)
			{
				m_array = new Punt[TAMANY_MINIM];
				m_maxElements = TAMANY_MINIM;
				m_nElements = 0;
			}
			else
				redimensiona(2 * m_maxElements);
		}
		for (int i = m_nElements; i > posicio; i--)
			m_array[i] = m_array[i - 1];
		m_array[posicio] = pt;
		m_nElements++;
	}
	return resultat;
}

bool Vector::elimina(int posicio)
{
	bool resultat = false;
	if ((posicio >= 0) && (posicio < m_nElements))
	{
		resultat = true;
		for (int i = posicio; i < (m_nElements - 1); i++)
			m_array[i] = m_array[i + 1];
		m_nElements--;
		if (m_nElements < (m_maxElements / 4))
		{
			if ((m_maxElements / 2) >= TAMANY_MINIM)
				redimensiona(m_maxElements / 2);
		}
	}
	return resultat;
}


int Vector::getNElements()
{
	return m_nElements;
}

int Vector::getMaxElements()
{
	return m_maxElements;
}

Punt& Vector::operator[] (int nIndex)
{
	if (nIndex >= 0 && nIndex < m_nElements)
		return m_array[nIndex];
	else
	{
		cout << "Error d'acces a l'array" << endl;
		return m_valorDefecte;
	}
}




