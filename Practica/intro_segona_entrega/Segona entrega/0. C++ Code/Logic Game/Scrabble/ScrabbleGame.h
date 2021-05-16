//
//  ScrabbleGame.hpp
//  Letris
//
//  Created by Enric Vergara on 13/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef ScrabbleGame_hpp
#define ScrabbleGame_hpp

#include <stdio.h>


class ScrabbleGame
{
public:
    ScrabbleGame();
    ~ScrabbleGame();
    
    void updateAndRender    (int mousePosX, int mousePosY,bool mouseStatus);
    
    
private:
	
	//TODO 4.3: Instanciar el botó send fent ús de la classe Button.
	// - Eliminem el codi que hem fet per poder gestionar un botó i ara ho fem mitjançant la classe Button
	// - Inicialitzar la instància de button en el constructor de ScrabbleGame.
	// - Fer la crida del render i update de la instància en el updateAndRender(...).


};

#endif /* ScrabbleGame_hpp */
