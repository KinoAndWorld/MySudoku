//
//  MenuLayer.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#ifndef __MySudoku__MenuLayer__
#define __MySudoku__MenuLayer__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;


class MenuLayer : public CCLayer {
public:
    CREATE_FUNC(MenuLayer);
    bool init();
    
    void startGame();
    void settingGame();
    void aboutGame();
    
protected:
    void createMenu();
    void createBackground();
};

#endif /* defined(__MySudoku__MenuLayer__) */
