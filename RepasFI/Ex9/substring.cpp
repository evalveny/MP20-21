#include "substring.h"
#include <string.h>

bool esSubStringAPosicio(char str[], char subStr[], int posicio)
{
	bool iguals = true;
	int i = 0;
	while (iguals && (i < strlen(subStr)))
	{
		if (str[posicio + i] != subStr[i])
			iguals = false;
		else
			i++;
	}
	return iguals;
}

bool esSubString(char str[], char subStr[], int& posicio)
{
	bool trobat = false;
	posicio = 0;
	int maxPosicio = strlen(str) - strlen(subStr) + 1;

	while (!trobat && (posicio < maxPosicio))
	{
		if (esSubStringAPosicio(str, subStr, posicio))
			trobat = true;
		else
			posicio++;
	}

	return trobat;
}
