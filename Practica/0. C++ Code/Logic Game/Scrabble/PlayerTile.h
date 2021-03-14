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
#include "Board.h"


class PlayerTile
{
public:
    PlayerTile();
    ~PlayerTile();
    
    void    render          (bool small);
    bool    isOnBoard       () {return m_bIsOnBoard;}
    bool    isEmpty         () {return m_bIsEmpty;}
    void    leaveOnBoard    () {m_bIsOnBoard = true;};
    void    pickupFromBoard () {m_bIsOnBoard = false;};
    void    playTile        () {m_bIsEmpty = true;}
    void    setTile         (const Tile& tile);
    void    setPosition     (float posX, float posY);
    void    recall          ();
    float   getPosX         () {return m_fPosX;}
    float   getPosY         () {return m_fPosY;}
    Tile&   getTile         () {return m_oTile;}
    BoardPosition   getBoardPos () {return m_oBoardPosition;}
    void            setBoardPos (BoardPosition pos) {m_oBoardPosition = pos;}
    
    
    
private:
    float           m_fPosX;
    float           m_fPosY;
    Tile            m_oTile;
    bool            m_bIsOnBoard;
    bool            m_bIsEmpty;
    BoardPosition   m_oBoardPosition;
};


#endif /* PlayerTile_h */
