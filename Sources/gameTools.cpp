#include "../Headers/gameTools.h"

gameTools::gameTools()
{
}

gameTools::~gameTools()
{
}

bool gameTools::checkLength(int col, int row, string word, char dir)
{
    int boardSpace;
    // gets the space in the bard for the row or column depeding on the direction
    switch (dir)
    {
    case 'U':
        boardSpace = (row + 1) - 0;
        break;
    case 'D':
        boardSpace = setBoard.getRowSize() - row;
        break;
    case 'L':
        boardSpace = (col + 1) - 0;
        break;
    case 'R':
        boardSpace = setBoard.getColSize() - col;
        break;

    default:
        break;
    }

    // word doesn't fit
    if (word.length() > boardSpace)
        return false;
    return true;
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

bool gameTools::checkSpace(char c, int col, int row)
{
    if ((availSpace(col, row) == true) || (compareLetters(c, col, row)))
        return true;
    else
        return false;
}

bool gameTools::insertUp(int col, int row, string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (checkSpace(word.at(i), col, row) == true)
        {
            row--;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool gameTools::insertDown(int col, int row, string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (checkSpace(word.at(i), col, row) == true)
        {
            row++;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool gameTools::insertLeft(int col, int row, string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (checkSpace(word.at(i), col, row) == true)
        {
            col--;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool gameTools::insertRight(int col, int row, string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        if (checkSpace(word.at(i), col, row) == true)
        {
            col++;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
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

char gameTools::randDirection()
{
    int randDirNum = rand() % 4; //  gets a random number [0-3]
    char randChar = '\0';
    switch (randDirNum) // assigns the number to a direction
    {
    case 0:
        randChar = 'U';
        break;
    case 1:
        randChar = 'D';
        break;
    case 2:
        randChar = 'L';
        break;
    case 3:
        randChar = 'R';
        break;

    default:
        break;
    }
    return randChar;
}

void gameTools::setWord(string word, int col, int row, char direct)
{
    switch (direct) // inserts word depending on the direction
    {
    case 'U':
        for (int i = 0; i < word.length(); i++)
        {
            setBoard.setSpace(word.at(i), col, row);
            row--;
        }
        break;
    case 'D':
        for (int i = 0; i < word.length(); i++)
        {
            setBoard.setSpace(word.at(i), col, row);
            row++;
        }
        break;
    case 'L':
        for (int i = 0; i < word.length(); i++)
        {
            setBoard.setSpace(word.at(i), col, row);
            col--;
        }
        break;
    case 'R':
        for (int i = 0; i < word.length(); i++)
        {
            setBoard.setSpace(word.at(i), col, row);
            col++;
        }
        break;

    default:
        break;
    }
}

bool gameTools::findCoords(string word)
{
    int randCol;
    int randRow;
    char randDirect;
    bool setLetters = false; // boolean for do-while loop
    int loopIter = 0;        // used to break out of do-while loop after a # of tries

    do // randonly get a column,row,& direction until one is found or loopIter > 50
    {
        randCol = rand() % setBoard.getColSize(); // randomly get a column [0-((size of column)-1)]
        randRow = rand() % setBoard.getRowSize(); // randomly get a row [0-((size of row)-1)]
        randDirect = randDirection();             // randonly get a direction [UP,DOWN,LEFT,RIGHT]

        // check if there are enough spaces
        if (checkLength(randCol, randRow, word, randDirect) == true)
        {
            switch (randDirect) // check if the word will fit in the direction (U,D,L,R) given its coordinates
            {
            case 'U':
                if (insertUp(randCol, randRow, word) == true)
                {
                    setLetters = true;
                }
                break;
            case 'D':
                if (insertDown(randCol, randRow, word) == true)
                {
                    setLetters = true;
                }
                break;
            case 'L':
                if (insertLeft(randCol, randRow, word) == true)
                {
                    setLetters = true;
                }
                break;
            case 'R':
                if (insertRight(randCol, randRow, word) == true)
                {
                    setLetters = true;
                }
                break;

            default:
                break;
            }
        }
        else
        {
            continue;
        }
        loopIter++;
        if (loopIter > 50)
        {
            cout << "Please enter another word or try again." << endl;
            break;
        }
    } while (setLetters == false);

    if (setLetters == true)
    {
        //add word
        setWord(word, randCol, randRow, randDirect);
        cout << "----------------------------" << endl;
        cout << "Word was added successfully!" << endl;
        cout << "----------------------------" << endl;
    }
    return setLetters;
}

void gameTools::printBoard()
{
    setBoard.printBoard();
}

/* 
    UNIT TEST for GameTools checkLength
    gameTools g2;
    cout << "UP" << endl;
    cout << g2.checkLength(0, 0, "h", 'U') << endl;
    cout << g2.checkLength(0, 0, "Hi", 'U') << endl;
    cout << endl;
    cout << g2.checkLength(0, 1, "hi", 'U') << endl;
    cout << g2.checkLength(0, 1, "hii", 'U') << endl;
    cout << endl;
    cout << g2.checkLength(0, 2, "hii", 'U') << endl;
    cout << g2.checkLength(0, 2, "hiii", 'U') << endl;
    cout << "-----------------------------";
    cout << endl;
    cout << g2.checkLength(1, 0, "h", 'U') << endl;
    cout << g2.checkLength(1, 0, "Hi", 'U') << endl;
    cout << endl;
    cout << g2.checkLength(1, 1, "hi", 'U') << endl;
    cout << g2.checkLength(1, 1, "hii", 'U') << endl;
    cout << endl;
    cout << g2.checkLength(1, 2, "hii", 'U') << endl;
    cout << g2.checkLength(1, 2, "hiii", 'U') << endl;
    cout << "-----------------------------";
    cout << endl;
    cout << g2.checkLength(2, 0, "h", 'U') << endl;
    cout << g2.checkLength(2, 0, "Hi", 'U') << endl;
    cout << endl;
    cout << g2.checkLength(2, 1, "hi", 'U') << endl;
    cout << g2.checkLength(2, 1, "hii", 'U') << endl;
    cout << endl;
    cout << g2.checkLength(2, 2, "hii", 'U') << endl;
    cout << g2.checkLength(2, 2, "hiii", 'U') << endl;

    cout << endl
         << endl
         << "DOWN" << endl;
    cout << g2.checkLength(0, 0, "hii", 'D') << endl;
    cout << g2.checkLength(0, 0, "Hiii", 'D') << endl;
    cout << endl;
    cout << g2.checkLength(0, 1, "hi", 'D') << endl;
    cout << g2.checkLength(0, 1, "hii", 'D') << endl;
    cout << endl;
    cout << g2.checkLength(0, 2, "h", 'D') << endl;
    cout << g2.checkLength(0, 2, "hi", 'D') << endl;
    cout << "-----------------------------";
    cout << endl;
    cout << g2.checkLength(1, 0, "hii", 'D') << endl;
    cout << g2.checkLength(1, 0, "Hiii", 'D') << endl;
    cout << endl;
    cout << g2.checkLength(1, 1, "hi", 'D') << endl;
    cout << g2.checkLength(1, 1, "hii", 'D') << endl;
    cout << endl;
    cout << g2.checkLength(1, 2, "h", 'D') << endl;
    cout << g2.checkLength(1, 2, "hi", 'D') << endl;
    cout << "-----------------------------";
    cout << endl;
    cout << g2.checkLength(2, 0, "hii", 'D') << endl;
    cout << g2.checkLength(2, 0, "Hiii", 'D') << endl;
    cout << endl;
    cout << g2.checkLength(2, 1, "hi", 'D') << endl;
    cout << g2.checkLength(2, 1, "hii", 'D') << endl;
    cout << endl;
    cout << g2.checkLength(2, 2, "h", 'D') << endl;
    cout << g2.checkLength(2, 2, "hi", 'D') << endl;

    cout << endl
         << endl
         << "LEFT" << endl;
    cout << g2.checkLength(0, 0, "h", 'L') << endl;
    cout << g2.checkLength(0, 0, "Hi", 'L') << endl;
    cout << endl;
    cout << g2.checkLength(1, 0, "hi", 'L') << endl;
    cout << g2.checkLength(1, 0, "hii", 'L') << endl;
    cout << endl;
    cout << g2.checkLength(2, 0, "hii", 'L') << endl;
    cout << g2.checkLength(2, 0, "hiii", 'L') << endl;
    cout << "-----------------------------";
    cout << endl;
    cout << g2.checkLength(0, 1, "h", 'L') << endl;
    cout << g2.checkLength(0, 1, "Hi", 'L') << endl;
    cout << endl;
    cout << g2.checkLength(1, 1, "hi", 'L') << endl;
    cout << g2.checkLength(1, 1, "hii", 'L') << endl;
    cout << endl;
    cout << g2.checkLength(2, 1, "hii", 'L') << endl;
    cout << g2.checkLength(2, 1, "hiii", 'L') << endl;
    cout << "-----------------------------";
    cout << endl;
    cout << g2.checkLength(0, 2, "h", 'L') << endl;
    cout << g2.checkLength(0, 2, "Hi", 'L') << endl;
    cout << endl;
    cout << g2.checkLength(1, 2, "hi", 'L') << endl;
    cout << g2.checkLength(1, 2, "hii", 'L') << endl;
    cout << endl;
    cout << g2.checkLength(2, 2, "hii", 'L') << endl;
    cout << g2.checkLength(2, 2, "hiii", 'L') << endl;
    cout << "-----------------------------";
    cout << endl;

    cout << endl
         << endl
         << "RIGHT" << endl;
    cout << g2.checkLength(0, 0, "hii", 'R') << endl;
    cout << g2.checkLength(0, 0, "Hiii", 'R') << endl;
    cout << endl;
    cout << g2.checkLength(1, 0, "hi", 'R') << endl;
    cout << g2.checkLength(1, 0, "hii", 'R') << endl;
    cout << endl;
    cout << g2.checkLength(2, 0, "h", 'R') << endl;
    cout << g2.checkLength(2, 0, "hi", 'R') << endl;
    cout << "-----------------------------";
    cout << endl;
    cout << g2.checkLength(0, 1, "hii", 'R') << endl;
    cout << g2.checkLength(0, 1, "Hiii", 'R') << endl;
    cout << endl;
    cout << g2.checkLength(1, 1, "hi", 'R') << endl;
    cout << g2.checkLength(1, 1, "hii", 'R') << endl;
    cout << endl;
    cout << g2.checkLength(2, 1, "h", 'R') << endl;
    cout << g2.checkLength(2, 1, "hi", 'R') << endl;
    cout << "-----------------------------";
    cout << endl;
    cout << g2.checkLength(0, 2, "hii", 'R') << endl;
    cout << g2.checkLength(0, 2, "Hiii", 'R') << endl;
    cout << endl;
    cout << g2.checkLength(1, 2, "hi", 'R') << endl;
    cout << g2.checkLength(1, 2, "hii", 'R') << endl;
    cout << endl;
    cout << g2.checkLength(2, 2, "h", 'R') << endl;
    cout << g2.checkLength(2, 2, "hi", 'R') << endl; */