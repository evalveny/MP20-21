#include <iostream>
#include <fstream>
using namespace std;

#include "notes.h"

float testCalculNotes()
{
	const int N_PROVES = 10;
	float notaFinalEsperada[N_PROVES] = { 2.9, 5, 7.2, 9.25, 10, -1, -1, -1, -1, -1 };
	char notaActaEsperada[N_PROVES] = { 'S', 'A', 'N', 'E', 'M', 'P', 'P', 'P', 'P', 'P' };
	int nNotesEsperada = 10;

	int nNotes;
	float notesFinals[MAX_NOTES];
	char notesActa[MAX_NOTES];
	float reduccio = 0.0;
	float notaTeoria, notaProblemes, notaPractiques;
	char continuar;

	ifstream fitxerNotes;

	fitxerNotes.open("notes.txt");
	streambuf* buffer_cin = cin.rdbuf(fitxerNotes.rdbuf());
	
	nNotes = calculaNotes(notesFinals, notesActa);
	
	cin.rdbuf(buffer_cin);
	fitxerNotes.close();

	cout << endl;
	cout << "Comment :=>>" << endl;
	cout << "Comment :=>> -----------------------------------------------" << endl;
	cout << "Comment :=>> N. de notes introduides esperat: " << nNotesEsperada << endl;
	cout << "Comment :=>> ----------" << endl;
	cout << "Comment :=>> N. de notes introduides obtingut: " << nNotes << endl;
	if (nNotesEsperada == nNotes)
		cout << "Comment :=>> CORRECTE" << endl;
	else
	{
		cout << "Comment :=>> ERROR" << endl;
		reduccio += 2;
	}
	cout << "Comment :=>> -----------------------------------------------" << endl;


	fitxerNotes.open("notes.txt");
	if (fitxerNotes.is_open())
	{
		for (int i = 0; i < N_PROVES; i++)
		{
			cout << "Comment :=>> TEST " << i + 1 << endl;
			fitxerNotes >> notaTeoria >> notaProblemes >> notaPractiques >> continuar;
			cout << "Comment :=>> Nota de teoria: " << notaTeoria << endl;
			cout << "Comment :=>> Nota de problemes: " << notaProblemes << endl;
			cout << "Comment :=>> Nota de practiques: " << notaPractiques << endl;
			cout << "Comment :=>> ----------" << endl;
			cout << "Comment :=>> Nota final esperada: " << notaFinalEsperada[i] << endl;
			cout << "Comment :=>> Nota acta esperada: " << notaActaEsperada[i] << endl;
			cout << "Comment :=>> ----------" << endl;
			cout << "Comment :=>> Nota final obtinguda: " << notesFinals[i] << endl;
			cout << "Comment :=>> Nota acta obtinguda: " << notesActa[i] << endl;
			if ((notesFinals[i] == notaFinalEsperada[i]) && (notesActa[i] == notaActaEsperada[i]))
				cout << "Comment :=>> CORRECTE" << endl;
			else
			{
				cout << "Comment :=>> ERROR" << endl;
				reduccio += 2;
			}
			cout << "Comment :=>> -----------------------------------------------" << endl;
		}
		fitxerNotes.close();
	}
	else
		reduccio = 10.0;

	return reduccio;
}

int main()
{
	float grade = 0.0;

	cout << endl << endl;
	cout << "Comment :=>> INICIANT TEST" << endl;
	cout << "Comment :=>> =============" << endl;
	cout << "Comment :=>> " << endl;

	cout << "Grade :=>> " << grade << endl;
	float reduccio = testCalculNotes();
	grade = grade + (10 - reduccio);
	if (grade < 0)
		grade = 0.0;
	if (grade == 10.0)
		cout << "Comment :=>> Final del test sense errors" << endl;
	cout << "Grade :=>> " << grade << endl;

	return 0;
}