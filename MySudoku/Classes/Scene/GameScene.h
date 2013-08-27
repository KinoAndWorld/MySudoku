//
//  GameScene.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#ifndef __MySudoku__GameScene__
#define __MySudoku__GameScene__

#include <iostream>
#include "cocos2d.h"
//LAYER
#include "BackGroundLayer.h"
#include "GameBoardLayer.h"

#include "BoardMeumLayer.h"
#include "BoardNumberLayer.h"
#include "BoardNumber.h"

#include "TouchLayer.h"

USING_NS_CC;

class GameScene : public CCScene {
public:
    CREATE_FUNC(GameScene);
    bool init();
    //转发点击事件
    void touchCell(CCTouch *target);
    //转发数字选择事件
    void selectNumberToFillBoard(int num);
    
    BoardNumber *getBoardNumber(int num);
protected:
    BackGroundLayer *_bgLayer;
    GameBoardLayer *_gbLayer;
    //GameBoardCell *_gbcLayer;
    BoardMeumLayer *_bmLayer;
    BoardNumberLayer *_bnLayer;
    TouchLayer *_touchLayer;
};

#endif /* defined(__MySudoku__GameScene__) */
