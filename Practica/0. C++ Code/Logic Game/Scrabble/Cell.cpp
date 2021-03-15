//
//  Cell.cpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "Cell.h"
#include "../GraphicManager.h"

void Cell::render (int pos_x, int pos_y){
    if (!m_bEmpty){
        GraphicManager* gm = GraphicManager::getInstance();
        //[IMAGE_LETTER_A_SMALL - IMAGE_LETTER_Z_SMALL] - [0 - 25]
        int index = m_oTile.getLetter() - 'a'; //index 0 - 25-->
        
        gm->drawSprite((IMAGE_NAME)index, pos_x, pos_y);
        
    }
}

void Cell::setTile (Tile tile) {
    m_oTile = tile;
    m_bEmpty = false;
}
