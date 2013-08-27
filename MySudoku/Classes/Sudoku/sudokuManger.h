//
//  sudokuManger.h
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#ifndef __MySudoku__sudokuManger__
#define __MySudoku__sudokuManger__

#include <iostream>
#include <vector.h>
#include "Board.h"
#include "Sudoku.h"

#define Sudoku_Num 9

class SudokuManger {
public:
    static SudokuManger* sharedSudokuManger();
    /*创建数独*/
    std::vector<int> create();
    /*填入了一个新的数字*/
    bool inputNewNumber(int index, int num);
    /*是否完成游戏*/
    bool isFinishGame();
    
    
protected:
    Board *_sudokuBoard;
    Board *_sudokuSolveBoard;
    Sudoku *_sudoku;
    vector<int> _sudokuNunbers;
    
    void loadDataFromDb(const char *b1 , const char *b2);
private:
    //bool init();
    SudokuManger();
    ~SudokuManger();
};

#endif /* defined(__MySudoku__sudokuManger__) */
