#include <iostream>
#include <fstream>
#include "Joc.h"
using namespace std;

float testMoviments()
{
	float grade = 10.0;

	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> Iniciant test dels moviments de la partida" << endl;
	cout << "Comment :=>> ==========================================" << endl;

	ifstream fitxerEsperat, fitxerObtingut;

	fitxerEsperat.open("llistat_moviments_resultat.txt");
	if (fitxerEsperat.is_open())
	{
		fitxerObtingut.open("llistat_moviments.txt");
		if (fitxerObtingut.is_open())
		{
			int jugadorEsperat, accioEsperada, colorEsperat, valorEsperat;
			int jugadorObtingut, accioObtinguda, colorObtingut, valorObtingut;
			fitxerEsperat >> jugadorEsperat >> accioEsperada >> colorEsperat >> valorEsperat;
			while (!fitxerEsperat.eof())
			{
				cout << "Comment :=>> Moviment Esperat:  " << "Jugador: " << jugadorEsperat;
				if (accioEsperada == 0)
					cout << " TIRA CARTA ";
				else
					if (accioEsperada == 1)
						cout << " ROBA CARTA ";
				cout << "Color: " << colorEsperat << " Valor: " << valorEsperat << endl;
				cout << "Comment :=>> ---" << endl;

				fitxerObtingut >> jugadorObtingut >> accioObtinguda >> colorObtingut >> valorObtingut;
				if (!fitxerObtingut.eof())
				{
					cout << "Comment :=>> Moviment Obtingut:  " << "Jugador: " << jugadorObtingut;
					if (accioObtinguda == 0)
						cout << " TIRA CARTA ";
					else
						if (accioObtinguda == 1)
							cout << " ROBA CARTA ";
					cout << "Color: " << colorObtingut << " Valor: " << valorObtingut << endl;
					if ((jugadorEsperat == jugadorObtingut) && (accioEsperada == accioObtinguda) &&
						(colorEsperat == colorObtingut) && (valorEsperat == valorObtingut))
						cout << "Comment :=>> CORRECTE" << endl;
					else
					{
						cout << "Comment :=>> ERROR" << endl;
						grade -= 0, 5;
					}
					cout << "Comment :=>> ---------------------------------" << endl;
				}
				else
				{
					cout << "Comment :=>> ERROR. No hi ha mes moviments al fitxer resultat de la partida" << endl;
					grade -= 5.0;
				}
				fitxerEsperat >> jugadorEsperat >> accioEsperada >> colorEsperat >> valorEsperat;
			}
			fitxerObtingut >> jugadorObtingut >> accioObtinguda >> colorObtingut >> colorObtingut;
			if (!fitxerObtingut.eof())
			{
				cout << "Comment :=>> ERROR. Hi ha mes moviments dels esperats al fitxer resultat de la partida" << endl;
				grade -= 5.0;
			}

			fitxerObtingut.close();
		}
		else
		{
			cout << "Comment :=>> ERROR. No es pot obrir fitxer amb el resultat de la partida" << endl;
			grade = 0.0;
		}

		fitxerEsperat.close();
	}
	else
	{
		cout << "Comment :=>> ERROR. No es pot obrir fitxer amb el resultat esperat" << endl;
		grade = 0.0;
	}
	return grade;
}


int main()
{
	Joc partida;

	cout << endl;
	cout << "Comment :=>> ==============" << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> ==============" << endl;

	cout << endl;
	cout << "Comment :=>> Execucio de la partida completa" << endl;
	cout << "Comment :=>> ===============================" << endl;
	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ......." << endl;


	partida.inicialitza("cartes_inicial.txt", 4);
	while (!partida.final())
		partida.fesMoviment();
	partida.guarda("llistat_moviments.txt");


	cout << "Comment :=>> " << endl;
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Final de la partida" << endl;

	float grade = testMoviments();
	if (grade < 0)
		grade = 0.0;
	cout << "Comment :=>> ------------------------------------------" << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;


	return 0;
}
