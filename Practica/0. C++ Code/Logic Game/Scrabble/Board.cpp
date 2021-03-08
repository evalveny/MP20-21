//
//  Board.cpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "Board.h"
#include <algorithm>

Board::Board()
:m_oSprite_Board("data/GUI/game-board.png")
{
    m_aCells[0][0].SetScoreEffect(TW);
    m_aCells[7][0].SetScoreEffect(TW);
    m_aCells[14][0].SetScoreEffect(TW);
    m_aCells[0][7].SetScoreEffect(TW);
    m_aCells[14][7].SetScoreEffect(TW);
    m_aCells[0][14].SetScoreEffect(TW);
    m_aCells[7][14].SetScoreEffect(TW);
    m_aCells[14][14].SetScoreEffect(TW);
    
    m_aCells[5][1].SetScoreEffect(TL);
    m_aCells[9][1].SetScoreEffect(TL);
    m_aCells[1][5].SetScoreEffect(TL);
    m_aCells[5][5].SetScoreEffect(TL);
    m_aCells[9][5].SetScoreEffect(TL);
    m_aCells[13][9].SetScoreEffect(TL);
    m_aCells[1][9].SetScoreEffect(TL);
    m_aCells[5][9].SetScoreEffect(TL);
    m_aCells[9][9].SetScoreEffect(TL);
    m_aCells[13][9].SetScoreEffect(TL);
    m_aCells[5][13].SetScoreEffect(TL);
    m_aCells[9][13].SetScoreEffect(TL);
    
    m_aCells[1][1].SetScoreEffect(DW);
    m_aCells[2][2].SetScoreEffect(DW);
    m_aCells[3][3].SetScoreEffect(DW);
    m_aCells[4][4].SetScoreEffect(DW);
    m_aCells[10][10].SetScoreEffect(DW);
    m_aCells[11][11].SetScoreEffect(DW);
    m_aCells[12][12].SetScoreEffect(DW);
    m_aCells[13][13].SetScoreEffect(DW);
    m_aCells[1][13].SetScoreEffect(DW);
    m_aCells[2][12].SetScoreEffect(DW);
    m_aCells[3][11].SetScoreEffect(DW);
    m_aCells[4][10].SetScoreEffect(DW);
    m_aCells[10][4].SetScoreEffect(DW);
    m_aCells[11][3].SetScoreEffect(DW);
    m_aCells[12][2].SetScoreEffect(DW);
    m_aCells[13][1].SetScoreEffect(DW);
    
    m_aCells[0][3].SetScoreEffect(DL);
    m_aCells[0][11].SetScoreEffect(DL);
    m_aCells[14][3].SetScoreEffect(DL);
    m_aCells[14][11].SetScoreEffect(DL);
    m_aCells[2][6].SetScoreEffect(DL);
    m_aCells[2][8].SetScoreEffect(DL);
    m_aCells[12][6].SetScoreEffect(DL);
    m_aCells[12][8].SetScoreEffect(DL);
    m_aCells[3][0].SetScoreEffect(DL);
    m_aCells[3][7].SetScoreEffect(DL);
    m_aCells[11][14].SetScoreEffect(DL);
    m_aCells[11][0].SetScoreEffect(DL);
    m_aCells[11][7].SetScoreEffect(DL);
    m_aCells[11][14].SetScoreEffect(DL);
    m_aCells[6][2].SetScoreEffect(DL);
    m_aCells[6][6].SetScoreEffect(DL);
    m_aCells[6][8].SetScoreEffect(DL);
    m_aCells[6][12].SetScoreEffect(DL);
    m_aCells[8][2].SetScoreEffect(DL);
    m_aCells[8][6].SetScoreEffect(DL);
    m_aCells[8][8].SetScoreEffect(DL);
    m_aCells[8][12].SetScoreEffect(DL);
    m_aCells[7][3].SetScoreEffect(DL);
    m_aCells[7][11].SetScoreEffect(DL);
    
    m_oDictionary.SetLanguage(ENGLISH);
    m_bIsFirstWord = true;
}

Board::~Board(){
    
}

void Board::Render (TileRenderer& renderer) {
    m_oSprite_Board.draw(BOARD_POS_X, BOARD_POS_Y);
    
    for (int i=0; i < BOARD_COLS_AND_ROWS; i++){
        for (int j=0; j < BOARD_COLS_AND_ROWS; j++){
            m_aCells[i][j].Render(BOARD_POS_X + i*BOARD_TILE_SIZE,
                                  BOARD_POS_Y + j*BOARD_TILE_SIZE,
                                  renderer);
        }
    }
    
}

void Board::SendCurrentWordToBoard () {
    for (int i = 0; i < m_aCurrentWord.size(); i++){
        int col = m_aCurrentWord[i].GetCol();
        int row = m_aCurrentWord[i].GetRow();
        m_aCells[col][row].SetTilePlayed();
    }
    m_aCurrentWord.clear();
    m_bIsFirstWord = false;
    m_iTotalScore = 0;
}

PositionResult Board::SetTile (Tile &tile,
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
        boardPos.SetCol(col);
        boardPos.SetRow(row);
        if (!m_aCells[col][row].IsEmpty()){
            return NOT_EMPTY;
        }else{
            //TODO get all the wrong words...
            m_aCurrentWord.push_back(BoardPosition(col, row));
            m_aCells[col][row].SetTile(tile);
            return VALID_POSITTIOIN;
        }
    }
    
    return result;
}

bool Board::IsInTheCurrentWord (int col, int row){
    bool isTheCurrentWord = false;
    int i = 0;
    while(!isTheCurrentWord && i < m_aCurrentWord.size()){
        isTheCurrentWord = m_aCurrentWord[i].GetCol() == col && m_aCurrentWord[i].GetRow() == row;
        i++;
    }
    return isTheCurrentWord;
}



void Board::ResetWord (){
    m_sNewWord = "";
    m_bHasLetterOfCurrentWord = false;
    m_iScoreOfNewWord = 0;
    m_iMultiplyFactorOfNewWord = 1;
}


void Board::FinishSearchInLine () {
    if (m_bHasLetterOfCurrentWord && m_sNewWord.length() > 1){
        m_aNewWords.push_back(m_sNewWord);
        m_iTotalScore += m_iScoreOfNewWord * m_iMultiplyFactorOfNewWord;
    }
}

void Board::ReadCell (int col, int row) {
    m_bHasLetterOfCurrentWord = m_bHasLetterOfCurrentWord || IsInTheCurrentWord(col, row);
    if( !m_aCells[col][row].IsEmpty()){
        m_sNewWord += m_aCells[col][row].GetTile().GetLetter();
        int letterScore= m_aCells[col][row].GetTile().GetScore();
        switch (m_aCells[col][row].GetScoreEffect()) {
            case DL:
                letterScore *= 2;
                break;
            case TL:
                letterScore *= 2;
                break;
            case DW:
                m_iMultiplyFactorOfNewWord *= 2;
                break;
            case TW:
                m_iMultiplyFactorOfNewWord *= 3;
                break;
            default:
                break;
        }
        m_iScoreOfNewWord += letterScore;
        
    }else{
        if (m_bHasLetterOfCurrentWord && m_sNewWord.length() > 1){
            m_aNewWords.push_back(m_sNewWord);
            m_iTotalScore += m_iScoreOfNewWord * m_iMultiplyFactorOfNewWord;
        }
        ResetWord();
    }
}

void Board::SearchForNewWords () {
    m_aNewWords.clear();
    m_iTotalScore = 0;
    
    //Horizontal sweep:
    for(int row = 0; row < BOARD_COLS_AND_ROWS; row++){
        ResetWord();
        for(int col = 0; col < BOARD_COLS_AND_ROWS; col++){
            //For each row we make a Horizontal sweep:
            ReadCell(col,row);
        }
        FinishSearchInLine();
    }
    
    //Vertical sweep:
    for(int col = 0; col < BOARD_COLS_AND_ROWS; col++){
        ResetWord();
        for(int row = 0; row < BOARD_COLS_AND_ROWS; row++){
            //For each row we make a Horizontal sweep:
            ReadCell(col,row);
        }
        FinishSearchInLine();
    }
    
    //Print word list to console:
    cout << "---------------------------"<<endl;
    cout << "    List of new words"<< endl;
    cout << "---------------------------"<<endl;
    for (int i = 0; i < m_aNewWords.size(); i++){
        cout << "- " << m_aNewWords[i] << endl;;
    }
    
}
void Board::SearchForWrongWords()
{
    m_aWrongWords.clear();
    vector<string>::iterator it = m_aNewWords.begin();
    vector<string>::iterator itEnd = m_aNewWords.end();
    for(;it != itEnd; it++){
        if (!m_oDictionary.Check(*it)){
            m_aWrongWords.push_back(*it);
        }
    }
}

bool Board::CheckPosition (std::string& errorMsg){
    errorMsg = "";
    bool isOk = true;
    
    int center_coordinate = (int)BOARD_COLS_AND_ROWS/2;
    if (m_bIsFirstWord){
        if (m_aCells[center_coordinate][center_coordinate].IsEmpty()){
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
        int col = m_aCurrentWord[0].GetCol();
        std::vector<int> l_aCols;
        for (int i = 0; i < m_aCurrentWord.size(); i++){
            l_aCols.push_back(m_aCurrentWord[i].GetCol());
            if (col != m_aCurrentWord[i].GetCol()){
                verticallyAligned  = false;
            }
        }
        
        //to check if all tiles are horizontally aligned
        std::vector<int> l_aRows;
        bool horizontallyAligned = true;
        int row = m_aCurrentWord[0].GetRow();
        for (int i = 0; i < m_aCurrentWord.size(); i++){
            l_aRows.push_back(m_aCurrentWord[i].GetRow());
            if (row != m_aCurrentWord[i].GetRow()){
                horizontallyAligned  = false;
            }
        }
        if (horizontallyAligned){
            std::sort(l_aCols.begin(), l_aCols.end());
            int minCol = l_aCols[0];
            int maxCol = l_aCols[l_aCols.size()-1];
            int row = m_aCurrentWord[0].GetRow();
            for(int col = minCol; col <= maxCol; col++){
                //there can be no empty cells between min and max:
                if (m_aCells[col][row].IsEmpty()){
                    horizontallyAligned = false;
                }
            }
        }else if (verticallyAligned){
            std::sort(l_aRows.begin(), l_aRows.end());
            int minRow = l_aRows[0];
            int maxRow = l_aRows[l_aRows.size()-1];
            int col = m_aCurrentWord[0].GetCol();
            for(int row = minRow; row <= maxRow; row++){
                //there can be no empty cells between min and max:
                if (m_aCells[col][row].IsEmpty()){
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
            int col =  m_aCurrentWord[i].GetCol();
            int row =  m_aCurrentWord[i].GetRow();
            int col_aux, row_aux;
            //Four directions:
            col_aux = max(0, col - 1); //UP
            row_aux = row;
            if (m_aCells[col_aux][row_aux].IsTilePlayed()){
                someNeighbor = true;
            }
            col_aux = min(BOARD_COLS_AND_ROWS - 1, col + 1); //DOWN
            row_aux = row;
            if (m_aCells[col_aux][row_aux].IsTilePlayed()){
                someNeighbor = true;
            }
            col_aux = col;
            row_aux = max(0, row - 1); //LEFT;
            if (m_aCells[col_aux][row_aux].IsTilePlayed()){
                someNeighbor = true;
            }
            col_aux = col;
            row_aux = min(BOARD_COLS_AND_ROWS - 1, row + 1); //RIGHT;
            if (m_aCells[col_aux][row_aux].IsTilePlayed()){
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



bool Board::CheckNewWords (int& points) {
    bool isCorrect = false;
    
    SearchForNewWords();
    SearchForWrongWords();
    
    if (m_aWrongWords.size() == 0){
        isCorrect = true;
        points = m_iTotalScore;
    }
    
    return isCorrect;
}

void Board::RemoveCurrentWord () {
    
    vector<BoardPosition>::iterator it = m_aCurrentWord.begin();
    vector<BoardPosition>::iterator itEnd = m_aCurrentWord.end();
    for(;it != itEnd; it++){
        int col = (*it).GetCol();
        int row = (*it).GetRow();
        m_aCells[col][row].RemoveTile();
    }
    m_aCurrentWord.clear();
}

void Board::RemoveLetter(BoardPosition boardPos) {
    vector<BoardPosition>::iterator it = m_aCurrentWord.begin();
    vector<BoardPosition>::iterator itEnd = m_aCurrentWord.end();
    
    int col = boardPos.GetCol();
    int row = boardPos.GetRow();
    bool found = false;
    while(it!=itEnd && !found){
        int col_aux = (*it).GetCol();
        int row_aux = (*it).GetRow();
        if (boardPos.GetCol() == col_aux && row == row_aux){
            m_aCells[col][row].RemoveTile();
            found = true;
        }else{
            it++;
        }
    }
    if (found){
        m_aCurrentWord.erase(it);
    }
    
    
}



