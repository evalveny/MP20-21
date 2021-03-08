//
//  PlayerTile.cpp
//  Scrabble
//
//  Created by Enric Vergara on 21/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "PlayerTile.h"


PlayerTile::PlayerTile(){
    m_bIsOnBoard = false;
    m_bIsEmpty = true;
}

PlayerTile::~PlayerTile(){
    
}

void PlayerTile::Render (TileRenderer& renderer, bool small){
    if (!m_bIsEmpty && !m_bIsOnBoard) {
        renderer.Render(m_oTile.GetLetter(), m_fPosX, m_fPosY, small);
    }
}

void PlayerTile::Recall (){
    if (!m_bIsEmpty){
        m_bIsOnBoard = false;
    }
}

void PlayerTile::SetPosition (float posX, float posY){
    m_fPosX = posX;
    m_fPosY = posY;
}


void PlayerTile::SetTile (const Tile& tile){
    m_bIsOnBoard = false;
    m_bIsEmpty = false;
    m_oTile = tile;
}
