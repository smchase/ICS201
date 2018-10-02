#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    float ans; // real answer
    int num1, num2, op1, in; // 1st number, 2nd number, operator (0-3), user answer
    char op2; // operator character
    srand (time(NULL));

    op1 = rand() % 4;
    num1 = rand() % 9 + 1;
    num2 = rand() % 9 + 1;

    switch (op1) {
    case 0:
        op2 = '+';
        ans = num1 + num2;
        break;

    case 1:
        op2 = '-';
        ans = num1 - num2;
        break;

    case 2:
        op2 = '*';
        ans = num1 * num2;
        break;

    case 3:
        op2 = '/';
        ans = num1 / num2;
        break;
    }

    printf("Round down\n%i %c %i? ", num1, op2, num2);
    scanf("%i", &in);

    in == floor(ans) ? printf("Correct!") : printf("Wrong");
}
