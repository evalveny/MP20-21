//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
#include "Joc.h" //Aquest inclou llibreria grafica
#include <conio.h>      /* getch */ 

#elif __APPLE__
#include "joc.h" //Aquest inclou llibreria grafica
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif





int main(int argc, const char* argv[])
{
	//Instruccions necesaries per poder incloure la llibreria i que trobi el main
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	///////////////////////////////////////////////////////////////////////////

	joc();


	//Instruccio necesaria per poder incloure la llibreria i que trobi el main
	SDL_Quit();
	///////////////////////////////////////////////////////////////////////////
	return 0;
}

