#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    float p, pay;
    printf("Pieces: ");
    cin >> p;

    if (p >= 1 && p <= 199)
        pay += (p * 0.5);
    else if (p >= 200 && p <= 399)
        pay += (p * 0.55);
    else if (p >= 400 && p <= 599)
        pay += (p * 0.6);
    else if (p >= 600)
        pay += (p * 0.65);

    printf("Pay: $%.2f\n", pay);
}
