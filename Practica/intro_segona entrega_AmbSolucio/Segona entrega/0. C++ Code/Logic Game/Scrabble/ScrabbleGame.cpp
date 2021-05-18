//
//  ScrabbleGame.cpp
//  Letris
//
//  Created by Enric Vergara on 13/02/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "ScrabbleGame.h"
#include "../Scrabble_Defs.h"

#include "../GraphicManager.h"
#include "Tile.h"

ScrabbleGame::ScrabbleGame()
{
	//TODO 3.1
	
	btn_isPressed = false;
	draw_tiles = true;

	
}

ScrabbleGame::~ScrabbleGame(){
    
}

void ScrabbleGame::updateAndRender (int mousePosX, int mousePosY, bool mouseStatus){
       
	//TODO 1: Interactuar amb la crida de pintar images (sprites).
	//--------------------------------------------------------------

	//TODO 1.1 Afegir l'include de GraphicManager --> #include "../GraphicManager.h"
	//TODO 1.2 Fer la crida de pintar sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY);
	//	    Per començar podem cridar el drawSprite amb els params --> (IMAGE_BOARD,0,0)
	
	// GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, 0, 0);
	
	//	1.3 Reescriure la crida de pintar el IMAGE_BOARD però que estigui centrat en l'eix X i a 40 píxels de l'eix Y
	//		Podeu fer servir la constant BOARD_SIZE definida a Scrabble_Defs.h
	//          SCREEN_SIZE_X (tenim aquesta constant que definexi el width de la pantalla)
	//  (0,0) ----------------> X+ 
	//    |
	//    |
	//    |
	//    v
	//    Y+ 
	// SCREEN_SIZE_Y (tenim aquesta altre constant que defineixi el height de la pantalla)

	// GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, int(SCREEN_SIZE_X * 0.5 - BOARD_SIZE*0.5), 40);
	
	
	//TODO 1.4: Us anirà molt bé definir en el Scrabble_Defs.h dos constants BOARD_POS_X, BOARD_POS_Y i refer la 
	//		crida anterior. Reutilitzareu diverses vegades aquestes constants. 
	// GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);
	
	
	//TODO 1.5: Cridar el sprite IMAGE_BACKGROUND. Aquest ocupa tota la pantalla i bàsicament és de color blau.
	//			El podem cridar utilitzant la posició inicial 0,0.
	
	// GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);
	// GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);

	//TODO 1.6: Fixeu-vos que el sprite del board ha desaparegut. Això ha passat ja que l'última crida de drawSprite
	//			queda per sobre de l'anterior. Reescriure l'ordre de pintat per tal que el board estigui després del
	//			background.

	// GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	// GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);
	
	
	//TODO 1.7: Anem a pintar la imatge de la tile 'A' (IMAGE_LETTER_A_SMALL)
	//			Recordeu que podeu utilitzar les constants definides en Scrabble_Defs.h --> 
	//			BOARD_POS_X: posició inicial del board en l'eix X
	//			BOARD_POS_Y: posició inicial del board en l'eix Y
	//			BOARD_TILE_SIZE: Mida de la tile (tant per width com per height)
	//			BOARD_COLS_AND_ROWS: Nombre de columnes i rows (és el mateix).

	/* GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);

	int posX = BOARD_POS_X;
	int posY = BOARD_POS_Y;
	for (int i = 0; i < BOARD_COLS_AND_ROWS; i++) {

		for (int j = 0; j < BOARD_COLS_AND_ROWS; j++) {
			GraphicManager::getInstance()->drawSprite(IMAGE_LETTER_A_SMALL, posX, posY);
			posX += BOARD_TILE_SIZE;
		}
		posY += BOARD_TILE_SIZE;
		posX = BOARD_POS_X;
	}
	*/ 

	//TODO 2: Interacció amb el mouse
	//------------------------------------------
	
	//TODO 2.1: Observeu que passa si poseu tot el codi del pintat de les tiles 'A' en un if(mouseStatus)
	
	/*GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);

	if (mouseStatus) {
		int posX = BOARD_POS_X;
		int posY = BOARD_POS_Y;
		for (int i = 0; i < BOARD_COLS_AND_ROWS; i++) {

			for (int j = 0; j < BOARD_COLS_AND_ROWS; j++) {
				GraphicManager::getInstance()->drawSprite(IMAGE_LETTER_A_SMALL, posX, posY);
				posX += BOARD_TILE_SIZE;
			}
			posY += BOARD_TILE_SIZE;
			posX = BOARD_POS_X;
		}
	}
	*/

	//TODO 2.2: Afegiu com a última crida del vostre codi la següent crida del GraphicManager-->
	//			GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 10, 10, 0.6, "Hello world!");
	//			Recordeu que tota crida de drawSprite o drawFont segueix l'ordre de pintat. Si executem
	//			aquesta crida de drawFont com a primera instrucció no es visualitzarà, ja que està per darrera
	//			del background.

	/*GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);


	if (mouseStatus) {
		int posX = BOARD_POS_X;
		int posY = BOARD_POS_Y;
		for (int i = 0; i < BOARD_COLS_AND_ROWS; i++) {

			for (int j = 0; j < BOARD_COLS_AND_ROWS; j++) {
				GraphicManager::getInstance()->drawSprite(IMAGE_LETTER_A_SMALL, posX, posY);
				posX += BOARD_TILE_SIZE;
			}
			posY += BOARD_TILE_SIZE;
			posX = BOARD_POS_X;
		}
	}
	
	GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 10, 10, 0.6, "Hello world!");
	*/
	//TODO 2.3: Imprimiu les coordenades del mouse (us la passen per paràmetres), fent ús de drawFont.
	/*GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);


	if (mouseStatus) {
		int posX = BOARD_POS_X;
		int posY = BOARD_POS_Y;
		for (int i = 0; i < BOARD_COLS_AND_ROWS; i++) {

			for (int j = 0; j < BOARD_COLS_AND_ROWS; j++) {
				GraphicManager::getInstance()->drawSprite(IMAGE_LETTER_A_SMALL, posX, posY);
				posX += BOARD_TILE_SIZE;
			}
			posY += BOARD_TILE_SIZE;
			posX = BOARD_POS_X;
		}
	}

	std::string msg = "PosX: " + to_string(mousePosX) + ", PosY: " + to_string(mousePosY);
	GraphicManager::getInstance()->drawFont(FONT_GREEN_30, 10, 10, 0.6, msg);
	*/

	//TODO 3: Programar el codi per afegir un botó
	//--------------------------------------------
	//Per no liar - nos amb el click del mouse treiem el pintat dels tiles respecte l'estat del botó del mouse.
	//TODO 3.1: - Programar un botó fent ús de les imatges 
	//			    IMAGE_BUTTON_SEND_NORMAL: per dibuixar la seva representació del botó quan el mouse no està pressionant dintre de la seva zona
	//			    IMAGE_BUTTON_SEND_PRESSED: per dibuixar la representació del botó quan el mouse està pressionant dintre de la seva zona
	//			- Haureu de fer servir una variable per saber en quin estat està el mouse respecte el botó.
	//			- Podeu fer servir les següents coordenades pel botó-->
	//			    int btn_size_w = 139;
	//			    int btn_size_h = 100;
	//			    int btn_pos_x = SCREEN_SIZE_X*0.5 - btn_size_w*0.5;
	//			    int btn_pos_y = SCREEN_SIZE_Y - btn_size_h;
	//			- Heu de fer que es produeixi una acció al prémer en el botó --> pintar/deixar de pintar les lletres
	//				- Acció es produeix quan entrem en la zona del botó i passem d'estar apretant el botó de mouse a no estar-hi
	//

	/*GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	GraphicManager::getInstance()->drawSprite(IMAGE_BOARD, BOARD_POS_X, BOARD_POS_Y);
	if (draw_tiles) {
		int posX = BOARD_POS_X;
		int posY = BOARD_POS_Y;
		for (int i = 0; i < BOARD_COLS_AND_ROWS; i++) {

			for (int j = 0; j < BOARD_COLS_AND_ROWS; j++) {
				GraphicManager::getInstance()->drawSprite(IMAGE_LETTER_A_SMALL, posX, posY);
				posX += BOARD_TILE_SIZE;
			}
			posY += BOARD_TILE_SIZE;
			posX = BOARD_POS_X;
		}
	}

	std::string msg = "PosX: " + to_string(mousePosX) + ", PosY: " + to_string(mousePosY);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 10, 10, 0.6, msg);

	int btn_size_w = 139;
	int btn_size_h = 100;
	int btn_pos_x = SCREEN_SIZE_X*0.5 - btn_size_w*0.5;
	int btn_pos_y = SCREEN_SIZE_Y - btn_size_h;
	if (btn_isPressed) {
		GraphicManager::getInstance()->drawSprite(IMAGE_BUTTON_SEND_PRESSED, btn_pos_x, btn_pos_y);
	}
	else {
		GraphicManager::getInstance()->drawSprite(IMAGE_BUTTON_SEND_NORMAL, btn_pos_x, btn_pos_y);
	}

	if (mousePosX > btn_pos_x && mousePosX < btn_pos_x + btn_size_w &&
		mousePosY > btn_pos_y && mousePosY < btn_pos_y + btn_size_h) {
		if (mouseStatus) {
			btn_isPressed = true;
		}
		else {
			if (btn_isPressed) {
				btn_isPressed = false;
				//Do action:
				draw_tiles = !draw_tiles;
			}
		}
	}
	else {
		btn_isPressed = false;
	}
	*/



	//TODO TASQUES PER FER: Mostrar l'estat actual del tauler 
	//------------------------------------------------------

	GraphicManager::getInstance()->drawSprite(IMAGE_BACKGROUND, 0, 0);
	if (draw_tiles) {
		Tile tile1('i', 1);
		board.setTile(tile1, BoardPosition(7, 7)); //BoardPosition(col, row)
		Tile tile2('s', 1);
		board.setTile(tile2, BoardPosition(8, 7));
	}
	board.render();
	board.removeCurrentWord();

	std::string msg = "PosX: " + to_string(mousePosX) + ", PosY: " + to_string(mousePosY);
	GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 10, 10, 0.6, msg);

	int btn_size_w = 139;
	int btn_size_h = 100;
	int btn_pos_x = SCREEN_SIZE_X*0.5 - btn_size_w*0.5;
	int btn_pos_y = SCREEN_SIZE_Y - btn_size_h;
	if (btn_isPressed) {
		GraphicManager::getInstance()->drawSprite(IMAGE_BUTTON_SEND_PRESSED, btn_pos_x, btn_pos_y);
	}
	else {
		GraphicManager::getInstance()->drawSprite(IMAGE_BUTTON_SEND_NORMAL, btn_pos_x, btn_pos_y);
	}

	if (mousePosX > btn_pos_x && mousePosX < btn_pos_x + btn_size_w &&
		mousePosY > btn_pos_y && mousePosY < btn_pos_y + btn_size_h) {
		if (mouseStatus) {
			btn_isPressed = true;
		}
		else {
			if (btn_isPressed) {
				btn_isPressed = false;
				//Do action:
				draw_tiles = !draw_tiles;
			}
		}
	}
	else {
		btn_isPressed = false;
	}
	
}
