#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>

using namespace std;

void DisplayTip (int r)
{
    string tips[4] = {"Do not expose diskettes to extreme cold or heat", "Keep away from electrical or magnetic devices", "Store away from dust, dirt, or moisture", "Never touch the magnetic surface"};

    printf("%s\n", tips[r].c_str());
}

int main()
{
    srand (time(NULL));
    int ranNum = rand() % 4;

    DisplayTip(ranNum);
}
