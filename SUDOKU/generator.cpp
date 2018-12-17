#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

void resetOptions (vector<int> &options)
{
    options.clear();
    for (int i = 1; i < 10; i ++) {
        options.push_back(i);
    }
}

void checkClear (vector<int> &options, int n)
{
    for (int i = options.size()-1; i >= 0; i--) {
        if (options[i] == n) {
            options.erase(options.begin()+i);
        }
    }
}

int main ()
{
    array<array<int, 9>, 9> grid;
    ofstream file("sudoku.txt", ios::trunc|ios::out);

    vector<int> options;
    array<array<int, 2>, 8> pos = {{{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}}};
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            resetOptions(options);

            for (int k = 0; k < i; k ++) {
                checkClear(options, grid[k][j]);
            }

            for (int k = 0; k < j; k ++) {
                checkClear(options, grid[i][k]);
            }

            for (int k = 0; k < ((i%3)*3)+(j%3); k ++) {
                //checkClear(options, grid[i/3+pos[k][0]][j/3+pos[k][1]]);
            }

            if (options.size() == 0) {
                cout << " ";
            } else {
                random_shuffle(options.begin(), options.end());
                grid[i][j] = options[0];

                cout << grid[i][j];
                file << grid[i][j];
            }
        }
        cout << endl;
        file << endl;
    }
}
