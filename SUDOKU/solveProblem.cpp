// solver using dancing links

#include <iostream>
#include <fstream>
#include <array>

using namespace std;

struct node {
    node *header, *left, *right, *up, *down;
    int num;
};

int main () {
    array<node, 10*9*9*4+1> matrix;

    matrix[0].left = &matrix[0];
    matrix[0].right = &matrix[0];

    for (int i = 1; i < 9*9*4+1; i ++) {
        matrix[i].up = &matrix[i];
        matrix[i].down = &matrix[i];
        matrix[i].left = &matrix[i-1];
        matrix[i-1].right = &matrix[i];
    }

    for (int i = 9*9*4+1; i < matrix.size(); i ++) {
        
    }

    cout << "Hello world!" << endl;
}
