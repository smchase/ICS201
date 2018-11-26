#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

struct w {

} vector

int main ()
{
    // School: H:\\Documents\\Assignments
    // Home: C:\\Users\\dumba\\OneDrive\\Documents\\GitHub\\Assignments
    string location = "H:\\Documents\\Assignments";

    fstream file(location + "\\DATA41.txt");
    string out;
    vector<string> tests;
    while (file >> out) tests.push_back(out);

    vector<
    for (int i = 0; i < tests.size(); i ++) {
        cout << tests[i] << endl;
    }
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
