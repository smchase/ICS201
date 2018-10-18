#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string strIn, a[13] = {"Ageloff", "Anderson", "Biegel", "Biow", "Bisland", "Arnott", "Arnston", "Ault", "Avison", "Bard", "Bowman", "Adams", "Adrian"};
    vector<string> n(&a[0], &a[0]+13);
    char chIn;

    printf("To select an item from the menu enter its corrosponding letter\na: Display all the names\nb: Display names which begin with the letter A\nc: Display names which begin with the letter B\nd: Search for a specific name (Displays names which match the one entered by the user)\ne: Partial search (Displays names which contain letters entered by the user)\nf: Sort the names in descending order\ng: Exit\n\nLetter: ");
    cin >> chIn;

    while (chIn != 'g') {
        switch (chIn) {
        case 'a':
            for (int i = 0; i < n.size(); i ++) {
                
            }
            break;

        case 'b':

            break;

        case 'c':

            break;

        case 'd':

            break;

        case 'e':

            break;

        case 'f':

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
