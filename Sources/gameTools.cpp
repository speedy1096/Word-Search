#include "../Headers/gameTools.h"

gameTools::gameTools(/* args */)
{
}

gameTools::~gameTools()
{
}

bool gameTools::checkLength(int col, int row, string dir, int size)
{
}

bool gameTools::availSpace(int col, int row)
{
    if (*setBoard.getSpace(col, row) == '\0')
        return true;
    else
        return false;
}

bool gameTools::compareLetters(char c, int col, int row)
{
    if (*setBoard.getSpace(col, row) == c)
        return true;
    else
        return false;
}

/* wants to see if space is empty or [has a letter in it 
  if so does it match the letter in it] */
bool gameTools::checkSpace(char c, int col, int row)
{
    if ((availSpace(col, row) == true) || (compareLetters(c, col, row)))
        return true;
    else
        return false;
}

void gameTools::fillEmpty()
{
    int colS = setBoard.getColSize();
    int rowS = setBoard.getRowSize();
    char randChar;

    for (int i = 0; i < colS; i++)
    {
        for (int j = 0; j < rowS; j++)
        {
            if (availSpace(i, j) == true)
            {
                randChar = rand() % 26 + 97;
                setBoard.setSpace(randChar, i, j);
            }
        }
    }
}

void gameTools::setWord(char c, int col, int row)
{
    setBoard.setSpace(c, col, row);
}

void gameTools::printBoard()
{
    setBoard.printBoard();
}