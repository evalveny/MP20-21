//
//  Cell.cpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "Cell.h"


void Cell::setTile (Tile tile) {
    m_oTile = tile;
    m_bEmpty = false;
}
