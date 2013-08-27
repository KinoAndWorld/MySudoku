//
//  BoardNumber.h
//  MySudoku
//
//  Created by Kino on 13-8-26.
//
//

#ifndef __MySudoku__BoardNumber__
#define __MySudoku__BoardNumber__

#include "cocos2d.h"
USING_NS_CC;

class BoardNumber : public CCNode {
public:
    CREATE_FUNC(BoardNumber);
    ~BoardNumber();
    bool init();
    
    CC_PROPERTY(CCSprite *, _sprite, Sprite);
    /*成功填入一个数字 返回true则表示9个次数全部填完*/
    bool succeedInput();
    
    void clear();
protected:
    int _numberOfsucceedInput;
};

#endif /* defined(__MySudoku__BoardNumber__) */
