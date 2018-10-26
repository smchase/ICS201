#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
    fstream f("\\\\HS2\\C588 Students$\\schase9914\\Documents\\Assignments\\Ass74.txt", ios::in);
    int arr[10], i = 0, j;

    printf("The numbers are: ");
    while (!f.eof()) {
        f >> j;
        cout << (int)j;
        arr[0] = j;
        printf("%c%s", arr[i], (i == 9 ? "" : ", "));
        i ++;
    }
}

/*
Create a file which has 10 numbers in it. (Note: you must assume that you don’t previously know the number in the file).  Create a program which reads the numbers, displays the numbers to the screen and calculates the mean and the mode (mean – average, mode- the most frequent number). Name this application Ass74

The numbers are: 6,4,4,6,8,5,4,9,2,1
The mean is: 4.9
The mode is: 4

Note: Mode – if each number only occurs once there is no mode.  If there is more than one mode, they should all be listed.  For example:
The numbers are: 6,4,4,6,6,5,4,9,2,1
The mean is: 4.9
The mode is: 4, 6
*/
