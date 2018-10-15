#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    string names[6] = {"Tulips", "Orchids", "Mixed Stems", "Baby Roses", "Cactus Plants", "Red Roses"}, holdName, headers[4] = {"Name", "Unit Price", "Quantity Sold", "Total Sales"};
    float prices[6] = {15.50, 27.00, 3.95, 18.50, 7.65, 19.00}, holdPrice;
    int sold[6] = {12, 7, 35, 15, 18, 21}, holdSold, place;
    float total[6], holdTotal, big = 0, small = 10000;
    char input;

    for (int i = 0; i < 6; i ++)
        total[i] = prices[i] * sold[i];

    printf("To select an item from the menu enter its corresponding letter\na: View all of the data sorted by total sales (descending)\nb: View all of the data sorted by name (ascending)\nc: View the name of the highest quantity sold\nd: View the name of the lowest quantity sold\ne: Exit\n\nLetter: ");
    cin >> input;
    printf("\n");

    while (input != 'e') {
        switch (input) {
            case 'a':
                for (int i = 0; i < 4; i ++)
                    printf("%-*s", 15, headers[i].c_str());

                for (int j = 0; j < 5; j ++) {
                    for (int i = 0; i < 5; i ++) {
                        if (total[i] < total[i + 1]) {
                            holdName = names[i];
                            holdPrice = prices[i];
                            holdSold = sold[i];
                            holdTotal = total[i];

                            names[i] = names[i + 1];
                            prices[i] = prices[i + 1];
                            sold[i] = sold[i + 1];
                            total[i] = total[i + 1];

                            names[i + 1] = holdName;
                            prices[i + 1] = holdPrice;
                            sold[i + 1] = holdSold;
                            total[i + 1] = holdTotal;
                        }
                    }
                }

                for (int n = 0; n < 6; n ++) {
                    printf("\n");
                    for (int i = 0; i < 4; i ++) {
                        switch (i) {
                            case 0:
                                printf("%-*s", 15, names[n].c_str());
                                break;
                            case 1:
                                printf("$%-*.2f", 14, prices[n]);
                                break;
                            case 2:
                                printf("%-*i", 15, sold[n]);
                                break;
                            case 3:
                                printf("$%.2f", total[n]);
                                break;
                        }
                    }
                }
                break;

            case 'b':
                for (int i = 0; i < 4; i ++)
                    printf("%-*s", 15, headers[i].c_str());

                for (int j = 0; j < 5; j ++) {
                    for (int i = 0; i < 5; i ++) {
                        if (names[i] > names[i + 1]) {
                            holdName = names[i];
                            holdPrice = prices[i];
                            holdSold = sold[i];
                            holdTotal = total[i];

                            names[i] = names[i + 1];
                            prices[i] = prices[i + 1];
                            sold[i] = sold[i + 1];
                            total[i] = total[i + 1];

                            names[i + 1] = holdName;
                            prices[i + 1] = holdPrice;
                            sold[i + 1] = holdSold;
                            total[i + 1] = holdTotal;
                        }
                    }
                }

                for (int n = 0; n < 6; n ++) {
                    printf("\n");
                    for (int i = 0; i < 4; i ++) {
                        switch (i) {
                            case 0:
                                printf("%-*s", 15, names[n].c_str());
                                break;
                            case 1:
                                printf("$%-*.2f", 14, prices[n]);
                                break;
                            case 2:
                                printf("%-*i", 15, sold[n]);
                                break;
                            case 3:
                                printf("$%.2f", total[n]);
                                break;
                        }
                    }
                }
                break;

            case 'c':
                for (int i = 0; i < 6; i ++) {
                    if (total[i] > big) {
                        big = total[i];
                        place = i;
                    }
                }

                printf("%s has the most total sales", names[place].c_str());
                break;

            case 'd':
                for (int i = 0; i < 6; i ++) {
                    if (total[i] < small) {
                        small = total[i];
                        place = i;
                    }
                }

                printf("%s has the least total sales", names[place].c_str());
                break;
        }

        printf("\n\nTo select an item from the menu enter its corresponding letter: ");
        cin >> input;
        printf("\n");
    }
}

/*
Create a program, which stores the following information into arrays and calculates the total sales.

Name 			Unit Price		Quantity  Sold 		Total Sales
Tulips 			15.50 			12
Orchids 		27.00 			7
Mixed Stems 	3.95 			35
Baby Roses		18.50 			15
Cactus Plants 	7.65 			18
Red Roses 		19.00 			21

Create menu based program to perform the following:
a) Sort and display the information according to the Total Sales (Descending order)
b) Sort and display the information according to the Name (Ascending order)
c) Display the Name of the highest quantity sold
d) Display the Name of the lowest quantity sold


Name the program Ass66
*/
