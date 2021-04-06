//
//  Player.hpp
//  Letris
//
//  Created by Enric Vergara on 20/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Tile.h"
#include "PlayerTile.h"
#include "Board.h"
#include "LettersBag.h"

const int NUM_MAX_PLAYER_TILES = 7;
const int PLAYER_SEPATION_BETWEEN_TILE = 5;
const int PLAYER_TILE_SIZE = 100;
const int PLAYER_TILE_POS_Y = BOARD_POS_Y + BOARD_SIZE + 10;
const int PLAYER_TILE_POS_X = SCREEN_SIZE_X*0.5 - ((PLAYER_TILE_SIZE+PLAYER_SEPATION_BETWEEN_TILE)*NUM_MAX_PLAYER_TILES)*0.5;


class Player
{
public:
    Player();
    ~Player();
    
    void    update                  (int mousePosX, int mousePosY,
                                     bool mouseIsPressed, bool mouseStatus,
                                     float deltaTime, Board& board,
                                     std::string& correctMove,
                                     std::string& incorrectMove);
    void    render                  ();
    void    addTiles                (LettersBag& bag);
    void    sendCurrentWordToBoard  (Board& board);
    void    recall                  ();
    void    shuffle                 ();
    bool    anyTileOnTheBoard       ();
    bool    allTilesPlayed          ();
    int     getScore                () {return m_iScore;}
    void    checkBoard              (Board & board,
                                     std::string& correctMove,
                                     std::string& incorrectMove);
    
private:
    int         m_iScore;
    PlayerTile  m_aTiles[NUM_MAX_PLAYER_TILES];
    bool        m_bIsDragging;
    int         m_iTileDragging;
    
};


#endif /* Player_hpp */
