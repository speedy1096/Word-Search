#ifndef GAMETOOLS_H
#define GAMETOOLS_H

#include <iostream>
#include <cstdlib>
#include <string>
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
    bool checkLength(int, int, string, char);

    // checks if space is empty
    bool availSpace(int, int);

    // called by checkSpace
    bool compareLetters(char, int, int);

    // checks if space is empty or has letter
    bool checkSpace(char, int, int);

    bool insertUp(int, int, string);

    bool insertDown(int, int, string);

    bool insertLeft(int, int, string);

    bool insertRight(int, int, string);

    // fills the empty spaces
    void fillEmpty();

    char randDirection();

    // inserts word in board
    void setWord(string, int, int, char);

    // finds the column, row, and direction to
    // insert the word
    bool findCoords(string);

    void printBoard();
};

#endif