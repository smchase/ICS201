#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    srand(time(NULL));

    printf("How many numbers to generate? ");
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i ++) {
        int r = rand() % 40 + 1;
        while (arr.count(arr.begin(), arr.end(), r) != 0) {
            r = rand() % 40 + 1
        }
        arr[i] = r;
    }
}
