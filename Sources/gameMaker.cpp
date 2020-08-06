#include "../Headers/gameMaker.h"

gameMaker::gameMaker(/* args */)
{
}

gameMaker::~gameMaker()
{
}

void gameMaker::insert(string word)
{
    if (tools.findCoords(word) == true)
    {
        wordBank.push_back(word);
    }
}

void gameMaker::printBoard()
{
    tools.printBoard();
}

void gameMaker::fillEmpty()
{
    tools.fillEmpty();
}

void gameMaker::printWordBank()
{
    for (int i = 0; i < wordBank.size(); i++)
    {
        cout << wordBank.at(i) << "     ";
    }
    cout << endl;
}
