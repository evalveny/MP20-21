//
//  Tile.hpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp


class Tile
{
public:
    Tile();
    Tile(char letter, unsigned int score);
    ~Tile();
    
    
    char            getLetter   () {return m_cLetter;}
    unsigned int    getScore    () {return m_uiScore;}
    
    
private:
    char            m_cLetter;
    unsigned int    m_uiScore;
};


#endif /* Tile_hpp */
