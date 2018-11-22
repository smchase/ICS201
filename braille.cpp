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
    string out, ltr[3];
    vector<string> br;
    vector<string> txt;
    string ref[26][3] = {
        { // a
            "xo",
            "oo",
            "oo"
        },
        { // b
            "xo",
            "xo",
            "oo"
        },
        { // c
            "xx",
            "oo",
            "oo"
        },
        { // d
            "xx",
            "ox",
            "oo"
        },
        { // e
            "xo",
            "ox",
            "oo"
        },
        { // f
            "xx",
            "xo",
            "oo"
        },
        { // g
            "xx",
            "xx",
            "oo"
        },
        { // h
            "xo",
            "xx",
            "oo"
        },
        { // i
            "ox",
            "xo",
            "oo"
        },
        { // j
            "ox",
            "xx",
            "oo"
        },
        { // k
            "xo",
            "oo",
            "xo"
        },
        { // l
            "xo",
            "xo",
            "xo"
        },
        { // m
            "xx",
            "oo",
            "xo"
        },
        { // n
            "xx",
            "ox",
            "xo"
        },
        { // o
            "xo",
            "ox",
            "xo"
        },
        { // p
            "xx",
            "xo",
            "xo"
        },
        { // q
            "xx",
            "xx",
            "xo"
        },
        { // r
            "xo",
            "xx",
            "xo"
        },
        { // s
            "ox",
            "xo",
            "xo"
        },
        { // t
            "ox",
            "xx",
            "xo"
        },
        { // u
            "xo",
            "oo",
            "xx"
        },
        { // v
            "xo",
            "xo",
            "xx"
        },
        { // w
            "ox",
            "xx",
            "ox"
        },
        { // x
            "xx",
            "oo",
            "xx"
        },
        { // y
            "xx",
            "ox",
            "xx"
        },
        { // z
            "xo",
            "ox",
            "xx"
        }
    };

    while (!f.eof()) {
        getline(f, out);
        br.push_back(out);
    }

    for (int i = 0; i < br.size(); i += 3) {
        for (int j = 0; j < br[i].length(); j += 2) {
            ltr[0] = br[i].substr(j, 2);
            ltr[1] = br[i].substr(j+1, 2);
            ltr[2] = br[i].substr(j+2, 2);

            printf("%i\n", distance(ref, find(ref, ref+26, ltr)));
        }
    }
}
