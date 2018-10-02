#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int num1, num2, total = 0;

    printf("Enter two numbers in the format \'num1 num2\'\n");
    scanf("%i %i", &num1, &num2);

    for (int i = num1; i <= num2; i++) {
        total += i;
    }

    printf("The sum of the numbers from %i to %i is %i\n", num1, num2, total);
}
