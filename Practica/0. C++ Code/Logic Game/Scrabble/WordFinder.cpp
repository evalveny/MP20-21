//
//  WordFinder.cpp
//  MP_Practica
//
//  Created by Enric Vergara on 14/03/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "WordFinder.h"
#include <iostream>



bool WordFinder::isInTheCurrentWord (int col, int row,
                                     const VectorOfPositions& currentWord){
    bool isTheCurrentWord = false;
    int i = 0;
    BoardPosition bp(col, row);
    while(!isTheCurrentWord && i < currentWord.size()){
        isTheCurrentWord = (currentWord[i] == bp);
        i++;
    }
    return isTheCurrentWord;
}

void WordFinder::searchForAllNewWords (Cell cells[][BOARD_COLS_AND_ROWS],
                                       const VectorOfPositions& currentWord){

    m_aNewWords.clear();
    m_iTotalScore = 0;
    
    //Horizontal sweep:
    for(int row = 0; row < BOARD_COLS_AND_ROWS; row++){
        resetWord();
        //For each row we make a Horizontal sweep:
        for(int col = 0; col < BOARD_COLS_AND_ROWS; col++){
            
            readCell(cells, col,row, currentWord);
        }
        finishSearchInLine();
    }
    
    //Vertical sweep:
    for(int col = 0; col < BOARD_COLS_AND_ROWS; col++){
        resetWord();
        //For each column we make a Vertical sweep:
        for(int row = 0; row < BOARD_COLS_AND_ROWS; row++){
            
            readCell(cells, col,row, currentWord);
        }
        finishSearchInLine();
    }
    
    /*
    //Print word list to console:
    cout << "---------------------------"<<endl;
    cout << "    List of new words"<< endl;
    cout << "---------------------------"<<endl;
    for (int i = 0; i < m_aNewWords.size(); i++){
        cout << "- " << m_aNewWords[i] << endl;;
    }
     */
}

void WordFinder::resetWord (){
    m_sNewWord = "";
    m_bHasLetterOfCurrentWord = false;
    m_iScoreOfNewWord = 0;
    m_iMultiplyFactorOfNewWord = 1;
}


void WordFinder::finishSearchInLine () {
    if (m_bHasLetterOfCurrentWord && m_sNewWord.length() > 1){
        m_aNewWords.push_back(m_sNewWord);
        m_iTotalScore += m_iScoreOfNewWord * m_iMultiplyFactorOfNewWord;
    }
}

void WordFinder::readCell (Cell cells[][BOARD_COLS_AND_ROWS],
                           int col, int row, const VectorOfPositions& currentWord) {
    m_bHasLetterOfCurrentWord = m_bHasLetterOfCurrentWord || isInTheCurrentWord(col, row, currentWord);
    if( !cells[col][row].isEmpty()){
        m_sNewWord += cells[col][row].getTile().getLetter();
        int letterScore = cells[col][row].getTile().getScore();
        if( !cells[col][row].isTilePlayed()) {
            switch (cells[col][row].getScoreEffect()) {
                case DL:
                    letterScore *= 2;
                    break;
                case TL:
                    letterScore *= 3;
                    break;
                case DW:
                    m_iMultiplyFactorOfNewWord *= 2;
                    break;
                case TW:
                    m_iMultiplyFactorOfNewWord *= 3;
                    break;
                case NO_EFFECT:
                    //Nothing to do.
                    break;
                default:
                    break;
            }
        }
        
        m_iScoreOfNewWord += letterScore;
        
    }else{
        if (m_bHasLetterOfCurrentWord && m_sNewWord.length() > 1){
            m_aNewWords.push_back(m_sNewWord);
            m_iTotalScore += m_iScoreOfNewWord * m_iMultiplyFactorOfNewWord;
        }
        resetWord();
    }
}
