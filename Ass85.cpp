#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <windows.h>

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

void genPos (int arr[2], string m[10][16], int n[2])
{

}

void play (int m[2], int c[2], string maze[10][16], vector<int[2]> moves)
{

}

int main ()
{
    string maze[10][16] = {
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

    int mouse[2], cheese[2];
    genPos(mouse, maze);
    genPos(cheese, maze, mouse);

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
