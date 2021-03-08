//
//  LettersBag.cpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "LettersBag.h"
#include <time.h>

LettersBag::LettersBag(){
    srand((unsigned int)time(0));
     
    //               letter, score, frequency
    vector<char> aL;
    vector<int> aS;
    vector<int> aF;
    aL.push_back('a'); aS.push_back(1);  aF.push_back(9);
    aL.push_back('b'); aS.push_back(3);  aF.push_back(2);
    aL.push_back('c'); aS.push_back(3);  aF.push_back(2);
    aL.push_back('d'); aS.push_back(2);  aF.push_back(4);
    aL.push_back('e'); aS.push_back(1);  aF.push_back(12);
    aL.push_back('f'); aS.push_back(4);  aF.push_back(2);
    aL.push_back('g'); aS.push_back(2);  aF.push_back(3);
    aL.push_back('h'); aS.push_back(4);  aF.push_back(2);
    aL.push_back('i'); aS.push_back(1);  aF.push_back(9);
    aL.push_back('j'); aS.push_back(8);  aF.push_back(1);
    aL.push_back('k'); aS.push_back(5);  aF.push_back(1);
    aL.push_back('l'); aS.push_back(1);  aF.push_back(4);
    aL.push_back('m'); aS.push_back(3);  aF.push_back(2);
    aL.push_back('n'); aS.push_back(1);  aF.push_back(6);
    aL.push_back('o'); aS.push_back(1);  aF.push_back(8);
    aL.push_back('p'); aS.push_back(3);  aF.push_back(2);
    aL.push_back('q'); aS.push_back(10); aF.push_back(1);
    aL.push_back('r'); aS.push_back(1);  aF.push_back(6);
    aL.push_back('s'); aS.push_back(1);  aF.push_back(4);
    aL.push_back('t'); aS.push_back(1);  aF.push_back(6);
    aL.push_back('u'); aS.push_back(1);  aF.push_back(4);
    aL.push_back('v'); aS.push_back(4);  aF.push_back(2);
    aL.push_back('w'); aS.push_back(4);  aF.push_back(2);
    aL.push_back('x'); aS.push_back(8);  aF.push_back(1);
    aL.push_back('y'); aS.push_back(4);  aF.push_back(2);
    aL.push_back('z'); aS.push_back(10); aF.push_back(1);
    //aL.push_back('_'); aS.push_back(1);  aF.push_back(2);
    
        
    for (int aux = 0; aux < aL.size(); aux++) {
        for(int i = 0; i < aF[aux]; i++){
            int score = aS[i];
            int letter = aL[i];
            m_aLetters.push_back(Tile(letter,score));
        }
    }
}

LettersBag::~LettersBag(){
    
}

Tile LettersBag::GetLetter() {
    int index = rand() % m_aLetters.size();
    Tile letter = m_aLetters[index];
    m_aLetters.erase(m_aLetters.begin() +  index);
    return letter;
}
