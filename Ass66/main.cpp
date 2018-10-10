#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    srand (time(NULL));
    string names[6] = {"Tulips", "Orchids", "Mixed Stems", "Baby Roses", "Cactus Plants", "Red Roses"};
    float prices[6] = {15.50, 27.00, 3.95, 18.50, 7.65, 19.00};
    float sold[6] = {12, 7, 35, 15, 18, 21};
    float total[6];

    for (int i = 0; i < 6; i ++)
        total[i] = prices[i] * sold[i];

    string headers[4] = {"Name", "Unit Price", "Quantity Sold", "Total Sales"};
    for (int i = 0; i < 4; i ++) {
        printf("%-*s", 15, headers[i].c_str());
        for (int n = 0; n < 6; n ++) {

        }
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
