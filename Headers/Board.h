#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
using namespace std;

class Board
{
private:
    /* data */
    static const int rowSize = 15;
    static const int colSize = 15;
    char board[colSize][rowSize];
    ofstream writeToFile;

public:
    Board(/* args */);
    ~Board();

    int getRowSize();
    int getColSize();

    void setSpace(char, int, int);

    char *getSpace(int, int);

    void printBoard();
};

#endif