#include <iostream>
#include <iostream>
#include "Headers/Board.h"
using namespace std;

int main()
{
    Board b1;
    b1.setSpace('y', 0, 0);
    b1.setSpace('e', 0, 1);
    b1.setSpace('s', 0, 2);

    b1.printBoard();

    char *r = b1.getSpace(0, 0);
    *r = 'j';

    b1.printBoard();
    return 0;
}