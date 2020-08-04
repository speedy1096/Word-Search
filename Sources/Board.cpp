#include "../Headers/Board.h"

Board::Board(/* args */)
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            board[i][j] = 'n';
        }
    }
}

Board::~Board()
{
}

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
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}
