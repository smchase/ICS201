#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compLen (int i, int j)
{
    return i < j;
}

int main()
{
    srand (time(NULL));
    vector<int> temps;
    for (int i = 0; i < 30; i++)
        temps.push_back(5 + rand() % 21);

    vector<int> sorted = temps;
    sort(sorted.begin(), sorted.end(), compLen);

    char page;
    printf("Enter the corresponding letter for what you want\na: Display all the temperatures\nb: Display the highest temperature\nc: Display the lowest temperature\nd: Display the average temperature\ne: Sort the temperatures in ascending order\nf: Sort the temperatures in descending order\ng: Quit\n\n");
    printf("Letter: ");
    cin >> page;

    int total;
    while (page != 'g') {
        printf("\n");
        switch (page) {
            case 'a':
                printf("All the temperatures:\n");
                for (int i = 0; i < temps.size() - 1; i++)
                    printf("%i, ", temps[i]);
                printf("%i", temps[temps.size() - 1]);
                break;

            case 'b':
                printf("Highest temperature: %i", sorted[sorted.size() - 1]);
                break;

            case 'c':
                printf("Lowest temperature: %i", sorted[0]);
                break;

            case 'd':
                total = 0;
                for (int i = 0; i < temps.size() - 1; i++)
                    total += temps[i];
                printf("Average temperature: %.2f", float(total)/temps.size());
                break;

            case 'e':
                printf("All the temperatures sorted low to high:\n");
                for (int i = 0; i < sorted.size() - 1; i++)
                    printf("%i, ", sorted[i]);
                printf("%i", sorted[sorted.size() - 1]);
                break;

            case 'f':
                printf("All the temperatures sorted high to low:\n");
                for (int i = sorted.size() - 1; i > 0; i--)
                    printf("%i, ", sorted[i]);
                printf("%i", sorted[0]);
                break;
        }

        printf("\n\nLetter: ");
        cin >> page;
    }
}

/*
1. Create a program, which stores 30 temperatures (you can make up the temperatures or randomly generate them)
for a month into an array. Create a menu based program to perform the following:

a) Display the entire array
b) Display the highest temperature (Your program should determine this)
c) Display the lowest temperature
d) Display the average temperature
e) Sort the temperatures in ascending order
f) Sort the temperatures in descending order
g) Quit

Name the program Ass65
*/
