#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int rNum, cpu = 0, usr = 0;
    char again = 'y';
    srand (time(NULL));

    printf("Welcome to blackjack!\n\n");

    while (cpu < 17) {
        rNum = rand() % 11 + 1;
        cpu += rNum;
    }

    if (cpu > 21) {
        printf("The CPU lost!\n");
        return 0;
    } else {
        printf("CPU has finished its turn.\n\n");
    }

    while (again == 'y') {
        rNum = rand() % 11 + 1;
        usr += rNum;

        if (usr > 21) {
            printf("You got a %i, bringing your total to %i. As that's over 21, you lost.\n", rNum, usr);
            return 0;
        }

        printf("You got a %i, bringing your total to %i.\nWould you like to procede? (y/n)\n", rNum, usr);
        scanf(" %c", &again);
        printf("\n");
    }

    if (cpu == usr) {
        printf("You tied %i to %i\n", usr, cpu);
        return 0;
    }

    usr > cpu ? printf("You won %i to %i!\n", usr, cpu) : printf("You lost %i to %i\n", usr, cpu);
}
