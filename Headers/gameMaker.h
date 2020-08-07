#ifndef GAMEMAKER_H
#define GAMEMAKER_H

#include <iostream>
#include <vector>
/*
-   hides the tools to determine if a word is place on the board
    & only shows the functions that the user will need to use in
    the main file
*/
#include <fstream>
#include "gameTools.h"
using namespace std;
class gameMaker
{
private:
    vector<string> wordBank; // stores words added to to board
    gameTools tools;
    ofstream writeToFile; // used to output to screen

public:
    gameMaker();
    ~gameMaker();

    void insert(string); // if word fits in board it is add to the word bank

    void printBoard();    // prints the board to the file
    void fillEmpty();     // fills the empty spaces
    void printWordBank(); // prints the word bank to the file
};

#endif
