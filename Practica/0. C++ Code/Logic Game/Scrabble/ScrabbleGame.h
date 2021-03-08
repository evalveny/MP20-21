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
#include "TileRenderer.h"
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
    
    void UpdateAndRender    (int mousePosX, int mousePosY,
                             bool mouseIsPressed, bool mouseStatus,
                             float deltaTime);
    
    void ChangePlayer       ();
    bool HasAnyoneWon       (int& winner);
    
private:
    TileRenderer    m_oTileRenderer;
    Board           m_oBoard;
    Player          m_aPlayers[NUM_PLAYERS];
    int             m_iCurrentPlayer;
    LettersBag      m_oLettersBag;
    Button          m_oButton_Recall;
    Button          m_oButton_Shuffle;
    Button          m_oButton_Send;
    Button          m_oButton_Pass;
    Sprite          m_oSpriteBackground;
    NFont           m_oFont_Info;
    NFont           m_oFont_CorrectMove;
    NFont           m_oFont_IncorrectMove;
    string          m_sCorrectMove;
    string          m_sIncorrectMove;
    
};

#endif /* ScrabbleGame_hpp */
