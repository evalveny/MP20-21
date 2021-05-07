#include "Titulacio.h"



void Titulacio::afegeixEstudiant(const string& niu, const string& nom)
{
	Estudiant estudiantAux(niu, nom);
	NodeEstudiant* nodeAux = new NodeEstudiant;
	nodeAux->setValor(estudiantAux);
	nodeAux->setNext(m_estudiants);
	m_estudiants = nodeAux;
	m_nEstudiants++;
}

void Titulacio::eliminaPrimerEstudiant()
{
	NodeEstudiant* aux = m_estudiants;
	m_estudiants = m_estudiants->getNext();
	delete aux;
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
	bool trobat = false;
	NodeEstudiant* aux = m_estudiants;
	NodeEstudiant* anterior = nullptr;
	while ((aux != nullptr) && !trobat)
	{
		if (niu == aux->getValor().getNiu())
			trobat = true;
		else
		{
			anterior = aux;
			aux = aux->getNext();
		}
	}
	if (trobat)
	{
		if (anterior != nullptr)
			anterior->setNext(aux->getNext());
		else
			m_estudiants = aux->getNext();
		delete aux;
		m_nEstudiants--;
	}
	return trobat;
}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
	bool trobat = false;
	NodeEstudiant *aux = m_estudiants;
	while ((aux != nullptr) && (!trobat))
	{
		e = aux->getValor();
		if (e.getNiu() == niu)
			trobat = true;
		else
			aux = aux->getNext();
	}
	return trobat;
}