#include <string>
using namespace std;

class Usuari
{
public:
	Usuari(){}
	Usuari(string codi, string nom, int edat);
	string getCodi() const { return m_codi; };
	string getNom() const { return m_nom; };
	int getEdat() const { return m_edat; };
private:
	string m_codi;
	string m_nom;
	int m_edat;
};
