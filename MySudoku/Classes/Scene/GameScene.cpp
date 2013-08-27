//
//  GameScene.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#include "GameScene.h"

bool GameScene::init(){
    if (CCScene::init()) {
        //=========== 添加各层 ==========
        _bgLayer = BackGroundLayer::create();
        this->addChild(_bgLayer);
        
        _gbLayer = GameBoardLayer::create();
        this->addChild(_gbLayer);
//
        _bmLayer = BoardMeumLayer::create();
        this->addChild(_bmLayer);
//
        _bnLayer = BoardNumberLayer::create();
        this->addChild(_bnLayer);
        
        _touchLayer = TouchLayer::create();
        this->addChild(_touchLayer);
        //=========== 开始 ==========
        //this->scheduleUpdate();
        return true;
    }
    return false;
}

/*
 判断点击的区域来分发事件
 */
void GameScene::touchCell(CCTouch *target){
    //转换成精灵相对坐标
    CCPoint touchPoint = convertTouchToNodeSpace(target);
    if (_gbLayer->getBoardSprite()->boundingBox().containsPoint(touchPoint)) {
        //CCLOG("点击画板。");
        _gbLayer->touchCell(target);
    }else if (_bnLayer->getBoardNumberSprite()->boundingBox().containsPoint(touchPoint)){
        //CCLOG("点击草地。");
        _bnLayer->touchCell(target);
    }
    
}

void GameScene::selectNumberToFillBoard(int num){
    _gbLayer->selectNumberToFillBoard(num);
}

BoardNumber *GameScene::getBoardNumber(int num){
    num--;
    if (num >=0 && num<_bnLayer->getNumbers()->count()) {
        BoardNumber *boardNumber = (BoardNumber *)_bnLayer->getNumbers()->objectAtIndex(num);
        return boardNumber;
    }
    return NULL;
}
