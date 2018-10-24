#include <iostream>
#include <stdio.h>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

bool goodIn (string i)
{
    if (i.length() != 4)
        return false;

    for (int n = 0; n < 4; n ++) {
        if (count(i.begin(), i.end(), i[n]) != 1)
            return false;

        if (!(i[n] >= (n == 0 ? '1' : '0') && i[n] <= '9'))
            return false;
    }

    return true;
}

int bulls (string i, string n)
{
    int b = 0;

    for (int j = 0; j < 4; j ++) {
        if (i[j] == n[j])
            b++;
    }

    return b;
}

int cows (string i, string n)
{
    int c = 0;

    for (int j = 0; j < 4; j ++) {
        if (n.find(i[j]) != -1 && i[j] != n[j])
            c++;
    }

    return c;
}

int main()
{
    int attempt = 1, rn;
    string input, num = "----";
    char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        do
            i == 0 ? rn = rand() % 9 + 1 : rn = rand() % 10;
        while
            (num.find(arr[rn]) != -1);
        num[i] = arr[rn];
    }

    printf("Welcome to the game of BULLS and COWS.\n\nThe objective in this game is for you to guess a 4 digit non-repeating integer (1000 to 9999) in 10 tries or less\nThe computer responds with how close your guess is to the target\n\nBULLS = # common digits with exact matches\nCOWS  = # common digits in wrong position\n\n");

    while (input != num && attempt <= 10)
    {
        printf("%i. Enter your guess: ", attempt);
        cin >> input;

        if (goodIn (input)) {
            printf("> Bulls: %i\n> Cows: %i\n\n", bulls(input, num), cows(input, num));
            attempt ++;
        } else
            printf("> Input must be a 4 digit non-repeating integer (1000 to 9999)\n\n");
    }

    attempt == 11 ? printf("> You Lose\n> The number was %s\n", num.c_str()) : printf("> You Win!\n");
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
