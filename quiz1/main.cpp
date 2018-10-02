#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    float r, h, sa;

    printf("Radius: ");
    cin >> r;

    printf("Height: ");
    cin >> h;

    sa = 2 * 3.14 * r * r + 2 * 3.14 * r * h;

    printf("\nSurface Area: %.2f", sa);
}
