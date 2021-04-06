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
    
    bool        isEmpty         () {return m_bEmpty;}
    ScoreEffect getScoreEffect  () {return m_eScoreEffect;}
    void        setScoreEffect  (ScoreEffect effect) {m_eScoreEffect = effect;}
    Tile        getTile         () {return m_oTile;}
    void        setTile         (Tile tile);
    void        removeTile      () {m_bEmpty = true;}
    void        setTilePlayed   () {m_bTilePlayed = true;}
    bool        isTilePlayed    () {return m_bTilePlayed;}
private:
    ScoreEffect m_eScoreEffect;
    Tile        m_oTile;
    bool        m_bEmpty;
    bool        m_bTilePlayed;
};


#endif /* Cell_hpp */
