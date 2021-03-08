//
//  ScrabbleGame.cpp
//  Letris
//
//  Created by Enric Vergara on 13/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "ScrabbleGame.h"
#include "Player.h"
/*
 Button( const string& path_normal,
         const string& path_pressed,
         int posX, int posY, int width, int height);
 */
const int SIZE_BUTTON_RECALL = 100;
const int SIZE_BUTTON_SHUFFLE = 100;

const int SIZE_W_BUTTON_SEND = 139;
const int SIZE_H_BUTTON_SEND = 100;
const int SIZE_W_BUTTON_PASS = 139;
const int SIZE_H_BUTTON_PASS = 100;

ScrabbleGame::ScrabbleGame()
: m_oButton_Recall("data/GUI/recall_normal.png", "data/GUI/recall_pressed.png",
                   SCREEN_SIZE_X*0.5 - SIZE_W_BUTTON_SEND*0.5 - SIZE_BUTTON_RECALL - 10, //X, Y, WIDTH, HEIGHT
                   SCREEN_SIZE_Y - SIZE_BUTTON_RECALL,
                   SIZE_BUTTON_RECALL,
                   SIZE_BUTTON_RECALL)
, m_oButton_Shuffle("data/GUI/shuffle_normal.png", "data/GUI/shuffle_pressed.png",
                    SCREEN_SIZE_X*0.5 + SIZE_W_BUTTON_SEND*0.5 + 10,
                    SCREEN_SIZE_Y - SIZE_BUTTON_SHUFFLE,
                    SIZE_BUTTON_SHUFFLE,
                    SIZE_BUTTON_SHUFFLE)
, m_oButton_Send("data/GUI/send_normal.png", "data/GUI/send_pressed.png",
                 SCREEN_SIZE_X*0.5 - SIZE_W_BUTTON_SEND*0.5,
                 SCREEN_SIZE_Y - SIZE_H_BUTTON_SEND,
                 SIZE_W_BUTTON_SEND,
                 SIZE_H_BUTTON_SEND)
, m_oButton_Pass("data/GUI/pass_normal.png", "data/GUI/pass_pressed.png",
                 SCREEN_SIZE_X*0.5 - SIZE_W_BUTTON_SEND*0.5,
                 SCREEN_SIZE_Y - SIZE_H_BUTTON_SEND,
                 SIZE_W_BUTTON_PASS,
                 SIZE_H_BUTTON_PASS)
, m_oSpriteBackground("data/GUI/background.png")
, m_oFont_Info("data/Fonts/FreeSans.ttf", 30, NFont::Color(255,255,255,255))
, m_oFont_IncorrectMove("data/Fonts/FreeSans.ttf", 30, NFont::Color(255,0,0,255))
, m_oFont_CorrectMove("data/Fonts/FreeSans.ttf", 30, NFont::Color(0,255,0,255))
, m_iCurrentPlayer(0)
{
    m_sCorrectMove = "";
    m_sIncorrectMove = "";
    
    for (int i = 0 ; i < NUM_PLAYERS; i++){
        m_aPlayers[i].AddTiles(m_oLettersBag);
    }
}

ScrabbleGame::~ScrabbleGame(){
    
}

void ScrabbleGame::ChangePlayer (){
    m_sCorrectMove = "";
    m_sIncorrectMove = "";
    m_iCurrentPlayer = (m_iCurrentPlayer + 1) % NUM_PLAYERS;
}

void ScrabbleGame::UpdateAndRender (int mousePosX, int mousePosY,
                                    bool mouseIsPressed, bool mouseStatus,
                                    float deltaTime){
    
    
    //--------UPDATE ----
    m_aPlayers[m_iCurrentPlayer].Update(mousePosX, mousePosY,
                     mouseIsPressed, mouseStatus,
                     deltaTime, m_oBoard, m_sCorrectMove, m_sIncorrectMove);
    
    
    if (m_oButton_Recall.Update(mousePosX, mousePosY, mouseStatus)){
        m_aPlayers[m_iCurrentPlayer].Recall();
        m_oBoard.RemoveCurrentWord();
        m_sCorrectMove = "";
        m_sIncorrectMove = "";
    }
    if (m_oButton_Shuffle.Update(mousePosX, mousePosY, mouseStatus)){
        m_aPlayers[m_iCurrentPlayer].Suffle();
    }
    
    if (m_aPlayers[m_iCurrentPlayer].AnyTileOnTheBoard()){
        if (m_oButton_Send.Update(mousePosX, mousePosY, mouseStatus)){
            if (m_sIncorrectMove.compare("")==0){
                m_aPlayers[m_iCurrentPlayer].SendCurrentWordToBoard(m_oBoard);
                m_aPlayers[m_iCurrentPlayer].AddTiles(m_oLettersBag);
                
                ChangePlayer();
                m_sCorrectMove = "";
                m_sIncorrectMove = "";
            }
        }
    }else{
        if (m_oButton_Pass.Update(mousePosX, mousePosY, mouseStatus)){
            ChangePlayer();
        }
    }
    
    
    //--------RENDER ----
    m_oSpriteBackground.draw(0,0);
    
    m_oBoard.Render(m_oTileRenderer);
    
    m_oButton_Recall.Render();
    m_oButton_Shuffle.Render();
    
    if (m_aPlayers[m_iCurrentPlayer].AnyTileOnTheBoard()){
        m_oButton_Send.Render();
    }else{
        m_oButton_Pass.Render();
    }
    
    
    m_aPlayers[m_iCurrentPlayer].Render(m_oTileRenderer);
    
    NFont::Rectf rect = m_oFont_Info.draw(50, 0, NFont::Scale(0.7), "Player turn: %d", m_iCurrentPlayer+1);
    int posX_MoveMsg = 50 + rect.w + 10;
    m_oFont_IncorrectMove.draw(posX_MoveMsg, 0, NFont::Scale(0.7), "%s", m_sIncorrectMove.c_str());
    m_oFont_CorrectMove.draw(posX_MoveMsg, 0, NFont::Scale(0.7), "%s", m_sCorrectMove.c_str());
    
    int posY = BOARD_POS_Y + BOARD_SIZE + PLAYER_TILE_SIZE+15;
    for (int i = 0; i < NUM_PLAYERS; i++){
        NFont::Rectf rect = m_oFont_Info.draw(0, posY, NFont::Scale(0.6), "Score Player %d = %d", i+1, m_aPlayers[i].GetScore());
        posY += rect.h;
    }
    
    posY = BOARD_POS_Y + BOARD_SIZE + PLAYER_TILE_SIZE+15;
    m_oFont_Info.draw(SCREEN_SIZE_X - 200, posY, NFont::Scale(0.6), "Tiles in the bag: %d", m_oLettersBag.TilesInTheBag());
 
    int winner = -1;
    if (HasAnyoneWon(winner)){
        m_oFont_Info.draw(BOARD_POS_X*0.5, SCREEN_SIZE_Y*0.5f, NFont::Scale(2.0), "Player %d is the winner", winner+1);
    }
    
    
}


bool ScrabbleGame::HasAnyoneWon (int& winner){
    bool hasAnyoneWon = false;
    winner = 0;
    
    while(!hasAnyoneWon && winner < NUM_PLAYERS){
        if (m_aPlayers[winner].AllTilesPlayed()){
            hasAnyoneWon = true;
        }else{
            winner++;
        }
    }
    
    return hasAnyoneWon;
}
