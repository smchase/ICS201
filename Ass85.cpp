#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

void solve (string mz[], int m[2], string *p, int mvs, int &s)
{
    if (mz[m[0]][m[1]] == 'C') {
        if (mvs < s) {
            copy(mz, mz+12, p);
            s = mvs;
        }
    } else {
        if (mz[m[0]][m[1]] == ' ')
            mz[m[0]][m[1]] = '+';
        if (mz[m[0]+1][m[1]] == ' ' || mz[m[0]+1][m[1]] == 'C') {
            m[0] ++;
            solve(mz, m, p, mvs+1, s);
            m[0] --;
        }
        if (mz[m[0]-1][m[1]] == ' ' || mz[m[0]-1][m[1]] == 'C') {
            m[0] --;
            solve(mz, m, p, mvs+1, s);
            m[0] ++;
        }
        if (mz[m[0]][m[1]+1] == ' ' || mz[m[0]][m[1]+1] == 'C') {
            m[1] ++;
            solve(mz, m, p, mvs+1, s);
            m[1] --;
        }
        if (mz[m[0]][m[1]-1] == ' ' || mz[m[0]][m[1]-1] == 'C') {
            m[1] --;
            solve(mz, m, p, mvs+1, s);
            m[1] ++;
        }
    }
}

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments";

    srand(time(NULL));
    vector<string> mazeV;
    fstream file(location + "\\maze.txt");
    string out;
    int mouse[2], cheese[2];

    while (getline(file, out)) mazeV.push_back(out);

    do {
        mouse[0] = rand()%12;
        mouse[1] = rand()%12;
    } while (mazeV[mouse[0]][mouse[1]] != ' ');
    mazeV[mouse[0]][mouse[1]] = 'M';

    do {
        cheese[0] = rand()%12;
        cheese[1] = rand()%12;
    } while (mazeV[cheese[0]][cheese[1]] != ' ');
    mazeV[cheese[0]][cheese[1]] = 'C';

    for (int i = 0; i < 12; i ++) {
        printf("%s\n", mazeV[i].c_str());
    }

    string maze[12];
    copy(mazeV.begin(), mazeV.end(), maze);
    string path[12];
    int shortest = 100;
    solve(maze, mouse, path, 0, shortest);

    printf("\n");
    for (int i = 0; i < 12; i ++) {
        printf("%s\n", path[i].c_str());
    }
    printf("Shortest Path: %i\n", shortest);
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
