#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    fstream f("H:\\Documents\\Assignments\\precip.txt");
    string p[7][5], out, d, e;
    int xPos = 0, yPos = 0;
    float a = 0, b = 0, c = 0, june[4], london[6];

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

    printf("Avg Weekly Precipitation (cm)\n");
    for (int y = 0; y < 7; y ++) {
        for (int x = 0; x < 5; x ++) {
            printf("%-*s", 10, p[y][x].c_str());
            if (x == 3 && y != 0) a += atof(p[y][x].c_str());
            if (y == 4 && x != 0) b += atof(p[y][x].c_str());
            c += atof(p[y][x].c_str());
            if (y == 6 && x != 0) june[x - 1] = atof(p[y][x].c_str());
            if (x == 1 && y != 0) london[y - 1] = atof(p[y][x].c_str());
        }
        printf("\n");
    }

    float big = 0;
    for (int i = 0; i < 4; i ++) {
        if (june[i] > big) {
            big = june[i];
            d = (i == 0 ? "London" : (i == 1 ? "Kingston" : (i == 2 ? "North Bay" : "Dryden")));
        }
    }

    int small = 100;
    for (int i = 0; i < 6; i ++) {
        if (london[i] < small) {
            small = london[i];
            e = (i == 0 ? "January" : (i == 1 ? "Febuary" : (i == 2 ? "March" : (i == 3 ? "April" : (i == 4 ? "May" : "June")))));
        }
    }

    printf("\nAverage weekly precipitation for North Bay: %g\nAverage precipitation for April: %g\nTotal precipitation for all areas for the first 6 months of the year: %g\nCity with the largest precipitation for June: %s\nMonth with the smallest precipitation in London: %s\n", a / 6,  b / 4, c * 4, d.c_str(), e.c_str());
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
