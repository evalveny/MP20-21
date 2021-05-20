#include "Llista.h"
#include <iostream>
using namespace std;

#include <signal.h>
typedef void(*SignalHandlerPointer)(int);
void SignalHandler(int signal)
{
	if (signal == SIGSEGV) {
		throw "Segmentation fault";
	}
	else {
		throw "Other Error";
	}
}
SignalHandlerPointer previousHandler;

ostream& operator<<(ostream& out, const Punt& pt)
{
	out << "(" << pt.getX() << "," << pt.getY() << ")";
	return out;
}

void escriuLlista(Llista &l)
{
	try
	{
		Node *aux = l.getInici();
		cout << "Comment :=>>  [ ";
		while (aux != NULL)
		{
			cout << aux->getValor();
			aux = aux->getNext();
			if (aux != NULL) cout << ",";
		}
		cout << " ]" << endl;
	}
	catch (const char *e)
	{
		cout << "Comment :=>> ERROR EXECUCIO a l'escriure la llista: " << e << endl;
		throw e;
	}
}

void escriuVector(Punt v[],int mida)
{
	cout << "Comment :=>>  [ ";
	for (int i = 0; i < mida; i++)
	{
		cout << v[i];		
		if (i != mida-1) cout << ",";
	}		
	cout << " ]" << endl;
}

void creaLlista(Llista &l, Punt valors[], int nValors)
{
	try
	{
		Node *aux = NULL;
		for (int i = 0; i < nValors; i++)
		{
			aux = l.insereix(valors[i], aux);
		}
	}
	catch (const char *e)
	{
		cout << "Comment :=>> ERROR EXECUCIO al crear la llista: " << e << endl;
		throw e;
	}
}

void destrueixLlista(Llista &l)
{
	try
	{
		if (!l.esBuida())
		{
			while (l.elimina(nullptr) != nullptr);
		}
	}
	catch (const char *e)
	{
		cout << "Comment :=>> ERROR EXECUCIO al destruir la llista: " << e << endl;
		throw e;
	}
}

bool comparaLlista(Llista &l, Punt valors[], int nValors)
{
	try
	{
		bool iguals = true;
		Node *aux = l.getInici();
		int i = 0;

		while (iguals && (aux != NULL))
		{
			if (!(aux->getValor() == valors[i]))
				iguals = false;
			else
			{
				aux = aux->getNext();
				i++;
			}
		}
		return (iguals && (aux == NULL) && (i == nValors));
	}
	catch (const char *e)
	{
		cout << "Comment :=>> ERROR EXECUCIO al comparar la llista: " << e << endl;
		throw e;
	}	
}

Node* pos2Node(Llista& l, int posicio)
{
	Node* pos = nullptr;
	Node* aux = l.getInici();
	int i = 0;
	while ((i < posicio) and (aux != nullptr))
	{
		i++;
		pos = aux;
		aux = aux->getNext();
	}
	return pos;
}

float testInsereix(Llista& l)
{
	float reduccio = 0.0;

	const int MAX_PROVES = 6;

	Punt valors[MAX_PROVES] = { { 2,2 },{ 1,1 },{5,5},{ 3,3 },{4,4}, {6,6} };
	int posicio[MAX_PROVES] = { 0, 0, 2, 2, 3, 5};
	Punt llistaFinal[MAX_PROVES] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5}, {6,6} };


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode insereix" << endl;
	cout << "Comment :=>> =================================" << endl;


	for (int i = 0; i < MAX_PROVES; i++)
	{
		cout << "Comment :=>> Afegint punt " << valors[i] << " despres de la posicio " << posicio[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		l.insereix(valors[i], pos2Node(l, posicio[i]));
	}
	cout << "Comment :=>> Contingut final esperat de la llista: " << endl;
	escriuVector(llistaFinal, MAX_PROVES);
	cout << "Comment :=>> Contingut final obtingut de la llista: " << endl;
	escriuLlista(l);
	if (comparaLlista(l, llistaFinal, MAX_PROVES))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 6.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	return reduccio;
}


float testElimina(Llista& l)
{
	float reduccio = 0.0;

	const int MAX_PROVES = 4;
	const int N_ELEMENTS_FINAL = 2;

	int posicio[MAX_PROVES] = { 0, 4, 2, 1};
	Punt llistaFinal[N_ELEMENTS_FINAL] = { {2,2}, {5,5}};


	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode elimina" << endl;
	cout << "Comment :=>> (a partir de la llista final metode insereix)" << endl;
	cout << "Comment :=>> =============================================" << endl;


	for (int i = 0; i < MAX_PROVES; i++)
	{
		cout << "Comment :=>> Eliminant punt despres de la posicio " << posicio[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		l.elimina(pos2Node(l, posicio[i]));
	}
	cout << "Comment :=>> Contingut final esperat de la llista: " << endl;
	escriuVector(llistaFinal, N_ELEMENTS_FINAL);
	cout << "Comment :=>> Contingut final obtingut de la llista: " << endl;
	escriuLlista(l);
	if (comparaLlista(l, llistaFinal, N_ELEMENTS_FINAL))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 6.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	return reduccio;
}

float testOperadorAssignacio()
{
	float reduccio = 0.0;

	Llista lOriginal, lResultat;

	const int N_ELEMENTS = 12;
	Punt valors[N_ELEMENTS] = { { 1,1 },{ 2,2 },{ 3,3 },{ 4,4 },{ 5,5 },{ 6,6 },{ 7,7 },{ 8,8 },{ 9,9 },{ 10,10 },{ 11,11 },{ 12,12 } };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de l'operador d'assignacio" << endl;
	cout << "Comment :=>> ========================================" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Inicialitzant la llista original amb valors:" << endl;
	escriuVector(valors, N_ELEMENTS);
	for (int i = 0; i < N_ELEMENTS; i++)
		lOriginal.insereix(valors[i], pos2Node(lOriginal, i));
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>>" << endl;

	cout << "Comment :=>> Copiant la llista amb l'operador d'assignacio:" << endl;
	lResultat = lOriginal;
	cout << "Comment :=>> -----------------------------------------------" << endl;

	cout << "Comment :=>> Contingut final esperat de la llista: " << endl;
	escriuVector(valors, N_ELEMENTS);
	cout << "Comment :=>> Contingut final de la llista copiada amb l'operador d'assignacio: " << endl;
	escriuLlista(lResultat);
	if (comparaLlista(lResultat, valors, N_ELEMENTS))
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 4.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;

	return reduccio;
}

int main()
{
	float grade = 0;
	previousHandler = signal(SIGSEGV, SignalHandler); //SIGSEGV Illegal storage access
	
	Llista l;

	grade += (4 - testInsereix(l)); 
	cout << "Grade :=>> " << grade << endl;
	grade += (4 - testElimina(l));
	cout << "Grade :=>> " << grade << endl;
	grade += (2 - testOperadorAssignacio());

	if (grade < 0)
		grade = 0.0;
	if (grade >= 10.0)
	{
		grade = 10;
		cout << "Comment :=>> Final del test sense errors" << endl;
	}
	cout << "Grade :=>> " << grade << endl;

	return 0;
}