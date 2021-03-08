//
//  Tile.hpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <stdio.h>

class Tile
{
public:
    Tile();
    Tile(char letter, unsigned int score);
    ~Tile();
    
    char            GetLetter   () {return m_cLetter;}
    unsigned int    GetScore    () {return m_uiScore;}
    //void            SetLetter   (char letter) {m_cLetter = letter;}
    //void            SetScore    (unsigned int score) {m_uiScore = score;}
    
    
private:
    char            m_cLetter;
    unsigned int    m_uiScore;
};


#endif /* Tile_hpp */
