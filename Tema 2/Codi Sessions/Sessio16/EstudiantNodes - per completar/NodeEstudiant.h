#pragma once
#include "Estudiant.h"

class NodeEstudiant
{
public:
	Estudiant& getValor() { return m_valor; }
	NodeEstudiant* getNext() { return m_next; }
	void setValor(const Estudiant& valor) { m_valor = valor; }
	void setNext(NodeEstudiant* next) { m_next = next; }
private:
	Estudiant m_valor;
	NodeEstudiant* m_next;
};
