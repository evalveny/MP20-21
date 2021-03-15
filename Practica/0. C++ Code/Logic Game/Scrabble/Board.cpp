//
//  Board.cpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "Board.h"
#include <algorithm>
#include <iostream>
#include <fstream>

Board::Board()
:m_oSprite_Board("data/GUI/game-board.png")
{
    
    ifstream boardFile;
    boardFile.open ("data/Configuration/board.txt");
    if (boardFile.is_open())
    {
        int x, y;
        string effect;
        
        do
        {
            boardFile >> x >> y >> effect;
            ScoreEffect score_effect;
            if (effect.compare("DL")){
                score_effect = DL;
            }else if (effect.compare("TL")){
                score_effect = TL;
            }else if (effect.compare("DW")){
                score_effect = DW;
            }else {
                score_effect = TW;
            }
            m_aCells[x][y].setScoreEffect(score_effect);
            cout << x << " " << y << " " << effect <<endl;
            
        } while ( !boardFile.eof() );
        
        boardFile.close();
    }

    m_oDictionary.setLanguage(ENGLISH);
    m_bIsFirstWord = true;
}

Board::~Board(){
    
}

void Board::render () {
    m_oSprite_Board.draw(BOARD_POS_X, BOARD_POS_Y);
    
    for (int i=0; i < BOARD_COLS_AND_ROWS; i++){
        for (int j=0; j < BOARD_COLS_AND_ROWS; j++){
            m_aCells[i][j].render(BOARD_POS_X + i*BOARD_TILE_SIZE,
                                  BOARD_POS_Y + j*BOARD_TILE_SIZE);
        }
    }
}

void Board::sendCurrentWordToBoard () {
    for (int i = 0; i < m_aCurrentWord.size(); i++){
        int col = m_aCurrentWord[i].getCol();
        int row = m_aCurrentWord[i].getRow();
        m_aCells[col][row].setTilePlayed();
    }
    m_aCurrentWord.clear();
    m_bIsFirstWord = false;
    m_oWordFinder.resetTotalScore();
}

PositionResult Board::setTile (Tile &tile,
                               int posX, int posY,
                               BoardPosition& boardPos)
{
    PositionResult result = INVALID_POSITION;
    //Convert pixel position in Column, Row-->
    if (posX < BOARD_POS_X || posX > BOARD_POS_X + BOARD_SIZE){
        result = INVALID_POSITION;
    }else if (posY < BOARD_POS_Y || posY > BOARD_POS_Y + BOARD_SIZE){
        result = INVALID_POSITION;
    }else{
        float cellSize = BOARD_SIZE / BOARD_COLS_AND_ROWS;
        int col = int((posX - BOARD_POS_X)/cellSize);
        int row = int((posY - BOARD_POS_Y)/cellSize);
        boardPos.setCol(col);
        boardPos.setRow(row);
        if (!m_aCells[col][row].isEmpty()){
            return NOT_EMPTY;
        }else{
            //TODO get all the wrong words...
            m_aCurrentWord.push_back(BoardPosition(col, row));
            m_aCells[col][row].setTile(tile);
            return VALID_POSITTIOIN;
        }
    }
    
    return result;
}

void Board::searchForWrongWords()
{
    m_aWrongWords.clear();
    vector<string> newWords = m_oWordFinder.getNewWords();
    vector<string>::iterator it = newWords.begin();
    vector<string>::iterator itEnd = newWords.end();
    for(;it != itEnd; it++){
        if (!m_oDictionary.check(*it)){
            m_aWrongWords.push_back(*it);
        }
    }
}

bool Board::checkPosition (std::string& errorMsg){
    errorMsg = "";
    bool isOk = true;
    
    int center_coordinate = (int)BOARD_COLS_AND_ROWS/2;
    if (m_bIsFirstWord){
        if (m_aCells[center_coordinate][center_coordinate].isEmpty()){
            isOk = false;
            errorMsg = "You have to start using the center position";
        }else if (m_aCurrentWord.size()==1){
            isOk = false;
            errorMsg = "Only words of two or molre letters";
        }
    }else if (m_aCurrentWord.size() == 0){
        
    }
    
    
    
    
    if (isOk) {
        
        //to check if all tiles are vertically aligned
        bool verticallyAligned = true;
        int col = m_aCurrentWord[0].getCol();
        std::vector<int> l_aCols;
        for (int i = 0; i < m_aCurrentWord.size(); i++){
            l_aCols.push_back(m_aCurrentWord[i].getCol());
            if (col != m_aCurrentWord[i].getCol()){
                verticallyAligned  = false;
            }
        }
        
        //to check if all tiles are horizontally aligned
        std::vector<int> l_aRows;
        bool horizontallyAligned = true;
        int row = m_aCurrentWord[0].getRow();
        for (int i = 0; i < m_aCurrentWord.size(); i++){
            l_aRows.push_back(m_aCurrentWord[i].getRow());
            if (row != m_aCurrentWord[i].getRow()){
                horizontallyAligned  = false;
            }
        }
        if (horizontallyAligned){
            std::sort(l_aCols.begin(), l_aCols.end());
            int minCol = l_aCols[0];
            int maxCol = l_aCols[l_aCols.size()-1];
            int row = m_aCurrentWord[0].getRow();
            for(int col = minCol; col <= maxCol; col++){
                //there can be no empty cells between min and max:
                if (m_aCells[col][row].isEmpty()){
                    horizontallyAligned = false;
                }
            }
        }else if (verticallyAligned){
            std::sort(l_aRows.begin(), l_aRows.end());
            int minRow = l_aRows[0];
            int maxRow = l_aRows[l_aRows.size()-1];
            int col = m_aCurrentWord[0].getCol();
            for(int row = minRow; row <= maxRow; row++){
                //there can be no empty cells between min and max:
                if (m_aCells[col][row].isEmpty()){
                    verticallyAligned = false;
                }
            }
        }
        
        if (!horizontallyAligned && !verticallyAligned){
            isOk = false;
            errorMsg = "Tiles must be vertically or horizontally aligned and together";
        }
    }
    
    
    if (isOk && !m_bIsFirstWord){
        bool someNeighbor = false;
        
        for (int i = 0; i < m_aCurrentWord.size(); i++){
            int col =  m_aCurrentWord[i].getCol();
            int row =  m_aCurrentWord[i].getRow();
            int col_aux, row_aux;
            //Four directions:
            col_aux = max(0, col - 1); //UP
            row_aux = row;
            if (m_aCells[col_aux][row_aux].isTilePlayed()){
                someNeighbor = true;
            }
            col_aux = min(BOARD_COLS_AND_ROWS - 1, col + 1); //DOWN
            row_aux = row;
            if (m_aCells[col_aux][row_aux].isTilePlayed()){
                someNeighbor = true;
            }
            col_aux = col;
            row_aux = max(0, row - 1); //LEFT;
            if (m_aCells[col_aux][row_aux].isTilePlayed()){
                someNeighbor = true;
            }
            col_aux = col;
            row_aux = min(BOARD_COLS_AND_ROWS - 1, row + 1); //RIGHT;
            if (m_aCells[col_aux][row_aux].isTilePlayed()){
                someNeighbor = true;
            }
        }
        if (!someNeighbor){
            isOk = false;
            errorMsg = "At least one letter must be next to the rest of the words.";
        }
    }
    return isOk;
}



bool Board::checkNewWords (int& points) {
    bool isCorrect = false;
    
    m_oWordFinder.searchForAllNewWords(m_aCells, m_aCurrentWord);
    searchForWrongWords();
    
    if (m_aWrongWords.size() == 0){
        isCorrect = true;
        points = m_oWordFinder.getTotalScore();
    }
    
    return isCorrect;
}

void Board::removeCurrentWord () {
    
    vector<BoardPosition>::iterator it = m_aCurrentWord.begin();
    vector<BoardPosition>::iterator itEnd = m_aCurrentWord.end();
    for(;it != itEnd; it++){
        int col = (*it).getCol();
        int row = (*it).getRow();
        m_aCells[col][row].removeTile();
    }
    m_aCurrentWord.clear();
}

void Board::removeLetter(BoardPosition boardPos) {
    vector<BoardPosition>::iterator it = m_aCurrentWord.begin();
    vector<BoardPosition>::iterator itEnd = m_aCurrentWord.end();
    
    int col = boardPos.getCol();
    int row = boardPos.getRow();
    bool found = false;
    while(it!=itEnd && !found){
        int col_aux = (*it).getCol();
        int row_aux = (*it).getRow();
        if (boardPos.getCol() == col_aux && row == row_aux){
            m_aCells[col][row].removeTile();
            found = true;
        }else{
            it++;
        }
    }
    if (found){
        m_aCurrentWord.erase(it);
    }
    
    
}



