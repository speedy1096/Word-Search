#ifndef GAMETOOLS_H
#define GAMETOOLS_H

#include <iostream>
#include <cstdlib>
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
    bool checkLength(int, int, string, int);

    // checks if space is empty
    bool availSpace(int, int);

    // called by checkSpace
    bool compareLetters(char, int, int);

    // checks if space is empty or has letter
    bool checkSpace(char, int, int);

    // fills the empty spaces
    void fillEmpty();

    // inserts word in board
    void setWord(char, int, int);

    void printBoard();
};

#endif