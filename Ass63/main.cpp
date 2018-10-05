#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>

using namespace std;

int main()
{
    int arr[10];
    string odd = "Odds: ", even = "Evens: ";
    srand(time(NULL));

    for (int i = 0; i < 10; i ++)
        arr[i] = (rand() % 99 + 1);

    printf("Index | Number\n");

    for (int i = 0; i < 10; i ++)
        printf("    %i | %i\n", i, arr[i]);

    printf("\n\nOdds: ");
    for (int i = 0; i < 10; i ++) {
        if (arr[i] % 2 == 1)
            printf("%i ", arr[i]);
    }

    printf("\nEvens: ");
    for (int i = 0; i < 10; i ++) {
        if (arr[i] % 2 == 0)
            printf("%i ", arr[i]);
    }
    printf("\n");
}
