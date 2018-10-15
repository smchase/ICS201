#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string holdName, holdAdd, holdCity, holdState, headers[4] = {"Name", "Address", "City", "State"}, a[8] = {"Bantam Books", "ETN Corporation", "Benjamin/Cummings", "Intertext", "Addison Wesley", "Brady Pub", "Gale", "ACM"}, b[8] = {"666 Fifth Ave", "Rd 4, Box 659", "390 Bridge Pkwy", "2633 E.17th Ave", "Rte 128", "15 Columbus Cir", "835 Penobscot", "11W. 42nd St."}, c[8] = {"New York", "Detroit", "Redwood", "New York", "Reading", "New York", "Redwood", "New York"}, d[8] = {"NY", "MI", "CA", "NY", "MA", "NY", "CA", "NY"};

    vector<string> names(&a[0], &a[0]+8), addresses(&b[0], &b[0]+8), cities(&c[0], &c[0]+8), states(&d[0], &d[0]+8);

    char input;
    printf("To select an item from the menu enter its corrosponding letter\na: Display all Information\nb: Display information for New York only\nc: Add Information\nd: Sort the information according to the name in ascending order\ne: Exit\n\nLetter: ");
    cin >> input;
    printf("\n");

    while (input != 'e') {
        switch (input) {
        case 'a':
            for (int i = 0; i < 4; i ++)
                printf("%-*s", 15, headers[i].c_str());
            break;

        case 'b':

            break;

        case 'c':

            break;

        case 'd':
            for (int i = 0; i < names.size() - 1; i ++) {
                for (int j = 0; j < names.size() - 1; j ++) {
                    if (names[j] > names[j + 1]) {

                    }
                }
            }
            break;
        }

        printf("\n\nTo select an item from the menu enter its corresponding letter: ");
        cin >> input;
        printf("\n");
    }
}

/* Arrays/Functions/Sorting
1.	Store the following information into 4 arrays using assignment statements
Name 			Address 		City 		State
Bantam Books 		666 Fifth Ave 		New York	 NY
ETN Corporation 		Rd 4, Box 659 		Detroit 		MI
Benjamin/Cummings 	390 Bridge Pkwy 	Redwood 	CA
Intertext 			2633 E.17th Ave 	New York 	NY
Addison Wesley 		Rte 128 		Reading 	MA
Brady Pub 			15 Columbus Cir 	New York 	NY
Gale 			835 Penobscot 		Redwood 	CA
ACM 			11W. 42nd St. 		New York 	NY

Create a menu based program, which will perform the following and display the results to the screen.
•	Display all Information
•	Display information for New York only
•	Add Information (Adds a name, address, city, and state to the list)
•	Sort the information according to the name in ascending order
•	Exit

Name the program Ass67
*/
