#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main ()
{
    fstream f("H:\\Documents\\Assignments\\DATA11.txt");
    string out, s;
    char l

    while (!f.eof()) {
        s = "";
        getline(f, out);
        if (out != "") {
            for (int i = 0; i < out.length(); i ++) {
                if (tolower(out[i]) >= 97 && tolower(out[i]) <= 122) {
                    s += (char)tolower(out[i]);
                }
            }

            for (int i = 97; i <= 122; i ++) {
                cout << count(s.begin(), s.end(), (char)i);
            }
            cout << endl;
        }
    }
}
