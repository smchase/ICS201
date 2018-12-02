#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <array>

using namespace std;

struct coor {
    array<int, 2> pos;
    vector<string> path;
};

void solve(vector<coor> &coorList, vector<string> &maze, array<int, 2> &cheese, int i) {
    if (coorList[i].pos == cheese) {
        printf("\nShortest Path:\n");
        for (int j = 0; j < coorList[i].path.size(); j ++) {
            printf("%i. %s\n", j+1, coorList[i].path[j].c_str());
        }
    } else {
        if (maze[coorList[i].pos[0]-1][coorList[i].pos[1]] == ' ' || maze[coorList[i].pos[0]-1][coorList[i].pos[1]] == 'C') {
            maze[coorList[i].pos[0]-1][coorList[i].pos[1]] = '+';
            coorList[i].path.push_back("UP");
            coorList.push_back({{coorList[i].pos[0]-1, coorList[i].pos[1]}, coorList[i].path});
            coorList[i].path.pop_back();
        }
        if (maze[coorList[i].pos[0]+1][coorList[i].pos[1]] == ' ' || maze[coorList[i].pos[0]+1][coorList[i].pos[1]] == 'C') {
            maze[coorList[i].pos[0]+1][coorList[i].pos[1]] = '+';
            coorList[i].path.push_back("DOWN");
            coorList.push_back({{coorList[i].pos[0]+1, coorList[i].pos[1]}, coorList[i].path});
            coorList[i].path.pop_back();
        }
        if (maze[coorList[i].pos[0]][coorList[i].pos[1]-1] == ' ' || maze[coorList[i].pos[0]][coorList[i].pos[1]-1] == 'C') {
            maze[coorList[i].pos[0]][coorList[i].pos[1]-1] = '+';
            coorList[i].path.push_back("LEFT");
            coorList.push_back({{coorList[i].pos[0], coorList[i].pos[1]-1}, coorList[i].path});
            coorList[i].path.pop_back();
        }
        if (maze[coorList[i].pos[0]][coorList[i].pos[1]+1] == ' ' || maze[coorList[i].pos[0]][coorList[i].pos[1]+1] == 'C') {
            maze[coorList[i].pos[0]][coorList[i].pos[1]+1] = '+';
            coorList[i].path.push_back("RIGHT");
            coorList.push_back({{coorList[i].pos[0], coorList[i].pos[1]+1}, coorList[i].path});
            coorList[i].path.pop_back();
        }
        solve(coorList, maze, cheese, i+1);
    }
}

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments";
    fstream file(location + "\\maze.txt");
    string out;
    vector<string> maze;
    while (getline(file, out)) maze.push_back(out);

    array<int, 2> mouse, cheese;
    for (int i = 0; i < maze.size(); i ++) {
        for (int j = 0; j < maze[i].length(); j ++) {
            if (maze[i][j] == 'M') mouse = {i, j};
            if (maze[i][j] == 'C') cheese = {i, j};
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    vector<coor> coorList;
    coorList.push_back({mouse, {}});
    solve(coorList, maze, cheese, 0);
}
