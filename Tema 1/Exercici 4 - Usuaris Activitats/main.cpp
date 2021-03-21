#include "Activitat.h"
#include <iostream>
using namespace std;

const int MAX_USUARIS = 5;
const int MAX_ACTIVITATS = 3;

void mostraBool(bool valor)
{
	if (valor)
		cout << "TRUE ";
	else
		cout << "FALSE ";
}

float testClasseUsuari()
{
	float reduccio = 0.0;
	
	string nomSoci[MAX_USUARIS] = { "Usuari_1", "Usuari_2", "Usuari_3", "Usuari_4", "Usuari_5"};
	string codiSoci[MAX_USUARIS] = { "Codi_1", "Codi_2", "Codi_3", "Codi_4", "Codi_5"};
	int edatSoci[MAX_USUARIS] = { 18, 60, 40, 35, 40 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del constructor de la classe Usuari" << endl;
	cout << "Comment :=>> =================================================" << endl;
	for (int i = 0; i < MAX_USUARIS; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Creant un nou usuari ... " << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat despres inicialitzacio: " << endl;
		cout << "Comment :=>> Codi: " << codiSoci[i] << endl;
		cout << "Comment :=>> Nom: " << nomSoci[i] << endl;
		cout << "Comment :=>> Edat: " << edatSoci[i] << endl;
		Usuari u(codiSoci[i], nomSoci[i], edatSoci[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut despres inicialitzacio: " << endl;
		cout << "Comment :=>> Codi: " << u.getCodi() << endl;
		cout << "Comment :=>> Nom: " << u.getNom() << endl;
		cout << "Comment :=>> Edat: " << u.getEdat() << endl;
		if ((u.getCodi()!=codiSoci[i])||(u.getNom()!=nomSoci[i])||(u.getEdat()!= edatSoci[i]))
		{
			cout << "Comment :=>> ERROR " << endl;
			reduccio += 2.0;
		}
		else
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		cout << "Comment :=>> -----------------------------" << endl;
	}	
	return reduccio;
}

float testClasseActivitat()
{
	float reduccio = 0.0;

	string nomActivitats[MAX_ACTIVITATS] = { "Activitat_1", "Activitat_2", "Activitat_3" };
	string dies[MAX_ACTIVITATS] = { "dilluns", "dimarts", "dimecres" };
	string hores[MAX_ACTIVITATS] = { "9:00", "8:00", "18:00" };
	int edatMinima[MAX_ACTIVITATS] = { 18, 30, 40 };
	int edatMaxima[MAX_ACTIVITATS] = { 60, 70, 100 };
	int maximParticipants[MAX_ACTIVITATS] = { 3, 3, 15 };

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del constructor de la classe Activitat" << endl;
	cout << "Comment :=>> ====================================================" << endl;
	for (int i = 0; i < MAX_ACTIVITATS; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Creant una nova activitat... " << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat despres inicialitzacio: " << endl;
		cout << "Comment :=>> Nom: " << nomActivitats[i] << endl;
		cout << "Comment :=>> Dia: " << dies[i] << endl;
		cout << "Comment :=>> Hora: " << hores[i] << endl;
		cout << "Comment :=>> Edat Minima: " << edatMinima[i] << endl;
		cout << "Comment :=>> Edat Maxima: " << edatMaxima[i] << endl;
		cout << "Comment :=>> Maxim participants: " << maximParticipants[i] << endl;
		cout << "Comment :=>> N. participants: " << 0 << endl;
		Activitat a(nomActivitats[i], maximParticipants[i], edatMinima[i], edatMaxima[i], dies[i], hores[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut despres inicialitzacio: " << endl;
		cout << "Comment :=>> Nom: " << a.getNom() << endl;
		cout << "Comment :=>> Dia: " << a.getDia() << endl;
		cout << "Comment :=>> Hora: " << a.getHora() << endl;
		cout << "Comment :=>> Edat Minima: " << a.getEdatMinima() << endl;
		cout << "Comment :=>> Edat Maxima: " << a.getEdatMaxima() << endl;
		cout << "Comment :=>> Maxim participants: " << a.getMaximParticipants() << endl;
		cout << "Comment :=>> N. participants: " << a.getParticipants() << endl;
		if ((a.getNom() != nomActivitats[i]) || (a.getDia() != dies[i]) || (a.getHora() != hores[i]) || (a.getEdatMinima() != edatMinima[i]) ||
			(a.getEdatMaxima() != edatMaxima[i]) || (a.getMaximParticipants() != maximParticipants[i]) || (a.getParticipants() != 0))
		{
			cout << "Comment :=>> ERROR " << endl;
			reduccio += 2.0;
		}
		else
		{
			cout << "Comment :=>> CORRECTE" << endl;
		}
		cout << "Comment :=>> -----------------------------" << endl;
	}
	return reduccio;
}

	
float testAfegeixBuscaParticipant()
{
	float reduccio = 0.0;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del mètode afegeixParticipant" << endl;
	cout << "Comment :=>> ===========================================" << endl;
	string nomAct = "activitat_1";
	int maximParticipantsAct = 3;
	int edatMinimaAct = 30;
	int edatMaximaAct = 50;
	string diaAct = "dilluns";
	string horaAct = "10:00";
	Activitat a(nomAct, maximParticipantsAct, edatMinimaAct, edatMaximaAct, diaAct, horaAct);
	cout << "Comment :=>> Inicialitzant activitat...." << endl;
	cout << "Comment :=>> Nom: " << nomAct << endl;
	cout << "Comment :=>> Dia: " << diaAct << endl;
	cout << "Comment :=>> Hora: " << horaAct << endl;
	cout << "Comment :=>> Edat Minima: " << edatMinimaAct << endl;
	cout << "Comment :=>> Edat Maxima: " << edatMaximaAct << endl;
	cout << "Comment :=>> Maxim participants: " << maximParticipantsAct << endl;
	cout << "Comment :=>> -----------------------------" << endl;

	const int N_PROVES = 7;
	Usuari usuaris[N_PROVES] = 
	{
		{"codi_1", "nom_1", 18}, 
		{"codi_1", "nom_1", 60}, 
		{"codi_1", "nom_1", 40}, 
		{"codi_1", "nom_1", 35}, 
		{"codi_2", "nom_2", 40},
		{"codi_3", "nom_3", 40}, 
		{"codi_4", "nom_4", 40}
	};
	int resultatEsperat[N_PROVES] = { -1, -1, 0, -2, 0, 0, -3 };
	int nParticipants[N_PROVES] = { 0, 0, 1, 1, 2, 3, 3 };

	for (int i = 0; i < N_PROVES; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Afegint usuari ... " << endl;
		cout << "Comment :=>> Codi: " << usuaris[i].getCodi() << endl;
		cout << "Comment :=>> Nom: " << usuaris[i].getNom() << endl;
		cout << "Comment :=>> Edat: " << usuaris[i].getEdat() << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: " << resultatEsperat[i] << endl;
		cout << "Comment :=>> N. participants esperat: " << nParticipants[i] << endl;
		int resultat = a.afegeixParticipant(usuaris[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: " << resultat << endl;
		cout << "Comment :=>> N. participants despres afegir: " << a.getParticipants() << endl;
		if (resultat == resultatEsperat[i])
		{
			if (resultat == 0)
				if (a.getParticipants() == nParticipants[i])
					cout << "Comment :=>> CORRECTE" << endl;
				else
				{
					cout << "Comment :=>> ERROR " << endl;
					reduccio += 2.0;
				}
			else
				cout << "Comment :=>> CORRECTE" << endl;
		}
		else
		{
			cout << "Comment :=>> ERROR " << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> ----------------------------" << endl;
	}

	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> Iniciant test del mètode buscarParticipant" << endl;
	cout << "Comment :=>> (suposem que s'han afegit els participants del test anterior correctament)" << endl;
	cout << "Comment :=>> ==========================================================================" << endl;

	const int N_PROVES_BUSCAR = 5;
	bool resultatEsperatBuscar[N_PROVES_BUSCAR] = { true, true, true, false, false };
	string noms[N_PROVES_BUSCAR] = { "nom_1", "nom_2", "nom_3", "nom_4", "nom_5" };
	for (int i = 0; i < N_PROVES_BUSCAR; i++)
	{
		cout << "Comment :=>> TEST " << i + 1 << endl;
		cout << "Comment :=>> Buscant participant amb nom: " << noms[i] << endl;
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat esperat: ";  mostraBool(resultatEsperatBuscar[i]); cout << endl;
		bool resultat = a.buscaParticipant(noms[i]);
		cout << "Comment :=>> ----------" << endl;
		cout << "Comment :=>> Resultat obtingut: "; mostraBool(resultat); cout << endl;
		if (resultat == resultatEsperatBuscar[i])
			cout << "Comment :=>> CORRECTE" << endl;
		else
		{
			cout << "Comment :=>> ERROR " << endl;
			reduccio += 2.0;
		}
		cout << "Comment :=>> ----------------------------" << endl;
	}
	return reduccio;
}

int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	float reduccio = testClasseUsuari();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testClasseActivitat();
	grade = grade + (1 - reduccio);
	cout << "Grade :=>> " << grade << endl;

	reduccio = testAfegeixBuscaParticipant();
	grade = grade + (8 - reduccio);

	if (grade < 0)
		grade = 0.0;
	cout << "Grade :=>> " << grade << endl;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	return 0;
}