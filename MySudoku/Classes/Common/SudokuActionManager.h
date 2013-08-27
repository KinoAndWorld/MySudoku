//
//  SudokuActionManager.h
//  MySudoku
//
//  Created by Kino on 13-8-25.
//
//

#ifndef __MySudoku__SudokuActionManager__
#define __MySudoku__SudokuActionManager__

#include "cocos2d.h"

USING_NS_CC;


class SudokuActionManager : public CCObject {
public:
    static SudokuActionManager *sharedSudokuActionManger();
    
    CCAction *createRoateScaleAction(); //cell旋转并放大
    CCAction *createFailInputCellAction(CCPoint pt);  //填数字的动画 - 错误
    CCAction *createSucceedInputCellAction(CCPoint pt);  //填数字的动画 - 正确
    
private:
    SudokuActionManager();
    ~SudokuActionManager();
};

#endif /* defined(__MySudoku__SudokuActionManager__) */
