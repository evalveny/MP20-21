//
//  TileRenderer.cpp
//  Letris
//
//  Created by Enric Vergara on 15/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "TileRenderer.h"
#include <string>
using namespace std;

TileRenderer::TileRenderer(){
    for (int i = 0; i < MAX_ALPHABET_ENGLISH; i++){
        string path_big = "data/Letters/Big/" + to_string(i) + ".png";
        string path_small = "data/Letters/Small/" + to_string(i) + ".png";
        m_aLetters_big[i].create(path_big.c_str());
        m_aLetters_small[i].create(path_small.c_str());
    }
        
}

TileRenderer::~TileRenderer(){
    
}

void TileRenderer::Render (char letter, int posX, int posY, bool small){
    int index = letter - 'a';
        if (small){
            m_aLetters_small[index].draw(posX, posY);
        }else{
            m_aLetters_big[index].draw(posX, posY);
        }
}
