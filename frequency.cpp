#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

bool srt (int i, int j) { return (i < j); }

int main ()
{
    fstream f("H:\\Documents\\Assignments\\DATA11.txt");
    string out, s;
    vector<char> l;
    int n = 0;

    while (!f.eof()) {
        s = "";
        n = 0;
        l.clear();
        getline(f, out);
        if (out != "") {
            for (int i = 0; i < out.length(); i ++) {
                if (tolower(out[i]) >= 97 && tolower(out[i]) <= 122) {
                    s += (char)tolower(out[i]);
                }
            }

            for (int i = 97; i <= 122; i ++) {
                if (count(s.begin(), s.end(), (char)i) > n) {
                    l.clear();
                    n = count(s.begin(), s.end(), (char)i);
                    l.push_back((char)i);
                }
                else if (count(s.begin(), s.end(), (char)i) == n) l.push_back((char)i);
            }

            if (l.size() == 1) printf("%c occur(s) %i times.\n", toupper(l[0]), n);
            else {
                sort(l.begin(), l.end(), srt);
                for (int i = 0; i < l.size()-2; i ++) {
                    printf("%c, ", toupper(l[i]));
                }
                printf("%c and %c %s occur %i time(s).\n", toupper(l[l.size()-2]), toupper(l[l.size()-1]), l.size() == 2 ? "both" : "all", n);
            }
        }
    }
}
