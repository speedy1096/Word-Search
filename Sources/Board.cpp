#include "../Headers/Board.h"

Board::Board(/* args */)
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            board[i][j] = '\0';
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
    for (int i = 0; i < colSize; i++)
    {
        for (int j = 0; j < rowSize; j++)
        {
            // switch 'j' & 'i' to represent 2D array
            cout << board[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
