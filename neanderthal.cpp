// 41: 99s
// 42: 58s

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

void solve (vector<vector<w>> &w, int &n, int p, int l)
{
    if (p == l) n ++;
    else {
        for (int i = 0; i <= w[p].size(); i ++) {
            solve(w, n, w[p][i].pos[1], l);
        }
    }
}

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    // load tests
    fstream file(location + "\\DATA41.txt");
    string out;
    vector<string> tests;
    while (file >> out) tests.push_back(out);

    // find all working words and add them to array
    string arr[10] = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};
    vector<vector<vector<w>>> words;
    vector<vector<w>> words1;
    vector<w> words2;
    for (int i = 0; i < tests.size(); i ++) {
        printf("%s ", tests[i].c_str());
        for (int j = 0; j < tests[i].length(); j ++) {
            for (int k = 2; k <= (tests[i].length()-j < 8 ? tests[i].length()-j : 8); k ++) {
                if (find(arr, arr+10, tests[i].substr(j, k)) != arr+10) words2.push_back({tests[i].substr(j, k), {j, j+k}});
            }
            words1.push_back(words2);
            words2.clear();
        }
        words.push_back(words1);
        words1.clear();
    }
    printf("\n");

    for (int i = 0; i < words.size(); i ++) {
        for (int j = 0; j < words[i].size(); j ++) {
            for (int k = 0; k < words[i][j].size(); k ++) {
                printf("Word: %s, Start: %i, End: %i, [%i][%i][%i]\n", words[i][j][k].word.c_str(), words[i][j][k].pos[0], words[i][j][k].pos[1], i, j, k);
            }
        }
        cout << endl;
    }

    // use recursion to find all working sequences of words
    int num = 0;
    for (int i = 0; i < words.size(); i ++) {
        num = 0;
        solve(words[i], num, 0, tests[i].size());
        printf("%i ", num);
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
