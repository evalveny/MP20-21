#include "Titulacio.h"
#include <fstream>
#include <iostream>
using namespace std;

void Titulacio::afegeixEstudiant(const string& niu, const string& nom, int anyInici)
{
	std::list<Estudiant>::iterator aux = m_estudiants.begin();
	bool trobat = false;
	while (aux != m_estudiants.end() && !trobat)
	{
		if (nom < (*aux).getNom())
			trobat = true;
		else
			aux++;
	}
	Estudiant e(niu, nom, anyInici);
	m_estudiants.insert(aux, e);
	m_nEstudiants++;
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	std::list<Estudiant>::iterator aux = m_estudiants.begin();
	while ((aux != m_estudiants.end()) && !trobat)
	{
		if (niu == (*aux).getNiu())
			trobat = true;
		else
		{
			aux++;
		}
	}
	if (trobat)
	{
		m_estudiants.erase(aux);
		m_nEstudiants--;
	}
	return trobat;
}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	std::list<Estudiant>::iterator aux = m_estudiants.begin();
	while ((aux != m_estudiants.end()) && (!trobat))
	{
		e = *aux;
		if (e.getNiu() == niu)
			trobat = true;
		else
			aux++;
	}
	return trobat;
}

void Titulacio::llegeixEstudiants(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		string niu, nom;
		int any;
		fitxer >> niu >> nom >> any;
		while (!fitxer.eof())
		{
			afegeixEstudiant(niu, nom, any);
			fitxer >> niu >> nom >> any;
		}
		fitxer.close();
	}
}

void Titulacio::mostraEstudiants()
{
	std::list<Estudiant>::reverse_iterator aux;
	for (aux = m_estudiants.rbegin(); aux != m_estudiants.rend(); aux++)
	{
		Estudiant e = (*aux);
		cout << e.getNiu() << ", " << e.getNom() << ", " << e.getAnyInici()
			<< endl;
	}
}

void Titulacio::eliminaEstudiantsAny(int any)
{
	std::list<Estudiant>::iterator aux = m_estudiants.begin();
	while (aux != m_estudiants.end())
	{
		Estudiant e = (*aux);
		if (e.getAnyInici() < any)
			aux = m_estudiants.erase(aux);
		else
		{
			aux++;
		}
	}
}

