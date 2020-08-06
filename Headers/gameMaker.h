#ifndef GAMEMAKER_H
#define GAMEMAKER_H

#include <iostream>
#include <vector>
#include "gameTools.h"
using namespace std;
class gameMaker
{
private:
    /* data */
    vector<string> wordBank;
    gameTools tools;

public:
    gameMaker(/* args */);
    ~gameMaker();

    void insert(string);
    void printBoard();
    void fillEmpty();
    void printWordBank();
};

#endif
