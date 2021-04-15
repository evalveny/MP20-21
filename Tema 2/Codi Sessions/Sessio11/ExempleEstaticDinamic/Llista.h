#ifndef LLISTA_H
#define LLISTA_H

#include "Data.h"
#include <iostream>
#include <fstream>
using namespace std;

class Llista
{
public:
	Llista() : m_nElements(0) {}
	Llista(const Data v[], int mida);

	int getNumElements() const { return m_nElements; }
	bool pertany(const Data& element) const;
	Data getElement(int posicio) const;

	bool insereix(const Data& element, int posicio);
	bool elimina(int posicio);
	bool operator+(const Data &element);
	bool operator-(const Data &element);

private:
	static const int MAX_ELEMENTS = 10000000;
	Data m_elements[MAX_ELEMENTS];
	int m_nElements;
};


ostream& operator<<(ostream& output, const Llista& llista);
ofstream& operator<<(ofstream& output, const Llista& llista);
ifstream& operator>>(ifstream& input, Llista& llista);

#endif