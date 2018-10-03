#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

void redFrac (int n, int d)
{
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && d % i == 0) {
            n /= i;
            d /= i;
        }
    }

    printf("%i/%i\n", n, d);
}

int main()
{
    int num, den;

    printf("Numerator: ");
    cin >> num;

    printf("Denomenator: ");
    cin >> den;

    redFrac(num, den);
}
