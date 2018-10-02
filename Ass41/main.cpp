#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    bool first = true;
    string pwd = "password";
    string sGuess = "";
    char cGuess[8];

    while (sGuess != pwd) {
        first ? first = false : printf("Incorrect\n");

        printf("Please enter password: ");
        scanf("%s", &cGuess);
        printf("\n");

        sGuess = cGuess;
    }

    printf("Correct!\n");
}
