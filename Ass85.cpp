#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void clear ()
{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
};

void play (int m[2], int c[2], string maze[10], vector<int[2]> moves)
{

}

int main ()
{
    string maze[10]/*[16]*/ = {
        {"%%%%%%%%%%%%%%%%"},
        {"%%             %"},
        {"%%%   %   %    %"},
        {"%%%   %%%%%%%%%%"},
        {"%%      %%%%%%%%"},
        {"%     %%%      %"},
        {"%%%%%      %%  %"},
        {"%%%%%%%%%%%%% %%"},
        {"%             %%"},
        {"%%%%%%%%%%%%%%%%"}
    };

    srand(time(NULL));
    int mouse[2], cheese[2];

    do {
        mouse[0] = rand() % 10;
        mouse[1] = rand() % 16;
    } while (maze[mouse[0]][mouse[1]] != ' ');

    do {
        cheese[0] = rand() % 10;
        cheese[1] = rand() % 16;
    } while (maze[cheese[0]][cheese[1]] != ' ' && cheese != mouse);

    play(mouse, cheese, maze);
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
