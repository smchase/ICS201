#include <iostream>
#include <stdio.h>

using namespace std;

float addCoins (int q, int d, int n)
{
    return double (q * 25 + d * 10 + n * 5) / 100;
}

int main()
{
    int q, d, n;

    printf("Enter the number of quarters: ");
    cin >> q;


    printf("Enter the number of dimes: ");
    cin >> d;


    printf("Enter the number of nickles: ");
    cin >> n;

    printf("The total amount %f$\n", addCoins(q, d, n));
}
