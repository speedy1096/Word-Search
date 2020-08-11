/* 
- Takes care of the basic baord operations
    # setting a space
    # getting a sapce
    # printing the board 
 */

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
using namespace std;

class Board
{
private:
       static const int colSize = 15; // the # of columns
    static const int rowSize = 15; // the # of rows
    char board[colSize][rowSize];  // board
    ofstream writeToFile;          // used to output to screen

public:
    Board();
    ~Board();

    int getColSize(); // returns the # of columns
    int getRowSize(); // returns the # of rows

    void setSpace(char, int, int); // sets a letter in the 2d array

    char *getSpace(int, int); // return a ptr to the space in the 2d array

    void printBoard(); // prints the board to a file
};

#endif