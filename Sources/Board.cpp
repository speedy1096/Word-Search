#include "../Headers/Board.h"

Board::Board(/* args */)
{
    for (int i = 0; i < colSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            board[j][i] = '\0';
        }
    }
}

Board::~Board()
{
}

int Board::getRowSize() { return rowSize; }
int Board::getColSize() { return colSize; }

void Board::setSpace(char newChar, int col, int row)
{
    board[col][row] = newChar;
}

char *Board::getSpace(int col, int row)
{
    return &board[col][row];
}

void Board::printBoard()
{
    writeToFile.open("search.txt", ios_base::out | ios_base::trunc);
    if (writeToFile.is_open())
    {
        for (int i = 0; i < colSize; i++)
        {
            for (int j = 0; j < rowSize; j++)
            {
                // switch 'j' & 'i' to represent 2D array
                writeToFile << board[j][i] << " ";
            }
            writeToFile << endl;
        }
        writeToFile << endl
                    << endl;
    }
    writeToFile.close();
}
