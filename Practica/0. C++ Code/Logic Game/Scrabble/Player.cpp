//
//  Player.cpp
//  Letris
//
//  Created by Enric Vergara on 20/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "Player.h"



Player::Player(){
    m_bIsDragging = false;
    m_iScore = 0;
}

Player::~Player(){
    
}

void Player::addTiles (LettersBag& bag){
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++) {
        if (m_aTiles[i].isEmpty()) {
            if (!bag.isEmpty()){
                m_aTiles[i].setTile(bag.getLetter());
            }
        }
    }
    recall();
}

void Player::render () {
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++){
        if (m_bIsDragging && i == m_iTileDragging){
            m_aTiles[i].render(true);
        }else{
            m_aTiles[i].render(false);
        }
    }
}

bool Player::anyTileOnTheBoard () {
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++){
        if (!m_aTiles[i].isEmpty() && m_aTiles[i].isOnBoard()){
            return true;
        }
    }
    return false;
}

void Player::sendCurrentWordToBoard (Board& board){
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++) {
        if (m_aTiles[i].isOnBoard()){
            //hem de marcar les fitxes jugades del player com a buides.
            m_aTiles[i].playTile();
        }
    }
    m_iScore += board.getScoreCurrentWord();
    //hem de marcar les fitxes de la current word en el board com jugades
    board.sendCurrentWordToBoard();
}

void Player::update (int mousePosX, int mousePosY,
                     bool mouseIsPressed, bool mouseStatus,
                     float deltaTime, Board & board,
                     std::string& correctMove,
                     std::string& incorrectMove) {
    
    if (m_bIsDragging){
        m_aTiles[m_iTileDragging].setPosition(mousePosX, mousePosY);
        if (!mouseStatus){
            m_bIsDragging = false;
            BoardPosition boardPos;
            
            PositionResult result;
            //Convert pixel position in Column, Row-->
            if (mousePosX < BOARD_POS_X || mousePosX > BOARD_POS_X + BOARD_SIZE){
                result = INVALID_POSITION;
            }else if (mousePosY < BOARD_POS_Y || mousePosY > BOARD_POS_Y + BOARD_SIZE){
                result = INVALID_POSITION;
            }else{
                float cellSize = BOARD_SIZE / BOARD_COLS_AND_ROWS;
                int col = int((mousePosX - BOARD_POS_X)/cellSize);
                int row = int((mousePosY - BOARD_POS_Y)/cellSize);
                boardPos.setCol(col);
                boardPos.setRow(row);
                result = board.setTile(m_aTiles[m_iTileDragging].getTile(), boardPos);
            }
            switch (result){
                case INVALID_POSITION:
                    m_aTiles[m_iTileDragging].setPosition(
                            PLAYER_TILE_POS_X + (PLAYER_TILE_SIZE + PLAYER_SEPATION_BETWEEN_TILE)*m_iTileDragging,
                            PLAYER_TILE_POS_Y);
                    if (anyTileOnTheBoard()){
                        checkBoard(board,correctMove, incorrectMove);
                    }
                    
                    break;
                case VALID_POSITTIOIN:
                {
                    int posX = BOARD_POS_X + boardPos.getCol()*BOARD_TILE_SIZE;
                    int posY = BOARD_POS_Y + boardPos.getRow()*BOARD_TILE_SIZE;
                    m_aTiles[m_iTileDragging].setPosition(posX,posY);
                    m_aTiles[m_iTileDragging].setBoardPos(boardPos);
                    m_aTiles[m_iTileDragging].leaveOnBoard();
                    
                    checkBoard(board,correctMove, incorrectMove);
                }
                    
                    
                    break;
                case NOT_EMPTY:
                    correctMove = "";
                    incorrectMove = "Cell is not empty";
                    m_aTiles[m_iTileDragging].setPosition(
                            PLAYER_TILE_POS_X + (PLAYER_TILE_SIZE + PLAYER_SEPATION_BETWEEN_TILE)*m_iTileDragging,
                            PLAYER_TILE_POS_Y);
                    break;
            }
            
        }
    }else if (mouseStatus){
        for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++) {
            if (!m_aTiles[i].isEmpty()){
                
                int size_Tile;
                if(m_aTiles[i].isOnBoard()){
                    size_Tile = BOARD_TILE_SIZE;
                }else{
                    size_Tile = PLAYER_TILE_SIZE;
                }
                
                int posX_Tile = m_aTiles[i].getPosX();
                int posY_Tile = m_aTiles[i].getPosY();
                
                if (mousePosX >= posX_Tile && mousePosX <= posX_Tile + size_Tile &&
                    mousePosY >= posY_Tile && mousePosY <= posY_Tile + size_Tile){
                    m_bIsDragging = true;
                    correctMove = incorrectMove = "";
                    m_iTileDragging = i;
                    if(m_aTiles[i].isOnBoard()){
                        m_aTiles[i].pickupFromBoard();
                        board.removeLetter(m_aTiles[i].getBoardPos());
                    }
                    
                }
            }
        }
    }
}

void Player::checkBoard(Board & board,
                        std::string& correctMove,
                        std::string& incorrectMove){
    
    int points = 0;
    
    std::vector<std::string> wrongWords;
    CurrentWordResult result = board.checkCurrentWord(points, wrongWords);
    switch(result){
        case INVALID_NOT_ALIGNED:
            correctMove = "";
            incorrectMove = "Tiles must be vertically or horizontally aligned and together.";
            break;
        case INVALID_NOT_CONNECTION:
            correctMove = "";
            incorrectMove = "At least one letter must be next to the rest of the words.";
            break;
        case INVALID_WORDS_NOT_IN_DICTIONARY:
            correctMove = "";
            incorrectMove = "The new words are not in the dictionary: " + board.getWrongWords()[0];
            break;
        case INVALID_WORD_OF_ONE_LETTER:
            correctMove = "";
            incorrectMove = "Only words of two or more letters.";
            break;
        case INVALID_START_NOT_IN_CENTER:
            correctMove = "";
            incorrectMove = "You have to start using the center position.";
            break;
        case ALL_CORRECT:
            correctMove = "Points: " + std::to_string(points);
            incorrectMove = "";
            break;
    }
}

void Player::recall (){
    float l_fPosY = PLAYER_TILE_POS_Y;
    float l_fPosX = PLAYER_TILE_POS_X;
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++) {
        m_aTiles[i].setPosition(l_fPosX, l_fPosY);
        m_aTiles[i].recall();
        l_fPosX  += PLAYER_TILE_SIZE + PLAYER_SEPATION_BETWEEN_TILE;
    }
}

void Player::shuffle (){
    
}


bool Player::allTilesPlayed () {
    bool allTilesPlayed = true;
    int index = 0;
    while(allTilesPlayed && index < NUM_MAX_PLAYER_TILES){
        if (!m_aTiles[index].isEmpty()){
            allTilesPlayed = false;
        }else{
            index++;
        }
    }
    return allTilesPlayed;
}

