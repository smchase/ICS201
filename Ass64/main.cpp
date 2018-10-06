#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    srand(time(NULL));

    printf("How many numbers to generate? ");
    cin >> n;

    if (n > 20)
        n = 20;

    vector<int> arr;
    for (int i = 0; i < n; i ++) {
        int r = rand() % 40 + 1;
        while (count(arr.begin(), arr.end(), r) != 0) {
            r = rand() % 40 + 1;
        }
        arr.push_back(r);
        printf("%i\n", r);
    }
}
