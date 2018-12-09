// Minesweeper
// by Simon Chase

#include <iostream>
#include <string>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main ()
{
    array<string, 9> base;
    base.fill("         ");
    array<string, 9> open;
    open.fill("+++++++++");

    srand(time(NULL));
    int x, y;
    for (int i = 0; i < 10; i ++) {
        do {
            x = rand() % 9;
            y = rand() % 9;
        } while (base[y][x] == '*');
        base[y][x] = '*';
    }

    int n;
    for (int i = 0; i < 9; i ++) {
        for (int j = 0; j < 9; j ++) {
            n = 0;
            if (base[i+1][j] == '*') n ++;
            if (base[i-1][j] == '*') n ++;
            if (base[i][j+1] == '*') n ++;
            if (base[i][j-1] == '*') n ++;
            if (base[i+1][j+1] == '*') n ++;
            if (base[i-1][j-1] == '*') n ++;
            if (base[i-1][j+1] == '*') n ++;
            if (base[i+1][j-1] == '*') n ++;
            if (n != 0 && base[i][j] != '*') base[i][j] = n+'0';
        }
    }

    for (int i = 0; i < 10; i ++) {
        if (i == 0) cout << "  ";
        else cout << i << " ";
        for (int j = 0; j < 9; j ++) {
            if (i == 0) cout << (char)(65+j) << " ";
            else cout << base[i-1][j] << " ";
        }
        cout << endl;
    }
}
