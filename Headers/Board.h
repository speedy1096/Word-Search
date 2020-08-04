#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Board
{
private:
    /* data */
    static const int rowSize = 3;
    static const int colSize = 3;
    char board[rowSize][colSize];

public:
    Board(/* args */);
    ~Board();

    void setSpace(char);

    void getSpace();

    void printBoard();
};

#endif