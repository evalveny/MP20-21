#include <iostream>
#include "MultMatriu.h"
using namespace std;

void multiplicaMatriu(int m1[N][N],int m2[N][N],int result[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < N; k++)
			{
				result[i][j] += m1[i][k] * m2[k][j];
			}

		}
	}
}
