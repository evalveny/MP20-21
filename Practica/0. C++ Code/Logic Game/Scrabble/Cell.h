//
//  Cell.hpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include "Tile.h"
#include "TileRenderer.h"

typedef enum {
    DL = 0,
    TL,
    DW,
    TW,
    NO_EFFECT
} ScoreEffect;

class Cell
{
public:
    Cell(): m_bEmpty(true), m_eScoreEffect(NO_EFFECT), m_bTilePlayed(false) {}
    ~Cell() {}
    
    void        Render          (int pos_x, int pos_y, TileRenderer& renderer);
    bool        IsEmpty         () {return m_bEmpty;}
    ScoreEffect GetScoreEffect  () {return m_eScoreEffect;}
    void        SetScoreEffect  (ScoreEffect effect) {m_eScoreEffect = effect;}
    Tile        GetTile         () {return m_oTile;}
    void        SetTile         (Tile tile);
    void        RemoveTile      () {m_bEmpty = true;}
    void        SetTilePlayed   () {m_bTilePlayed = true;}
    bool        IsTilePlayed    () {return m_bTilePlayed;}
private:
    ScoreEffect m_eScoreEffect;
    Tile        m_oTile;
    bool        m_bEmpty;
    bool        m_bTilePlayed;
};


#endif /* Cell_hpp */
