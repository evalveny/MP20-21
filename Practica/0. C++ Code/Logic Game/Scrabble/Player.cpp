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

void Player::AddTiles (LettersBag& bag){
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++) {
        if (m_aTiles[i].IsEmpty()) {
            if (!bag.IsEmpty()){
                m_aTiles[i].SetTile(bag.GetLetter());
            }
        }
    }
    Recall();
}

void Player::Render (TileRenderer& renderer) {
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++){
        if (m_bIsDragging && i == m_iTileDragging){
            m_aTiles[i].Render(renderer, true);
        }else{
            m_aTiles[i].Render(renderer, false);
        }
    }
}

bool Player::AnyTileOnTheBoard () {
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++){
        if (!m_aTiles[i].IsEmpty() && m_aTiles[i].IsOnBoard()){
            return true;
        }
    }
    return false;
}

void Player::SendCurrentWordToBoard (Board& board){
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++) {
        if (m_aTiles[i].IsOnBoard()){
            //hem de marcar les fitxes jugades del player com a buides.
            m_aTiles[i].PlayTile();
        }
    }
    m_iScore += board.GetScoreCurrentWord();
    //hem de marcar les fitxes de la current word en el board com jugades
    board.SendCurrentWordToBoard();
}

void Player::Update (int mousePosX, int mousePosY,
                     bool mouseIsPressed, bool mouseStatus,
                     float deltaTime, Board & board,
                     std::string& correctMove,
                     std::string& incorrectMove) {
    
    if (m_bIsDragging){
        m_aTiles[m_iTileDragging].SetPosition(mousePosX, mousePosY);
        if (!mouseStatus){
            m_bIsDragging = false;
            BoardPosition boardPos;
            PositionResult result = board.SetTile(m_aTiles[m_iTileDragging].GetTile(), mousePosX, mousePosY, boardPos);
            
            switch (result){
                case INVALID_POSITION:
                    m_aTiles[m_iTileDragging].SetPosition(
                            PLAYER_TILE_POS_X + (PLAYER_TILE_SIZE + PLAYER_SEPATION_BETWEEN_TILE)*m_iTileDragging,
                            PLAYER_TILE_POS_Y);
                    if (AnyTileOnTheBoard()){
                        CheckBoard(board,correctMove, incorrectMove);
                    }
                    
                    break;
                case VALID_POSITTIOIN:
                {
                    int posX = BOARD_POS_X + boardPos.GetCol()*BOARD_TILE_SIZE;
                    int posY = BOARD_POS_Y + boardPos.GetRow()*BOARD_TILE_SIZE;
                    m_aTiles[m_iTileDragging].SetPosition(posX,posY);
                    m_aTiles[m_iTileDragging].SetBoardPos(boardPos);
                    m_aTiles[m_iTileDragging].LeaveOnBoard();
                    
                    CheckBoard(board,correctMove, incorrectMove);
                }
                    
                    
                    break;
                case NOT_EMPTY:
                    correctMove = "";
                    incorrectMove = "Cell is not empty";
                    m_aTiles[m_iTileDragging].SetPosition(
                            PLAYER_TILE_POS_X + (PLAYER_TILE_SIZE + PLAYER_SEPATION_BETWEEN_TILE)*m_iTileDragging,
                            PLAYER_TILE_POS_Y);
                    break;
            }
            
        }
    }else if (mouseStatus){
        for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++) {
            if (!m_aTiles[i].IsEmpty()){
                
                int size_Tile;
                if(m_aTiles[i].IsOnBoard()){
                    size_Tile = BOARD_TILE_SIZE;
                }else{
                    size_Tile = PLAYER_TILE_SIZE;
                }
                
                int posX_Tile = m_aTiles[i].GetPosX();
                int posY_Tile = m_aTiles[i].GetPosY();
                
                if (mousePosX >= posX_Tile && mousePosX <= posX_Tile + size_Tile &&
                    mousePosY >= posY_Tile && mousePosY <= posY_Tile + size_Tile){
                    m_bIsDragging = true;
                    correctMove = incorrectMove = "";
                    m_iTileDragging = i;
                    if(m_aTiles[i].IsOnBoard()){
                        m_aTiles[i].PickupFromBoard();
                        board.RemoveLetter(m_aTiles[i].GetBoardPos());
                    }
                    
                }
            }
        }
    }
}

void Player::CheckBoard(Board & board,
                        std::string& correctMove,
                        std::string& incorrectMove){
    
    int points = 0;
    std::string errorMsg = "";
    if (!board.CheckPosition(errorMsg))
    {
        correctMove = "";
        incorrectMove = errorMsg;
    }else{
        if (board.CheckNewWords(points)){
            correctMove = "Points: " + std::to_string(points);
            incorrectMove = "";
        }else{
            correctMove = "";
            incorrectMove = board.GetWrongWords()[0];
        }
    }
}

void Player::Recall (){
    float l_fPosY = PLAYER_TILE_POS_Y;
    float l_fPosX = PLAYER_TILE_POS_X;
    for (int i = 0; i < NUM_MAX_PLAYER_TILES; i++) {
        m_aTiles[i].SetPosition(l_fPosX, l_fPosY);
        m_aTiles[i].Recall();
        l_fPosX  += PLAYER_TILE_SIZE + PLAYER_SEPATION_BETWEEN_TILE;
    }
}

void Player::Suffle (){
    
}


bool Player::AllTilesPlayed () {
    bool allTilesPlayed = true;
    int index = 0;
    while(allTilesPlayed && index < NUM_MAX_PLAYER_TILES){
        if (!m_aTiles[index].IsEmpty()){
            allTilesPlayed = false;
        }else{
            index++;
        }
    }
    return allTilesPlayed;
}

