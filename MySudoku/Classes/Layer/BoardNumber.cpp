//
//  BoardNumber.cpp
//  MySudoku
//
//  Created by Kino on 13-8-26.
//
//

#include "BoardNumber.h"

BoardNumber::~BoardNumber(){
    CC_SAFE_RELEASE_NULL(_sprite);
}
bool BoardNumber::init(){
    return true;
}

CCSprite * BoardNumber::getSprite(){
    return _sprite;
}

void BoardNumber::setSprite(CCSprite *spr){
    if (_sprite != NULL) {
        CC_SAFE_DELETE(_sprite);
    }
    _sprite = spr;
    CC_SAFE_RETAIN(_sprite);
}

bool BoardNumber::succeedInput(){
    if (++_numberOfsucceedInput == 9) {
        return true;
    }
    return false;
}

void BoardNumber::clear(){
    
}