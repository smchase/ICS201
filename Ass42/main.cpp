#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    float amt, intRate, endAmt;
    int yrs = 0;

    printf("Please enter the starting amount ($), interest rate (%%), and desired end amount ($) (format: \'start interest end')\n");
    scanf("%f%f%f", &amt, &intRate, &endAmt);

    while (amt < endAmt) {
        amt *= (1 + intRate/100);
        yrs ++;
    }

    printf("\nIt would take %i years to grow your money to $%.0f at %%%.0f per year\n", yrs, endAmt, intRate);
}
