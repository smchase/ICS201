#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <windows.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Credit: http://www.cplusplus.com/articles/4z18T05o/#Windows
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

void play (int m[2], int c[2], string mz[10], int i)
{
    clear();
    for (int y = 0; y < 10; y ++) {
        if (m[0] == y || c[0] == y) {
            for  (int x = 0; x < 16; x ++) {
                if (y == m[0] && x == m[1]) printf("@");
                else if (y == c[0] && x == c[1]) printf("%c", i%2 == 0 ? '\\' : '/');
                else printf("%c", mz[y][x]);
            }
        }
        else printf("%s", mz[y].c_str());
        printf("\n");
    }
    if (m[0] == c[0] && m[1] == c[1]) return;

    int ry, rx;
    do {
        ry = (rand()%3)-1;
        rx = (rand()%3)-1;
    } while (mz[m[0]+ry][m[1]+rx] != ' ');
    m[0] += ry;
    m[1] += rx;

    Sleep(100);
    play(m, c, mz, i + 1);
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

    play(mouse, cheese, maze, 0);
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
