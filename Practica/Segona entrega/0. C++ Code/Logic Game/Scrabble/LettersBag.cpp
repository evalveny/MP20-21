//
//  LettersBag.cpp
//  Letris
//
//  Created by Enric Vergara on 14/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "LettersBag.h"
#include <time.h>
#include <iostream>
#include <fstream>

LettersBag::LettersBag(){
    srand((unsigned int)time(0));
     
    // letter, score, frequency
    vector<char> aL;
    vector<int> aS;
    vector<int> aF;
    
    
    ifstream lettersBagFile;
    lettersBagFile.open ("data/Configuration/lettersBag.txt");
    if (lettersBagFile.is_open())
    {
        int frequency, score;
        char letter;
        
        do
        {
            lettersBagFile >> letter >> score >> frequency;
            aL.push_back(letter);
            aS.push_back(score);
            aF.push_back(frequency);
            
            cout << letter << " " << score << " " << frequency <<endl;
            
        } while ( !lettersBagFile.eof() );
        
        lettersBagFile.close();
    }
    
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

Tile LettersBag::getLetter() {
    int index = rand() % m_aLetters.size();
    Tile letter = m_aLetters[index];
    m_aLetters.erase(m_aLetters.begin() +  index);
    return letter;
}
