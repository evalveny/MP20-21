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

    bool l_bDoAction = false;
    if (mousePosX >= m_iPosX && mousePosX <= m_iPosX + m_iWidth &&
        mousePosY >= m_iPosY && mousePosY <= m_iPosY + m_iHeight)
    {
        if (mouseIsPressed && m_eCurrentState == NORMAL){
            m_eCurrentState = PRESSED; //Hem entrat amb el mouse apretant --> no fer res.
        }else if (!mouseIsPressed && m_eCurrentState == PRESSED)
        {
            l_bDoAction = true;
            m_eCurrentState = NORMAL;
        }
    }else{
        m_eCurrentState = NORMAL;
    }

    return l_bDoAction;
}

void Button::render () {
    switch (m_eCurrentState){
        case NORMAL:
            GraphicManager::getInstance()->drawSprite(m_eStateNormal,m_iPosX, m_iPosY);
            break;
        case PRESSED:
            GraphicManager::getInstance()->drawSprite(m_eStatePressed,m_iPosX, m_iPosY);
            
            break;
        case NONE:
            //Nothing to do.
            break;
    }
}

