//
//  ScrabbleGame.hpp
//  Letris
//
//  Created by Enric Vergara on 13/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef ScrabbleGame_hpp
#define ScrabbleGame_hpp

#include <stdio.h>
#include "Board.h"
#include "Player.h"
#include "LettersBag.h"
#include "Button.h"
#include "../joc.h"

const int NUM_PLAYERS = 3;

using namespace std;

class ScrabbleGame
{
public:
    ScrabbleGame();
    ~ScrabbleGame();
    
    void updateAndRender    (int mousePosX, int mousePosY,
                             bool mouseIsPressed, bool mouseStatus,
                             float deltaTime);
    
    void changePlayer       ();
    bool hasAnyoneWon       (int& winner);
    
private:
    Board           m_oBoard;
    Player          m_aPlayers[NUM_PLAYERS];
    int             m_iCurrentPlayer;
    LettersBag      m_oLettersBag;
    Button          m_oButton_Recall;
    Button          m_oButton_Shuffle;
    Button          m_oButton_Send;
    Button          m_oButton_Pass;
    string          m_sCorrectMove;
    string          m_sIncorrectMove;
    
};

#endif /* ScrabbleGame_hpp */
