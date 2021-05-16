//
//  Button.cpp

#include "Button.h"

Button::Button(IMAGE_NAME state_normal,
               IMAGE_NAME state_pressed,
               int posX, int posY,
               int width, int height)
{
    m_eCurrentState = NORMAL;
    m_iPosX = posX;
    m_iPosY = posY;
    m_iWidth = width;
    m_iHeight = height;
    m_eStateNormal = state_normal;
    m_eStatePressed = state_pressed;
}

Button::~Button(){
}


bool Button::update ( int mousePosX, int mousePosY, bool mouseIsPressed) {

	//TODO 4.1: Implementar la programació del update...
    return false; //Això s'ha de modificar, ho deixem posat per tal que compili sense errors.
}

void Button::render () {
    //TODO 4.2: Implementar la programació del render...
}

