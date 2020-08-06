#include <iostream>
#include <fstream>
#include <string>
#include "Headers/gameMaker.h"
using namespace std;

int main()
{
     gameMaker boardMaster;
     string userInput = "";
     string stop = "66";
     gameTools g2;
     cout << "<To Quit> type 66 & hit ENTER>" << endl;
     cout << "----------------------------------" << endl
          << endl;
     cout << "Please enter a SINGLE word LESS THAN 12 LEETER& hit ENTER." << endl
          << endl;

     do
     {
          cout << "load: ";
          cin >> userInput;
          cout << endl;
          if (userInput.compare("66") == 0)
          {
               break;
          }

          if (userInput.length() > 12)
          {
               cout << "The word you entered is too long" << endl
                    << endl;
               continue;
          }

          boardMaster.insert(userInput);
          boardMaster.printBoard();

     } while (userInput.compare("66") != 0);

     boardMaster.fillEmpty();
     boardMaster.printBoard();

     cout << endl
          << endl;
     boardMaster.printWordBank();
     // lower class string
     // g2.findCoords("asr");
     // g2.findCoords("a");
     // g2.findCoords("rat");
     // g2.printBoard();

     return 0;
}
