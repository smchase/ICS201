#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>

using namespace std;

void showRaise (int p[6][3], int n[6][3], float r)
{
    float total = 0, ogTotal = 0;
    string arr[6] = {"Y 0  ", "E 1  ", "A 2  ", "R 3  ", "S 4  ", "  5+ "};
    printf("     Rank\n     Lieutenant  Sergeant    Constable\n");
    for (int y = 0; y < 6; y ++) {
        printf("%s", arr[y].c_str());
        for (int x = 0; x < 3; x ++) {
            printf("%-*g", 12, (float)p[y][x] * r);
            total += (float)p[y][x] * r * (float)n[y][x];
            ogTotal += (float)p[y][x] * (float)n[y][x];
        }
        printf("\n");
    }
    printf("\nTotal Pay : $%#.2f (+ $%#.2f)\n\n\n\n", total, total - ogTotal);
}

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    fstream f(location + "\\police.txt");
    int pay[6][3], num[6][3], yPos = 0, xPos = 0;
    string out, n;
    bool isPay = true;

    while (!f.eof()) {
        getline(f, out);

        if (out == "") {
            isPay = false;
            yPos = 0;
        } else {
            n = "";
            for (int x = 0; x < out.length(); x ++) {
                if (out[x] != ' ') n += out[x];
                if (out[x] == ' ' || x == out.length() - 1) {
                    isPay ? pay[yPos][xPos] = atoi(n.c_str()) : num[yPos][xPos] = atoi(n.c_str());
                    n = "";
                    xPos ++;
                }
            }
            xPos = 0;
            yPos ++;
        }
    }

    printf("Original Pay ($)\n\n");
    showRaise (pay, num, 1);

    printf("Pay with 1.5%% Raise ($)\n\n");
    showRaise (pay, num, 1.015);

    printf("Pay with 2.5%% Raise ($)\n\n");
    showRaise (pay, num, 1.025);

    printf("Pay with 4%% Raise ($)\n\n");
    showRaise (pay, num, 1.04);
}

/*
Write a program that reads the police salary grid into a two-dimensional array from a data file you have prepared. Negotiators have asked you to project new pay grids based on various increases. Use 1.5%, 2.5%, and 4% increases in pay as your test data. Calculate the new pay increases across the pay grid. Output the original grid and the new grids with pay increases. The grid below is used to pay police officers:
Police Pay Schedule
		Rank
		Lieutenant	Sergeant	Constable
	0	30000	28750	26500
Y	1	32000	30540	28750
E	2	34000	32400	29900
A	3	37300	34100	31200
R	4	39100	36200	33300
S	5+	40000	38000	35000


The police Commission is also concerned with the cost of the raise in pay. The following is a table indicating how many employees are in each category.
Number of Employees in Each Category
		Constable	Sergeant	Lieutenant
	0	89	90	55
Y	1	90	36	47
E	2	45	23	20
A	3	73	41	42
R	4	91	62	33
S	5+	12	80	52
Find the total cost to the Police Commission if any of the above pay increases was granted. Display your results in an appropriate format.


Name this application Ass77
*/
