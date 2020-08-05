#ifndef GAMETOOLS_H
#define GAMETOOLS_H

#include <iostream>
#include "Board.h"
using namespace std;

class gameTools
{
private:
    /* data */
    Board setBoard;

public:
    gameTools(/* args */);
    ~gameTools();

    // checks if word will fit in available row/column & direction
    bool checkLength();

    // checks if space is empty
    bool availSpace();

    // called by checkSpace
    bool compareLetters();

    // checks if space is empty or has letter
    bool checkSpace(int, int);

    // fills the empty spaces
    void fillEmpty();

    // inserts word in board
    void setWord();

    void printBoard();
};

#endif