//
//  Button.cpp

#include "Button.h"

Button::Button( const string& path_normal,
                const string& path_pressed,
                int posX, int posY, int width, int height)
{
    m_eCurrentState = NORMAL;
    m_iPosX = posX;
    m_iPosY = posY;
    m_iWidth = width;
    m_iHeight = height;
    m_oNormal.create(path_normal.c_str());
    m_pPressed.create(path_pressed.c_str());
}

Button::~Button(){
}


bool Button::Update ( int mousePosX, int mousePosY, bool mouseIsPressed) {

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

void Button::Render () {
    switch (m_eCurrentState){
        case NORMAL:
            m_oNormal.draw(m_iPosX, m_iPosY);
            break;
        case PRESSED:
            m_pPressed.draw(m_iPosX, m_iPosY);
            break;
        case NONE:
            //Nothing to do.
            break;
    }
}

