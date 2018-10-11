#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int t = 0;
    for (int i = 0; i < 5; i++) {
        int s = rand() % 10 + 1;
        t += s;
        printf("%i, ", s);
    }
    printf("%i\n", t);
}
