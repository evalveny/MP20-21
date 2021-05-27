#include "LlistaDoble.h"
#include <iostream>
using namespace std;



int main()
{
	LlistaDoble l;

	for (int i = 0; i < 10; i++)
		l.push_front(i);
	Node* aux = l.begin();
	aux = l.erase(aux);
	aux = aux->getNext();
	aux = l.erase(aux);
	aux = l.rbegin();
	aux = l.erase(aux);

	aux = l.begin();
	while (aux != nullptr)
	{
		cout << aux->getValor() << endl;
		aux = aux->getNext();
	}
	return 0;
}