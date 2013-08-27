//
//  StartScene.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//  开始菜单
//

#ifndef __MySudoku__StartScene__
#define __MySudoku__StartScene__

#include <iostream>
#include "cocos2d.h"
#include "MenuLayer.h"

USING_NS_CC;

class StartScene : public CCScene{
public:
    CREATE_FUNC(StartScene);
    bool init();
    ~StartScene();
    
    //菜单页面相关的函数
    void startGame();
    void settingGame();
    void aboutGame();
    void playBackgroundMusic();
protected:
    MenuLayer *_menuLayer;
};

#endif /* defined(__MySudoku__StartScene__) */
