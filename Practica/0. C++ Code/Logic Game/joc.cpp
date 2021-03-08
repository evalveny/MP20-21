#include "joc.h"
#include "ScrabbleGame.h"
#include "../Graphic Lib/NFont/NFont.h"




//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc()
{
	//Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
	Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
	//Mostrem la finestra grafica
	pantalla.show();

	ScrabbleGame game;
	
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	do
	{
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());

		// Captura tots els events de ratolí i teclat de l'ultim cicle
		pantalla.processEvents();

		bool mouseStatus = Mouse_getBtnLeft();
		bool moousePressed = Mouse_getButLeft();
		
		int mousePosX = Mouse_getX();
		int mousePosY = Mouse_getY();
		game.UpdateAndRender(mousePosX, mousePosY, moousePressed, mouseStatus,(float)deltaTime);
		
		// Actualitza la pantalla
		pantalla.update();

	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
	// Sortim del bucle si pressionem ESC
}
