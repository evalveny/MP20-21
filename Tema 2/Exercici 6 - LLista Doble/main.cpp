#include "LlistaDoble.h"
#include <iostream>
using namespace std;
#include <signal.h>


typedef void(*SignalHandlerPointer)(int);

void SignalHandler(int signal)
{
	if (signal == SIGSEGV) {
		throw "Segmentation fault";
	}
	else 
	{
		throw "Other Error";
	}
}



void escriuValors(int valors[], int nValors)
{
	cout << "[";
	for (int i = 0; i < nValors-1; i++)
	{
		cout << valors[i] << ",";
	}
	if (nValors > 0)
		cout << valors[nValors - 1];
	cout << "]";
}

void escriuValorsLlista(LlistaDoble& l)
{
	cout << "[";
	Node* aux = l.begin();
	int i = 0;
	if (aux != NULL)
	{
		cout << aux->getValor();
		aux = aux->getNext();
	}
	while (aux != NULL)
	{
		cout << "," << aux->getValor();
		aux = aux->getNext();
	}
	cout << "]";
}

void creaLlista(LlistaDoble& l, int valors[], int nValors)
{
	Node* aux = NULL;
	for (int i = nValors-1; i >=0; i--)
		aux = l.insert(valors[i], aux);
}

void destrueixLlista(LlistaDoble& l)
{
	while (l.begin()!=NULL)
	{
		l.erase(l.begin());
	}
}

bool comparaLlista(LlistaDoble& l, int valors[], int nValors)
{
	bool iguals = true;
	Node* aux = l.begin();
	int i = 0;
	while (iguals && (aux != NULL) && (i < nValors))
	{
		if (aux->getValor() != valors[i])
			iguals = false;
		else
		{
			aux = aux->getNext();
			i++;
		}
	}
	iguals = iguals && (aux == NULL) && (i == nValors);
	aux = l.rbegin();
	i = nValors - 1;
	while (iguals && (aux != NULL) && (i >= 0))
	{
		if (aux->getValor() != valors[i])
			iguals = false;
		else
		{
			aux = aux->getPrev();
			i--;
		}
	}
	return (iguals && (aux == NULL) && (i == -1));
}

Node* getPosicioLlista(LlistaDoble& l, int posicio)
{
	Node* nodePosicio = NULL;
	Node* aux = l.begin();
	for (int i = 0; i < posicio; i++)
	{
		nodePosicio = aux;
		aux = aux->getNext();
	}
	return nodePosicio;
}

float testInsereix()
{
	const int N_PROVES = 8;
	const int MAX_ELEMENTS = 4;
	float reduccio = 0;

	int valorsLlista[N_PROVES][MAX_ELEMENTS] = 
	{ 
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0 },
		{ 0 },
		{} 
	};
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 4, 4, 1, 1, 0 };
	int posicioInserir[N_PROVES] = { 1, 2, 3, 4, 0, 1, 0, 0 };
	int valorInserir = 1;
	int resultatLlista[N_PROVES][MAX_ELEMENTS+1] = 
	{ 
		{ 1, 0, 2, 4, 6 },
		{ 0, 1, 2, 4, 6 },
		{ 0, 2, 1, 4, 6 },
		{ 0, 2, 4, 1, 6 },
		{ 0, 2, 4, 6, 1 },
		{ 1, 0 },
		{ 0, 1 },
		{ 1 } 
	};
	int nValorsResultat[N_PROVES] = { 5, 5, 5, 5, 5, 2, 2, 1 };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode INSEREIX" << endl;
	cout << "Comment :=>> =============================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;

		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Creant Llista inicial................ " << endl;
		cout << "Comment :=>> Valors de la llista: ";  escriuValors(valorsLlista[i], nValorsLlista[i]); cout << endl;
		try
		{ 
			creaLlista(l, valorsLlista[i], nValorsLlista[i]);

			cout << "Comment :=>> Afegint element....................... " << endl;
			cout << "Comment :=>> Valor a inserir: " << valorInserir << endl;
			cout << "Comment :=>> Posició on inserir: " << posicioInserir[i] << endl;
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valors esperats de la llista final: "; escriuValors(resultatLlista[i], nValorsResultat[i]); cout << endl;

			Node* posicio = getPosicioLlista(l, posicioInserir[i]);
			l.insert(valorInserir, posicio);
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valors obtinguts de la llista final: "; escriuValorsLlista(l); cout << endl;

			bool valid = comparaLlista(l, resultatLlista[i], nValorsResultat[i]);

			if (valid)
			{
				cout << "Comment :=>> CORRECTE" << endl;
			}
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}
		catch (const char *e)
		{
			cout << "Comment :=>> ERROR d'execucio: " << e << endl;
			reduccio += 1.0;
		}

		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}


float testElimina()
{
	const int N_PROVES = 8;
	const int MAX_ELEMENTS = 4;
	float reduccio = 0;
	int valorsLlista[N_PROVES][MAX_ELEMENTS] = 
	{ 
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0 },
		{ 0 },
		{} 
	};
	int nValorsLlista[N_PROVES] = { 4, 4, 4, 4, 4, 1, 1, 0 };
	int posicioEliminar[N_PROVES] = { 1 , 2, 3, 4, 0, 1, 0, 0 };
	int resultatLlista[N_PROVES][4] = { 
		{ 2, 4, 6 },
		{ 0, 4, 6 },
		{ 0, 2, 6 },
		{ 0, 2, 4 },
		{ 0, 2, 4, 6 },
		{},
		{ 0 },
		{} 
	};
	int nValorsResultat[N_PROVES] = { 3, 3, 3, 3, 4, 0, 1, 0 };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode ELIMINA" << endl;
	cout << "Comment :=>> ============================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;

		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Creant Llista inicial................ " << endl;
		cout << "Comment :=>> Valors de la llista: ";  escriuValors(valorsLlista[i], nValorsLlista[i]); cout << endl;
		try
		{
			creaLlista(l, valorsLlista[i], nValorsLlista[i]);

			cout << "Comment :=>> Eliminant element....................... " << endl;
			cout << "Comment :=>> Posicio de l'element a eliminar: " << posicioEliminar[i] << endl;
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valors esperats de la llista final: "; escriuValors(resultatLlista[i], nValorsResultat[i]); cout << endl;

			Node *posicio = getPosicioLlista(l, posicioEliminar[i]);
			l.erase(posicio);

			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valors obtinguts de la llista final: "; escriuValorsLlista(l); cout << endl;

			bool valid = comparaLlista(l, resultatLlista[i], nValorsResultat[i]);

			if (valid)
			{
				cout << "Comment :=>> CORRECTE" << endl;
			}
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}
		catch (const char *e)
		{
			cout << "Comment :=>> ERROR d'execucio: " << e << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}

float testUnique()
{
	const int N_PROVES = 8;
	const int MAX_ELEMENTS = 6;
	float reduccio = 0;
	int valorsLlista[N_PROVES][MAX_ELEMENTS] =
	{
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6, 2 },
		{ 2, 2, 4, 6 },
		{ 2, 2, 2, 2 },
		{ 0, 2, 2, 4 },
		{ 0 },
		{ 0, 2, 2, 4, 6, 6 },
		{}
	};
	int nValorsLlista[N_PROVES] = { 4, 5, 4, 4, 4, 1, 6, 0 };
	int resultatLlista[N_PROVES][MAX_ELEMENTS] = 
	{
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6, 2},
		{ 2, 4, 6 },
		{ 2},
		{ 0, 2, 4},
		{ 0 },
		{ 0, 2, 4, 6 },
		{}
	};
	int nValorsResultat[N_PROVES] = { 4, 5, 3, 1, 3, 1, 4, 0 };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode UNIQUE" << endl;
	cout << "Comment :=>> ===========================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l;

		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Creant Llista inicial................ "  << endl;
		cout << "Comment :=>> Valors de la llista: ";  escriuValors(valorsLlista[i], nValorsLlista[i]); cout << endl;
		try
		{
			creaLlista(l, valorsLlista[i], nValorsLlista[i]);

			cout << "Comment :=>> Eliminant elements duplicats consecutius....................... " << endl;
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valors esperats de la llista final: "; escriuValors(resultatLlista[i], nValorsResultat[i]); cout << endl;

			l.unique();

			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valors obtinguts de la llista final: "; escriuValorsLlista(l); cout << endl;

			bool valid = comparaLlista(l, resultatLlista[i], nValorsResultat[i]);

			if (valid)
			{
				cout << "Comment :=>> CORRECTE" << endl;
			}
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}
		catch (const char *e)
		{
			cout << "Comment :=>> ERROR d'execucio: " << e << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}

float testMerge()
{
	const int N_PROVES = 8;
	const int MAX_ELEMENTS = 4;
	float reduccio = 0;

	int valorsLlista1[N_PROVES][MAX_ELEMENTS] =
	{
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{ },
		{}
	};
	int nValorsLlista1[N_PROVES] = { 4, 4, 4, 4, 4, 4, 0, 0 };
	int valorsLlista2[N_PROVES][MAX_ELEMENTS] =
	{
		{ 1, 3, 5, 7 },
		{ 8, 10, 12, 14 },
		{ -3, -1 },
		{ -1, 3, 7 },
		{ 0, 2, 4, 6 },
		{ },
		{ 0, 2, 4, 6 },
		{}
	};
	int nValorsLlista2[N_PROVES] = { 4, 4, 2, 3, 4, 0, 4, 0 };

	int resultatLlista[N_PROVES][MAX_ELEMENTS * 2] =
	{
		{ 0, 1, 2, 3, 4, 5, 6, 7 },
		{ 0, 2, 4, 6, 8, 10, 12, 14 },
		{ -3, -1, 0, 2, 4, 6 },
		{ -1, 0, 2, 3, 4, 6, 7 },
		{ 0, 0, 2, 2, 4, 4, 6, 6 },
		{ 0, 2, 4, 6 },
		{ 0, 2, 4, 6 },
		{  }
	};
	int nValorsResultat[N_PROVES] = { 8, 8, 6, 7, 8, 4, 4, 0 };

	cout << endl;
	cout << "Comment :=>> Iniciant test metode MERGE" << endl;
	cout << "Comment :=>> ==========================" << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		LlistaDoble l1, l2;

		cout << "Comment :=>> TEST " << i + 1 << endl;

		cout << "Comment :=>> Creant Llista original................ " << endl;
		cout << "Comment :=>> Valors de la llista: ";  escriuValors(valorsLlista1[i], nValorsLlista1[i]); cout << endl;
		try
		{
			creaLlista(l1, valorsLlista1[i], nValorsLlista1[i]);

			cout << "Comment :=>> Creant Llista per fusionar................ " << endl;
			cout << "Comment :=>> Valors de la llista: ";  escriuValors(valorsLlista2[i], nValorsLlista2[i]); cout << endl;

			creaLlista(l2, valorsLlista2[i], nValorsLlista2[i]);

			cout << "Comment :=>> Fusionant elements de les dues llistes.........." << endl;
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valors esperats de la llista final: "; escriuValors(resultatLlista[i], nValorsResultat[i]); cout << endl;

			l1.merge(l2);
			cout << "Comment :=>> ---" << endl;
			cout << "Comment :=>> Valors obtinguts de la llista final: "; escriuValorsLlista(l1); cout << endl;

			bool valid = comparaLlista(l1, resultatLlista[i], nValorsResultat[i]);

			if (valid)
			{
				cout << "Comment :=>> CORRECTE" << endl;
			}
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 1.0;
			}
		}
		catch (const char *e)
		{
			cout << "Comment :=>> ERROR d'execucio: " << e << endl;
			reduccio += 1.0;
		}
		cout << "Comment :=>> -----------------------------------------------" << endl;
	}
	return reduccio;
}


float testOperadorAssignacio()
{
	const int MAX_ELEMENTS = 4;
	float reduccio = 0;

	int valorsLlista[MAX_ELEMENTS] = { 0, 2, 4, 6 };
	int nValorsLlista = 4;

	cout << endl;
	cout << "Comment :=>> Iniciant test operador ASSIGNACIO" << endl;
	cout << "Comment :=>> =================================" << endl;

	LlistaDoble l1, l2;
	cout << "Comment :=>> Creant Llista inicial................ " << endl;
	cout << "Comment :=>> Valors de la llista: ";  escriuValors(valorsLlista, nValorsLlista); cout << endl;
	try
	{
		creaLlista(l1, valorsLlista, nValorsLlista);
		cout << "Comment :=>> Fent copia de la llista inicial amb operador assignacio................ " << endl;
		l2 = l1;
		cout << "Comment :=>> Destruint llista inicial................ " << endl;
		destrueixLlista(l1);
		cout << "Comment :=>> Valors la llista obtinguda amb la copia: ";  escriuValorsLlista(l2); cout << endl;

		bool valid = comparaLlista(l2, valorsLlista, nValorsLlista);

		if (valid)
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 3.0;
		}
	}
	catch (const char *e)
	{
		cout << "Comment :=>> ERROR d'execucio: " << e << endl;
		reduccio += 3.0;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;
	return reduccio;
}

int main()
{
	bool valid = true;
	float grade = 0;
	float reduccio;

	SignalHandlerPointer previousHandler;
	previousHandler = signal(SIGSEGV, SignalHandler); //SIGSEGV Illegal storage access

	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testInsereix();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;
		
	reduccio = testElimina();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testUnique();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testMerge();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	reduccio = testOperadorAssignacio();
	if (reduccio > 3.0)
		reduccio = 3.0;
	grade += (2.0 - reduccio);
	if (grade < 0)
		grade = 0.0;
	cout << endl << "Grade :=>> " << grade << endl << endl;

	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}