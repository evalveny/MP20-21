//
//  Board.hpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "Scrabble.h"
#include <stdio.h>
#include <string>


#include "Cell.h"
#include "Dictionary.h"
#include "BoardPosition.h"
#include "WordFinder.h"


using namespace std;

// (0,0) ----> X
//   |  (col:0, row:0), (col:1, row:0)
//   |  (col:0, row:1), (col:1, row:1)
//   |     <- Size X (width)->
//   |      Coordinate system
//   v
//   Y

typedef enum {
    VALID_POSITION = 0,
    INVALID_POSITION,
    NOT_EMPTY
} PositionResult;

typedef enum {
    ALL_CORRECT = 0,
    //Tiles must be vertically or horizontally aligned and together
    INVALID_NOT_ALIGNED,
    //At least one letter must be next to the rest of the words.
    INVALID_NOT_CONNECTION,
    //You have to start using the center position
    INVALID_START_NOT_IN_CENTER,
    //Only words of two or more letters
    INVALID_WORD_OF_ONE_LETTER,
    //The new words are not in the dictionary
    INVALID_WORDS_NOT_IN_DICTIONARY,
} CurrentWordResult;
//-----------------------------




class Board
{
public:
    Board();
    ~Board();
    
    
    void                debugRender             ();
    PositionResult      setTile                 (Tile &tile, const BoardPosition& boardPos);
    CurrentWordResult   checkCurrentWord        (int& points, vector<string>& wrongWords);
    void                sendCurrentWordToBoard  ();
    void                removeCurrentWord       ();
    
        
private:
    Cell                m_aCells[BOARD_COLS_AND_ROWS][BOARD_COLS_AND_ROWS];
    Dictionary          m_oDictionary;
    WordFinder          m_oWordFinder;
    VectorOfPositions   m_aCurrentWord;
    bool                m_bIsFirstWord;
    vector<string>      m_aWrongWords;
    
};

#endif /* Board_hpp */
