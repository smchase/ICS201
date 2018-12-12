#include <iostream>
#include <fstream>
#include <array>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{
    srand(time(NULL));
    array<int, 9> nums;
    array<array<int, 3>, 3> small;
    array<array<array<array<int, 3>, 3>, 3>, 3> big;

    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            small[i][j] = nums[rand()%nums.size()];

        }
    }
}
