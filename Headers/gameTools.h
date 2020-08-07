/*
- Uses board methods to create the tools the will govern 
  if a word is place on the board and how

 * UP: the word is printed in board with the first Letterin the word at 
   higer row value than the last letter in the word & the same column value
  
 * DOWN: the word is printed in the board with the first letter in the word
   at a lower row value than the last letter in the word & the same column value

 * LEFT: the word is printed in the board with the first letter in the word
   at a higher column value than the last letter in the word & the same row value

 * RIGHT: the word is printed in the board with the first letter in the word 
 * at a lower column value than the last letter in the word & the smae row value
 */
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
    Board setBoard;

public:
    gameTools(/* args */);
    ~gameTools();

    bool checkLength(int, int, string, char); // check if the word will fit on the board in a specific direction

    bool availSpace(int, int); // checks if space is empty [no letter in it]

    bool compareLetters(char, int, int); // compares two letters

    bool checkSpace(char, int, int); // checks if space is empty [availSpace] or matches the char in param [compareLetters]

    bool insertUp(int, int, string); // checks if the word will fit if inserted UP

    bool insertDown(int, int, string); // checks if the word will fit if inserted DOWN

    bool insertLeft(int, int, string); // checks if the word will fit if inserted LEFT

    bool insertRight(int, int, string); // checks if the word will fit if inserted RIGHT

    void fillEmpty(); // fills the empty spaces at the user stops entering words

    char randDirection(); // returns a randdom direction [UP,DOWN,LEFT,RIGHT]

    void setWord(string, int, int, char); // inserts word in board

    bool findCoords(string); // finds the column, row, and direction to & if so calls setWord()

    void printBoard(); // prints board file
};

#endif