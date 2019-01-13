/*
SUDOKU SOLVER USING DANCING LINKS
Essentially, the way this solver works is it translates a sudoku puzzle to a binary 2D matrix. The rows represent options (ex. a 9 at row 3 and column 7), and the columns represent constraints (ex. there needs to be a 2 in row 5). This matrix is an example of an exact cover problem, where you must find a combination of rows that satisfies each column exactly once. The most efficient way to do this is to turn our 2D matrix into a doubly linked list. We can solve this list using an algorithm called Dancing Links developed by Donald Knuth. A link to Knuth's paper can be found below.

Steps:
1.

Dancing links paper: https://www.ocf.berkeley.edu/~jchu/publicportal/sudoku/0011047.pdf
Sudoku exact cover binary matrix: https://www.stolaf.edu/people/hansonr/sudoku/exactcovermatrix.htm

TODO
cin sudoku problem
clean code
elegance
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

struct solutionNum {
    int num;
    array<int, 2> pos; // row, column
};

void cover (node &column) {
    column.left->right = column.right;
    column.right->left = column.left;

    for (node *n1 = column.down; n1 != &column; n1 = n1->down) {
        for (node *n2 = n1->right; n2 != n1; n2 = n2->right) {
            n2->up->down = n2->down;
            n2->down->up = n2->up;
        }
    }
}

void uncover (node &column) {
    column.left->right = &column;
    column.right->left = &column;

    for (node *n1 = column.up; n1 != &column; n1 = n1->up) {
        for (node *n2 = n1->left; n2 != n1; n2 = n2->left) {
            n2->up->down = n2;
            n2->down->up = n2;
        }
    }
}

array<array<node2d, 9*9*4>, 9*9*9> matrix2d;
array<node, (10*9*9*4)+1> matrix;
array<array<int, 9>, 9> sudoku;
vector<solutionNum> solution;

void solve (int layer = 0) {
    if (matrix[0].right == &matrix[0]) {
        for (int i = 0; i < solution.size(); i ++) {
            sudoku[solution[i].pos[0]][solution[i].pos[1]] = solution[i].num;
        }
        cout << endl;
        for (int i = 0; i < sudoku.size(); i ++) {
            for (int j = 0; j < sudoku[i].size(); j ++) {
                cout << sudoku[i][j];
            }
            cout << endl;
        }
        return;
    }

    node *col;
    int smallest = 9, size;
    for (node *c = matrix[0].right; c != &matrix[0]; c = c->right) {
        size = 0;
        for (node *r = c->down; r != c; r = r->down) {
            size ++;
        }
        if (size < smallest) {
            smallest = size;
            col = c;
        }
    }

    cover(*col);
    for (node *r = col->down; r != col; r = r->down) {
        for (node *c = r->right; c != r; c = c->right) {
            cover(*c->header);
        }
        solution.push_back({r->num, {r->pos[0], r->pos[1]}});
        solve(layer+1);
        for (node *c = r->left; c != r; c = c->left) {
            uncover(*c->header);
        }
        solution.pop_back();
    }
    uncover(*col);
}

int main () {
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

    matrix[0].left = &matrix[9*9*4];
    for (int i = 1; i < (9*9*4)+1; i ++) {
        matrix[i].up = &matrix[i];
        matrix[i].down = &matrix[i];
        matrix[i].left = &matrix[i-1];
        matrix[i-1].right = &matrix[i];
    }
    matrix[9*9*4].right = &matrix[0];

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

    ifstream file("/Users/smchase/Documents/Assignments/SUDOKU/problem.txt");
    char n;
    it = 0;
    while (file.get(n)) {
        cout << (n == 48 ? ' ' : n);
        if (n != '\n') {
            sudoku[it/9][it%9] = n-48;
            it ++;
        }
    }

    for (int i = 0; i < sudoku.size(); i ++) {
        for (int j = 0; j < sudoku[i].size(); j ++) {
            if (sudoku[i][j] != 0) {
                for (int k = 0; k < matrix.size(); k ++) {
                    if (matrix[k].num == sudoku[i][j] && matrix[k].pos[0] == i && matrix[k].pos[1] == j) {
                        cover(*matrix[k].header);
                    }
                }
            }
        }
    }

    solve();
}
