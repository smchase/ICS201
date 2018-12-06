#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <array>
#include <math.h>
#include <algorithm>

using namespace std;

void bounce (array<string, 30> arr, int spd = 320)
{
    int first = -1;
    printf("\n");
    for (int i = 0; i < arr.size(); i ++) {
        printf("%s", arr[i].c_str());
        if (i < arr.size()-1) {
            printf("\n");
        }
        if (find(arr[i].begin(), arr[i].end(), 'O') != arr[i].end() && first == -1) {
            first = i;
        }
    }

    if (spd > 0) {
        if (first == arr.size()-3) {
            spd -= (2*spd);
            swap(arr[first+2], arr[first-1]);
            spd += first;
        } else {
            swap(arr[first], arr[first+3]);
            spd -= first;
        }
    } else {
        if (first == 0) {
            spd += (2*abs(spd));
            swap(arr[first], arr[first+3]);
            spd -= first;
        } else {
            swap(arr[first+2], arr[first-1]);
            spd += first;
        }
    }

    Sleep(abs(spd));
    bounce(arr, spd);
}

int main ()
{
    array<string, 30> arr =
    {
        "                  OOOO                  ",
        "                  OOOO                  ",
        "                  OOOO                  ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        ",
        "                                        "
    };
    bounce(arr);
}
