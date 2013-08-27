// $Id: BoardGenerator.h 297 2008-05-30 20:16:20Z wimleers $


/**
 * Board Generator class definition.
 * 
 * @file BoardGenerator.h
 * @author Wim Leers
 */


#ifndef BOARDGENERATOR_H
#define BOARDGENERATOR_H

#include "Sudoku.h"


class BoardGenerator  {
public:
    BoardGenerator() { }
    virtual ~BoardGenerator(void) { }

    void QueueBoardGeneration(Board * board, int level = 1);

protected:
    void run();

private:
    Board * m_board;
    int m_level;
};

#endif // BOARDGENERATOR_H
