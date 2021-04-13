//
//  Cell.hpp
//  Scrabble
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

private:
    ScoreEffect m_scoreEffect;
    Tile m_tile;
    bool m_empty;
    bool m_tilePlayed;
};


#endif /* Cell_hpp */
