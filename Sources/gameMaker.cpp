#include "../Headers/gameMaker.h"

gameMaker::gameMaker()
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
    writeToFile.open("search.txt", ios_base::app);
    if (writeToFile.is_open())
    {

        for (int i = 0; i < wordBank.size(); i++)
        {
            writeToFile << wordBank.at(i) << "     ";
        }
        writeToFile << endl;
    }
    writeToFile.close();
}
