//
//  sudokuManger.cpp
//  MySudoku
//
//  Created by Kino on 13-8-21.
//
//

#include "sudokuManger.h"
#include "CppSQLite3.h"
#include <string.h>
#include <stdlib.h>
#include "cocos2d.h"
#include "CCFileUtils.h"

USING_NS_CC;

static SudokuManger* _sharedSudokuManger = NULL;
SudokuManger* SudokuManger::sharedSudokuManger()
{
    if(_sharedSudokuManger == NULL){
        _sharedSudokuManger = new SudokuManger();
        //_sharedSudokuManger->init();
    }
    return _sharedSudokuManger;
}

std::vector<int> SudokuManger::create(){
    
    _sudokuBoard = new Board();
    _sudoku = new Sudoku();
    _sudokuSolveBoard = new Board();
    _sudokuNunbers.clear();
    //生成数独
    //_sudoku->GenerateBoard(_sudokuBoard,1);
    //生成答案
    //_sudokuSolveBoard = new Board(*_sudokuBoard);
    /*
     
     _sudoku->SolveBoard(_sudokuSolveBoard);
    vector<int> sudokuNunbers;
    
    for (int i = 0;i < Sudoku_Num; i++) {
        for (int j = 0; j < Sudoku_Num; j++) {
            int num = _sudokuBoard->Get(i, j);
            sudokuNunbers.push_back(num);
        }
    }
     */
    
    CCFileUtils* fileUtils = CCFileUtils::sharedFileUtils();
        
    CppSQLite3DB *db = new CppSQLite3DB();
    
    const char* fileName = "SudokuData.sqlite";
    
    string path = fileUtils->fullPathForFilename(fileName);
    db->open(path.c_str());
    //CppSQLite3Table table = db->getTable("select * from sudoku");
    CppSQLite3Query query = db->execQuery("select * from sudoku order by random() limit 1");
    
    while(!query.eof()){
        CCLOG("%s || %s",query.fieldValue(1),query.fieldValue(2));
        loadDataFromDb(query.fieldValue(1),query.fieldValue(2));
        query.nextRow();
    }
    db->close();
    //CCLOG("%d", table.numRows());
    return _sudokuNunbers;
}

void SudokuManger::loadDataFromDb(const char *b1 , const char *b2){
    string str1 = b1;
    string str2 = b2;
    int i = 0;
    for (string::iterator it = str1.begin(); it != str1.end(); it++ , i++) {
        char ch = *it;
        int num =  atoi(&ch);
        int y = i % Sudoku_Num ;
        int x = (i - y) / Sudoku_Num;
        _sudokuBoard->Set(x, y, num);
        _sudokuNunbers.push_back(num);
    }
    i = 0;
    for (string::iterator it = str2.begin(); it != str2.end(); it++ , i++) {
        char ch = *it;
        int num =  atoi(&ch);
        int y = i % Sudoku_Num ;
        int x = (i - y) / Sudoku_Num;
        _sudokuSolveBoard->Set(x, y, num);
    }
}


bool SudokuManger::inputNewNumber(int index, int num){
    int y = index % Sudoku_Num ;
    int x = (index - y) / Sudoku_Num;
    if (_sudokuSolveBoard->Get(x, y) == num) {
        //判断是否完成游戏
        _sudokuBoard->Set(x, y, num);
        return true;
    }
    return false;
}

bool SudokuManger::isFinishGame(){
    return _sudokuSolveBoard->IsEqualTo(_sudokuBoard);
    //return _sudokuSolveBoard==(_sudokuBoard);
}

SudokuManger::SudokuManger(){
    
}
SudokuManger::~SudokuManger(){
//    if(_sharedSudokuManger != NULL){
//        
//    }
}

