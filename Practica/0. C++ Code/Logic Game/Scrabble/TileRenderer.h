//
//  TileRenderer.hpp
//  Letris
//
//  Created by Enric Vergara on 15/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef TileRenderer_hpp
#define TileRenderer_hpp

#include "../joc.h"
#include <stdio.h>

//const int MAX_ALPHABET_ENGLISH = 27;
const int MAX_ALPHABET_ENGLISH = 26;

class TileRenderer
{
public:
    TileRenderer();
    ~TileRenderer();
    
    void Render (char letter, int posX, int posY, bool small);
    
private:
    Sprite  m_aLetters_big[MAX_ALPHABET_ENGLISH];
    Sprite  m_aLetters_small[MAX_ALPHABET_ENGLISH];
};

#endif /* TileRenderer_hpp */
