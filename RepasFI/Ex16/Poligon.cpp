#include "poligon.h"
#include <iostream>

using namespace std;

void llegeixPoligon(Poligon& p)
{
	cout << "Introdueix el nombre de costats del polígon: ";
	cin >> p.nCostats;
	for (int i = 0; i < p.nCostats; i++)
	{
		cout << "Llegint dades del vertex " << i + 1 << endl;
		llegeixPunt(p.vertexs[i]);
	}
}

void mostraPoligon(Poligon& p)
{
	for (int i = 0; i < p.nCostats; i++)
	{
		mostraPunt(p.vertexs[i]);
		cout << " ";
	}
}

float calculaPerimetre(Poligon& p)
{
	float perimetre = 0.0;

	for (int i = 0; i < p.nCostats - 1; i++)
		perimetre += distanciaPunts(p.vertexs[i], p.vertexs[i + 1]);
	perimetre += distanciaPunts(p.vertexs[p.nCostats - 1], p.vertexs[0]);

	return perimetre;
}

void rectangleMinim(Poligon& p, Punt& superiorEsquerra, Punt& inferiorDreta)
{
	float xMin = p.vertexs[0].x;
	float xMax = p.vertexs[0].x;
	float yMin = p.vertexs[0].y;
	float yMax = p.vertexs[0].y;
	for (int i = 1; i < p.nCostats; i++)
	{
		if (p.vertexs[i].x < xMin)
			xMin = p.vertexs[i].x;
		if (p.vertexs[i].x > xMax)
			xMax = p.vertexs[i].x;
		if (p.vertexs[i].y < yMin)
			yMin = p.vertexs[i].y;
		if (p.vertexs[i].y > yMax)
			yMax = p.vertexs[i].y;
	}
	superiorEsquerra.x = xMin;
	superiorEsquerra.y = yMin;
	inferiorDreta.x = xMax;
	inferiorDreta.y = yMax;
}

bool interiorRectangle(Punt& pt, Punt& supEsq, Punt& infDreta)
{
	return ((pt.x >= supEsq.x) && (pt.x <= infDreta.x) &&
		(pt.y >= supEsq.y) && (pt.y <= infDreta.y));
}

bool interseccioRectangle(Poligon& p1, Poligon& p2)
{
	Punt supEsq1, infDreta1, supEsq2, infDreta2;
	bool interseccio = false;

	rectangleMinim(p1, supEsq1, infDreta1);
	rectangleMinim(p2, supEsq2, infDreta2);

	Punt supDreta1, infEsq1;
	supDreta1.x = infDreta1.x;
	supDreta1.y = supEsq1.y;
	infEsq1.x = supEsq1.x;
	infEsq1.y = infDreta1.y;

	interseccio = interiorRectangle(supEsq1, supEsq2, infDreta2);
	interseccio = interseccio || interiorRectangle(supDreta1, supEsq2, infDreta2);
	interseccio = interseccio || interiorRectangle(infEsq1, supEsq2, infDreta2);
	interseccio = interseccio || interiorRectangle(infDreta1, supEsq2, infDreta2);

	return interseccio;
}