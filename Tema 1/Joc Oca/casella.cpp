#include "casella.h"

const int TORNS_INACTIVITAT_POU = 2;
const int CASELLA_INICIAL = 1;


bool Casella::executaAccio(Jugador& j)
{
	j.setPosicio(m_posicio);
	bool esOca = false;

	switch (m_tipus)
	{
	case OCA:
		esOca = true;
		break;
	case POU:
		j.setTornsInactiu(TORNS_INACTIVITAT_POU);
		break;
	case MORT:
		j.setPosicio(CASELLA_INICIAL);
		break;
	case FINAL:
		j.guanya();
		break;
	case NORMAL:
	default:
		break;
	}

	return esOca;
}

