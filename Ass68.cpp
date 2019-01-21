#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

bool comp (string i, string j)
{
    return i < j;
}

int main()
{
    string strIn, a[13] = {"Ageloff", "Anderson", "Biegel", "Biow", "Bisland", "Arnott", "Arnston", "Ault", "Avison", "Bard", "Bowman", "Adams", "Adrian"};
    vector<string> n(&a[0], &a[0]+13);
    char chIn;
    bool res = false;

    printf("To select an item from the menu enter its corrosponding letter\na: Display all the names\nb: Display names which begin with the letter A\nc: Display names which begin with the letter B\nd: Search for a specific name (Displays names which match the one entered by the user)\ne: Partial search (Displays names which contain letters entered by the user)\nf: Sort the names in descending order\ng: Exit\n\nLetter: ");
    cin >> chIn;
    printf("\n");

    while (chIn != 'g') {
        switch (chIn) {
        case 'a':
            printf("> Names:");
            for (int i = 0; i < n.size(); i ++)
                printf("\n>> %s", n[i].c_str());
            break;

        case 'b':
            printf("> Names:");
            for (int i = 0; i < n.size(); i ++) {
                if (n[i][0] == 'A' || n[i][0] == 'a')
                    printf("\n>> %s", n[i].c_str());
            }
            break;

        case 'c':
            printf("> Names:");
            for (int i = 0; i < n.size(); i ++) {
                if (n[i][0] == 'B' || n[i][0] == 'b')
                    printf("\n>> %s", n[i].c_str());
            }
            break;

        case 'd':
            printf("> Search: ");
            cin.ignore(256, '\n');
            getline(cin, strIn);

            printf(">> Results:");
            if (count(n.begin(), n.end(), strIn) != 0)
                for (int i = 0; i < n.size(); i ++) {
                    if (n[i] == strIn)
                        printf("\n>>> %s", n[i].c_str());
                }
            else
                printf("\n>>> No matches were found");
            break;

        case 'e':
            printf("> Search: ");
            cin.ignore(256, '\n');
            getline(cin, strIn);

            res = false;
            printf(">> Results:");
            for (int i = 0; i < n.size(); i ++) {
                if (n[i].find(strIn) != -1) {
                    printf("\n>>> %s", n[i].c_str());
                    res = true;
                }
            }

            if (!res)
                printf("\n>>> No matches were found");
            break;

        case 'f':
            sort(n.begin(), n.end(), comp);
            printf("> Sorted!");
            break;
        }

        printf("\n\nTo select an item from the menu enter its corrosponding letter: ");
        cin >> chIn;
        printf("\n");
    }
}

/*
2.	Store the following names into an array (Use assignment statements)
Ageloff
Anderson
Biegel
Biow
Bisland
Arnott
Arnston
Ault
Avison
Bard
Bowman
Adams
Adrian
Create a menu based program, which will perform and display the following to the screen:
�	Display all the names
�	Display names which begin with the letter A
�	Display names which begin with the letter B
�	Search for a specific name (Displays names which match the one entered by the user)
�	Partial search (Displays names which contain letters entered by the user)
�	Sort the names in descending order
�	Exit
*/
