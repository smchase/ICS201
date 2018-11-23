#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main ()
{
    fstream f("H:\\Documents\\Assignments\\DATA21.txt");
    string out, ltr;
    vector<string> br;
    vector<string> txt;
    string ref[26] = {
        "xooooo", // a
        "xoxooo", // b
        "xxoooo", // c
        "xxoxoo", // d
        "xooxoo", // e
        "xxxooo", // f
        "xxxxoo", // g
        "xoxxoo", // h
        "oxxooo", // i
        "oxxxoo", // j
        "xoooxo", // k
        "xoxoxo", // l
        "xxooxo", // m
        "xxoxxo", // n
        "xooxxo", // o
        "xxxoxo", // p
        "xxxxxo", // q
        "xoxxxo", // r
        "oxxoxo", // s
        "oxxxxo", // t
        "xoooxx", // u
        "xoxoxx", // v
        "oxxxox", // w
        "xxooxx", // x
        "xxoxxx", // y
        "xooxxx"  // z
    };

    while (!f.eof()) {
        getline(f, out);
        br.push_back(out);
    }

    for (int i = 0; i < br.size(); i += 3) {
        for (int j = 0; j < br[i].length(); j += 2) {
            ltr = br[i].substr(j, 2) + br[i+1].substr(j, 2) + br[i+2].substr(j, 2);
            ltr == "oooooo" ? printf(" ") : printf("%c", (char)97+distance(ref, find(ref, ref+26, ltr)));
        }
        printf("\n");
    }
}
