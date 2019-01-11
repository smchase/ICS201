/*
SUDOKU SOLVER USING DANCING LINKS
Essentially, the way this solver works is it translates a sudoku puzzle to a binary 2D matrix. The rows represent options (ex. a 9 at row 3 and column 7), and the columns represent constraints (ex. there needs to be a 2 in row 5). This matrix is an example of an exact cover problem, where you must find a combination of rows that satisfies each column exactly once. The most efficient way to do this is to turn our 2D matrix into a doubly linked list. We can solve this list using an algorithm called Dancing Links developed by Donald Knuth. A link to Knuth's paper can be found below.

Steps:
1.

Dancing links paper: https://www.ocf.berkeley.edu/~jchu/publicportal/sudoku/0011047.pdf
Sudoku exact cover binary matrix: https://www.stolaf.edu/people/hansonr/sudoku/exactcovermatrix.htm
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <array>

using namespace std;

struct node {
    node *up;
    node *down;
    node *left;
    node *right;
    node *header;
    int num;
    array<int, 2> pos; // row, column
};

struct node2d {
    bool filled = false;
    node *pointer;
};

void cover (node &column) {
    column.left->right = column.right;
    column.right->left = column.left;

    node *n1 = &column;
    node *n2;
    int i = 0;
    do {
        n1 = n1->down;
        n1->left->right = n1->right;
        n1->right->left = n1->left;

        n2 = n1;
        do {
            n2 = n2->right;
            n2->up->down = n2->down;
            n2->down->up = n2->up;
        } while (n2 != n1->left);
    } while (n1 != column.up);
}

void uncover (node &column) {
    column.left->right = &column;
    column.right->left = &column;

    node *n1 = &column;
    node *n2;
    int i = 0;
    do {
        n1 = n1->up;
        n1->left->right = n1;
        n1->right->left = n1;

        n2 = n1;
        do {
            n2 = n2->left;
            n2->up->down = n2;
            n2->down->up = n2;
        } while (n2 != n1->right);
    } while (n1 != column.down);
}

int main () {
    array<array<node2d, 9*9*4>, 9*9*9> matrix2d;
    array<node, (10*9*9*4)+1> matrix;
    int it = (9*9*4)+1;

    for (int i = 0; i < 9*9*9; i ++) {
        matrix2d[i][i/9] = {true, &matrix[it]};
        matrix[it].num = (i%9)+1;
        matrix[it].pos = {i/81, (i/9)%9};
        it ++;

        matrix2d[i][(9*9)+(i%9)+((i/81)*9)] = {true, &matrix[it]};
        matrix[it].num = (i%9)+1;
        matrix[it].pos = {i/81, (i/9)%9};
        it ++;

        matrix2d[i][(9*9*2)+(i%81)] = {true, &matrix[it]};
        matrix[it].num = (i%9)+1;
        matrix[it].pos = {i/81, (i/9)%9};
        it ++;

        matrix2d[i][(9*9*3)+(i%9)+(((i%(9*9))/(9*3))*9)+((i/(9*9*3))*9*3)] = {true, &matrix[it]}; // god this took torever
        matrix[it].num = (i%9)+1;
        matrix[it].pos = {i/81, (i/9)%9};
        it ++;
    }
    cout << "created 2d matrix" << endl;

    matrix[0].left = &matrix[9*9*4];
    for (int i = 1; i < (9*9*4)+1; i ++) {
        matrix[i].up = &matrix[i];
        matrix[i].down = &matrix[i];
        matrix[i].left = &matrix[i-1];
        matrix[i-1].right = &matrix[i];
    }
    matrix[9*9*4].right = &matrix[0];
    cout << "created headers" << endl;

    node *leftNode;
    for (int i = 0; i < 9*9*9; i ++) {
        for (int j = 0; j < 9*9*4; j ++) {
            if (matrix2d[i][j].filled) {
                // header
                matrix2d[i][j].pointer->header = &matrix[j+1];

                // up
                for (int n = i; n >= 0; n --) {
                    if (matrix2d[n][j].filled && n != i) {
                        matrix2d[i][j].pointer->up = matrix2d[n][j].pointer;
                        break;
                    } else if (n == 0) {
                        matrix2d[i][j].pointer->up = &matrix[j+1];
                        matrix[j+1].down = matrix2d[i][j].pointer;
                    }
                }

                // down
                for (int n = i; n < 9*9*9; n ++) {
                    if (matrix2d[n][j].filled && n != i) {
                        matrix2d[i][j].pointer->down = matrix2d[n][j].pointer;
                        break;
                    } else if (n+1 == 9*9*9) {
                        matrix2d[i][j].pointer->down = &matrix[j+1];
                        matrix[j+1].up = matrix2d[i][j].pointer;
                    }
                }

                // left
                node *leftNode;
                for (int n = j; n >= 0; n --) {
                    if (matrix2d[i][n].filled && n != j) {
                        matrix2d[i][j].pointer->left = matrix2d[i][n].pointer;
                        break;
                    } else if (n == 0) {
                        leftNode = matrix2d[i][j].pointer;
                    }
                }

                // right
                for (int n = j; n < 9*9*4; n ++) {
                    if (matrix2d[i][n].filled && n != j) {
                        matrix2d[i][j].pointer->right = matrix2d[i][n].pointer;
                        break;
                    } else if (n+1 == 9*9*4) {
                        matrix2d[i][j].pointer->right = leftNode;
                        leftNode->left = matrix2d[i][j].pointer;
                    }
                }
            }
        }
    }
    cout << "filled body pointers" << endl;

    cout << "finished!" << endl;
}
