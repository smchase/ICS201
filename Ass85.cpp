#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void solve (char mz[12][12], int m[2], int c[2], char d)
{
    if (m[0] == c[0] && m[1] == c[1]) {
        printf("\n");
        for (int i = 0; i < 12; i ++) {
            for (int j = 0; j < 12; j ++) {
                printf("%c", c[0]==i&&c[1]==j ? 'C' : (mz[i][j] == 'M' || mz[i][j] == '%' ? mz[i][j] : ' '));
            }
            printf("\n");
        }
        printf("\n");
        for (int i = 0; i < 12; i ++) {
            for (int j = 0; j < 12; j ++) {
                printf("%c", c[0]==i&&c[1]==j ? 'C' : mz[i][j]);
            }
            printf("\n");
        }
    } else {
        if (mz[m[0]][m[1]] != 'M') mz[m[0]][m[1]] = 'o';

        char arr[4] = {'^', 'v', '>', '<'};
        do {
            d = arr[rand()%4];
        } while (d == '>' && mz[m[0]][m[1]+1] == '%' || d == '<' && mz[m[0]][m[1]-1] == '%' || d == '^' && mz[m[0]-1][m[1]] == '%' || d == 'v' && mz[m[0]+1][m[1]] == '%');

        if (d == '>') m[1] ++;
        else if (d == '<') m[1] --;
        else if (d == '^') m[0] --;
        else if (d == 'v') m[0] ++;

        printf("%c", d);
        solve(mz, m, c, d);
    }
}

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    srand(time(NULL));
    char maze[12][12];
    fstream file(location + "\\maze.txt");
    string out;
    int y = 0, mouse[2], cheese[2];

    while (!file.eof()) {
        getline(file, out);
        for (int x = 0; x < 12; x ++) {
            maze[y][x] = out[x];
        }
        y ++;
    }

    do {
        mouse[0] = rand()%12;
        mouse[1] = rand()%12;
    } while (maze[mouse[0]][mouse[1]] != ' ');
    maze[mouse[0]][mouse[1]] = 'M';

    do {
        cheese[0] = rand()%12;
        cheese[1] = rand()%12;
    } while (maze[cheese[0]][cheese[1]] != ' ');

    solve(maze, mouse, cheese, '>');
}

/*
1.	A mouse in a maze is searching for cheese (#) located at an unknown position in the maze.  The mouse can move in four directions (up, down, left, right).  The mouse begins at a position in the maze marked by (s) and must search through the maze until it finds the cheese without going through any walls (%).  Output the path the mouse could take to find the cheese.
%%%%%%%%%%%%%%%%
%%             %
%%%   %   %    s
%%%   %%%%%%%%%%
%%      %%%%%%%%
%     %%%      %
%%%%%      %%  %
%%%%%%%%%%%%% %%
%#            %%
%%%%%%%%%%%%%%%%
*/
