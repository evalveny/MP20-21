
#include "Usuari.h"


class Activitat
{
public:
	Activitat() { m_maximParticipants = 0; m_numParticipants = 0; };
	Activitat(string nom, int maximParticipants, int edatMinima , int edatMaxima, string dia, string hora);

	string getNom() { return m_nom; }
	string getDia() { return m_dia; }
	string getHora() { return m_hora; }
	int getEdatMinima() { return m_edatMinima; }
	int getEdatMaxima() { return m_edatMaxima; }
	int getMaximParticipants() { return m_maximParticipants; }
	int getParticipants() { return m_numParticipants; }


	int afegeixParticipant(const Usuari& u);
	bool buscaParticipant(string& nom);
private:
	static const int MAXIMUSUARIS = 40;
	string m_nom;
	string m_dia;
	string m_hora;
	int m_edatMinima;
	int m_edatMaxima;
	int m_maximParticipants;
	int m_numParticipants;
	Usuari m_participants[MAXIMUSUARIS];
};
