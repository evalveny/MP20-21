#include "Espectacle.h"

class LlistatEspectacles
{
public:
	LlistatEspectacles() { m_NEspectacles = 0; }
	bool afegeixEspectacle(Espectacle& e);
	int compraEntrades(string nom, string dia, int nEntrades, float& preu);

private:
	static const int MAXESPECTACLES = 5;
	Espectacle m_espectacles[MAXESPECTACLES];
	int m_NEspectacles;

	int buscaEspectacle(string nom, string dia);
};

