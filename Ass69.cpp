#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string data[9][4] = {
        {"Name", "Address", "City", "State"},
        {"Bantam Books", "666 Fifth Ave", "New York", "NY"},
        {"ETN Corporation", "Rd 4, Box 659", "Detroit", "MI"},
        {"Benjamin/Cummings", "390 Bridge Pkwy", "Redwood", "CA"},
        {"Intertext", "2633 E.17th Ave", "New York", "NY"},
        {"Addison Wesley", "Rte 128", "Reading", "MA"},
        {"Brady Pub", "15 Columbus Cir", "New York", "NY"},
        {"Gale", "835 Penobscot", "Redwood", "CA"},
        {"ACM", "11W. 42nd St.", "New York", "NY"}
    };

    printf("All data:\n");
    for (int col = 0; col < 9; col ++) {
        for (int row = 0; row < 4; row ++)
            printf("%-*s", 20, data[col][row].c_str());
        printf("\n");
    }

    printf("\nData from New York:\n");

    for (int col = 0; col < 9; col ++) {
        if (data[col][2] == "New York") {
            for (int row = 0; row < 4; row ++)
                printf("%-*s", 20, data[col][row].c_str());
            printf("\n");
        }
    }
}

/*
3.	 Store the following information into one two Dimensional array using assignment statements.
Name 			Address 		City 		State
Bantam Books 		666 Fifth Ave 		New York	 NY
ETN Corporation 		Rd 4, Box 659 		Detroit 		MI
Benjamin/Cummings 	390 Bridge Pkwy 	Redwood 	CA
Intertext 			2633 E.17th Ave 	New York 	NY
Addison Wesley 		Rte 128 		Reading 	MA
Brady Pub 			15 Columbus Cir 	New York 	NY
Gale 			835 Penobscot 		Redwood 	CA
ACM 			11W. 42nd St. 		New York 	NY

Create a program, which will perform the following and display the results to the screen.
•	Display all Information
•	Display information for New York only
*/
