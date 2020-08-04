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
    char board[colSize][rowSize];

public:
    Board(/* args */);
    ~Board();

    void setSpace(char, int, int);

    char *getSpace(int, int);

    void printBoard();
};

#endif