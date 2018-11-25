#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

using namespace std;

int main ()
{
    ifstream f("H:\\Documents\\Assignments\\Ass74.txt");
    int n, mean = 0, i = 0, arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("The numbers are: ");
    while (!f.eof()) {
        f >> n;
        printf("%i ", n);
        mean += n;
        i ++;
        arr[n] ++;
    }
    printf("\n");

    vector<int> mode;
    int freq = -1;
    for (int j = 0; j < 10; j ++) {
        if (arr[j] > freq) {
            mode.clear();
            mode.push_back(j);
            freq = arr[j];
        } else if (arr[j] == freq) {
            mode.push_back(j);
        }
    }

    printf("\nThe mean is: %g\nThe mode is: ", ((float)mean / (float)i));
    for (int j = 0; j < mode.size(); j ++) {
        printf("%i ", mode[j]);
    }
    printf("\n");
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
