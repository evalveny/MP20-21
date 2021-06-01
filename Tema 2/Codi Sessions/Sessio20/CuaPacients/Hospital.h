#pragma once
#include <queue>
#include <string>
using namespace std;

class Hospital
{
private:
	static const int N_CONSULTES = 3;
	std::queue<string> m_consultes[N_CONSULTES];
public:
	int registraPacient(const string &nom);
	string atendrePacient(int nConsulta);
};
