#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <array>

using namespace std;

struct coord {
    array<int, 2> pos;
    vector<string> path;
};

void solve (vector<coord> &coordList, vector<string> &maze, int i) {
    if (maze[coordList[i].pos[0]][coordList[i].pos[1]] == 'C') {
        printf("\nShortest Path:\n");
        for (int j = 0; j < coordList[i].path.size(); j ++) {
            printf("%i. %s\n", j+1, coordList[i].path[j].c_str());
        }
    } else {
        if (maze[coordList[i].pos[0]-1][coordList[i].pos[1]] == ' ' || maze[coordList[i].pos[0]-1][coordList[i].pos[1]] == 'C') {
            if (maze[coordList[i].pos[0]-1][coordList[i].pos[1]] != 'C') maze[coordList[i].pos[0]-1][coordList[i].pos[1]] = '+';
            coordList[i].path.push_back("UP");
            coordList.push_back({{coordList[i].pos[0]-1, coordList[i].pos[1]}, coordList[i].path});
            coordList[i].path.pop_back();
        }
        if (maze[coordList[i].pos[0]+1][coordList[i].pos[1]] == ' ' || maze[coordList[i].pos[0]+1][coordList[i].pos[1]] == 'C') {
            if (maze[coordList[i].pos[0]+1][coordList[i].pos[1]] != 'C') maze[coordList[i].pos[0]+1][coordList[i].pos[1]] = '+';
            coordList[i].path.push_back("DOWN");
            coordList.push_back({{coordList[i].pos[0]+1, coordList[i].pos[1]}, coordList[i].path});
            coordList[i].path.pop_back();
        }
        if (maze[coordList[i].pos[0]][coordList[i].pos[1]-1] == ' ' || maze[coordList[i].pos[0]][coordList[i].pos[1]-1] == 'C') {
            if (maze[coordList[i].pos[0]][coordList[i].pos[1]-1] != 'C') maze[coordList[i].pos[0]][coordList[i].pos[1]-1] = '+';
            coordList[i].path.push_back("LEFT");
            coordList.push_back({{coordList[i].pos[0], coordList[i].pos[1]-1}, coordList[i].path});
            coordList[i].path.pop_back();
        }
        if (maze[coordList[i].pos[0]][coordList[i].pos[1]+1] == ' ' || maze[coordList[i].pos[0]][coordList[i].pos[1]+1] == 'C') {
            if (maze[coordList[i].pos[0]][coordList[i].pos[1]+1] != 'C') maze[coordList[i].pos[0]][coordList[i].pos[1]+1] = '+';
            coordList[i].path.push_back("RIGHT");
            coordList.push_back({{coordList[i].pos[0], coordList[i].pos[1]+1}, coordList[i].path});
            coordList[i].path.pop_back();
        }
        solve(coordList, maze, i+1);
    }
}

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    fstream file(location + "\\maze.txt");
    string out;
    vector<string> maze;
    while (getline(file, out)) maze.push_back(out);

    array<int, 2> mouse;
    for (int i = 0; i < maze.size(); i ++) {
        for (int j = 0; j < maze[i].length(); j ++) {
            if (maze[i][j] == 'M') mouse = {i, j};
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    vector<coord> coordList;
    coordList.push_back({mouse, {}});
    solve(coordList, maze, 0);
}
