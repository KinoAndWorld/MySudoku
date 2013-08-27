//
//  GameBoardLayer.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//
#include "GameScene.h"
#include "GameBoardLayer.h"
#include "BoardNumber.h"
#include "StaticData.h"
#include "sudokuManger.h"
#include "SudokuActionManager.h"
#include <vector.h>
//MUSIC
#include "SimpleAudioEngine.h"

bool GameBoardLayer::init(){
    if (CCLayer::init()) {
        //初始化数组
        _cells = CCArray::createWithCapacity(Sudoku_Num * Sudoku_Num);
        CC_SAFE_RETAIN(_cells);
        //添加画板
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        _boardSprite = CCSprite::create(S_BOARD);
        CC_SAFE_RETAIN(_boardSprite);
        _boardSprite->setPosition(ccp(winSize.width * 0.5, winSize.height * 0.5));
        this->addChild(_boardSprite);
        //载入初始化数字
        GameBoardLayer::loadGameBoardCell();
        return true;
    }
    return false;
}

/*排列放置单元格*/
void GameBoardLayer::loadGameBoardCell(){
    vector<int> sudokuList = SudokuManger::sharedSudokuManger()->create();
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    //画板宽高
    CCSize boardSize = _boardSprite->getContentSize();
    //单元格宽高
    CCSize cellSize = CCSizeMake(boardSize.width/9 - 6, boardSize.height/9 - 7);
    //行 和 列
    int index = 0;
    int row = 0;
    //单元格初始坐标
    
    CCPoint startPoint = CCPointMake(55 , winSize.height*0.15625);
    if (winSize.height == 1136) {
        startPoint = CCPointMake(55 , 240);
    }
    //读取精灵
    for(vector<int>::iterator iter = sudokuList.begin(); iter != sudokuList.end(); ++iter,++index){
        if (index%9 == 0) row++;
        
        int number = *iter;
        //计算放在哪个位置
        //大边框是5像素 小边框1像素 X的起点是55像素
        int gapW = index % 3 == 0 ? 5 : 1;
        int gapH = row % 3 == 0 ? 5 : 1;
        gapW += startPoint.x;
        gapH += startPoint.y;
        CCPoint sprPt = ccp( index % 9 * cellSize.width + gapW, boardSize.height - row * cellSize.height + gapH);
        
        //放进一个单元格里面
        GameBoardCell *cell = GameBoardCell::create();
        CCSprite *sprite = cell->getSpritrByNumber(number);
        _cells->addObject(cell);
        
        //显示
        sprite->setPosition(sprPt);
        this->addChild(sprite);
    }
    this->scheduleOnce(schedule_selector(GameBoardLayer::showActionByAllCells), 1.0);
}
/*第一次进入的动画*/
void GameBoardLayer::showActionByAllCells(){
    CCObject *obj;
    CCARRAY_FOREACH(_cells, obj){
        GameBoardCell *gameBoardCell = (GameBoardCell *)obj;
        CCSprite *spr = gameBoardCell->getSprite();
        if (gameBoardCell->getNumber() != 0) {
            spr->runAction(SudokuActionManager::sharedSudokuActionManger()->createRoateScaleAction());
        }
    }
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(M_STAERGAME);
}

CCArray * GameBoardLayer::getCells(){
    return _cells;
}

CCSprite * GameBoardLayer::getBoardSprite(){
    return _boardSprite;
}


GameScene* GameBoardLayer::getGameScene(){
    return (GameScene*)this->getParent();
}

/*通过点击区域判断选中了哪一个cell*/
void GameBoardLayer::touchCell(CCTouch *target){
    CCObject *obj;
    //确保点中了某个cell
    int numbeOfTtouchCell = -1;
    CCARRAY_FOREACH(_cells, obj){
        GameBoardCell *gameBoardCell = (GameBoardCell *)obj;
        CCSprite *spr = gameBoardCell->getSprite();
        //转换成精灵相对坐标
        CCPoint touchPoint = convertTouchToNodeSpace(target);
        //CCLOG("sprRectX=%f,sprRectY=%f",spr->boundingBox().origin.x,spr->boundingBox().origin.y);
        if (spr->boundingBox().containsPoint(touchPoint)) {
            if (gameBoardCell == _lastSelectCell)  return; 
            //点击的是哪个数字
            numbeOfTtouchCell = gameBoardCell->getNumber();
            gameBoardCell->_selected = true;
            this->saveLastSelectCell(gameBoardCell);
            //音效
            CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(M_Click);
            break;
        }
    }
    if (numbeOfTtouchCell != -1) {
        CCARRAY_FOREACH(_cells, obj){
            GameBoardCell *gameBoardCell = (GameBoardCell *)obj;
            if (gameBoardCell->getNumber() == 0) {
                if (gameBoardCell->_selected) {
                    gameBoardCell->showSelectBackground(SelectBackgroundTypeRed);
                }
            }else if(gameBoardCell->getNumber() == numbeOfTtouchCell){
                gameBoardCell->showSelectBackground(SelectBackgroundTypeGreen);
            }else{
                gameBoardCell->showSelectBackground(SelectBackgroundTypeNone);
                gameBoardCell->_selected = false;
            }
        }
    }
    
}

/*保存上次选中的单元格*/
void GameBoardLayer::saveLastSelectCell(GameBoardCell *gameBoardCell){
    CCAssert(gameBoardCell!=NULL, "gameBoardCell不能为空！");
    if (_lastSelectCell != NULL) {
        _lastSelectCell->_selected = false;
        _lastSelectCell->showSelectBackground(SelectBackgroundTypeNone);
        
        CC_SAFE_RELEASE(_lastSelectCell);
    }
    _lastSelectCell = gameBoardCell;
    CCLog("x:%f,y:%f",_lastSelectCell->getPositionX(),_lastSelectCell->getPositionY());
    CC_SAFE_RETAIN(_lastSelectCell);
}

/*填空*/
void GameBoardLayer::selectNumberToFillBoard(int num){
    if (_lastSelectCell == NULL) return;
    GameBoardCell *gameBoardCell = _lastSelectCell;
    if (gameBoardCell->getNumber() == 0) {
        //验证是否正确
        int index = _cells->indexOfObject(_lastSelectCell);
        CCSprite *cellSpr = _lastSelectCell->getSprite();
        BoardNumber *boardNumber = this->getGameScene()->getBoardNumber(num);
        CCSprite *numberSpr = boardNumber->getSprite();
        
        CCPoint directPt = ccpSub(cellSpr->getPosition(),numberSpr->getPosition());
        bool isCorrect = SudokuManger::sharedSudokuManger()->inputNewNumber(index, num);
        if (isCorrect) {
            //记录原本位置
            _oriNumberPoint = numberSpr->getPosition();
            //播放正确地动画
            numberSpr->runAction(SudokuActionManager::sharedSudokuActionManger()->createSucceedInputCellAction(directPt));
            //填上数字
            _curSelectNumber = num;
            this->scheduleOnce(schedule_selector(GameBoardLayer::showNumberSelectCorrect), 0.3);
            this->scheduleOnce(schedule_selector(GameBoardLayer::renewSelectNumber), 0.8);
            
        }else{
            //播放失败的动画
            if (numberSpr->numberOfRunningActions() == 0) {
                numberSpr->runAction(SudokuActionManager::sharedSudokuActionManger()->createFailInputCellAction(directPt));
                //音效
                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(M_SEL_ERROR);
                //this->scheduleOnce(schedule_selector(GameBoardLayer::showActionWhenSelectNumber), 1.0);
            }
            //
            //CCMessageBox("太让我失望了!", "你错了");
        }
    }
}


void GameBoardLayer::showNumberSelectCorrect(){
    GameBoardCell *gameBoardCell = _lastSelectCell;
    gameBoardCell->getSpritrByNumber(_curSelectNumber);
    gameBoardCell->showSelectBackground(SelectBackgroundTypeGreen);
    //音效
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(M_SEL_CORRECT);
}

void GameBoardLayer::renewSelectNumber(){
    //还原选择的数字的位置
    BoardNumber *boardNumber = this->getGameScene()->getBoardNumber(_curSelectNumber);
    CCSprite *numberSpr = boardNumber->getSprite();
    numberSpr->setPosition(_oriNumberPoint);
    numberSpr->setOpacity(255);
    numberSpr->setScale(1.0);

    _curSelectNumber = -1;
    //判断是否全部填完
    if (SudokuManger::sharedSudokuManger()->isFinishGame()) {
        //音效
        CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(M_FINISH);
        CCMessageBox("你真牛逼了!", "你赢了");
    }
}


GameBoardLayer::~GameBoardLayer(){
    CC_SAFE_RELEASE_NULL(_boardSprite);
    CC_SAFE_RELEASE_NULL(_cells);
    CC_SAFE_RELEASE_NULL(_lastSelectCell);
}