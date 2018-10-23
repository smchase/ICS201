/*
TODO check input with goodIn()
TODO calculate bulls and cows with bulls() and cows()
TODO generate random number with no repeats

USE INTS FOR NUM & INPUT?
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

bool goodIn (int i)
{
    return true;
}

int bulls (int i, int n)
{
    return 0;
}

int cows (int i, int n)
{
    return 0;
}

int main()
{
    int attempt = 1, j, input, num = 0;

    srand(time(NULL));
    for (int i = 0; i < 8; i++) {
        i == 0 ? j = rand() % 9 + 1 : j = rand() % 10;
        while (num % 10 == j || (num / 10) % 10 == j || (num / 100) % 10 == j) {
            i == 0 ? j = rand() % 9 + 1 : j = rand() % 10;
        }
        num *= 10;
        num += j;
        cout << j << endl;
    }

    cout << num << endl;
    return 1;

    printf("Welcome to the game of BULLS and COWS.\n\nThe objective in this game is for you to guess a 4-digit number\nThe computer responds with how close your guess is to the target\n\nBULLS = # common digits with exact matches\nCOWS  = # common digits in wrong position\n\n");

    while (input != num && attempt <= 10)
    {
        printf("%i. Enter your guess: ", attempt);
        cin >> input;

        if (goodIn (input)) {
            printf("> Bulls: %i\n> Cows: %i\n\n", bulls(input, num), cows(input, num));
            attempt ++;
        } else
            printf("> Input must be a 4 digit non-repeating number\n\n");
    }

    attempt == 10 ? printf("> You Lose\n> The number was %i\n", num) : printf("> You Win!\n");
}

/*
4.	Write a program for the game of BULLS and COWS. The objective of this game is to make the user (player) guess a 4-digit number which is randomly generated in the program. The 4-digit number should not have repeating digits and will be in the range 1000 to 9999. The player will be given a maximum of 10 tries to guess. The player WINS if he/she guesses the number within 10 tries; otherwise the player LOSES the game.
The main program should first display a Welcome Message explaining the rules of the games. Then, it should generate a 4-digit random number between 1000 and 9999 with no repeating digits. After that, it should repeatedly ask the user for his/her guess and report the BULLS and COWS for the guess compared with the random number. The game stops when either the player has made a correct guess or when the player had made 10 guesses.
The game interaction should look something like this:
Welcome to the game of BULLS and COWS.
The Objective in this game is for you to guess a 4-digit number
The computer responds with how close your guess is to the target
BULLS = # common digits with exact matches and
COWS  = # common digits in wrong position.

1.  Enter your guess: 1234
    Bulls = 1  Cows = 0
2.  Enter your guess: 8567
    Bulls = 0  Cows = 1
3.  Enter your guess: 1233
    Your guess should not contain repeating digits
4.  Enter your guess: 7654
    Bulls = 0  Cows = 1
5.  Enter your guess: 7642
    Bulls = 0  Cows = 0
6.  Enter your guess: 5913
    Bulls = 1  Cows = 2
7.  Enter your guess: 5091
    Bulls = 2  Cows = 1
8.  Enter your guess: 5039
    Bulls = 4  Cows = 0

    Congratulations; You Won!!
or a message saying that you lost and PRINT THE ACTUAL NUMBER.
Name the program Ass610
*/
