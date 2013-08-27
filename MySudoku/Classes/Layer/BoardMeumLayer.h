//
//  BoardMeumLayer.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#ifndef __MySudoku__BoardMeumLayer__
#define __MySudoku__BoardMeumLayer__

#include <iostream>
#include "cocos2d.h"
USING_NS_CC;

class BoardMeumLayer : public CCLayer{
public:
    CREATE_FUNC(BoardMeumLayer);
    bool init();
    
    void BackGame();
    void ResetGame();
    
protected:
    CCMenu *_menu;
    CCMenuItemLabel *_scoreLabel;
};

#endif /* defined(__MySudoku__BoardMeumLayer__) */
