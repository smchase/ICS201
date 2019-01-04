// solver using dancing links

#include <iostream>
#include <fstream>
#include <array>

using namespace std;

struct node {
    node *header, *up, *down, *left, *right;
    int num;
};

array<node, 10*9*9*4+1> matrix;

void makeMatrix () {
    matrix[0].left = &matrix[0];
    matrix[0].right = &matrix[0];

    for (int i = 1; i < 9*9*4+1; i ++) {
        matrix[i].up = &matrix[i];
        matrix[i].down = &matrix[i];
        matrix[i].left = &matrix[i-1];
        matrix[i-1].right = &matrix[i];
    }

    for (int i = 9*9*4+1; i < matrix.size(); i ++) {
        switch ((i-1)%4) {
            case 0:
                matrix[i].header = &matrix[1+(i-9*9*4-1)%9];
                break;
            case 1:
                matrix[i].header = &matrix[9*9+1+(i-9*9*4-1)];
                break;
            case 2:
                matrix[i].header = &matrix[9*9*2+1+];
                break;
            case 3:
                matrix[i].header = &matrix[9*9*3+1+];
                break;

        }
        matrix[i].right = &matrix[i-(i-1)%4];
        matrix[i].right->left = &matrix[i];
    }
}

int main () {
    makeMatrix();

    cout << "Hello world!" << endl;
}
