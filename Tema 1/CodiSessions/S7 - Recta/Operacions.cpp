#include "Operacions.h"
#include "Recta.h"

void distancia(Punt& pt1, Punt& pt2, Punt llistaPunts[], int nPunts, float distancies[])
{
	Recta r(pt1, pt2);
	for (int i = 0; i < nPunts; i++)
		distancies[i] = r.distancia(llistaPunts[i]);
}

void interseccio(Recta& r, Punt llistaPunts1[], Punt llistaPunts2[], int nPunts, bool interseccio[], Punt ptInterseccio[])
{
	for (int i = 0; i < nPunts; i++)
	{
		Recta r2(llistaPunts1[i], llistaPunts2[i]);
		interseccio[i] = r.interseccio(r2, ptInterseccio[i]);
	}
}