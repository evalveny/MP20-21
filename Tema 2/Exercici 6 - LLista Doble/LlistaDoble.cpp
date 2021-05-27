
#include "LlistaDoble.h"

LlistaDoble::LlistaDoble()
{
     m_primer = NULL;
	 m_ultim = NULL;
}

LlistaDoble::~LlistaDoble()
{
	while (m_primer != NULL)
		m_primer = erase(m_primer);
}

bool LlistaDoble::empty() const
{
    return (m_primer == NULL);
}

Node* LlistaDoble::begin() const
{
    return m_primer;
}

Node* LlistaDoble::rbegin() const
{
	return m_ultim;
}

Node* LlistaDoble::insert(const int& valor, Node* posicio)
{
	Node* aux = new Node;
	if (aux != NULL)
	{
		aux->setValor(valor);
		if (posicio == NULL)
		{
			aux->setPrev(m_ultim);
			if (m_ultim == NULL)
				m_primer = aux;
			else
				m_ultim->setNext(aux);
			m_ultim = aux;
		}
		else
		{
			aux->setPrev(posicio->getPrev());
			aux->setNext(posicio);
			if (posicio->getPrev() == NULL)
				m_primer = aux;
			else
				posicio->getPrev()->setNext(aux);
			posicio->setPrev(aux);
		}
	}
	return aux;
}

Node* LlistaDoble::erase(Node *posicio)
{
	Node* anterior = NULL;
	Node* seguent = NULL;
	if (posicio != NULL)
	{
		anterior = posicio->getPrev();
		seguent = posicio->getNext();
		delete posicio;
		if (anterior != NULL)
			anterior->setNext(seguent);
		else
			m_primer = seguent;
		if (seguent != NULL)
			seguent->setPrev(anterior);
		else
			m_ultim = anterior;
	}
	return seguent;
}

void LlistaDoble::unique()
{
	if (m_primer != nullptr)
	{
		Node* anterior = m_primer;
		Node* actual = m_primer->getNext();
		while (actual != nullptr)
		{
			if (actual->getValor() == anterior->getValor())
				actual = erase(actual);
			else
			{
				anterior = actual;
				actual = actual->getNext();
			}
		}
	}
}

void LlistaDoble::merge(LlistaDoble& llista)
{
	Node* auxDesti = m_primer;
	while ((llista.m_primer != nullptr) && (auxDesti != nullptr))
	{
		if (auxDesti->getValor() < llista.m_primer->getValor())
			auxDesti = auxDesti->getNext();
		else
		{
			Node* anteriorDesti = auxDesti->getPrev();
			Node* auxOriginal = llista.m_primer;
			llista.m_primer = llista.m_primer->getNext();
			if (anteriorDesti != nullptr)
				anteriorDesti->setNext(auxOriginal);
			else
				m_primer = auxOriginal;
			auxOriginal->setPrev(anteriorDesti);
			auxOriginal->setNext(auxDesti);
			auxDesti->setPrev(auxOriginal);
		}
	}
	if (llista.m_primer != nullptr)
	{
		if (m_ultim != nullptr)
			m_ultim->setNext(llista.m_primer);
		else
			m_primer = llista.m_primer;
		llista.m_primer->setPrev(m_ultim);
		m_ultim = llista.m_primer;
		while (m_ultim->getNext() != nullptr)
			m_ultim = m_ultim->getNext();
		llista.m_primer = nullptr;
	}
}

LlistaDoble& LlistaDoble::operator=(const LlistaDoble& llista)
{
	while (m_primer != NULL)
		m_primer = erase(m_primer);
	Node* actual = llista.m_primer;
	while (actual != NULL)
	{
		insert(actual->getValor(), NULL);
		actual = actual->getNext();
	}
	return *this;
}