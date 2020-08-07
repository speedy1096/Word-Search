#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Headers/gameMaker.h"
using namespace std;

bool isLowerCase(string word) // checks if the user enters a word that is not lower case
{
     for (int i = 0; i < word.length(); i++)
     {
          if (islower(word.at(i)) == false)
               return false;
     }
     return true;
}

int main()
{
     gameMaker boardMaster;
     string userInput = "";

     gameTools g2;

     cout << "<To Quit> type 66 & hit ENTER>" << endl;
     cout << "----------------------------------" << endl
          << endl;
     cout << "Please enter a SINGLE word LESS THAN 12 LEETERS & hit ENTER." << endl
          << endl;

     do
     {
          cout << "load: ";
          cin >> userInput;
          cout << endl;

          if (userInput.compare("66") == 0) // exits loop entered
          {
               break;
          }

          if (isLowerCase(userInput) == false) // user is only allowed to use lower case letters
          {
               cout << "Please enter lower case letters only." << endl
                    << endl;
               continue;
          }
          if (userInput.length() > 12) // user cannot enter words longer than 12 letters
          {
               cout << "The word you entered is too long" << endl
                    << endl;
               continue;
          }

          boardMaster.insert(userInput);

     } while (userInput.compare("66") != 0);

     boardMaster.fillEmpty();
     boardMaster.printBoard();

     cout << endl
          << endl;
     boardMaster.printWordBank();

     return 0;
}
