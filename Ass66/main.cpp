#include <iostream>
using namespace std;

int main()
{
    int age[] = {23,16,18,12,35,42};
    string name[] = {"Dave","Mary","Cathy","Peter","John","Kim"};
    int holdAge=0;
    string holdName="";

    for(int intC=0;intC<6;intC++){
        for(int intCtr=0;intCtr<5;intCtr++){
             if(age[intCtr]>age[intCtr+1]){ //Ascending 1-10, A-Z
                holdAge=age[intCtr];
                age[intCtr]=age[intCtr+1];
                age[intCtr+1]=holdAge;

                holdName=name[intCtr];
                name[intCtr]=name[intCtr+1];
                name[intCtr+1]=holdName;
             }
        }
    }

    cout<<"List(Sorted)- According to Age"<<endl;
    for(int intC=0; intC<6;intC++){
        cout<<name[intC]<<"\t"<<age[intC]<<endl;
    }
return 0;
}


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct data
{
    string names[6];
    float prices[6];
    int sold[6];
    float total[6];
} ;

int main()
{
    srand (time(NULL));
    string names[6] = {"Tulips", "Orchids", "Mixed Stems", "Baby Roses", "Cactus Plants", "Red Roses"};
    float prices[6] = {15.50, 27.00, 3.95, 18.50, 7.65, 19.00};
    int sold[6] = {12, 7, 35, 15, 18, 21};
    float total[6];

    for (int i = 0; i < 6; i ++)
        total[i] = prices[i] * sold[i];

    string headers[4] = {"Name", "Unit Price", "Quantity Sold", "Total Sales"};
    for (int i = 0; i < 4; i ++) {
        printf("%-*s", 15, headers[i].c_str());
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
