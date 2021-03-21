//
//  GraphicManager.hpp
//  MP_Practica
//
//  Created by Enric Vergara on 13/03/2021.
//  Copyright © 2021 CompiledCreations. All rights reserved.
//

#ifndef GraphicManager_hpp
#define GraphicManager_hpp

#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <stdio.h>
#include <string>
#include <map>
using namespace std;


typedef enum {
    IMAGE_LETTER_A_SMALL = 0,
    IMAGE_LETTER_B_SMALL,
    IMAGE_LETTER_C_SMALL,
    IMAGE_LETTER_D_SMALL,
    IMAGE_LETTER_E_SMALL,
    IMAGE_LETTER_F_SMALL,
    IMAGE_LETTER_G_SMALL,
    IMAGE_LETTER_H_SMALL,
    IMAGE_LETTER_I_SMALL,
    IMAGE_LETTER_J_SMALL,
    IMAGE_LETTER_K_SMALL,
    IMAGE_LETTER_L_SMALL,
    IMAGE_LETTER_M_SMALL,
    IMAGE_LETTER_N_SMALL,
    IMAGE_LETTER_O_SMALL,
    IMAGE_LETTER_P_SMALL,
    IMAGE_LETTER_Q_SMALL,
    IMAGE_LETTER_R_SMALL,
    IMAGE_LETTER_S_SMALL,
    IMAGE_LETTER_T_SMALL,
    IMAGE_LETTER_U_SMALL,
    IMAGE_LETTER_V_SMALL,
    IMAGE_LETTER_W_SMALL,
    IMAGE_LETTER_X_SMALL,
    IMAGE_LETTER_Y_SMALL,
    IMAGE_LETTER_Z_SMALL, // 25
    IMAGE_LETTER_A_BIG,   // 26
    IMAGE_LETTER_B_BIG,
    IMAGE_LETTER_C_BIG,
    IMAGE_LETTER_D_BIG,
    IMAGE_LETTER_E_BIG,
    IMAGE_LETTER_F_BIG,
    IMAGE_LETTER_G_BIG,
    IMAGE_LETTER_H_BIG,
    IMAGE_LETTER_I_BIG,
    IMAGE_LETTER_J_BIG,
    IMAGE_LETTER_K_BIG,
    IMAGE_LETTER_L_BIG,
    IMAGE_LETTER_M_BIG,
    IMAGE_LETTER_N_BIG,
    IMAGE_LETTER_O_BIG,
    IMAGE_LETTER_P_BIG,
    IMAGE_LETTER_Q_BIG,
    IMAGE_LETTER_R_BIG,
    IMAGE_LETTER_S_BIG,
    IMAGE_LETTER_T_BIG,
    IMAGE_LETTER_U_BIG,
    IMAGE_LETTER_V_BIG,
    IMAGE_LETTER_W_BIG,
    IMAGE_LETTER_X_BIG,
    IMAGE_LETTER_Y_BIG,
    IMAGE_LETTER_Z_BIG,
    IMAGE_BOARD,
    IMAGE_BACKGROUND,
    IMAGE_BUTTON_RECALL_NORMAL,
    IMAGE_BUTTON_RECALL_PRESSED,
    IMAGE_BUTTON_SHUFFLE_NORMAL,
    IMAGE_BUTTON_SHUFFLE_PRESSED,
    IMAGE_BUTTON_SEND_NORMAL,
    IMAGE_BUTTON_SEND_PRESSED,
    IMAGE_BUTTON_PASS_NORMAL,
    IMAGE_BUTTON_PASS_PRESSED,
    
    IMAGE_NUM_MAX
} IMAGE_NAME;

typedef enum {
    FONT_WHITE_30 = 0,
    FONT_RED_30,
    FONT_GREEN_30,
    
    FONT_NUM_MAX
} FONT_NAME;


class GraphicManager
{
public:
    
    void            drawSprite  (IMAGE_NAME name, float posX, float posY);
    //size: [0-1]∫
    NFont::Rectf    drawFont    (FONT_NAME name, float posX,
                                 float posY, float size,
                                 const string& msg);
    
    
    static GraphicManager *getInstance()
    {
        if (instance == NULL)
          instance = new GraphicManager();
        return instance;
    }
    

protected:
    GraphicManager();
    virtual ~GraphicManager() {}
    GraphicManager(GraphicManager const&);
    GraphicManager& operator=(GraphicManager const&);

private:
    static GraphicManager *instance;
    
    Sprite  m_aSprites[IMAGE_NUM_MAX];
    NFont   m_oFontWhite_30;
    NFont   m_oFontRed_30;
    NFont   m_oFontGreen_30;
    
private:
    string getImagePath (IMAGE_NAME);
    string getFontPath  (FONT_NAME);
};



#endif /* GraphicManager_hpp */
