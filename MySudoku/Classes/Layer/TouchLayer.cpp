//
//  TouchLayer.cpp
//  MySudoku
//
//  Created by Kino on 13-8-22.
//
//

#include "TouchLayer.h"
#include "GameScene.h"

bool TouchLayer::init(){
    this->setTouchEnabled(true);
    return true;
}

bool TouchLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    //CCPoint pt = pTouch->getLocationInView();
    
    this->getGameScene()->touchCell(pTouch);
    return true;
}

void TouchLayer::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    
}

void TouchLayer::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    
}

//开启、关闭触摸的接口
void TouchLayer::setTouchEnabled(bool flag){
    if (m_bTouchEnabled != flag){
        m_bTouchEnabled = flag;
        if(flag){
            CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        }else{
            CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
        }
    }
}

GameScene* TouchLayer::getGameScene(){
    return (GameScene*)this->getParent();
}

CCPoint TouchLayer::locationFromTouch(CCTouch* touch)
{
    //把点从UI坐标系转到GL坐标系
    return CCDirector::sharedDirector()->convertToGL(touch->getLocationInView());
}


