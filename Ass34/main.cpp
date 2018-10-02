#include <iostream>
#include <cmath>
#include <stdio.h>
#define PI 3.14159265


using namespace std;

int main()
{
    float a, b, c, C;

    printf("Please enter the values of the triangle in the format \'a b C\'\n");
    scanf("%f%f%f", &a, &b, &C);

    c = sqrt(pow(a, 2) + pow(b, 2) - (2 * a * b * cos(C * PI / 180)));

    printf("Side c is ~%.2f", c);

    return 0;
}
