#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    fstream f(location + "\\police.txt");
    int pay[6][3], num[6][3], y = 0;
    string out, n;
    bool isPay = true;

    while (!f.eof()) {
        getline(f, out);

        if (out == "") {
            isPay = false;
            y = 0;
        } else {
            n = "";
            for (int x = 0; x < out.length(); x ++) {
                if (out[x] != ' ') n += out[x];
                else {
                    isPay ? pay[y][x] = atoi(n.c_str()) : num[y][x] = atoi(n.c_str());
                    n = "";
                }
            }
            y ++;
        }
    }
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
