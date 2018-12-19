#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

void resetOptions (vector<int> &options, minstd_rand0 &seed)
{
    options.clear();
    for (int i = 1; i < 10; i ++) {
        options.push_back(i);
    }
    shuffle(options.begin(), options.end(), seed);
}

void removeElement (vector<int> &options, int n)
{
    for (int i = options.size()-1; i >= 0; i--) {
        if (options[i] == n) {
            options.erase(options.begin()+i);
            break;
        }
    }
}

int main ()
{
    ofstream file("solution.txt", ios::trunc|ios::out);
    array<array<vector<int>, 9>, 9> options;
    array<array<int, 2>, 8> pos = {{{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}}};
    minstd_rand0 seed (chrono::system_clock::now().time_since_epoch().count());

    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            resetOptions(options[i][j], seed);
            for (int k = 0; k < i; k ++) {
                removeElement(options[i][j], options[k][j][0]);
            }
            for (int k = 0; k < j; k ++) {
                removeElement(options[i][j], options[i][k][0]);
            }
            for (int k = 0; k < ((i%3)*3)+(j%3); k ++) {
                removeElement(options[i][j], options[i-i%3+pos[k][0]][j-j%3+pos[k][1]][0]);
            }
            if (options[i][j].size() == 0) {
                i = 0;
                j = 0;
            }
        }
    }

    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            cout << options[i][j][0] << " ";
            file << options[i][j][0] << " ";
        }
        cout << endl;
        file << endl;
    }
}
