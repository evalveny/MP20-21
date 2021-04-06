//
//  Button.hpp
#pragma once

#include <stdio.h>
#include <string>
#include "../GraphicManager.h"

using namespace std;

class Button
{
public:
    typedef enum {
        NORMAL = 0,
        PRESSED,
        NONE
    } ButtonState;

    Button(IMAGE_NAME state_normal,
           IMAGE_NAME state_pressed,
           int posX, int posY,
           int width, int height);

    ~Button();

    bool update ( int mousePosX, int mousePosY, bool mouseIsPressed);
    void render ();

private:
    ButtonState m_eCurrentState;
    int         m_iPosX;
    int         m_iPosY;
    int         m_iWidth;
    int         m_iHeight;
    IMAGE_NAME  m_eStateNormal;
    IMAGE_NAME  m_eStatePressed;
};

