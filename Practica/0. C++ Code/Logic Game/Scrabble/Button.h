//
//  Button.hpp
#pragma once

#include <stdio.h>
#include <string>
#include "../joc.h"

using namespace std;

class Button
{
public:
    typedef enum {
        NORMAL = 0,
        PRESSED,
        NONE
    } ButtonState;

    Button( const string& path_normal,
            const string& path_pressed,
            int posX, int posY, int width, int height);

    ~Button();

    bool Update ( int mousePosX, int mousePosY, bool mouseIsPressed);
    void Render ();

private:
    ButtonState m_eCurrentState;
    int         m_iPosX;
    int         m_iPosY;
    int         m_iWidth;
    int         m_iHeight;
    Sprite      m_oNormal;
    Sprite      m_pPressed;
};

