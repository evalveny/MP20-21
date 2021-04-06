#include "Llista.h"
#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
using namespace std;

void mostraBool(bool logic)
{
	if (logic)
		cout << "TRUE";
	else
		cout << "FALSE";
}

bool comparaLlistes(Llista& l, Data* resultat, int longitud)
{
	bool iguals = (longitud == l.getNumElements());
	if (iguals)
	{
		int i = 0;
		while ((i < longitud) && iguals)
		{
			if (!(resultat[i] == l.getElement(i)))
				iguals = false;
			else
				i++;
		}
	}
	return iguals;
}

void mostraVector(Data v[], int mida)
{
	cout << "[ ";
	for (int i = 0; i < mida - 1; i++)
	{
		cout << v[i] << ",";
	}
	if (mida > 0)
		cout << v[mida - 1];
	cout << " ]";
}

void mostraBuffer(stringstream& buffer)
{
	string stringData;
	getline(buffer, stringData);
	while (stringData != "")
	{
		cout << "Comment :=>> " << stringData << endl;
		getline(buffer, stringData);
	}
}

float testInicialitzacioLlista()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test de la inicialitzacio de la classe Llista" << endl;
	cout << "Comment :=>> ======================================================" << endl;
	const int N_ELEMENTS = 8;
	Data dataTest[N_ELEMENTS] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 },
		{ 10, 11, 2018 },
		{ 1, 12, 2019 },
		{ 20, 12, 2018},
		{ 10, 1, 2020 }
	};
	cout << "Comment :=>> Inicialitzant la llista amb valors (els valors es mostrem utilitzant l'operador << de la classe Data): " << endl;
	cout << "Comment :=>> "; mostraVector(dataTest, N_ELEMENTS); cout << endl;
	Llista l(dataTest, N_ELEMENTS);
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Contingut de la llista despres d'inicialitzar (es mostra utilitzant operador << de la classe Llista): " << endl;

	stringstream buffer;
	streambuf* buffer_cout = cout.rdbuf(buffer.rdbuf());
	cout << l << endl;
	cout.rdbuf(buffer_cout);
	mostraBuffer(buffer);
	cout << "Comment :=>> ----------" << endl;
	bool iguals = comparaLlistes(l, dataTest, N_ELEMENTS);
	cout << "Comment :=>> Comprovant si contingut correcte (fa servir metodes getElement i getNumElements)... " << endl;
	if (!iguals)
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}
	else
		cout << "Comment :=>> CORRECTE" << endl;

	return reduccio;
}

float testPertany()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode pertany" << endl;
	cout << "Comment :=>> ================================" << endl;
	const int N_ELEMENTS = 8;
	Data dataTest[N_ELEMENTS] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 },
		{ 10, 11, 2018 },
		{ 1, 12, 2019 },
		{ 20, 12, 2018},
		{ 10, 1, 2020 }
	};

	const int N_PROVES = 5;
	Data dataTestPertany[N_PROVES] =
	{
		{ 10, 1, 2018 },
		{ 1, 12, 2019 },
		{ 10, 1, 2020 },
		{ 10, 1, 2000},
		{ 20, 1, 2018}
	};
	bool resultatEsperat[N_PROVES] = { true, true, true, false, false };

	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(dataTest, N_ELEMENTS); cout << endl;
	Llista l(dataTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data a buscar dins la llista: " << dataTest[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " ; mostraBool(resultatEsperat[i]); cout <<  endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = l.pertany(dataTestPertany[i]);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == resultatEsperat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testGetElement()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del metode getElement" << endl;
	cout << "Comment :=>> ===================================" << endl;
	const int N_ELEMENTS = 8;
	Data dataTest[N_ELEMENTS] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 },
		{ 10, 11, 2018 },
		{ 1, 12, 2019 },
		{ 20, 12, 2018},
		{ 10, 1, 2020 }
	};

	const int N_PROVES = 5;
	int posicio[N_PROVES] = { 0, 7, 3, -1, 8 };
	Data resultatEsperat[N_PROVES] = 
	{
		{ 10, 1, 2018 },
		{ 10, 1, 2020 },
		{ 10, 10, 2018 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};

	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(dataTest, N_ELEMENTS); cout << endl;
	Llista l(dataTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Posicio de la llista a retornar: " << posicio[i] << endl;
		cout << "Comment :=>> ---" << endl;
		cout << "Comment :=>> Valor retorn esperat: " << resultatEsperat[i] << endl;
		cout << "Comment :=>> ---" << endl;
		Data resultat = l.getElement(posicio[i]);
		cout << "Comment :=>> Valor retorn obtingut: " << resultat << endl;
		if (resultat == resultatEsperat[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


float testOperadorSuma()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador +" << endl;
	cout << "Comment :=>> ========================" << endl;
	cout << "Comment :=>> Inicialitzant la llista buida (amb el constructor per defecte): " << endl;
	Llista l;

	const int N_PROVES = 4;
	const int N_ELEMENTS = 4;
	Data dataTest[N_PROVES] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 }
	};
	Data resultatEsperat[N_PROVES][N_ELEMENTS] =
	{
		{
			{ 10, 1, 2018 },

		},
		{
			{ 10, 1, 2018 },
			{ 1, 1, 2018 }
		},
		{
			{ 10, 1, 2018 },
			{ 1, 1, 2018 },
			{ 10, 1, 2019 }
		},
		{
			{ 10, 1, 2018 },
			{ 1, 1, 2018 },
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		}
	};
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data a afegir: " << dataTest[i] << endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = l + dataTest[i];
		cout << "Comment :=>> Llista resultat esperada: " << endl;
		cout << "Comment :=>> "; mostraVector(resultatEsperat[i], i + 1); cout << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(true); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Llista resultat obtinguda: " << endl;
		stringstream buffer;
		streambuf* buffer_cout = cout.rdbuf(buffer.rdbuf());
		cout << l << endl;
		cout.rdbuf(buffer_cout);
		mostraBuffer(buffer);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, resultatEsperat[i], i + 1);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals && resultat)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Afegint elements fins a omplir la llista ..." << endl;
	for (int i = N_PROVES; i < 100; i++)
		bool resultat = l + dataTest[0];
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Afegint un element a la llista plena ..." << endl;
	bool resultat = l + dataTest[0];
	cout << "Comment :=>> Valor retorn esperat: "; mostraBool(false); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	if (!resultat)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testOperadorResta()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador -" << endl;
	cout << "Comment :=>> ========================" << endl;

	const int N_PROVES = 7;
	const int N_ELEMENTS = 4;
	Data dataTest[N_ELEMENTS] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 }
	};
	Data dataEliminar[N_PROVES] = 
	{
		{ 1, 1, 2010 },
		{ 1, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 1, 2018 },
		{ 10, 10, 2018 },
		{ 10, 1, 2019 },
		{ 1, 1, 2010 }
	};
	Data llistaEsperada[N_PROVES][N_ELEMENTS] =
	{
		{
			{ 10, 1, 2018 },
			{ 1, 1, 2018 },
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		},
		{
			{ 10, 1, 2018 },
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		},
		{
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		},
		{
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		},
		{
			{ 10, 1, 2019 }
		},
		{
		},
		{
		}
	};
	bool resultatEsperat[N_PROVES] = { false, true, true, false, true, true, false };
	int nElementsEsperats[N_PROVES] = { 4, 3, 2, 2, 1, 0, 0 };
	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(dataTest, N_ELEMENTS); cout << endl;
	Llista l(dataTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data a eliminar: " << dataEliminar[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		bool resultat = l - dataEliminar[i];
		cout << "Comment :=>> Llista resultat esperada: " << endl;
		cout << "Comment :=>> "; mostraVector(llistaEsperada[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Llista resultat obtinguda: " << endl;
		stringstream buffer;
		streambuf* buffer_cout = cout.rdbuf(buffer.rdbuf());
		cout << l << endl;
		cout.rdbuf(buffer_cout);
		mostraBuffer(buffer);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, llistaEsperada[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals && (resultat == resultatEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


float testInsereix()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test metode insereix" << endl;
	cout << "Comment :=>> =============================" << endl;
	cout << "Comment :=>> Inicialitzant la llista buida (amb el constructor per defecte): " << endl;
	Llista l;

	const int N_PROVES = 7;
	const int N_ELEMENTS = 5;
	Data dataTest[N_PROVES] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 1, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 },
		{ 1, 1, 2010 }
	};
	int posicioTest[N_PROVES] = { 0, 1, 3, -1, 1, 1, 0 };
	Data llistaEsperada[N_PROVES][N_ELEMENTS] =
	{
		{
			{ 10, 1, 2018 },

		},
		{
			{ 10, 1, 2018 },
			{ 1, 1, 2018 }
		},
		{
			{ 10, 1, 2018 },
			{ 1, 1, 2018 }
		},
		{
			{ 10, 1, 2018 },
			{ 1, 1, 2018 }
		},
		{
			{ 10, 1, 2018 },
			{ 10, 1, 2019 },
			{ 1, 1, 2018 }
		},
		{
			{ 10, 1, 2018 },
			{ 10, 10, 2018 },
			{ 10, 1, 2019 },
			{ 1, 1, 2018 }
		},
		{
			{ 1, 1, 2010 },
			{ 10, 1, 2018 },
			{ 10, 10, 2018 },
			{ 10, 1, 2019 },
			{ 1, 1, 2018 }
		}
	};
	bool resultatEsperat[N_PROVES] = { true, true, false, false, true, true, true };
	int nElementsEsperats[N_PROVES] = { 1, 2, 2, 2, 3, 4, 5 };
	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Data a afegir: " << dataTest[i] << endl;
		cout << "Comment :=>> Posicio: " << posicioTest[i] << endl;
		cout << "Comment :=>> ---" << endl;
		bool resultat = l.insereix(dataTest[i], posicioTest[i]);
		cout << "Comment :=>> Llista resultat esperada: " << endl;
		cout << "Comment :=>> "; mostraVector(llistaEsperada[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Llista resultat obtinguda: " << endl;
		stringstream buffer;
		streambuf* buffer_cout = cout.rdbuf(buffer.rdbuf());
		cout << l << endl;
		cout.rdbuf(buffer_cout);
		mostraBuffer(buffer);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, llistaEsperada[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals && (resultat == resultatEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}
	cout << "Comment :=>> ------------------------------------------" << endl;
	cout << "Comment :=>> Afegint elements fins a omplir la llista ..." << endl;
	for (int i = 5; i < 100; i++)
		bool resultat = l.insereix(dataTest[0], 0);
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Afegint un element a la llista plena ..." << endl;
	bool resultat = l.insereix(dataTest[0], 0);
	cout << "Comment :=>> Valor retorn esperat: "; mostraBool(false); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
	cout << "Comment :=>> ----------" << endl;
	if (!resultat)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 1.0;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testElimina()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test metode elimina" << endl;
	cout << "Comment :=>> ============================" << endl;

	const int N_PROVES = 7;
	const int N_ELEMENTS = 4;
	Data dataTest[N_ELEMENTS] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 }
	};
	int posicioEliminar[N_PROVES] = { -1, 1, 3, 0, 1, 0, 1 };
	Data llistaEsperada[N_PROVES][N_ELEMENTS] =
	{
		{
			{ 10, 1, 2018 },
			{ 1, 1, 2018 },
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		},
		{
			{ 10, 1, 2018 },
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		},
		{
			{ 10, 1, 2018 },
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		},
		{
			{ 10, 1, 2019 },
			{ 10, 10, 2018 }
		},
		{
			{ 10, 1, 2019 }
		},
		{
		},
		{
		}
	};
	bool resultatEsperat[N_PROVES] = { false, true, false, true, true, true, false };
	int nElementsEsperats[N_PROVES] = { 4, 3, 3, 2, 1, 0, 0 };
	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(dataTest, N_ELEMENTS); cout << endl;
	Llista l(dataTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> ------------------------------------------" << endl;
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Posicio a eliminar: " << posicioEliminar[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		bool resultat = l.elimina(posicioEliminar[i]);
		cout << "Comment :=>> Llista resultat esperada: " << endl;
		cout << "Comment :=>> "; mostraVector(llistaEsperada[i], nElementsEsperats[i]); cout << endl;
		cout << "Comment :=>> Valor retorn esperat: "; mostraBool(resultatEsperat[i]); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Llista resultat obtinguda: " << endl;
		stringstream buffer;
		streambuf* buffer_cout = cout.rdbuf(buffer.rdbuf());
		cout << l << endl;
		cout.rdbuf(buffer_cout);
		mostraBuffer(buffer);
		cout << "Comment :=>> Valor retorn obtingut: "; mostraBool(resultat); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, llistaEsperada[i], nElementsEsperats[i]);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (iguals && (resultat == resultatEsperat[i]))
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 1.0;
		}
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testSortidaPantalla()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador << de sortida a pantalla" << endl;
	cout << "Comment :=>> ===============================================" << endl;

	const int N_ELEMENTS = 4;
	Data dataTest[N_ELEMENTS] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 }
	};
	string resultatEsperat[N_ELEMENTS] = { "10/1/2018", "1/1/2018", "10/1/2019", "10/10/2018"};


	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(dataTest, N_ELEMENTS); cout << endl;
	Llista l(dataTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> Escrivint la llista a la sortida estàndard amb cout ...." << endl;
	ofstream fitxerTestOut;
	string nomFitxerOut = "test_llista_cout.txt";
	fitxerTestOut.open(nomFitxerOut);
	streambuf* buffer_cout = cout.rdbuf(fitxerTestOut.rdbuf());
	cout << l;
	cout.rdbuf(buffer_cout);
	fitxerTestOut.close();

	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat esperat: " << endl;
	for (int i = 0; i < N_ELEMENTS; i++)
		cout << "Comment :=>> " << resultatEsperat[i] << endl;

	ifstream fitxerTestResultat;
	fitxerTestResultat.open(nomFitxerOut);
	string resultat;
	cout << "Comment :=>> -----" << endl;
	cout << "Comment :=>> Resultat obtingut: " << endl;
	bool error = false;
	for (int i = 0; i < N_ELEMENTS; i++)
	{
		getline(fitxerTestResultat, resultat);
		cout << "Comment :=>> " << resultat << endl;
		if (resultat != resultatEsperat[i])
			error = true;
	}
	fitxerTestResultat.close();

	if (!error)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 3;
	}

	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


float testSortidaFitxer()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador << de escriptura a fitxer" << endl;
	cout << "Comment :=>> ================================================" << endl;

	const int N_ELEMENTS = 4;
	Data dataTest[N_ELEMENTS] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 }
	};
	string resultatEsperat[N_ELEMENTS] = { "10/1/2018", "1/1/2018", "10/1/2019", "10/10/2018" };


	cout << "Comment :=>> Inicialitzant la llista amb valors: " << endl;
	cout << "Comment :=>> "; mostraVector(dataTest, N_ELEMENTS); cout << endl;
	Llista l(dataTest, N_ELEMENTS);
	cout << "Comment :=>> " << endl;

	cout << "Comment :=>> Escrivint la llista al fitxer amb l'operador << ...." << endl;
	ofstream fitxerTestOut;
	string nomFitxerOut = "test_llista_fitxer.txt";
	fitxerTestOut.open(nomFitxerOut);
	if (fitxerTestOut.is_open())
	{
		fitxerTestOut << l;
		fitxerTestOut.close();

		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Resultat esperat: " << endl;
		for (int i = 0; i < N_ELEMENTS; i++)
			cout << "Comment :=>> " << resultatEsperat[i] << endl;

		ifstream fitxerTestResultat;
		fitxerTestResultat.open(nomFitxerOut);
		string resultat;
		cout << "Comment :=>> -----" << endl;
		cout << "Comment :=>> Resultat obtingut: " << endl;
		bool error = false;
		for (int i = 0; i < N_ELEMENTS; i++)
		{
			getline(fitxerTestResultat, resultat);
			cout << "Comment :=>> " << resultat << endl;
			if (resultat != resultatEsperat[i])
				error = true;
		}
		fitxerTestResultat.close();
		if (!error)
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 3;
		}
	}
	else
	{
		cout << "Comment :=>> ERROR OBRINT EL FITXER" << endl;
		reduccio += 3;
	}


	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}

float testLecturaFitxer()
{
	float reduccio = 0.0;

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test operador >> de lectura de fitxer" << endl;
	cout << "Comment :=>> ==============================================" << endl;

	const int N_ELEMENTS = 4;
	Data resultatEsperat[N_ELEMENTS] =
	{
		{ 10, 1, 2018 },
		{ 1, 1, 2018 },
		{ 10, 1, 2019 },
		{ 10, 10, 2018 }
	};

	cout << "Comment :=>> Llegint la llista del fitxer amb l'operador >> .... " << endl;
	Llista l;

	ifstream fitxerTestIn;
	string nomFitxerIn = "test_llista_fitxer_in.txt";
	fitxerTestIn.open(nomFitxerIn);
	if (fitxerTestIn.is_open())
	{
		fitxerTestIn >> l;
		fitxerTestIn.close();

		cout << "Comment :=>> " << endl;
		cout << "Comment :=>> Contingut esperat de la llista: " << endl;
		cout << "Comment :=>> "; mostraVector(resultatEsperat, N_ELEMENTS); cout << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Contingut de la llista despres llegir del fitxer: " << endl;
		stringstream buffer;
		streambuf* buffer_cout = cout.rdbuf(buffer.rdbuf());
		cout << l << endl;
		cout.rdbuf(buffer_cout);
		mostraBuffer(buffer);
		cout << "Comment :=>> ----------" << endl;
		bool iguals = comparaLlistes(l, resultatEsperat, N_ELEMENTS);
		cout << "Comment :=>> Comprovant si contingut correcte ... " << endl;
		if (!iguals)
		{
			cout << "Comment :=>> ERROR" << endl;
			reduccio += 3.0;
		}
		else
			cout << "Comment :=>> CORRECTE" << endl;

	}
	else
	{
		cout << "Comment :=>> ERROR OBRINT EL FITXER" << endl;
		reduccio += 3;
	}


	if (reduccio > 3.0)
		reduccio = 3.0;
	return reduccio;
}


int main()
{
	float grade = 0.0;
	float reduccio;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	reduccio = testInicialitzacioLlista();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testPertany();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testGetElement();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testOperadorSuma();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testOperadorResta();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testInsereix();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testElimina();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testSortidaPantalla();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testSortidaFitxer();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testLecturaFitxer();
	grade = grade + (1 - reduccio);

	if (grade < 0)
		grade = 0.0;
	cout << "Grade :=>> " << grade << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	return 0;

}