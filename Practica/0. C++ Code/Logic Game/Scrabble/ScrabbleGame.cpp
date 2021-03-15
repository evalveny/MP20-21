//
//  ScrabbleGame.cpp
//  Letris
//
//  Created by Enric Vergara on 13/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "ScrabbleGame.h"
#include "Player.h"
#include "../GraphicManager.h"

const int SIZE_BUTTON_RECALL = 100;
const int SIZE_BUTTON_SHUFFLE = 100;

const int SIZE_W_BUTTON_SEND = 139;
const int SIZE_H_BUTTON_SEND = 100;
const int SIZE_W_BUTTON_PASS = 139;
const int SIZE_H_BUTTON_PASS = 100;

ScrabbleGame::ScrabbleGame()
: m_oButton_Recall(IMAGE_BUTTON_RECALL_NORMAL, IMAGE_BUTTON_RECALL_PRESSED,
                   SCREEN_SIZE_X*0.5 - SIZE_W_BUTTON_SEND*0.5 - SIZE_BUTTON_RECALL - 10, //X, Y, WIDTH, HEIGHT
                   SCREEN_SIZE_Y - SIZE_BUTTON_RECALL,
                   SIZE_BUTTON_RECALL,
                   SIZE_BUTTON_RECALL)
, m_oButton_Shuffle(IMAGE_BUTTON_SHUFFLE_NORMAL, IMAGE_BUTTON_SHUFFLE_PRESSED,
                    SCREEN_SIZE_X*0.5 + SIZE_W_BUTTON_SEND*0.5 + 10,
                    SCREEN_SIZE_Y - SIZE_BUTTON_SHUFFLE,
                    SIZE_BUTTON_SHUFFLE,
                    SIZE_BUTTON_SHUFFLE)
, m_oButton_Send(IMAGE_BUTTON_SEND_NORMAL, IMAGE_BUTTON_SEND_PRESSED,
                 SCREEN_SIZE_X*0.5 - SIZE_W_BUTTON_SEND*0.5,
                 SCREEN_SIZE_Y - SIZE_H_BUTTON_SEND,
                 SIZE_W_BUTTON_SEND,
                 SIZE_H_BUTTON_SEND)
, m_oButton_Pass(IMAGE_BUTTON_PASS_NORMAL, IMAGE_BUTTON_PASS_PRESSED,
                 SCREEN_SIZE_X*0.5 - SIZE_W_BUTTON_SEND*0.5,
                 SCREEN_SIZE_Y - SIZE_H_BUTTON_SEND,
                 SIZE_W_BUTTON_PASS,
                 SIZE_H_BUTTON_PASS)
, m_iCurrentPlayer(0)
{
    m_sCorrectMove = "";
    m_sIncorrectMove = "";
    
    for (int i = 0 ; i < NUM_PLAYERS; i++){
        m_aPlayers[i].addTiles(m_oLettersBag);
    }
}

ScrabbleGame::~ScrabbleGame(){
    
}

void ScrabbleGame::changePlayer (){
    m_sCorrectMove = "";
    m_sIncorrectMove = "";
    m_iCurrentPlayer = (m_iCurrentPlayer + 1) % NUM_PLAYERS;
}

void ScrabbleGame::updateAndRender (int mousePosX, int mousePosY,
                                    bool mouseIsPressed, bool mouseStatus,
                                    float deltaTime){
    
    
    //--------UPDATE ----
    m_aPlayers[m_iCurrentPlayer].update(mousePosX, mousePosY,
                     mouseIsPressed, mouseStatus,
                     deltaTime, m_oBoard, m_sCorrectMove, m_sIncorrectMove);
    
    
    if (m_oButton_Recall.update(mousePosX, mousePosY, mouseStatus)){
        m_aPlayers[m_iCurrentPlayer].recall();
        m_oBoard.removeCurrentWord();
        m_sCorrectMove = "";
        m_sIncorrectMove = "";
    }
    if (m_oButton_Shuffle.update(mousePosX, mousePosY, mouseStatus)){
        m_aPlayers[m_iCurrentPlayer].shuffle();
    }
    
    if (m_aPlayers[m_iCurrentPlayer].anyTileOnTheBoard()){
        if (m_oButton_Send.update(mousePosX, mousePosY, mouseStatus)){
            if (m_sIncorrectMove.compare("")==0){
                m_aPlayers[m_iCurrentPlayer].sendCurrentWordToBoard(m_oBoard);
                m_aPlayers[m_iCurrentPlayer].addTiles(m_oLettersBag);
                
                changePlayer();
                m_sCorrectMove = "";
                m_sIncorrectMove = "";
            }
        }
    }else{
        if (m_oButton_Pass.update(mousePosX, mousePosY, mouseStatus)){
            changePlayer();
        }
    }
    
    
    //--------RENDER ----
    
    GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND,0,0);
    
    
    m_oBoard.render();
    
    m_oButton_Recall.render();
    m_oButton_Shuffle.render();
    
    if (m_aPlayers[m_iCurrentPlayer].anyTileOnTheBoard()){
        m_oButton_Send.render();
    }else{
        m_oButton_Pass.render();
    }
    
    
    m_aPlayers[m_iCurrentPlayer].render();
    
    NFont::Rectf rect  = GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 50, 0, 0.7, "Player turn: " + to_string(m_iCurrentPlayer+1));
    int posX_MoveMsg = 50 + rect.w + 10;
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 50, 0, 0.7, "Player turn: " + to_string(m_iCurrentPlayer+1));
    GraphicManager::getInstance()->drawFont(FONT_RED_30, posX_MoveMsg, 0, 0.7, m_sIncorrectMove);
    GraphicManager::getInstance()->drawFont(FONT_GREEN_30, posX_MoveMsg, 0, 0.7, m_sCorrectMove);
    
    string msg = "";
    int posY = BOARD_POS_Y + BOARD_SIZE + PLAYER_TILE_SIZE+15;
    for (int i = 0; i < NUM_PLAYERS; i++){
        msg = "Score Player " + to_string(i+1) +  " =" + to_string(m_aPlayers[i].getScore());
        NFont::Rectf rect = GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 0, posY, 0.6, msg);
        posY += rect.h;
    }
    
    posY = BOARD_POS_Y + BOARD_SIZE + PLAYER_TILE_SIZE+15;
    msg = "Tiles in the bag: " + to_string(m_oLettersBag.tilesInTheBag());
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, SCREEN_SIZE_X-200, posY, 0.6, msg);
    
    int winner = -1;
    if (hasAnyoneWon(winner)){
        msg = "Player " + to_string(winner+1 )+ " is the winner";
        GraphicManager::getInstance()->drawFont(FONT_GREEN_30,BOARD_POS_X*0.5, SCREEN_SIZE_Y*0.5f, 1.5, msg);
        
        
    }
    
    
}


bool ScrabbleGame::hasAnyoneWon (int& winner){
    bool hasAnyoneWon = false;
    winner = 0;
    
    while(!hasAnyoneWon && winner < NUM_PLAYERS){
        if (m_aPlayers[winner].allTilesPlayed()){
            hasAnyoneWon = true;
        }else{
            winner++;
        }
    }
    
    return hasAnyoneWon;
}
