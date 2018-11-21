#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    fstream f(location + "\\empinfo.txt");
    int inIn, found;
    string strIn, out;
    vector<string> row;
    vector<vector<string>> data;
    bool newNeeded;

    while (!f.eof()) {
        getline(f, out);
        if (out == "") {
            data.push_back(row);
            row.clear();
        }
        else row.push_back(out);
    }

    printf("Type the corresponding number to select from menu:\n1. Display\n2. Add\n3. Delete\n4. Mofify\n5. Save\n6. Exit\n\nNumber: ");
    cin >> inIn;
    printf("\n");

    while (inIn != 6) {
        switch (inIn) {
            case 1:
                // display
                for (int y = 0; y < data.size(); y ++) {
                    printf("> ");
                    for (int x = 0; x < data[y].size(); x ++) {
                        printf("%-*s", 20, data[y][x].c_str());
                    }
                    printf("\n");
                }
                break;

            case 2:
                // add
                cin.ignore(256, '\n');

                newNeeded = true;
                while (newNeeded) {
                    printf("> Enter Employee #\n>> ");
                    getline(cin, strIn);

                    newNeeded = false;
                    for (int i = 0; i < data.size(); i ++) {
                        if (data[i][0] == strIn) {
                            printf("\nERROR The employee # you enter cannot match an existing entry\n\n");
                            newNeeded = true;
                        }
                    }
                }
                row.push_back(strIn);

                printf("\n> Enter Employee Name\n>> ");
                getline(cin, strIn);
                row.push_back(strIn);

                printf("\n> Enter Address\n>> ");
                getline(cin, strIn);
                row.push_back(strIn);

                printf("\n> Enter Phone #\n>> ");
                getline(cin, strIn);
                row.push_back(strIn);

                printf("\n> Enter City\n>> ");
                getline(cin, strIn);
                row.push_back(strIn);

                printf("\n> Data successfully added!\n");
                data.push_back(row);
                row.clear();
                break;

            case 3:
                // delete
                cin.ignore(256, '\n');
                printf("> Enter the Employee # of the entry you wish to delete (all entries with that employee # will be deleted)\n>> ");
                getline(cin, strIn);

                found = 0;
                for (int y = 0; y < data.size(); y ++) {
                    if (data[y][0] == strIn) {
                        data.erase(data.begin()+y);
                        found = 1;
                    }
                }

                found == 1 ? printf("\n> Entry successfully deleted!\n") : printf("\nERROR No entry matching that Employee # found\n");
                break;

            case 4:
                // modify
                cin.ignore(256, '\n');
                printf("> Enter the Employee # of the entry you wish to modify (Employee # cannot be modified)\n>> ");
                getline(cin, strIn);

                found = -1;
                for (int y = 0; y < data.size(); y ++) {
                    if (data[y][0] == strIn) {
                        found = y;
                        for (int x = 0; x < data[y].size(); x ++) {
                            row.push_back(data[y][x]);
                        }
                    }
                }

                if (found == -1) {
                    printf("\nERROR No entry matching that Employee # found\n");
                    break;
                }

                printf("\n> Entry\n>> ");
                for (int i = 0; i < row.size(); i ++) {
                    printf("%s     ", row[i].c_str());
                }

                printf("\n\n> Enter Employee Name you wish to change it to (use a space [' '] to keep the same)\n>> ");
                getline(cin, strIn);
                if (strIn != " ") row[1] = strIn;

                printf("\n> Enter Address you wish to change it to (use a space [' '] to keep the same)\n>> ");
                getline(cin, strIn);
                if (strIn != " ") row[2] = strIn;

                printf("\n> Enter Phone # you wish to change it to (use a space [' '] to keep the same)\n>> ");
                getline(cin, strIn);
                if (strIn != " ") row[3] = strIn;

                printf("\n> Enter City (use a space you wish to change it to [' '] to keep the same)\n>> ");
                getline(cin, strIn);
                if (strIn != " ") row[4] = strIn;

                printf("\n> Data successfully modified!\n");
                data[found] = row;
                row.clear();
                break;

            case 5:
                // save
                out = "";
                for (int y = 0; y < data.size(); y ++) {
                    for (int x = 0; x < data[y].size(); x ++) {
                        out += (data[y][x] + "\n");
                    }
                    if (y != data.size() - 1) out += "\n";
                }

                f.close();
                f.open(location + "\\empinfo.txt", ios::trunc | ios::out);
                f << out;
                printf("> Data successfully saved!\n");
                break;
        }

        printf("\nSelect from menu: ");
        cin >> inIn;
        printf("\n");
    }
}

/*
Employee #
Employee Name
Address
Phone
City

0128
Brian Smithers
21 Queen St
905-522-1111
Hamilton

1008
Holly Rathman
21 North Side
905-634-1212
Burlington

2009
Scott Daniel
121 Ontario
905-643-1313
Grimsby

1109
Peter Weber
221 Lock
905-547-1414
Hamilton
*/

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
