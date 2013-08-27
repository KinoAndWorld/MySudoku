//
//  SudokuActionManager.cpp
//  MySudoku
//
//  Created by Kino on 13-8-25.
//
//

#include "SudokuActionManager.h"


static SudokuActionManager *_sharedSudokuActionManger = NULL;
SudokuActionManager * SudokuActionManager::sharedSudokuActionManger()
{
    if(_sharedSudokuActionManger == NULL){
        _sharedSudokuActionManger = new SudokuActionManager();
    }
    return _sharedSudokuActionManger;
}

CCAction *SudokuActionManager::createRoateScaleAction(){
    
    CCScaleBy *scale = CCScaleBy::create(0.5,1.5);
    CCRotateBy *rotate2 = CCRotateBy::create(1.0,360);
    CCSequence *sequence = CCSequence::create(scale,scale->reverse(),NULL);
    CCSpawn *roateScaleAction = CCSpawn::create(sequence,rotate2,NULL);
    return roateScaleAction;
}

CCAction *SudokuActionManager::createFailInputCellAction(CCPoint pt){
    
    CCMoveBy *acMove = CCMoveBy::create(0.2,pt);
    CCRotateBy *rotate = CCRotateBy::create(0.2,80.f);
    CCJumpBy *jump = CCJumpBy::create(0.5,ccp(0,0),25,5);
    CCSequence *inputCellAction = CCSequence::create(acMove,rotate, rotate->reverse(), acMove->reverse(), jump, NULL);
    
    return inputCellAction;
}

CCAction *SudokuActionManager::createSucceedInputCellAction(CCPoint pt){
    CCMoveBy *acMove = CCMoveBy::create(0.2,pt);
    
    CCScaleBy *scale = CCScaleBy::create(0.3, 5.0);
    CCFadeOut *fade = CCFadeOut::create(0.5);
    CCSpawn *fadeScaleAction = CCSpawn::create(scale,fade,NULL);
    //CCRotateBy *rotate = CCRotateBy::create(0.2,80.f);
    //CCJumpBy *jump = CCJumpBy::create(0.5,ccp(0,0),25,5);
    CCSequence *inputCellAction = CCSequence::create(acMove,fadeScaleAction, NULL);
    
    return inputCellAction;
}

SudokuActionManager::SudokuActionManager(){
    
}
SudokuActionManager::~SudokuActionManager(){
    
}
