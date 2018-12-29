// solver using dancing links

#include <iostream>
#include <fstream>
#include <array>

using namespace std;

struct node
{
    node *header, *row, *left, *right, *up, *down;
    int num, headerID, rowID;
};

int main ()
{
    array<node, 9*9*9*5+9*9*4+1> matrix;
}
