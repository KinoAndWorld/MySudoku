//
//  GameBoardLayer.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#ifndef __MySudoku__GameBoardLayer__
#define __MySudoku__GameBoardLayer__

#include <iostream>
#include "cocos2d.h"
#include "sudokuManger.h"
#include "GameBoardCell.h"

USING_NS_CC;
class GameScene;

class GameBoardLayer : public CCLayer{
public:
    CREATE_FUNC(GameBoardLayer);
    bool init();
    ~GameBoardLayer();
    
    CC_PROPERTY_READONLY(CCArray *, _cells, Cells);
    CC_PROPERTY_READONLY(CCSprite *,_boardSprite, BoardSprite);
    //公有方法
    /*点击画板*/
    void touchCell(CCTouch *target);
    /*选择数字*/
    void selectNumberToFillBoard(int num);
protected:
    GameBoardCell *_lastSelectCell;
    /*排列放置单元格*/
    void loadGameBoardCell();
    /*保存上次选中的单元格*/
    void saveLastSelectCell(GameBoardCell *gameBoardCell);
    /*第一次进入的动画*/
    void showActionByAllCells();
    /*填上了正确的数字*/
    void showNumberSelectCorrect();
    /*还原位置*/
    void renewSelectNumber();
    
    
    GameScene* getGameScene();
    
    int _curSelectNumber;
    CCPoint _oriNumberPoint;
};

#endif /* defined(__MySudoku__GameBoardLayer__) */
