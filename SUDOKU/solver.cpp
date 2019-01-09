/*
Sudoku solver using dancing links
Dancing links paper: https://www.ocf.berkeley.edu/~jchu/publicportal/sudoku/0011047.pdf
Sudoku exact cover binary matrix: https://www.stolaf.edu/people/hansonr/sudoku/exactcovermatrix.htm

Steps:
1. Read sudoku problem from problem.txt.
2. Create matrix using 2d arrays with pointers to nodes in another array.
3. Add header nodes to other array.
4. Set the parameters of the body nodes using the 2d matrix.
5. Add rows satisfied by the numbers in problem.txt to solution.
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

int main () {
    array<array<node2d, 9*9*4>, 9*9*9> matrix2d;
    array<node, 9*9*9*4> matrix;
    int it = 0;

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

    cout << "created 2d matrix!" << endl;

    cout << "finished!" << endl;
}
