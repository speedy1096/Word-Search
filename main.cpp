#include <iostream>
#include <iostream>
#include "Headers/Board.h"
#include "Headers/gameTools.h"
using namespace std;

int main()
{

    gameTools g2;
    g2.fillEmpty();
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