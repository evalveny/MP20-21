//
//  LettersBag.hpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef LettersBag_hpp
#define LettersBag_hpp

#include <stdio.h>
#include "Tile.h"
#include <vector>
using namespace std;

class LettersBag
{
public:
    LettersBag();
    ~LettersBag();
    
    Tile    getLetter       ();
    bool    isEmpty         () {return m_aLetters.size() == 0;}
    int     tilesInTheBag   () {return (int)m_aLetters.size();}
private:
    vector<Tile>    m_aLetters;
};



#endif /* LettersBag_hpp */
