//
//  WordFinder.hpp
//  MP_Practica
//
//  Created by Enric Vergara on 14/03/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef WordFinder_hpp
#define WordFinder_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "Cell.h"
#include "BoardPosition.h"
#include "..\Scrabble_Defs.h"


using namespace std;

class WordFinder
{
public:
    WordFinder(): m_iTotalScore(0) {};
    ~WordFinder() {}
    
    void            searchForAllNewWords    (Cell cells[][BOARD_COLS_AND_ROWS],
                                             const VectorOfPositions& currentWord);
    int             getTotalScore           () const {return m_iTotalScore;}
    void            resetTotalScore         () {m_iTotalScore = 0;}
    vector<string>& getNewWords             () {return m_aNewWords;}
    
    
private:
    int                 m_iTotalScore;
    int                 m_iMultiplyFactorOfNewWord;
    int                 m_iScoreOfNewWord;
    string              m_sNewWord;
    bool                m_bHasLetterOfCurrentWord;
    vector<string>      m_aNewWords;
    
private:
    void resetWord          ();
    void finishSearchInLine ();
    bool isInTheCurrentWord (int col, int row, const VectorOfPositions& currentWord);
    void readCell           (Cell cells[][BOARD_COLS_AND_ROWS],
                             int col, int row, const VectorOfPositions& currentWord);
    
};

#endif /* WordFinder_hpp */
