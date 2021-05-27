
#include "LlistaDoble.h"

LlistaDoble::LlistaDoble()
{
     m_primer = nullptr;
	 m_ultim = nullptr;
}

LlistaDoble::~LlistaDoble()
{
	while (m_primer != nullptr)
		m_primer = erase(m_primer);
}

bool LlistaDoble::empty() const
{
    return (m_primer == nullptr);
}

Node* LlistaDoble::begin() const
{
    return m_primer;
}

Node* LlistaDoble::rbegin() const
{
	return m_ultim;
}


Node* LlistaDoble::push_front(const int& valor)
{
	Node* aux = new Node;
	if (aux != nullptr)
	{
		aux->setValor(valor);
		aux->setPrev(nullptr);
		aux->setNext(m_primer);
		if (m_ultim == nullptr)
			m_ultim = aux;
		else
			m_primer->setPrev(aux);
		m_primer = aux;
	}
	return aux;
}

Node* LlistaDoble::erase(Node *posicio)
{
	Node* anterior = nullptr;
	Node* seguent = nullptr;
	if (posicio != nullptr)
	{
		// Recupera apuntadors als elements anterior i següent
		anterior = posicio->getPrev();
		seguent = posicio->getNext();
		// Si anterior es null modificar primer
		// sino modificar enllaç de l'element anterior
		if (anterior == nullptr)
			m_primer = seguent;
		else
			anterior->setNext(seguent);
		// Si seguent es null modificar ultim
		// sino  enllaç de l'element seguent
		if (seguent == nullptr)
			m_ultim = anterior;
		else
			seguent->setPrev(anterior);
		// Alliberar el node
		delete posicio;
	}
	return seguent;
}


