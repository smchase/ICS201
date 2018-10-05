#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int n;

    printf("How many numbers to generate? ");
    cin >> n;
    printf("\n");

    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = (rand() % 99 + 1);

    for (int i = 0; i < n; i++)
        printf("%i\n", arr[i]);
}
