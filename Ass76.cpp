#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    fstream f("H:\\Documents\\Assignments\\precip.txt");
    string p[7][5], out;
    int xPos = 0, yPos = 0;

    while (!f.eof()) {
        getline(f, out);
        if (out == "") {
            xPos = 0;
            yPos ++;
        } else {
            p[yPos][xPos] = out;
            xPos ++;
        }
    }

    printf("Precipitation (cm)\n");
    for (int y = 0; y < 7; y ++) {
        for (int x = 0; x < 5; x ++) {
            printf("%-*s", 10, p[y][x].c_str());
        }
        printf("\n");
    }

    printf("\nAverage weekly precipitation for North Bay: %g\nAverage precipitation for April: %g\nTotal precipitation for all areas for the first 6 months of the year: %g\nCity with the largest precipitation for June: %g\nMonth with the smallest precipitation in London: %g\n", (float)(atoi(p[1][3].c_str()) + atoi(p[2][3].c_str()) + atoi(p[3][3].c_str()) + atoi(p[4][3].c_str()) + atoi(p[5][3].c_str()) + atoi(p[6][3].c_str()) / 6));
}

/*
1.	This table contains the average weekly precipitation for four Ontario Cities.
	Precipitation (cm)
Month	London	Kingston	North Bay	Dryden
January	12.4	13.5	12.1	12.6
February	8.2	9.5	8.0	7.5
March	14.9	13.5	12.9	15.3
April	30.0	35.5	40.2	37.7
May	24.5	26.1	23.4	24.0
June	30.3	4.6	11.4	21.6

a)	Create a data file, containing the above data.
b)	Declare the two-dimensional array for the above data called PRECIPITATION.
c)	Read the data from the data file into the array PRECIPITATION.
d)	Display the precipitation data to the screen.
e)	Calculate and display:
a.	the average weekly precipitation for North Bay;
b.	the average precipitation for April;
c.	the total precipitation for all areas for the first six months of the year;
d.	the city with the largest precipitation for June;
e.	the month with the smallest precipitation in London.
*/
