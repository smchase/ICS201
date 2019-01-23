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
    int n = -1;
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

void solve (vector<node> &matrix, int &solutions) {
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
        solve(matrix, solutions);
        for (node *c = r->left; c != r; c = c->left) {
            uncover(*c->header);
        }
    }
    uncover(*col);
}

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
        matrix[i].push_back({});
        for (int j = 0; j < tests[i].length(); j ++) {
            matrix[i].push_back({});
        }
        for (int j = 0; j < tests[i].length(); j ++) {
            for (int k = 2; k <= (tests[i].length()-j < 8 ? tests[i].length()-j : 8); k ++) {
                for (int l = 0; l < arr.size(); l ++) {
                    if (tests[i].substr(j, k) == arr[l]) {
                        for (int m = 0; m < tests[i].length(); m ++) {
                            layer.push_back({});
                            if (m >= j && m < j+k) {
                                matrix[i].push_back({});
                                layer.back().filled = true;
                                layer.back().pointer = &matrix[0][0];
                            }
                        }

                        matrix2d[i].push_back(layer);
                        layer.clear();
                    }
                }
            }
        }
    }
    matrix[0][0].n = 5;

    for (int i = 0; i < matrix.size(); i ++) {
        matrix[i][0].left = &matrix[i][tests[i].length()];
        for (int j = 1; j < tests[i].length()+1; j ++) {
            matrix[i][j].up = &matrix[i][j];
            matrix[i][j].down = &matrix[i][j];
            matrix[i][j].left = &matrix[i][j-1];
            matrix[i][j-1].right = &matrix[i][j];
        }
        matrix[i][tests[i].length()].right = &matrix[i][0];
    }

    node *leftNode;
    for (int i = 0; i < matrix2d.size(); i ++) {
        for (int j = 0; j < matrix2d[i].size(); j ++) {
            cout << endl;
            for (int k = 0; k < matrix2d[i][j].size(); k ++) {
                if (matrix2d[i][j][k].filled) {
                    //matrix2d[i][j][k].pointer->header = &matrix[i][tests[i].length()+1+j];
                    cout << matrix2d[i][j][k].pointer->n;

                    /*for (int n = j; n >= 0; n --) {
                        if (matrix2d[i][n][k].filled && n != j) {
                            matrix2d[i][j][k].pointer->up = matrix2d[i][n][k].pointer;
                            break;
                        } else if (n == 0) {
                            matrix2d[i][j][k].pointer->up = matrix2d[i][j][k].pointer->header;
                            matrix2d[i][j][k].pointer->header->down = matrix2d[i][j][k].pointer;
                        }
                    }

                    for (int n = j; n < matrix2d[i].size(); n ++) {
                        if (matrix2d[i][n][k].filled && n != j) {
                            matrix2d[i][j][k].pointer->down = matrix2d[i][n][k].pointer;
                            break;
                        } else if (n+1 == matrix2d[i].size()) {
                            matrix2d[i][j][k].pointer->down = matrix2d[i][j][k].pointer->header;
                            matrix2d[i][j][k].pointer->header->up = matrix2d[i][j][k].pointer;
                        }
                    }

                    node *leftNode;
                    for (int n = k; n >= 0; n --) {
                        if (matrix2d[i][j][n].filled && n != k) {
                            matrix2d[i][j][k].pointer->left = matrix2d[i][j][n].pointer;
                            break;
                        } else if (n == 0) {
                            leftNode = matrix2d[i][j][k].pointer;
                        }
                    }

                    for (int n = k; n < matrix2d[i][j].size(); n ++) {
                        if (matrix2d[i][j][n].filled && n != k) {
                            matrix2d[i][j][k].pointer->right = matrix2d[i][j][n].pointer;
                            break;
                        } else if (n+1 == matrix2d[i][j].size()) {
                            matrix2d[i][j][k].pointer->right = leftNode;
                            leftNode->left = matrix2d[i][j][k].pointer;
                        }
                    }*/
                    //cout << i;
                }
            }
        }
    }

    /*vector<int> solutions;
    for (int i = 0; i < matrix.size(); i ++) {
        solutions.push_back(0);
        solve(matrix[i], solutions[i]);
        cout << solutions[i] << " ";
    }*/
}
