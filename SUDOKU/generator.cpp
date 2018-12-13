#include <iostream>
#include <fstream>
#include <array>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

void generate (array<array<int, 9>, 9> &grid)
{
    minstd_rand0 seed (chrono::system_clock::now().time_since_epoch().count());
    //cout << "Seed: " << seed;
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
    //cout << " Generated!" << endl;
}

bool doesntWork (array<array<int, 9>, 9> &grid)
{
    array<int, 9> arr;
    for (int i = 0; i < 9; i ++) {
        fill(arr.begin(), arr.end(), 0);
        for (int j = 0; j < 9; j ++) {
            arr[grid[i][j]-1] ++;
        }
        for (int j = 0; j < 9; j ++) {
            arr[grid[j][i]-1] ++;
        }
        if (count(arr.begin(), arr.end(), 2) != 9) {
            //cout << "Didn't work!" << endl << endl;
            return true;
        }
    }
    //cout << "Worked!" << endl << endl;
    return false;
}

int main ()
{
    array<array<int, 9>, 9> grid;

    do generate(grid);
    while (doesntWork(grid));

    ofstream file("sudoku.txt", ios::trunc|ios::out);
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            file << grid[i][j];
        }
        file << endl;
    }
    cout << "Wrote!" << endl;
}
