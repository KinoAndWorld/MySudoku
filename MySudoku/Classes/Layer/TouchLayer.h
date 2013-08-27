//
//  TouchLayer.h
//  MySudoku
//
//  Created by Kino on 13-8-22.
//
//

#ifndef __MySudoku__TouchLayer__
#define __MySudoku__TouchLayer__

#include "cocos2d.h"

USING_NS_CC;

class GameScene;

class TouchLayer : public CCLayer {
public:
    CREATE_FUNC(TouchLayer);
    bool init();

    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    //开启、关闭触摸的接口
    void setTouchEnabled(bool flag);
protected:
    GameScene* getGameScene();
    CCPoint locationFromTouch(cocos2d::CCTouch *touch);
};

#endif /* defined(__MySudoku__TouchLayer__) */
