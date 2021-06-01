#include <queue>
#include <string>
using namespace std;

class SistemaTelefons
{
public:
	SistemaTelefons();
	void introduirTelefon(const string& telf);
	string servirTelefon();
	void eliminarTot();
	int getNumTelefons() { return m_cuaTelefons.size(); }

private:
	queue<string> m_cuaTelefons;
};
