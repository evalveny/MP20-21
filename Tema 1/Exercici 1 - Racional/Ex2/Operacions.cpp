#include "Operacions.h"

void operar(NombreRacional v[], int mida, char operacio, NombreRacional& operand, NombreRacional resultat[])
{
	for (int i = 0; i < mida; i++)
	{
		if (v[i].esValid())
		{
			switch (operacio)
			{
			case '+':
				resultat[i] = v[i].suma(operand);
				break;
			case '-':
				resultat[i] = v[i].resta(operand);
				break;
			case '*':
				resultat[i] = v[i].multiplica(operand);
				break;
			case '/':
				resultat[i] = v[i].divideix(operand);
				break;

			}
		}
		else
		{
			resultat[i] = NombreRacional();
		}
	}
}

