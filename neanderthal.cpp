#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

struct node {
    node *up;
    node *down;
    node *left;
    node *right;
    node *header;
};

struct node2d {
    bool filled = false;
    node *pointer;
};

void cover (node &col) {
    col.left->right = col.right;
    col.right->left = col.left;

    for (node *n1 = col.down; n1 != &col; n1 = n1->down) {
        for (node *n2 = n1->right; n2 != n1; n2 = n2->right) {
            n2->up->down = n2->down;
            n2->down->up = n2->up;
        }
    }
}

void uncover (node &col) {
    col.left->right = &col;
    col.right->left = &col;

    for (node *n1 = col.up; n1 != &col; n1 = n1->up) {
        for (node *n2 = n1->left; n2 != n1; n2 = n2->left) {
            n2->up->down = n2;
            n2->down->up = n2;
        }
    }
}

/*void solve () {
    if (matrix[0].right == &matrix[0]) {
        solutions ++;
        return;
    }

    node *col;
    int smallest = 10, size;
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
        sudoku[r->row][r->col] = r->num;
        solve();
        for (node *c = r->left; c != r; c = c->left) {
            uncover(*c->header);
        }
    }
    uncover(*col);
}*/

int main () {
    string str;
    vector<string> tests;
    cout << "PASTE TESTS FROM FILE" << endl;
    while (cin >> str && str != "END") tests.push_back(str);

    vector<vector<vector<node2d>>> matrix2d;
    vector<vector<node>> matrix;
    vector<node2d> layer;
    array<string, 10> arr = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};
    for (int i = 0; i < tests.size(); i ++) {
        matrix2d.push_back({});
        matrix.push_back({});
        cout << "NEW TEST" << endl;
        for (int j = 0; j < tests[i].length(); j ++) {
            for (int k = 2; k <= (tests[i].length()-j < 8 ? tests[i].length()-j : 8); k ++) {
                for (int l = 0; l < arr.size(); l ++) {
                    if (tests[i].substr(j, k) == arr[l]) {
                        cout << "FOUND WORD ";
                        for (int m = 0; m < tests[i].length(); m ++) {
                            layer.push_back({});
                            if (m >= j && m < j+k) {
                                matrix[i].push_back({});
                                layer[layer.size()-1].filled = true;
                                layer[layer.size()-1].pointer = &matrix[i][matrix.size()-1];
                                cout << m << " ";
                            }
                        }

                        matrix2d[i].push_back(layer);
                        layer.clear();
                    }
                }
            }
        }
    }

    vector<int> solutions;
    /*matrix[0].left = &matrix[9*9*4];
    for (int i = 1; i < (9*9*4)+1; i ++) {
        matrix[i].up = &matrix[i];
        matrix[i].down = &matrix[i];
        matrix[i].left = &matrix[i-1];
        matrix[i-1].right = &matrix[i];
    }
    matrix[9*9*4].right = &matrix[0];

    // assign linked matrix pointers based off of 2d matrix
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
    */

    for (int i = 0; i < matrix.size(); i ++) {
        //solve(matrix[i], solutions[i]);
        cout << solutions[i] << " ";
    }
}
