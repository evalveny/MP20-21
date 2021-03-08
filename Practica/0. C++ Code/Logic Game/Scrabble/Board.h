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
#include "TileRenderer.h"
#include "Dictionary.h"

using namespace std;

// (0,0) ----> X
//   |  (col:0, row:0), (col:1, row:0)
//   |  (col:0, row:1), (col:1, row:1)
//   |     <- Size X (width)->
//   |      Coordinate system
//   v
//   Y


//----Auxiliar Declarations------->
const int BOARD_SIZE = 600;
const int BOARD_POS_X = SCREEN_SIZE_X*0.5 - BOARD_SIZE*0.5;
const int BOARD_POS_Y = 40;

const int BOARD_COLS_AND_ROWS = 15;
const int BOARD_TILE_SIZE = BOARD_SIZE / BOARD_COLS_AND_ROWS;

typedef enum {
    VALID_POSITTIOIN = 0,
    INVALID_POSITION,
    NOT_EMPTY
} PositionResult;

class BoardPosition {
public:
    BoardPosition(): m_iRow(-1), m_iCol(-1) {}
    BoardPosition(int col, int row): m_iRow(row), m_iCol(col) {}
    int     GetCol  () {return m_iCol;}
    int     GetRow  () {return m_iRow;}
    void    SetCol  (int col) {m_iCol = col;}
    void    SetRow  (int row) {m_iRow = row;}
private:
    int m_iRow;
    int m_iCol;
};
typedef std::vector<BoardPosition> VectorOfPositions;
//-----------------------------



class Board
{
public:
    Board();
    ~Board();
    
    PositionResult  SetTile                 (Tile &tile, int posX, int posY,
                                             BoardPosition& boardPos);
    bool            CheckNewWords           (int& points);
    bool            CheckPosition           (std::string& errorMsg);
    void            Render                  (TileRenderer& renderer);
    void            RemoveCurrentWord       ();
    void            RemoveLetter            (BoardPosition boardPos);
    vector<string>  GetWrongWords           () {return m_aWrongWords;}
    void            SendCurrentWordToBoard  ();
    int             GetScoreCurrentWord     () {return m_iTotalScore;}
    
private:
    Cell                m_aCells[BOARD_COLS_AND_ROWS][BOARD_COLS_AND_ROWS];
    Sprite              m_oSprite_Board;
    Dictionary          m_oDictionary;
    VectorOfPositions   m_aCurrentWord;
    bool                m_bIsFirstWord;
    
    //---Members for the search of new word:
    int                 m_iTotalScore;
    int                 m_iMultiplyFactorOfNewWord;
    int                 m_iScoreOfNewWord;
    string              m_sNewWord;
    bool                m_bHasLetterOfCurrentWord;
    vector<string>      m_aNewWords;
    vector<string>      m_aWrongWords;
    
    //Internal functions:
    
    void            FinishSearchInLine  ();
    void            ReadCell            (int col, int row);
    void            ResetWord           ();
    void            SearchForNewWords   ();
    void            SearchForWrongWords ();
    bool            IsInTheCurrentWord  (int col, int row);
    
};

#endif /* Board_hpp */
