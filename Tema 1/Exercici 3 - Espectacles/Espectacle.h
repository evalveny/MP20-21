#include <string>
using namespace std;

class Espectacle
{
public:
	//Espectacle();
	//Espectacle(string nom, string teatre, string dia, string hora, int NEntradesTotals, float preu);
	//~Espectacle();

	string getNom() const { return m_nom; }
	string getTeatre() const { return m_teatre; }
	string getDia() const { return m_dia; }
	string getHora() const { return m_hora; }
	int getEntradesTotals() const { return m_NEntradesTotals;  }
	int getEntradesLliures() const { return m_NEntradesLliures; }
	float getPreu() const { return m_preu; }
	
	void setNom(const string &nom) { m_nom = nom; }
	void setTeatre(const string &teatre) { m_teatre = teatre; }
	void setDia(const string &dia) { m_dia = dia; }
	void setHora(const string &hora) { m_hora = hora; }
	void setEntradesTotals(int nEntrades) {m_NEntradesTotals = nEntrades;m_NEntradesLliures = nEntrades;}
	void setPreu(float preu) { m_preu = preu; }
	void reservaEntrades(int nEntrades) { m_NEntradesLliures -= nEntrades; }
	
private:
	string m_nom;
	string m_teatre;
	string m_dia;
	string m_hora;
	int m_NEntradesTotals;
	int m_NEntradesLliures;
	float m_preu;
};

