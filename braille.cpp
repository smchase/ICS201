#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

int main ()
{
    fstream f("H:\\Documents\\Assignments\\DATA21.txt");
    string out;
    vector<vector<string>> br;
    vector<string> txt;
    int n = 0;

    while (!f.eof()) {
        getline(f, out);
        cout << out << endl;
        if (n % 3 == 0) br.push_back();
        br[(int)n/3].push_back(out);
        n ++;
    }

    for (int i = 0; i < br.size(); i ++) {
        for (int j = 0; j < br[i].size(); j ++) {
            cout << br[i][j];
        }
    }
}
