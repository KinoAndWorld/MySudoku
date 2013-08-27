//
//  BackGroundLayer.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#include "BackGroundLayer.h"
#include "StaticData.h"


bool BackGroundLayer::init(){
    if (CCLayer::init()) {
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        CCSprite *_background = CCSprite::create(S_BG);
        _background->setPosition(ccp(winSize.width *0.5, winSize.height *0.5));
        
        this->addChild(_background);
        return true;
    }
    return false;
}