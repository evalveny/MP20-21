

#include "Llista.h"

Llista::~Llista()
{
	while (m_primer != nullptr)
		elimina(nullptr);
}

Llista::Llista(const Llista& l)
{
	m_primer = nullptr;
	Node* aux = l.m_primer;
	Node* aux_nova = m_primer;
	while (aux != nullptr)
	{
		aux_nova = insereix(aux->getValor(), aux_nova);
		aux = aux->getNext();
	}

}

Llista& Llista::operator=(const Llista& l)
{
	if (this != &l)
	{
		while (m_primer != nullptr)
			elimina(nullptr);
		Node* aux = l.m_primer;
		Node* aux_nova = m_primer;
		while (aux != nullptr)
		{
			aux_nova = insereix(aux->getValor(), aux_nova);
			aux = aux->getNext();
		}
	}
	return *this;
}

Node *Llista::insereix(const Punt& valor, Node *posicio)
{
	Node* aux = new Node;
	if (aux != nullptr)
	{
		aux->setValor(valor);
		if (posicio == nullptr)
		{
			aux->setNext(m_primer);
			m_primer = aux;
		}
		else
		{
			aux->setNext(posicio->getNext());
			posicio->setNext(aux);
		}
	}

	return aux;
}

Node *Llista::elimina(Node *posicio)
{
 	Node* aux;
	Node *seguent = nullptr;
	if (posicio == nullptr)
	{
		aux = m_primer;
		m_primer = aux->getNext();
		delete aux;
		seguent = m_primer;
	}
	else
	{
		aux = posicio->getNext();
		if (aux != nullptr)
        {
            posicio->setNext(aux->getNext());
            seguent = aux->getNext();
            delete aux;
        }
	}
	return seguent;
}

int Llista::getNElements() const
{
	int nElements = 0;
	Node *aux = m_primer;
	while (aux != NULL)
	{
		nElements++;
		aux = aux->getNext();
	}
	
	return nElements;
}

