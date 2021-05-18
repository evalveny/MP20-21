//
//  Tile.cpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "Tile.h"

Tile::Tile()
:m_cLetter('?')
,m_uiScore(0)
{}

Tile::Tile(char letter, unsigned int score)
:m_cLetter(letter)
,m_uiScore(score)
{}

Tile::~Tile(){
    
}

