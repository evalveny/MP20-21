#ifndef SEIENT_H
#define SEIENT_H

#include "passatger.h"
#include <string>
using namespace std;

class Seient
{
public:
	Seient() : m_passatger(nullptr) {}
	Seient(const string& codi) : m_codi(codi) { m_passatger = nullptr; }
	~Seient() { if (m_passatger != nullptr) delete m_passatger; }

	void setCodi(const string& codi) { m_codi = codi; }
	void setPassatger(Passatger* p) { m_passatger = p; }

	bool assignaPassatger(const string& dni, const string& nom);
	bool eliminaPassatger();
	
	const string& getCodi () const { return m_codi; }
	Passatger* getPassatger() { return m_passatger; }
private:
	string m_codi;
	Passatger* m_passatger;
};

#endif
