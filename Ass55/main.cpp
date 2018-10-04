// Simon

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

using namespace std;

// Credit: http://www.cplusplus.com/articles/4z18T05o/#Windows
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

int main()
{
    string guess = "", sequence = "";
    srand(time(NULL));

    while (guess == sequence && sequence.length() < 10) {
        int n = rand() % 10;
        char arr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

        sequence += arr[n];
        printf("Simon: %s", sequence.c_str());
        Sleep(2000);

        ClearScreen();
        printf("You: ");
        cin >> guess;

        Sleep(1000);
        ClearScreen();
    }

    sequence.length() == 10 ? printf("Congrats, you won!") : printf("You lost.\nSimon: %s\nYou: %s\nYour score: %i\n", sequence.c_str(), guess.c_str(), sequence.length() - 1);
}
