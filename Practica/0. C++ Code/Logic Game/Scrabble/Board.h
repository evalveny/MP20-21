//
//  Board.hpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "../joc.h"
#include "Cell.h"
#include "Dictionary.h"
#include "BoardPosition.h"
#include "WordFinder.h"
#include "Scrabble.h"

using namespace std;

// (0,0) ----> X
//   |  (col:0, row:0), (col:1, row:0)
//   |  (col:0, row:1), (col:1, row:1)
//   |     <- Size X (width)->
//   |      Coordinate system
//   v
//   Y

typedef enum {
    VALID_POSITTIOIN = 0,
    INVALID_POSITION,
    NOT_EMPTY
} PositionResult;


//-----------------------------



class Board
{
public:
    Board();
    ~Board();
    
    PositionResult  setTile                 (Tile &tile, int posX, int posY,
                                             BoardPosition& boardPos);
    bool            checkNewWords           (int& points);
    bool            checkPosition           (std::string& errorMsg);
    void            render                  ();
    void            removeCurrentWord       ();
    void            removeLetter            (BoardPosition boardPos);
    vector<string>  getWrongWords           () {return m_aWrongWords;}
    void            sendCurrentWordToBoard  ();
    int             getScoreCurrentWord     () {return m_oWordFinder.getTotalScore();}
    
private:
    Cell                m_aCells[BOARD_COLS_AND_ROWS][BOARD_COLS_AND_ROWS];
    Sprite              m_oSprite_Board;
    Dictionary          m_oDictionary;
    WordFinder          m_oWordFinder;
    VectorOfPositions   m_aCurrentWord;
    bool                m_bIsFirstWord;
    
    //---Members for the search of new word:
    
    vector<string>      m_aWrongWords;
    
    //Internal functions:
    
    void searchForWrongWords ();
    
    
};

#endif /* Board_hpp */
