#include <iostream>
#include <stdio.h>

using namespace std;

bool pyTr (float A, float B, float C)
{
    return (A * A + B * B == C * C) && (A < B && B < C);
}

int main()
{
    float a, b, c;

    printf("Please enter a value for A: ");
    cin >> a;

    printf("Please enter a value for B: ");
    cin >> b;

    printf("Please enter a value for C: ");
    cin >> c;

    if (pyTr(a, b, c))
        printf("\n%g, %g, and %g is a Pythagorean Triple\n", a, b, c);
    else
        printf("\n%g, %g, and %g is not a Pythagorean Triple\n", a, b, c);
}
