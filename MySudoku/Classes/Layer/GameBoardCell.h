//
//  GameBoardCell.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#ifndef __MySudoku__GameBoardCell__
#define __MySudoku__GameBoardCell__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

typedef enum {
    SelectBackgroundTypeNone = 0,
    SelectBackgroundTypeGreen,
    SelectBackgroundTypeRed,
}SelectBackgroundType;

class GameBoardCell : public CCNode{
public:
    CREATE_FUNC(GameBoardCell);
    ~GameBoardCell();
    bool init();
    
    //是否被选中
    bool _selected;
    
    CC_PROPERTY_READONLY(int, _number, Number);
    CC_PROPERTY_READONLY(CCSprite *, _sprite, Sprite);
    //方法
    CCSprite * getSpritrByNumber(int number);
    void showSelectBackground(SelectBackgroundType type = SelectBackgroundTypeNone);
protected:
    CCSprite *_selectSpr;
private:
    
};
#endif /* defined(__MySudoku__GameBoardCell__) */
