#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    fstream f("H:\\Documents\\Assignments\\empinfo.txt");
    int inIn;
    string strIn, out;
    vector<string> row;
    vector<vector<string>> data;

    while (!f.eof()) {
        getline(f, out);
        if (row.size() == 5) {
            data.push_back(row);
            row.clear();
        } else
            row.push_back(out);
    }

    printf("Type the corresponding number:\n1. Display\n2. Add\n3. Delete\n4. Mofify\n5. Save\n6. Exit\n\n> Number: ");
    cin >> inIn;
    printf("\n");

    while (inIn != 6) {
        switch (inIn) {
            case 1:
                for (int y = 0; y < data.size(); y ++) {
                    for (int x = 0; x < data[y].size(); x ++) {
                        printf("%-*s", 20, data[y][x].c_str());
                    }
                    printf("\n");
                }
                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:

                break;
        }

        printf("\n> Type the corresponding number: ");
        cin >> inIn;
        printf("\n");
    }
}

/*
1.	Create an employee information application which has a sequential file which contains the following information:
(You may use notepad or code the information)

Employee#  Employee Name		Address	Phone 			City
0128	        Brian Smithers		21 Queen st	905-522-1111		Hamilton
1008	        Holly Rathman		21 NorthSide	905-634-1212		Burlington
2009	        Scott Daniel		121 Ontario	905-643-1313		Grimsby
1109	        Peter Weber		221 Lock	905-547-1414		Hamilton

Save the file empinfo.txt

New Project
Create the following Menu

1.	Display
2.	Add
3.	Delete
4.	Mofify
5.	Save
6.	Exit


When the program starts up the file is opened and the contents are retrieved. (The file should be retrieved into an array)

When Add is selected from the menu a new employee can be added (this includes all the above information).  There should no file access at this point.

When Delete is selected from the menu an employee is selected to be removed.  The employee is then removed from the array(s).

When Modify is selected from the menu an employee is selected to their information changed and saved back into the array(s).

When Save is selected from the menu the file is re-written along with any changes to the data.

When Exit is selected from the menu the program terminates

Note: the menu should be looped until 6(Exit) is selected

Name this application Ass75
*/
