void normalitzaValors(float vector[], int nValors)
{
	if (nValors > 0)
	{
		float minim = vector[0];
		float maxim = vector[0];
		for (int i = 1; i < nValors; i++)
			if (vector[i] < minim)
				minim = vector[i];
			else
				if (vector[i] > maxim)
					maxim = vector[i];
		if (minim != maxim)
			for (int i = 0; i < nValors; i++)
				vector[i] = (vector[i] - minim) / (maxim - minim);
	}
}
