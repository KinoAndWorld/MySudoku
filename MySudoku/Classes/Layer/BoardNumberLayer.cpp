//
//  BoardNumberLayer.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#include "BoardNumberLayer.h"
#include "BoardNumber.h"
#include "StaticData.h"
#include "GameScene.h"

const static int numberCount = 9;

bool BoardNumberLayer::init(){
    this->loadBoardNumber();
    this->showBoardNumberByRandom();
    return true;
}

void BoardNumberLayer::loadBoardNumber(){
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    _boardNumberSprite = CCSprite::create(S_BOARD_NUMBER_BG);
    CC_SAFE_RETAIN(_boardNumberSprite);
    _boardNumberSprite->setPosition(ccp(winSize.width*0.5, -winSize.height*0.08));
    this->addChild(_boardNumberSprite);
    
    _numbers = CCArray::createWithCapacity(numberCount);
    CC_SAFE_RETAIN(_numbers);
    
    for (int i = 0; i < numberCount; i++) {
        CCString *sprName = CCString::createWithFormat("normal-tile-%d-x10@2x.png",i+1);
        CCSprite *spr = CCSprite::create(sprName->getCString());
        spr->setTag(i+1);
        BoardNumber *boardNumber = BoardNumber::create();
        boardNumber->setSprite(spr);
        _numbers->addObject(boardNumber);
    }
}

void BoardNumberLayer::showBoardNumberByRandom(){
    //CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCObject *obj;
    int index = 0;
    CCARRAY_FOREACH(_numbers, obj){
        BoardNumber *boardNumber = (BoardNumber *)obj;
        CCSprite *spr = boardNumber->getSprite();
        float positionX = index * 70 + 50;
        float positionY =  CCRANDOM_0_1() * 80 + 70;
        spr->setPosition(ccp(positionX, positionY));
        this->addChild(spr);
        index++;
    }
}

CCArray * BoardNumberLayer::getNumbers(){
    return _numbers;
}

CCSprite * BoardNumberLayer::getBoardNumberSprite(){
    return _boardNumberSprite;
}

//点击事件
void BoardNumberLayer::touchCell(CCTouch *target){
    CCObject *obj;
    //确保点中了某个cell
    int numbeOfTtouch = -1;
    CCARRAY_FOREACH(_numbers, obj){
        BoardNumber *boardNumber = (BoardNumber *)obj;
        CCSprite *numberSprite = boardNumber->getSprite();
        //转换成精灵相对坐标
        CCPoint touchPoint = convertTouchToNodeSpace(target);
        //CCLOG("sprRectX=%f,sprRectY=%f",spr->boundingBox().origin.x,spr->boundingBox().origin.y);
        if (numberSprite->boundingBox().containsPoint(touchPoint)) {
            //点击的是哪个数字
            numbeOfTtouch = numberSprite->getTag();
            this->getGameScene()->selectNumberToFillBoard(numbeOfTtouch);
            break;
        }
    }
}

GameScene* BoardNumberLayer::getGameScene(){
    return (GameScene*)this->getParent();
}

BoardNumberLayer::~BoardNumberLayer(){
    CC_SAFE_RELEASE_NULL(_numbers);
    CC_SAFE_RELEASE_NULL(_boardNumberSprite);
}