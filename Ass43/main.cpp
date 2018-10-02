#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num;
    float avg = 0;

    printf("Enter a number ");
    scanf("%i", &num);

    for (int i = 1; i <= num; i++) {
        avg += i;
    }
    avg /= num;

    printf("The average from 1 to %i is %f\n", num, avg);
}
