#include <iostream>
#include <fstream>
#include <array>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

int main ()
{
    array<array<int, 9>, 9> grid;

    minstd_rand0 seed (chrono::system_clock::now().time_since_epoch().count());
    array<int, 9> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            shuffle(nums.begin(), nums.end(), seed);
            for (int k = 0; k < 3; k ++) {
                for (int l = 0; l < 3; l ++) {
                    grid[i*3+k][j*3+l] = nums[k*3+l];
                }
            }
        }
    }

    ofstream file("sudoku.txt", ios::trunc|ios::out);
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            file << grid[i][j];
        }
        file << endl;
    }
    cout << "Wrote!" << endl;
}
