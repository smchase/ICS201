
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
    ifstream f("Ass71.txt");
    string s;

    printf("The numbers are: ");
    while (!f.eof()) {
        f >> s;
        printf("%s, ", s.c_str());
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
