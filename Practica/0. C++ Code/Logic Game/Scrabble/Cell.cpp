//
//  Cell.cpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "Cell.h"

void Cell::Render (int pos_x, int pos_y, TileRenderer& renderer){
    if (!m_bEmpty){
        renderer.Render(m_oTile.GetLetter(), pos_x, pos_y, true);
    }
}

void Cell::SetTile (Tile tile) {
    m_oTile = tile;
    m_bEmpty = false;
}
