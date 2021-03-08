//
//  PlayerTile.h
//  Scrabble
//
//  Created by Enric Vergara on 21/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef PlayerTile_h
#define PlayerTile_h

#include <stdio.h>
#include "Tile.h"
#include "TileRenderer.h"
#include "Board.h"


class PlayerTile
{
public:
    PlayerTile();
    ~PlayerTile();
    
    void    Render          (TileRenderer& renderer, bool small);
    bool    IsOnBoard       () {return m_bIsOnBoard;}
    bool    IsEmpty         () {return m_bIsEmpty;}
    void    LeaveOnBoard    () {m_bIsOnBoard = true;};
    void    PickupFromBoard () {m_bIsOnBoard = false;};
    void    PlayTile        () {m_bIsEmpty = true;}
    void    SetTile         (const Tile& tile);
    void    SetPosition     (float posX, float posY);
    void    Recall          ();
    float   GetPosX         () {return m_fPosX;}
    float   GetPosY         () {return m_fPosY;}
    Tile&   GetTile         () {return m_oTile;}
    BoardPosition   GetBoardPos () {return m_oBoardPosition;}
    void            SetBoardPos (BoardPosition pos) {m_oBoardPosition = pos;}
    
    
    
private:
    float           m_fPosX;
    float           m_fPosY;
    Tile            m_oTile;
    bool            m_bIsOnBoard;
    bool            m_bIsEmpty;
    BoardPosition   m_oBoardPosition;
};


#endif /* PlayerTile_h */
