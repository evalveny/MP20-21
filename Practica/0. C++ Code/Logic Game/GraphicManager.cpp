//
//  GraphicManager.cpp
//  MP_Practica
//
//  Created by Enric Vergara on 13/03/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#include "GraphicManager.h"
#include <iostream>

GraphicManager* GraphicManager::instance=NULL;

GraphicManager::GraphicManager()
: m_oFontWhite_30(getFontPath(FONT_WHITE_30).c_str(),30,NFont::Color(255,255,255,255))
, m_oFontRed_30(getFontPath(FONT_RED_30).c_str(),30,NFont::Color(255,0,0,255))
, m_oFontGreen_30(getFontPath(FONT_GREEN_30).c_str(),30,NFont::Color(0,255,0,255))
{
    for (int i = 0; i < IMAGE_NUM_MAX; i ++){
        string path = getImagePath((IMAGE_NAME)i);
        m_aSprites[i].create(path.c_str());
    }
}


void GraphicManager::drawSprite (IMAGE_NAME name, float posX, float posY) {
    if (name >= 0 && name < IMAGE_NUM_MAX){
        m_aSprites[name].draw(posX, posY);
    }else{
        cout << "Error: no existeix el identificador de image";
    }
    
}

NFont::Rectf GraphicManager::drawFont (FONT_NAME name,
                                       float posX, float posY,
                                       float size,
                                       const string& msg)
{
    switch (name) {
        case FONT_GREEN_30:
            return m_oFontGreen_30.draw(posX, posY, NFont::Scale(size), "%s", msg.c_str());
            break;
        case FONT_RED_30:
            return m_oFontRed_30.draw(posX, posY, NFont::Scale(size), "%s", msg.c_str());
            break;
        case FONT_WHITE_30:
            return m_oFontWhite_30.draw(posX, posY, NFont::Scale(size), "%s", msg.c_str());
            break;
            
        default:
            cout << "Error: no existeix el identificador de font";
            break;
    }
    return NFont::Rectf();
}

string GraphicManager::getImagePath(IMAGE_NAME name){
    string path;
    
    
    if(name < 26){
        path = "data/Letters/Small/" + to_string(name) + ".png";
    }else if (name < 52){ //26+26{
        path = "data/Letters/Big/" + to_string(name - 26) + ".png";
    }else{
        switch (name) {
            case IMAGE_BOARD:
                path = "data/GUI/game-board.png";
                break;
            case IMAGE_BACKGROUND:
                path = "data/GUI/background.png";
                break;
            case IMAGE_BUTTON_RECALL_NORMAL:
                path = "data/GUI/recall_normal.png";
                break;
            case IMAGE_BUTTON_RECALL_PRESSED:
                path = "data/GUI/recall_pressed.png";
                break;
            case IMAGE_BUTTON_SHUFFLE_NORMAL:
                path = "data/GUI/shuffle_normal.png";
                break;
            case IMAGE_BUTTON_SHUFFLE_PRESSED:
                path = "data/GUI/shuffle_pressed.png";
                break;
            case IMAGE_BUTTON_SEND_NORMAL:
                path = "data/GUI/send_normal.png";
                break;
            case IMAGE_BUTTON_SEND_PRESSED:
                path = "data/GUI/send_pressed.png";
                break;
            case IMAGE_BUTTON_PASS_NORMAL:
                path = "data/GUI/pass_normal.png";
                break;
            case IMAGE_BUTTON_PASS_PRESSED:
                path = "data/GUI/pass_pressed.png";
                break;
            default:
                path = "";
                break;
        }
    }
    
    
    
    return path;
}
string GraphicManager::getFontPath(FONT_NAME name){
    string path;
    switch (name) {
        case FONT_GREEN_30:
        case FONT_RED_30:
        case FONT_WHITE_30:
            path = "data/Fonts/FreeSans.ttf";
            break;
            
        default:
            path = "";
            break;
    }
    
    return path;
}

