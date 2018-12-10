// Minesweeper
// by Simon Chase

#include <iostream>
#include <array>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

using namespace std;

// check if input is proper
bool goodIn (string in)
{
    return in.length() == 2 && in[0] >= 65 && in[0] <= 73 && in[1] >= 49 && in[1] <= 57;
}

// recursive function for oppening spaces
void openSpaces (array<array<char, 9>, 9> &base, array<array<bool, 9>, 9> &open, array<int, 2> pos)
{
    open[pos[0]][pos[1]] = true;
    if (base[pos[0]][pos[1]] == ' ') {
        if (pos[0] < 8 && !open[pos[0]+1][pos[1]]) openSpaces(base, open, {pos[0]+1, pos[1]});
        if (pos[0] > 0 && !open[pos[0]-1][pos[1]]) openSpaces(base, open, {pos[0]-1, pos[1]});
        if (pos[1] < 8 && !open[pos[0]][pos[1]+1]) openSpaces(base, open, {pos[0], pos[1]+1});
        if (pos[1] > 0 && !open[pos[0]][pos[1]-1]) openSpaces(base, open, {pos[0], pos[1]-1});
        if (pos[0] < 8 && pos[1] < 8 && !open[pos[0]+1][pos[1]+1]) openSpaces(base, open, {pos[0]+1, pos[1]+1});
        if (pos[0] > 0 && pos[1] > 0 && !open[pos[0]-1][pos[1]-1]) openSpaces(base, open, {pos[0]-1, pos[1]-1});
        if (pos[0] > 0 && pos[1] < 8 && !open[pos[0]-1][pos[1]+1]) openSpaces(base, open, {pos[0]-1, pos[1]+1});
        if (pos[0] < 8 && pos[1] > 0 && !open[pos[0]+1][pos[1]-1]) openSpaces(base, open, {pos[0]+1, pos[1]-1});
    }
}


// recursive play function
void play (array<array<char, 9>, 9> &base, array<array<bool, 9>, 9> &open, int moves = 0)
{
    // display grid
    for (int i = 0; i < 30; i ++) printf("\n  ");
    for (int i = 0; i < 9; i ++) {
        printf("%c ", 65+i);
    }
    for (int i = 0; i < 9; i ++) {
        printf("\n%i ", i+1);
        for (int j = 0; j < 9; j ++)  {
            printf("%c ", open[i][j] ? base[i][j] : '+');
        }
    }
    printf("\n");

    // take and check input
    string in;
    array<int, 2> pos;
    do {
        printf("\nPick a coordinate (ex. A5): ");
        cin >> in;
    } while (!goodIn(in) || open[in[1]-'0'-1][(int)in[0]-65]);
    pos = {in[1]-'0'-1, (int)in[0]-65};

    // open spaces with recursion, check win or lose, if not continue with recursion
    openSpaces(base, open, pos);
    if (base[pos[0]][pos[1]] == '*') {
        for (int i = 0; i < 30; i ++) printf("\n  ");
        for (int i = 0; i < 9; i ++) {
            printf("%c ", 65+i);
        }
        for (int i = 0; i < 9; i ++) {
            printf("\n%i ", i+1);
            for (int j = 0; j < 9; j ++)  {
                printf("%c ", base[i][j]);
            }
        }
        printf("\n\nYou Lose!\n");
    } else if (moves == 70) {
        for (int i = 0; i < 30; i ++) printf("\n  ");
        for (int i = 0; i < 9; i ++) {
            printf("%c ", 65+i);
        }
        for (int i = 0; i < 9; i ++) {
            printf("\n%i ", i+1);
            for (int j = 0; j < 9; j ++)  {
                printf("%c ", open[i][j] ? base[i][j] : '+');
            }
        }
        printf("\n\nYou Win!\n");
    } else {
        play(base, open, moves+1);
    }
}

int main ()
{
    // create and fill base and open arrays
    array<array<char, 9>, 9> base;
    for (int i = 0; i < 9; i ++) base[i].fill(' ');
    array<array<bool, 9>, 9> open;
    for (int i = 0; i < 9; i ++) open[i].fill(false);

    // generate mines in base
    srand(time(NULL));
    array<int, 2> pos;
    for (int i = 0; i < 10; i ++) {
        do pos = {rand() % 9, rand() % 9};
        while (base[pos[0]][pos[1]] == '*');
        base[pos[0]][pos[1]] = '*';
    }

    // generate numbers for base
    int n;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            n = 0;
            if (i < 8 && base[i+1][j] == '*') n ++;
            if (i > 0 && base[i-1][j] == '*') n ++;
            if (j < 8 && base[i][j+1] == '*') n ++;
            if (j > 0 && base[i][j-1] == '*') n ++;
            if (i < 8 && j < 8 && base[i+1][j+1] == '*') n ++;
            if (i > 0 && j > 0 && base[i-1][j-1] == '*') n ++;
            if (i > 0 && j < 8 && base[i-1][j+1] == '*') n ++;
            if (i < 8 && j > 0 && base[i+1][j-1] == '*') n ++;
            if (n != 0 && base[i][j] != '*') base[i][j] = n+'0';
        }
    }

    // title and game
    printf(" __  __ _____ _   _ ______  _______          ________ ______ _____  ______ _____\n|  \\/  |_   _| \\ | |  ____|/ ____\\ \\        / /  ____|  ____|  __ \\|  ____|  __ \\ \n| \\  / | | | |  \\| | |__  | (___  \\ \\  /\\  / /| |__  | |__  | |__) | |__  | |__) |\n| |\\/| | | | | . ` |  __|  \\___ \\  \\ \\/  \\/ / |  __| |  __| |  ___/|  __| |  _  / \n| |  | |_| |_| |\\  | |____ ____) |  \\  /\\  /  | |____| |____| |    | |____| | \\ \\ \n|_|  |_|_____|_| \\_|______|_____/    \\/  \\/   |______|______|_|    |______|_|  \\_\\\n\nPress ENTER to play...");
    cin.ignore();
    play(base, open);
}
