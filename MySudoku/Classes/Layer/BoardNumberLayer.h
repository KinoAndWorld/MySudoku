//
//  BoardNumberLayer.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#ifndef __MySudoku__BoardNumberLayer__
#define __MySudoku__BoardNumberLayer__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class GameScene;

class BoardNumberLayer : public CCLayer {
public:
    CREATE_FUNC(BoardNumberLayer);
    ~BoardNumberLayer();
    bool init();
    
    CC_PROPERTY_READONLY(CCArray *, _numbers, Numbers);
    CC_PROPERTY_READONLY(CCSprite *, _boardNumberSprite, BoardNumberSprite);
    //加载选取的数字
    void loadBoardNumber();
    //随机添加在底部位置
    void showBoardNumberByRandom();
    //点击草地区域
    void touchCell(CCTouch *target);
protected:
    GameScene* getGameScene();
};

#endif /* defined(__MySudoku__BoardNumberLayer__) */
