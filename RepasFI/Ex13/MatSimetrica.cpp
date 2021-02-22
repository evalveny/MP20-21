//
//  Recorreguts.cpp
//  Test funcions rep�s
//
#include "Matsimetrica.h"

bool esSimetrica(int matriu[N][N]) 
{
	int i = 0;
	bool simetrica = true;
	while (i < N && simetrica)
	{
		int j = i + 1;
		while (j < N && simetrica)//matriu[i][i])
		{
			//cout << matriu[i][j] << endl;
			if (matriu[i][j] != matriu[j][i]) {
				simetrica = false;
			}
			j++;
		}
		//cout << endl;
		i++;
	}

	return simetrica;
}
