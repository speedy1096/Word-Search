#include <iostream>
#include <iostream>
#include "Headers/Board.h"
#include "Headers/gameTools.h"
using namespace std;

int main()
{
     gameTools g2;

     g2.findCoords("asr");
     g2.findCoords("a");
     g2.findCoords("rat");
     g2.printBoard();
     /*cout << g2.checkSpace('c', 0, 0) << endl;

    cout << endl;
    g2.setWord('h', 0, 0);
    cout << g2.checkSpace('c', 0, 0) << endl;
    g2.setWord('c', 0, 0);
    cout << g2.checkSpace('c', 0, 0) << endl; */

     // Board b1;
     // b1.setSpace('y', 0, 0);
     // b1.setSpace('e', 0, 1);
     // b1.setSpace('s', 0, 2);

     // b1.printBoard();

     // char *r = b1.getSpace(0, 0);
     // *r = 'j';

     // b1.printBoard();
     return 0;
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