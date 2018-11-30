#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

void solve (string mz[], int m[2], int c[2], int l, vector<string> &p, int mvs, int &s)
{
    cout << "test" << endl;
    if (m[0] == c[0] && m[1] == c[0]) {
        if (mvs < s) {
            copy(mz, mz+l, p.begin());
            s = mvs;
        }
    } else {
        if (mz[m[0]][m[1]] == ' ')
            mz[m[0]][m[1]] = '+';
        if (mz[m[0]+1][m[1]] == ' ') {
            m[0] ++;
            solve(mz, m, c, l, p, mvs+1, s);
            m[0] --;
        }
        if (mz[m[0]-1][m[1]] == ' ') {
            m[0] --;
            solve(mz, m, c, l, p, mvs+1, s);
            m[0] ++;
        }
        if (mz[m[0]][m[1]+1] == ' ') {
            m[1] ++;
            solve(mz, m, c, l, p, mvs+1, s);
            m[1] --;
        }
        if (mz[m[0]][m[1]-1] == ' ') {
            m[1] --;
            solve(mz, m, c, l, p, mvs+1, s);
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
        mouse[0] = rand()%mazeV.size();
        mouse[1] = rand()%mazeV[mouse[0]].length();
    } while (mazeV[mouse[0]][mouse[1]] != ' ');
    mazeV[mouse[0]][mouse[1]] = 'M';

    do {
        cheese[0] = rand()%12;
        cheese[1] = rand()%12;
    } while (mazeV[cheese[0]][cheese[1]] != ' ');
    mazeV[cheese[0]][cheese[1]] = 'C';

    for (int i = 0; i < mazeV.size(); i ++) {
        printf("%s\n", mazeV[i].c_str());
    }

    string maze[mazeV.size()];
    copy(mazeV.begin(), mazeV.end(), maze);
    vector<string> path;
    int shortest = 100;
    solve(maze, mouse, cheese, mazeV.size(), path, 0, shortest);

    printf("\n");
    for (int i = 0; i < path.size(); i ++) {
        printf("%s\n", path[i].c_str());
    }
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
