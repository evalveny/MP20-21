#pragma once

#include <string>
using namespace std;

const int MAX_EXEMPLARS = 10;

class Llibre
{
public:
	Llibre(): m_titol(""), m_autor(""), m_nExemplars(0) { }
	Llibre(const string& titol, const string& autor, int nExemplars); 
	void setTitol(const string &titol) { m_titol = titol; }
	void setAutor(const string &autor) { m_autor = autor; }
	void setNExemplars(int nExemplars);
	string& getTitol() { return m_titol; }
	string& getAutor() { return m_autor; }
	int getNExemplars() { return m_nExemplars; }

	bool presta(int &codiExemplar);
	bool retorna(int codiExemplar);


private:
	string m_titol;
	string m_autor;
	int m_nExemplars;
	bool m_exemplars[MAX_EXEMPLARS];
};

