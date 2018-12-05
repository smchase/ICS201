#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <array>
#include <algorithm>

using namespace std;

void ClearScreen ()
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
}

void bounce (array<string, 25> arr, string dir = "down")
{
    bool first = true;
    for (int i = 0; i < arr.size(); i ++) {
        if (find(arr[i].begin(), arr[i].end(), 'O') != arr[i].end() && first) {
            if (dir == "down" && find(arr[i+3].begin(), arr[i+3].end(), '#') == arr[i+3].end()) {
                arr[i].swap(arr[i+3]);
            } else {
                dir = (dir == "down" ? "up" : "down");
            }
            first = false;
        } else if (dir == "up") {
            if 
        }
        printf("%s\n", arr[i].c_str());
    }
    Sleep(250);
    ClearScreen();
    bounce(arr, dir);
}

int main ()
{
    array<string, 25> arr =
    {
        "                                                  ",
        "                       OOOO                       ",
        "                       OOOO                       ",
        "                       OOOO                       ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "                                                  ",
        "##################################################"
    };
    bounce(arr);
}
