#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct w {
    string word;
    int pos[2];
};

void solve (vector<w> &w, vector<vector<int>> &c)
{

}

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    fstream file(location + "\\DATA41.txt");
    string out;
    vector<string> tests;
    while (file >> out) tests.push_back(out);

    string arr[10] = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};
    vector<w> preWords;
    vector<vector<w>> words;
    for (int i = 0; i < tests.size(); i ++) {
        printf("%s ", tests[i].c_str());
        for (int j = 0; j < tests[i].length(); j ++) {
            for (int k = 2; k <= tests[i].length()-j; k ++) {
                if (find(arr, arr+10, tests[i].substr(j, k)) != arr+10) preWords.push_back({tests[i].substr(j, k), {j, j+k}});
            }
        }
        words.push_back(preWords);
        preWords.clear();
    }
    printf("\n");

    /*for (int i = 0; i < words.size(); i ++) {
        for (int j = 0; j < words[i].size(); j ++) {
            printf("Word: %s, Start: %i, End: %i, Test: %i\n", words[i][j].word.c_str(), words[i][j].pos[0], words[i][j].pos[1], i);
        }
        printf("\n");
    }*/

    vector<vector<int>> counted;
    for (int i = 0; i < words.size(); i ++) {
        counted.clear();
        solve(words[i], counted);
        printf("%i ", counted.size());
    }
    printf("\n");
}

/*
1 ook
2 ookook
3 oog
4 ooga
5 ug
6 mook
7 mookmook
8 oogam
9 oogum
10 ugug

DATA41.txt (DATA42.txt for the second try) will contain 10 test cases. Each test case consists of a single line of text with N (1 ≤ N ≤ 50) Neanderthal number words. The words are not separated by spaces. You must parse each line and print out (on a single line) the number of possible sequences of Neanderthal numbers that can be represented by a Neanderthal person speaking the words aloud (for example the string “oogamookoogumook” could be “ooga mook oogum ook” meaning “4 6 9 1” or “oogam ook oogum ook” meaning “8 1 9 1”.  Note that the sample input below only contains 2 test cases, but the real data files will contain 10.

Sample Input	 ookookook oogamookoogumook
Sample Output	 3 2
*/
