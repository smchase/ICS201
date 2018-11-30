#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void solve (vector<string> &mz, int m[2], int c[2], int &s, int mvs)
{
    
}

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    srand(time(NULL));
    vector<string> maze;
    fstream file(location + "\\maze.txt");
    string out;
    int mouse[2], cheese[2];

    while (!file.eof()) {
        getline(file, out);
        maze.push_back(out);
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
    maze[cheese[0]][cheese[1]] = 'C';

    for (int i = 0; i < maze.size(); i ++) {
        printf("%s\n", maze[i].c_str());
    }

    int shortest = 30;
    solve(maze, mouse, cheese, shortest, 0);
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
