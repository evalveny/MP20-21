#include "Poligon.h"
#include <fstream>
using namespace std;


ifstream& operator>>(ifstream& input, Poligon& pol)
{
	Punt pt;
	input >> pt;
	while (!input.eof())
	{
		pol.afegeixVertex(pt);
		input >> pt;
	}
	return input;
}

ofstream& operator<<(ofstream& output, Poligon& pol)
{
	for (int i = 0; i < pol.getNVertexs(); i++)
	{
		output << pol.getVertex(i) << endl;
	}
	return output;
}

istream& operator>>(istream& input, Poligon& pol)
{
	cout << "Introdueix numero de vertexs: ";
	int nVertexs;
	input >> nVertexs;
	for (int i = 0; i < nVertexs ; i++)
	{
		Punt pt;
		input >> pt;
		pol.afegeixVertex(pt);
	}
	return input;
}

ostream& operator<<(ostream& output, Poligon& pol)
{
	output << pol.getNVertexs() << endl;
	for (int i = 0; i < pol.getNVertexs(); i++)
		output << pol.getVertex(i) << endl;
	return output;
}

void Poligon::afegeixVertex(const Punt& pt)
{
	if (m_nVertexs < MAX_VERTEXS)
	{
		m_vertexs[m_nVertexs] = pt;
		m_nVertexs++;
		if (pt.getX() < m_topLeft.getX())
			m_topLeft.setX(pt.getX());
		else
			if (pt.getX() > m_bottomRight.getX())
				m_bottomRight.setX(pt.getX());
		if (pt.getY() < m_topLeft.getY())
			m_topLeft.setY(pt.getY());
		else
			if (pt.getY() > m_bottomRight.getY())
				m_bottomRight.setY(pt.getY());
	}	
}

float Poligon::calculaPerimetre() const
{
	float perimetre = 0;
	for (int i = 0; i < m_nVertexs - 1; i++)
		perimetre += m_vertexs[i].distancia(m_vertexs[i + 1]);
	perimetre += m_vertexs[0].distancia(m_vertexs[m_nVertexs-1]);
	return perimetre;
}