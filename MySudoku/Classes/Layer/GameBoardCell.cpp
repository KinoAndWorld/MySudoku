//
//  GameBoardCell.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#include "GameBoardCell.h"
#include "StaticData.h"


CCSprite * GameBoardCell::getSpritrByNumber(int number){
    _number = number;
    if (_sprite == NULL) {
        _sprite = CCSprite::create();
        _sprite->retain();
    }
    const char *sprName = CCString::createWithFormat("a-note-%d-x10@2x.png",number)->getCString();
    _sprite->initWithFile(sprName);
    return _sprite;
}

bool GameBoardCell::init(){
    
    _selected = false;
    //GameBoardCell::showSelectBackground();
    return true;
}

void GameBoardCell::showSelectBackground(SelectBackgroundType type){
    if (_sprite!=NULL) {
        //高亮
        if (_selectSpr==NULL) {
            _selectSpr = CCSprite::create();
            _selectSpr->setPosition(ccp(_sprite->getContentSize().width /2,_sprite->getContentSize().height/2));
            _sprite->addChild(_selectSpr);
        }
    }
    
    switch (type) {
        case SelectBackgroundTypeGreen:
            _selectSpr->initWithFile(S_CELL_SEL_GREEN);
            _selectSpr->setVisible(true);
            //_selected = true;
            break;
        case SelectBackgroundTypeRed:
            _selectSpr->initWithFile(S_CELL_SEL_RED);
            _selectSpr->setVisible(true);
            //_selected = true;
            break;
        case SelectBackgroundTypeNone:
            _selectSpr->setVisible(false);
            //_selected = false;
            break;
    }
    //CCLOG("_selectSpr:%d",_selectSpr->retainCount());
}

CCSprite * GameBoardCell::getSprite(){
    return _sprite;
}

int GameBoardCell::getNumber(){
    return _number;
}

GameBoardCell::~GameBoardCell(){
    CC_SAFE_RELEASE_NULL(_sprite);
    //CC_SAFE_RELEASE_NULL(_selectSpr);
}