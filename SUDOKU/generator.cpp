#include <iostream>
#include <fstream>
#include <array>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

void generate (array<array<int, 9>, 9> &grid, array<int, 9> &nums)
{
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            random_shuffle(nums.begin(), nums.end());
            for (int k = 0; k < 3; k ++) {
                for (int l = 0; l < 3; l ++) {
                    grid[i*3+k][j*3+l] = nums[k*3+l];
                }
            }
        }
    }
}

bool doesntWork (array<array<int, 9>, 9> &grid)
{
    return false;
}

int main ()
{
    array<int, 9> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<array<int, 9>, 9> grid;

    do generate(grid, nums);
    while (doesntWork(grid));

    ofstream file("sudoku.txt", ios::trunc|ios::out);
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            file << grid[i][j];
        }
        file << endl;
    }

}
