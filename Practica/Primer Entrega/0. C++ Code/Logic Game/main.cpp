//
//  main.cpp
//  MP_PrimeraEntrega
//
//  Created by Enric Vergara on 03/04/2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "Board.h"
#include "Tile.h"

using namespace std;

/*-----Notes:
- S'ha de dir que en el projecte es trobarà el fitxer amb la distribució dels efectes a paraula/lletra.
    és columna row efecte
- Hauríem de dir que primer es comprova:
    - si la posició/llargària de la nova paraula és correcte
    - si totes les noves paraules resultants estan al diccionari
- VALID_POSITION ho tenia mal escrit --> VALID_POSITTOION...modificat.
- Haurem de dir que s'ha de fer en un llenguatge específic: ho estic fent amb l'anglès.

 
*/



//-------------------------------------------
//-------   Funcions Auxiliars ------------->>
void readTilesFromFile(map<char,Tile>& tiles)
{
    ifstream lettersBagFile;
    lettersBagFile.open ("data/Configuration/lettersBag.txt");
    if (lettersBagFile.is_open())
    {
        int frequency, score;
        char letter;
        
        do
        {
            lettersBagFile >> letter >> score >> frequency;
            tiles.insert(std::pair<char,Tile>(letter,Tile(letter,score)));
            
        } while ( !lettersBagFile.eof() );
        
        lettersBagFile.close();
    }
}

string wordResult_to_string (CurrentWordResult result) {
    string output = "";
    switch(result){
        case ALL_CORRECT:
            output = "ALL_CORRECT";
            break;
        case INVALID_NOT_ALIGNED:
            output = "INVALID_NOT_ALIGNED";
            break;
        case INVALID_NOT_CONNECTION:
            output = "INVALID_NOT_CONNECTION";
            break;
        case INVALID_START_NOT_IN_CENTER:
            output = "INVALID_START_NOT_IN_CENTER";
            break;
        case INVALID_WORD_OF_ONE_LETTER:
            output = "INVALID_WORD_OF_ONE_LETTER";
            break;
        case INVALID_WORDS_NOT_IN_DICTIONARY:
            output = "INVALID_WORDS_NOT_IN_DICTIONARY";
            break;
    }
    return output;
}

string positionResult_to_string (PositionResult result) {
    string output = "";
    switch(result){
        case VALID_POSITION:
            output = "VALID_POSITTIOIN";
            break;
        case INVALID_POSITION:
            output = "INVALID_POSITION";
            break;
        case NOT_EMPTY:
            output = "NOT_EMPTY";
            break;
    }
    return output;
}

void comparePointResults (int result,
                          int valid_result,
                          float ammountToSubstract,
                          float& reduccio)
{
    cout << "Comment :=>> Resultat esperat:  " << valid_result << endl;
    cout << "Comment :=>> Resultat obtingut: " << result << endl;
    if (result != valid_result){
        reduccio += ammountToSubstract;
        cout << "Comment :=>> ERROR" << endl;
    }else{
        cout << "Comment :=>> CORRECTE" << endl;
    }
    cout << "Comment :=>> " << endl;
}

void compareWordResults (CurrentWordResult result,
                         CurrentWordResult valid_result,
                         float ammountToSubstract,
                         float& reduccio)
{
    cout << "Comment :=>> Resultat esperat:  " << wordResult_to_string(valid_result) << endl;
    cout << "Comment :=>> Resultat obtingut: " << wordResult_to_string(result) << endl;
    if (result != valid_result){
        reduccio += ammountToSubstract;
        cout << "Comment :=>> ERROR" << endl;
    }else{
        cout << "Comment :=>> CORRECTE" << endl;
    }
    cout << "Comment :=>> " << endl;
}

void wordResultCannotBeValid (CurrentWordResult result,
                              float ammountToSubstract,
                              float& reduccio){
    cout << "Comment :=>> Resultat NO pot ser " << wordResult_to_string(ALL_CORRECT) << endl;
    cout << "Comment :=>> Resultat obtingut: " << wordResult_to_string(result) << endl;
    if (result == ALL_CORRECT){
        reduccio += ammountToSubstract;
        cout << "Comment :=>> ERROR" << endl;
    }else{
        cout << "Comment :=>> CORRECTE" << endl;
    }
    cout << "Comment :=>> " << endl;
}

void comparePositionResults (PositionResult result,
                             PositionResult valid_result,
                             float ammountToSubstract,
                             float& reduccio)
{
    cout << "Comment :=>> Resultat esperat:  " << positionResult_to_string(valid_result) << endl;
    cout << "Comment :=>> Resultat obtingut: " << positionResult_to_string(result) << endl;
    if (result != valid_result){
        reduccio += ammountToSubstract;
        cout << "Comment :=>> ERROR" << endl;
    }else{
        cout << "Comment :=>> CORRECTE" << endl;
    }
    cout << "Comment :=>> " << endl;
}
//------------------------------------------<<




float test_1_EstatDeCasella(map<char,Tile>& tiles)
{
    cout << "Comment :=>>" << endl;
    cout << "Comment :=>> ======================================================" << endl;
    cout << "Comment :=>> Iniciant Tests 1: Estat de la casella a l'inserir tile" << endl;
    cout << "Comment :=>> ======================================================" << endl;
    
    float reduccio = 0.0;
    Board board;
    PositionResult result, valid_result;
    
    cout << "Comment :=>> 1.1 Inserint en posició vàlida:" <<  endl;
    cout << "Comment :=>> ------------------------------" << endl;
    result = board.setTile(tiles['a'], BoardPosition(0,0));
    valid_result = VALID_POSITION;
    comparePositionResults(result, valid_result, 2, reduccio);
    
    cout << "Comment :=>> 1.2 Inserint en posicions no vàlides:" <<  endl;
    cout << "Comment :=>> ------------------------------------" << endl;
    result = board.setTile(tiles['a'], BoardPosition(-1,0));
    valid_result = INVALID_POSITION;
    comparePositionResults(result, valid_result, 2, reduccio);
    result = board.setTile(tiles['a'], BoardPosition(0,-1));
    comparePositionResults(result, valid_result, 2, reduccio);
    result = board.setTile(tiles['a'], BoardPosition(20,1));
    comparePositionResults(result, valid_result, 2, reduccio);
    result = board.setTile(tiles['a'], BoardPosition(0,20));
    comparePositionResults(result, valid_result, 2, reduccio);
    
    cout << "Comment :=>> 1.3 Inserint en posició vàlida - treure - tornar a inserir en mateixa posició:" <<  endl;
    cout << "Comment :=>> -----------------------------------------------------------------------------" << endl;
    result = board.setTile(tiles['a'], BoardPosition(3,3));
    valid_result = VALID_POSITION;
    comparePositionResults(result, valid_result, 2, reduccio);
    board.removeCurrentWord();
    result = board.setTile(tiles['a'], BoardPosition(3,3));
    valid_result = VALID_POSITION;
    comparePositionResults(result, valid_result, 2, reduccio);
    
    
    cout << "Comment :=>> 1.4 Inserint dos cops en mateixa posició vàlida:" <<  endl;
    cout << "Comment :=>> -----------------------------------------------" << endl;
    result = board.setTile(tiles['a'], BoardPosition(4,4));
    valid_result = VALID_POSITION;
    comparePositionResults(result, valid_result, 2, reduccio);
    result = board.setTile(tiles['a'], BoardPosition(4,4));
    valid_result = NOT_EMPTY;
    comparePositionResults(result, valid_result, 2, reduccio);
    
    
    return reduccio;
}


float test_2_ParaulaInicial(map<char,Tile>& tiles)
{
    cout << "Comment :=>>" << endl;
    cout << "Comment :=>> ===================================================" << endl;
    cout << "Comment :=>> Iniciant Tests 2: Inserir paraula inicial" << endl;
    cout << "Comment :=>> ===================================================" << endl;
    
    float reduccio = 0.0;
    Board board;
    int npoints;
    vector<string> wrongWords;
    CurrentWordResult result, valid_result;
    
    
    cout << "Comment :=>> 2.1 Inserint en vertical sense utilitzar el centre:" <<  endl;
    cout << "Comment :=>> ---------------------------------------------------" << endl;
    board.setTile(tiles['i'], BoardPosition(0, 0)); //BoardPosition(col, row)
    board.setTile(tiles['s'], BoardPosition(0, 1));
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = INVALID_START_NOT_IN_CENTER;
    compareWordResults(result, valid_result, 2, reduccio);
    
    board.removeCurrentWord();
    cout << "Comment :=>> 2.2 Inserint en horitzontal sense utilitzar el centre:" <<  endl;
    cout << "Comment :=>> ------------------------------------------------------" << endl;
    board.setTile(tiles['i'], BoardPosition(0,14)); //BoardPosition(col, row)
    board.setTile(tiles['s'], BoardPosition(1,14));
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = INVALID_START_NOT_IN_CENTER;
    compareWordResults(result, valid_result, 2, reduccio);
    
    
    board.removeCurrentWord();
    cout << "Comment :=>> 2.3 Inserint en el centre però llargària 1:" <<  endl;
    cout << "Comment :=>> -------------------------------------------" << endl;
    board.setTile(tiles['i'], BoardPosition(7,7));
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = INVALID_WORD_OF_ONE_LETTER;
    compareWordResults(result, valid_result, 2, reduccio);
    
    
    return reduccio;
}

float test_3_ParaulaNoAlDiccionari(map<char,Tile>& tiles)
{
    cout << "Comment :=>>" << endl;
    cout << "Comment :=>> =============================================================" << endl;
    cout << "Comment :=>> Iniciant Tests 3: Inserir paraula sense entrada al diccionari" << endl;
    cout << "Comment :=>> =============================================================" << endl;
    
    float reduccio = 0.0;
    Board board;
    int npoints;
    vector<string> wrongWords;
    CurrentWordResult result, valid_result;
    
    
    cout << "Comment :=>> 3.1 Inserir paraula horitzontal de 4 lletres sense entrada al diccionari:" <<  endl;
    cout << "Comment :=>>    5 6 7 8 9" <<  endl;
    cout << "Comment :=>>    ---------" <<  endl;
    cout << "Comment :=>> 6| - - - - -" <<  endl;
    cout << "Comment :=>> 7| O O O O -" <<  endl;
    cout << "Comment :=>> 8| - - - - -" <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    board.setTile(tiles['o'], BoardPosition(5,7)); //BoardPosition(col, row)
    board.setTile(tiles['o'], BoardPosition(6,7));
    board.setTile(tiles['o'], BoardPosition(7,7));
    board.setTile(tiles['o'], BoardPosition(8,7));
    
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = INVALID_WORDS_NOT_IN_DICTIONARY;
    compareWordResults(result, valid_result, 2, reduccio);
    
    
    board.removeCurrentWord();
    cout << "Comment :=>> 3.2 Inserir paraula vertical de 3 lletres sense entrada al diccionari:" <<  endl;
    cout << "Comment :=>>    5 6 7 8 9" <<  endl;
    cout << "Comment :=>>    ---------" <<  endl;
    cout << "Comment :=>> 6| - - O - -" <<  endl;
    cout << "Comment :=>> 7| - - O - -" <<  endl;
    cout << "Comment :=>> 8| - - O - -" <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    board.setTile(tiles['o'], BoardPosition(7,6)); //BoardPosition(col, row)
    board.setTile(tiles['o'], BoardPosition(7,7));
    board.setTile(tiles['o'], BoardPosition(7,8));
    
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = INVALID_WORDS_NOT_IN_DICTIONARY;
    compareWordResults(result, valid_result, 2, reduccio);
    
    return reduccio;
}

float test_4_InserirSegonaParaula(map<char,Tile>& tiles)
{
    cout << "Comment :=>>" << endl;
    cout << "Comment :=>> ===================================================" << endl;
    cout << "Comment :=>> Iniciant Tests 4: Inserir dues paraules al board" << endl;
    cout << "Comment :=>> ===================================================" << endl;
    
    float reduccio = 0.0;
    Board board;
    int npoints;
    vector<string> wrongWords;
    CurrentWordResult result, valid_result;
    
    
    cout << "Comment :=>> 4.1 Inserir paraula vàlida horitzontal de 4 lletres:" <<  endl;
    cout << "Comment :=>>    5 6 7 8 9" <<  endl;
    cout << "Comment :=>>    ---------" <<  endl;
    cout << "Comment :=>> 6| - - - - -" <<  endl;
    cout << "Comment :=>> 7| L O S E -" <<  endl;
    cout << "Comment :=>> 8| - - - - -" <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    board.setTile(tiles['l'], BoardPosition(5,7)); //BoardPosition(col, row)
    board.setTile(tiles['o'], BoardPosition(6,7));
    board.setTile(tiles['s'], BoardPosition(7,7));
    board.setTile(tiles['e'], BoardPosition(8,7));
    
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = ALL_CORRECT;
    compareWordResults(result, valid_result, 2, reduccio);
    board.sendCurrentWordToBoard();
    
    cout << "Comment :=>> 4.2 Inserir paraula horitzontal de 3 lletres no connectada:" <<  endl;
    cout << "Comment :=>>    5 6 7 8 9" <<  endl;
    cout << "Comment :=>>    ---------" <<  endl;
    cout << "Comment :=>> 5| T H E - -" <<  endl;
    cout << "Comment :=>> 6| - - - - -" <<  endl;
    cout << "Comment :=>> 7| L O S E -" <<  endl;
    cout << "Comment :=>> 8| - - - - -" <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    
    board.setTile(tiles['t'], BoardPosition(5,5)); //BoardPosition(col, row)
    board.setTile(tiles['h'], BoardPosition(6,5));
    board.setTile(tiles['e'], BoardPosition(7,5));
    
    result = board.checkCurrentWord(npoints, wrongWords);
    wordResultCannotBeValid(result, 2, reduccio);
    board.removeCurrentWord();
    
    cout << "Comment :=>> 4.3 Inserir paraula vertical de 3 lletres no connectada:" <<  endl;
    cout << "Comment :=>>    3 4 5 6 7 8 9" <<  endl;
    cout << "Comment :=>>    -------------" <<  endl;
    cout << "Comment :=>> 3| T - - - - - -" <<  endl;
    cout << "Comment :=>> 4| H - - - - - -" <<  endl;
    cout << "Comment :=>> 5| E - - - - - -" <<  endl;
    cout << "Comment :=>> 6| - - - - - - -" <<  endl;
    cout << "Comment :=>> 7| - - L O S E -" <<  endl;
    cout << "Comment :=>> 8| - - - - - - -" <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    
    board.setTile(tiles['t'], BoardPosition(3,3)); //BoardPosition(col, row)
    board.setTile(tiles['h'], BoardPosition(3,4));
    board.setTile(tiles['e'], BoardPosition(3,5));
    
    result = board.checkCurrentWord(npoints, wrongWords);
    wordResultCannotBeValid(result, 2, reduccio);
    board.removeCurrentWord();
    
    cout << "Comment :=>> 4.4 Inserir paraula no alineada:" <<  endl;
    cout << "Comment :=>>    5 6 7 8 9" <<  endl;
    cout << "Comment :=>>    ---------" <<  endl;
    cout << "Comment :=>> 3| _ _ _ _ _" <<  endl;
    cout << "Comment :=>> 4| _ _ _ S -" <<  endl;
    cout << "Comment :=>> 5| _ _ _ _ _" <<  endl;
    cout << "Comment :=>> 6| _ _ _ H -" <<  endl;
    cout << "Comment :=>> 7| L O S E -" <<  endl;
    cout << "Comment :=>> 8| _ _ _ _ _" <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    
    board.setTile(tiles['s'], BoardPosition(8,4)); //BoardPosition(col, row)
    board.setTile(tiles['h'], BoardPosition(8,6));
    
    
    result = board.checkCurrentWord(npoints, wrongWords);
    wordResultCannotBeValid(result, 2, reduccio);
    board.removeCurrentWord();
    
    
    cout << "Comment :=>> 4.5 Inserir paraula vertical de tres lletres correcte:" <<  endl;
    cout << "Comment :=>>    5 6 7 8 9" <<  endl;
    cout << "Comment :=>>    ---------" <<  endl;
    cout << "Comment :=>> 5| - - - S -" <<  endl;
    cout << "Comment :=>> 6| - - - H -" <<  endl;
    cout << "Comment :=>> 7| L O S E -" <<  endl;
    cout << "Comment :=>> 8| - - - - -" <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    board.setTile(tiles['s'], BoardPosition(8,5)); //BoardPosition(col, row)
    board.setTile(tiles['h'], BoardPosition(8,6));
    
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = ALL_CORRECT;
    compareWordResults(result, valid_result, 2, reduccio);
    board.sendCurrentWordToBoard();
    
    
    cout << "Comment :=>> 4.6 Inserir paraula vertical de 5 lletres correcte:" <<  endl;
    cout << "Comment :=>>    5 6 7 8 9 10" <<  endl;
    cout << "Comment :=>>    ------------" <<  endl;
    cout << "Comment :=>> 5| - - - S - - " <<  endl;
    cout << "Comment :=>> 6| - - - H E - " <<  endl;
    cout << "Comment :=>> 7| L O S E R _ " <<  endl;
    cout << "Comment :=>> 8| - - - - O - " <<  endl;
    cout << "Comment :=>> 9| - - - - D - " <<  endl;
    cout << "Comment :=>>10| - - - - E - " <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    board.setTile(tiles['e'], BoardPosition(9,6)); //BoardPosition(col, row)
    board.setTile(tiles['r'], BoardPosition(9,7));
    board.setTile(tiles['o'], BoardPosition(9,8));
    board.setTile(tiles['d'], BoardPosition(9,9));
    board.setTile(tiles['e'], BoardPosition(9,10));
    
    
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = ALL_CORRECT;
    compareWordResults(result, valid_result, 2, reduccio);
    board.sendCurrentWordToBoard();
    
    
    cout << "Comment :=>> 4.7 Inserir paraula horitzontal de 2 lletres correcte:" <<  endl;
    cout << "Comment :=>>    5 6 7 8 9 10" <<  endl;
    cout << "Comment :=>>    ------------" <<  endl;
    cout << "Comment :=>> 5| - - - S - - " <<  endl;
    cout << "Comment :=>> 6| - - - H E - " <<  endl;
    cout << "Comment :=>> 7| L O S E R _ " <<  endl;
    cout << "Comment :=>> 8| - N O - O - " <<  endl;
    cout << "Comment :=>> 9| - - - - D - " <<  endl;
    cout << "Comment :=>>10| - - - - E - " <<  endl;
    cout << "Comment :=>> ----------------------------------------------------" << endl;
    board.setTile(tiles['n'], BoardPosition(6,8)); //BoardPosition(col, row)
    board.setTile(tiles['o'], BoardPosition(7,8));
    
    
    result = board.checkCurrentWord(npoints, wrongWords);
    valid_result = ALL_CORRECT;
    compareWordResults(result, valid_result, 2, reduccio);
    board.sendCurrentWordToBoard();
    
    return reduccio;
}



float test_5_VerificarPuntuacio(map<char,Tile>& tiles)
{
    cout << "Comment :=>>" << endl;
    cout << "Comment :=>> =====================================" << endl;
    cout << "Comment :=>> Iniciant Tests 5: Verificar puntuació" << endl;
    cout << "Comment :=>> =====================================" << endl;
    
    float reduccio = 0.0;
    Board board;
    int npoints;
    vector<string> wrongWords;
    int valid_result = 0;
    
    
    cout << "Comment :=>> Taulell inicial amb punutació:    " <<  endl;
    cout << "Comment :=>>                                   " <<  endl;
    cout << "Comment :=>>     7   8   9   10  11  12  13  14" <<  endl;
    cout << "Comment :=>>    -------------------------------" <<  endl;
    cout << "Comment :=>> 5|  -   -  TL.  -   -   -  TL.  - " <<  endl;
    cout << "Comment :=>> 6|  -  DL.  -   -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 7|  *   -   -   -  DL.  -   -  TP." <<  endl;
    cout << "Comment :=>> 8|  -  DL.  -   -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 9|  -   -  TL.  -   -   -  TL.  - " <<  endl;
    cout << "Comment :=>>10|  -   -   -  DP.  -   -   -   - " <<  endl;
    cout << "Comment :=>>    -------------------------------" << endl;
    cout << "Comment :=>>                                          " << endl;
    cout << "Comment :=>> 5.1 Inserint paraula victoria:" <<  endl;
    cout << "Comment :=>>     7   8   9   10  11  12  13  14" <<  endl;
    cout << "Comment :=>>    -------------------------------" <<  endl;
    cout << "Comment :=>> 5|  -   -  TL.  -   -   -  TL.  - " <<  endl;
    cout << "Comment :=>> 6|  -  DL.  -   -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 7|  V4  I1  C3  T1  O1  R1  I1  A1" <<  endl;
    cout << "Comment :=>> 8|  -  DL.  -   -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 9|  -   -  TL.  -   -   -  TL.  - " <<  endl;
    cout << "Comment :=>>10|  -   -   -  DP.  -   -   -   - " <<  endl;
    cout << "Comment :=>>    -------------------------------" << endl;
    board.setTile(tiles['v'], BoardPosition(7,7)); //BoardPosition(col, row)
    board.setTile(tiles['i'], BoardPosition(8,7));
    board.setTile(tiles['c'], BoardPosition(9,7));
    board.setTile(tiles['t'], BoardPosition(10,7));
    board.setTile(tiles['o'], BoardPosition(11,7));
    board.setTile(tiles['r'], BoardPosition(12,7));
    board.setTile(tiles['i'], BoardPosition(13,7));
    board.setTile(tiles['a'], BoardPosition(14,7));
    
    board.checkCurrentWord(npoints, wrongWords);
    valid_result = 84;
    comparePointResults(npoints, valid_result, 2, reduccio);
    board.sendCurrentWordToBoard();
    
    
    cout << "Comment :=>>                                          " << endl;
    cout << "Comment :=>> 5.1 Inserint paraula tickle:" <<  endl;
    cout << "Comment :=>>     7   8   9   10  11  12  13  14" <<  endl;
    cout << "Comment :=>>    -------------------------------" <<  endl;
    cout << "Comment :=>> 5|  -   -   T1  -   -   -  TL.  - " <<  endl;
    cout << "Comment :=>> 6|  -  DL.  I1  -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 7|  V4  I1  C3  T1  O1  R1  I1  A1" <<  endl;
    cout << "Comment :=>> 8|  -  DL.  K5  -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 9|  -   -   L1  -   -   -  TL.  - " <<  endl;
    cout << "Comment :=>>10|  -   -   E1 DP.  -   -   -   - " <<  endl;
    cout << "Comment :=>>    -------------------------------" << endl;
    board.setTile(tiles['t'], BoardPosition(9,5)); //BoardPosition(col, row)
    board.setTile(tiles['i'], BoardPosition(9,6));
    board.setTile(tiles['c'], BoardPosition(9,7));
    board.setTile(tiles['k'], BoardPosition(9,8));
    board.setTile(tiles['l'], BoardPosition(9,9));
    board.setTile(tiles['e'], BoardPosition(9,10));
    
    
    board.checkCurrentWord(npoints, wrongWords);
    valid_result = 16;
    comparePointResults(npoints, valid_result, 2, reduccio);
    board.sendCurrentWordToBoard();
    
    
    cout << "Comment :=>>                                          " << endl;
    cout << "Comment :=>> 5.1 Inserint paraules le, ex i ex:" <<  endl;
    cout << "Comment :=>>     7   8   9   10  11  12  13  14" <<  endl;
    cout << "Comment :=>>    -------------------------------" <<  endl;
    cout << "Comment :=>> 5|  -   -   T1  -   -   -  TL.  - " <<  endl;
    cout << "Comment :=>> 6|  -  DL.  I1  -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 7|  V4  I1  C3  T1  O1  R1  I1  A1" <<  endl;
    cout << "Comment :=>> 8|  -  DL.  K5  -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 9|  -   -   L1  E1  -   -  TL.  - " <<  endl;
    cout << "Comment :=>>10|  -   -   E1  X8  -   -   -   - " <<  endl;
    cout << "Comment :=>>    -------------------------------" << endl;
    board.setTile(tiles['e'], BoardPosition(10,9)); //BoardPosition(col, row)
    board.setTile(tiles['x'], BoardPosition(10,10)); //BoardPosition(col, row)
    
    
    board.checkCurrentWord(npoints, wrongWords);
    valid_result = 38;
    comparePointResults(npoints, valid_result, 2, reduccio);
    board.sendCurrentWordToBoard();
    
    
    cout << "Comment :=>>                                          " << endl;
    cout << "Comment :=>> 5.1 Inserint paraula extra:" <<  endl;
    cout << "Comment :=>>     7   8   9   10  11  12  13  14" <<  endl;
    cout << "Comment :=>>    -------------------------------" <<  endl;
    cout << "Comment :=>> 5|  -   -   T1  -   -   -  TL.  - " <<  endl;
    cout << "Comment :=>> 6|  -  DL.  I1  -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 7|  V4  I1  C3  T1  O1  R1  I1  A1" <<  endl;
    cout << "Comment :=>> 8|  -  DL.  K5  -   -  DL.  -   - " <<  endl;
    cout << "Comment :=>> 9|  -   -   L1  E1  -   -  TL.  - " <<  endl;
    cout << "Comment :=>>10|  -   -   E1  X8  T1  R1  A1  - " <<  endl;
    cout << "Comment :=>>    -------------------------------" << endl;
    board.setTile(tiles['t'], BoardPosition(11,10)); //BoardPosition(col, row)
    board.setTile(tiles['r'], BoardPosition(12,10));
    board.setTile(tiles['a'], BoardPosition(13,10));
    
    board.checkCurrentWord(npoints, wrongWords);
    valid_result = 12;
    comparePointResults(npoints, valid_result, 2, reduccio);
    board.sendCurrentWordToBoard();
    
    return reduccio;
}



int main(int argc, const char * argv[]) {
    
    float grade = 0.0;

    cout << endl << endl;
    cout << "Comment :=>> INICIANT TESTS" << endl;
    cout << "Comment :=>> ==============" << endl;
    cout << "Comment :=>> " << endl;

    cout << "Grade :=>> " << grade << endl;
    
    map<char,Tile> tiles;
    readTilesFromFile(tiles);
    
    float reduccio = 0;
    //-------------------------------------------------
    //----TESTS 1: Estat de la casella a l'inserir tile
    reduccio = test_1_EstatDeCasella(tiles);
    grade = grade + (10 - reduccio);
    cout << "Grade :=>> " << grade << endl;
    
    
    //-------------------------------------------------
    //----TESTS 2: Inserir paraula inicial
    reduccio = test_2_ParaulaInicial(tiles);
    grade = grade + (10 - reduccio);
    cout << "Grade :=>> " << grade << endl;
    
    
    //-------------------------------------------------
    //----TESTS 3: Paraula no al diccionari
    reduccio = test_3_ParaulaNoAlDiccionari(tiles);
    grade = grade + (10 - reduccio);
    cout << "Grade :=>> " << grade << endl;
    
    
    //-------------------------------------------------
    //----TESTS 4: Inserir segona paraula
    reduccio = test_4_InserirSegonaParaula(tiles);
    grade = grade + (10 - reduccio);
    cout << "Grade :=>> " << grade << endl;
    
    
    //-------------------------------------------------
    //----TESTS 5: Verificar puntuació
    reduccio = test_5_VerificarPuntuacio(tiles);
    grade = grade + (10 - reduccio);
    cout << "Grade :=>> " << grade << endl;
    
        
    
    
    if (grade < 0){
        grade = 0.0;
    }
    if (grade == 10.0){
        cout << "Comment :=>> Final del test sense errors" << endl;
    }
    
    cout << "Grade :=>> " << grade << endl;
    return 0;
}




