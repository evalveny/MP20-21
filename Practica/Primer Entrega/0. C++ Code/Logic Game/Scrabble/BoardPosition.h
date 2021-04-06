//
//  BoardPosition.hpp
//  MP_Practica
//
//  Created by Enric Vergara on 14/03/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef BoardPosition_hpp
#define BoardPosition_hpp

#include <stdio.h>

class BoardPosition {
public:
    BoardPosition(): m_iRow(-1), m_iCol(-1) {}
    BoardPosition(int col, int row): m_iRow(row), m_iCol(col) {}
    
    int     getCol      () const {return m_iCol;}
    int     getRow      () const {return m_iRow;}
    void    setCol      (int col) {m_iCol = col;}
    void    setRow      (int row) {m_iRow = row;}
    bool    operator==  (const BoardPosition& bp) const {return m_iRow==bp.m_iRow && m_iCol ==bp.m_iCol;}
private:
    int m_iRow;
    int m_iCol;
};



#endif /* BoardPosition_hpp */
