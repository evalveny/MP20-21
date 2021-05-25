#include "Titulacio.h"
#include <fstream>
#include <iostream>
using namespace std;

void Titulacio::afegeixEstudiant(const string& niu, const string& nom, int anyInici)
{
	Estudiant estudiantAux(niu, nom, anyInici);
	m_estudiants.push_front(estudiantAux);
	m_nEstudiants++;
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	std::forward_list<Estudiant>::iterator aux = m_estudiants.begin();
	std::forward_list<Estudiant>::iterator anterior = m_estudiants.before_begin();
	while ((aux != m_estudiants.end()) && !trobat)
	{
		if (niu == (*aux).getNiu())
			trobat = true;
		else
		{
			anterior = aux;
			aux++;
		}
	}
	if (trobat)
	{
		m_estudiants.erase_after(anterior);
		m_nEstudiants--;
	}
	return trobat;
}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	std::forward_list<Estudiant>::iterator aux = m_estudiants.begin();
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
		std::forward_list<Estudiant>::iterator ultim = m_estudiants.before_begin();
		while (!fitxer.eof())
		{
			Estudiant e(niu, nom, any);
			ultim = m_estudiants.insert_after(ultim, e);
			fitxer >> niu >> nom >> any;
		}
		fitxer.close();
	}
}

void Titulacio::mostraEstudiants()
{
	std::forward_list<Estudiant>::iterator aux;
	for (aux = m_estudiants.begin(); aux != m_estudiants.end(); aux++)
	{
		Estudiant e = (*aux);
		cout << e.getNiu() << ", " << e.getNom() << ", " << e.getAnyInici() << endl;
	}
}

void Titulacio::eliminaEstudiantsAny(int any)
{
	std::forward_list<Estudiant>::iterator aux = m_estudiants.begin();
	std::forward_list<Estudiant>::iterator anterior = m_estudiants.before_begin();
	while (aux != m_estudiants.end())
	{
		Estudiant e = (*aux);
		if (e.getAnyInici() < any)
			aux = m_estudiants.erase_after(anterior);
		else
		{
			anterior = aux;
			aux++;
		}
	}
}

