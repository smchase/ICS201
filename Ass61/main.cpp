#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    int arr[10], big = 0, small = 99;
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
        arr[i] = (rand() % 99 + 1);

    for (int i = 0; i < 10; i++) {
        if (arr[i] > big)
            big = arr[i];

        if (arr[i] < small)
            small = arr[i];

        printf("%i\n", arr[i]);
    }

    printf("\nLargest number: %i\nSmallest number: %i\n", big, small);
}
