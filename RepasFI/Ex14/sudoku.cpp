#include <iostream>
#include "sudoku.h"

using namespace std;



/**
* Llegeix un n�mero enter per teclat
* @return numero que s'ha llegit
*/
int llegeixNumero()
{
	int numero;
	do
	{
		cout << "Introdueix n�mero (entre 1 i 9): ";
		cin >> numero;
	} while ((numero < 0) || (numero > 9));
	return numero;
}


/**
* Llegeix per teclat una fila (1-9) i una columna (1-9) del tauler del sudoku
* @param fila n� de fila
* @param columan n� de columna
*/
void llegeixPosicio(int& fila, int& columna)
{
	do
	{
		cout << "Introdueix fila i columna (entre 1 i 9): ";
		cin >> fila;
		cin >> columna;
	} while ((fila < 0) || (fila > 9) || (columna < 0) || (columna > 9));
}

void llegeixNumeroPosicio(int& numero, int& fila, int& columna)
{
	numero = llegeixNumero();
	if (numero != 0)
		llegeixPosicio(fila, columna);
}

/**
* Comprova si �s v�lid posar un numero a una determinada fila (0-8) del sudoku
* @param tauler tauler del sudoku
* @param fila fila on es vol posar el n�mero
* @param numero que es vol posar al sudoku
* return true si �s valid i false si no ho �s
*/
bool esValidFila(int tauler[N_FILES][N_COLUMNES], int fila, int numero)
{
	int i = 0;
	bool valid = true;
	while ((i<N_COLUMNES) && (valid))
	{
		if (tauler[fila][i] == numero)
			valid = false;
		else
			i++;
	}
	return (valid);
}

/**
* Comprova si �s v�lid posar un numero a una determinada columna (0-8) del sudoku
* @param tauler tauler del sudoku
* @param columna fila on es vol posar el n�mero
* @param numero que es vol posar al sudoku
* return true si �s valid i false si no ho �s
*/
bool esValidColumna(int tauler[N_FILES][N_COLUMNES], int columna, int numero)
{
	int i = 0;
	bool valid = true;
	while ((i<N_FILES) && (valid))
	{
		if (tauler[i][columna] == numero)
			valid = false;
		else
			i++;
	}
	return valid;
}

/**
* Comprova si �s v�lid posar un numero a un subquadrat del sudoku determinat per fila (0-8) i columna (0-8)
* @param tauler tauler del sudoku
* @param fila fila on es vol posar el n�mero
* @param columna columna on es vol posar el n�emro
* @param numero que es vol posar al sudoku
* return true si �s valid i false si no ho �s
*/
bool esValidQuadrat(int tauler[N_FILES][N_COLUMNES], int fila, int columna, int numero)
{
	int filaInicial = (fila / TAMANY_QUADRAT) * TAMANY_QUADRAT;
	int columnaInicial = (columna / TAMANY_QUADRAT) * TAMANY_QUADRAT;
	bool valid = true;
	int i = filaInicial;
	while ((i < (filaInicial + TAMANY_QUADRAT)) && (valid))
	{
		int j = columnaInicial;
		while ((j < (columnaInicial + TAMANY_QUADRAT)) && (valid))
		{
			if (tauler[i][j] == numero)
				valid = false;
			else
				j++;
		}
		i++;
	}
	return valid;
}

/**
* Comprova si �s v�lid posar un numero al tauler del sudoku a la posici� determinada per fila (1-9) i columna (1-9)
* @param tauler tauler del sudoku
* @param fila fila on es vol posar el n�mero
* @param columna columna on es vol posar el n�emro
* @param numero que es vol posar al sudoku
* return true si �s valid i false si no ho �s
*/
bool esValid(int tauler[N_FILES][N_COLUMNES], int fila, int columna, int numero)
{
	bool valid;

	valid = esValidFila(tauler, fila - 1, numero);
	if (valid)
	{
		valid = esValidColumna(tauler, columna - 1, numero);
		if (valid)
			valid = esValidQuadrat(tauler, fila - 1, columna - 1, numero);
	}
	return valid;
}


bool posaNumero(int tauler[N_FILES][N_COLUMNES], int fila, int columna, int numero)
{
	bool valid = true;
	if (tauler[fila - 1][columna - 1] != 0)
		valid = false;
	else
		if (valid = esValid(tauler, fila, columna, numero))
			tauler[fila - 1][columna - 1] = numero;
	return valid;
}


/**
* Mostra l'estat actual del sudoku per pantalla
* @param tauler tauler del sudoku
*/
void mostraSudoku(int tauler[N_FILES][N_COLUMNES])
{
	int i, j, k;

	for (i = 0; i<N_FILES; i++)
	{
		if (i % 3 == 0)
		{
			for (k = 0; k<(N_COLUMNES * 2) + 1; k++)
				cout << "=";
			cout << "\n";
		}
		for (j = 0; j<N_COLUMNES; j++)
		{
			if (j % 3 == 0)
				cout << "|";
			else
				cout << " ";
			if (tauler[i][j] != 0)
				cout << tauler[i][j];
			else
				cout << " ";
		}
		cout << "|\n";
	}
	for (k = 0; k<(N_COLUMNES * 2) + 1; k++)
		cout << "=";
	cout << "\n";
}

/**
* Versi� simplificada del sudoku que fa el seg�ent:
* - Llegir per pantalla un sudoku a completar
* - Demanar un n� i una posici� del sudoku on es vol posar
* - Comprovar si �s v�lid posar el n� a la posici� indicada
*/
bool jugaSudoku(int tauler[N_FILES][N_COLUMNES], int nLliures, bool resultat[], int& nMoviments)
{
	bool valid;
	int numero, fila, columna;


	mostraSudoku(tauler);
	bool continuar = true;
	nMoviments = 0;
	bool final = false;
	do
	{
		llegeixNumeroPosicio(numero, fila, columna);
		if (numero == 0)
			continuar = false;
		else
		{
			valid = posaNumero(tauler, fila, columna, numero);
			if (valid)
			{
				nLliures--;
				mostraSudoku(tauler);
				resultat[nMoviments] = true;
			}
			else
			{
				cout << "No es valid posar aquest numero en aquesta casella" << endl;
				resultat[nMoviments] = false;
			}
			nMoviments++;
		}
	} while (continuar && (nLliures > 0));
	if (nLliures == 0)
	{
		cout << "Enhorabona. Has completat el sudoku" << endl;
		final = true;
	}
	return final;

}
