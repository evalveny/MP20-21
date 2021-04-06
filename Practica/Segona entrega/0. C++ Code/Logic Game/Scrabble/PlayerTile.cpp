//
//  PlayerTile.cpp
//  Scrabble
//
//  Created by Enric Vergara on 21/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "PlayerTile.h"
#include "../GraphicManager.h"

PlayerTile::PlayerTile(){
    m_bIsOnBoard = false;
    m_bIsEmpty = true;
}

PlayerTile::~PlayerTile(){
    
}

void PlayerTile::render (bool small){
    if (!m_bIsEmpty && !m_bIsOnBoard) {
        int index = m_oTile.getLetter() - 'a'; //index: 0 - 25
        if (!small){
            index += 26;
        }
        GraphicManager::getInstance()->drawSprite(IMAGE_NAME(index), m_fPosX, m_fPosY);
    }
}

void PlayerTile::recall (){
    if (!m_bIsEmpty){
        m_bIsOnBoard = false;
    }
}

void PlayerTile::setPosition (float posX, float posY){
    m_fPosX = posX;
    m_fPosY = posY;
}


void PlayerTile::setTile (const Tile& tile){
    m_bIsOnBoard = false;
    m_bIsEmpty = false;
    m_oTile = tile;
}
