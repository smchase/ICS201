#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main ()
{
    fstream f("H:\\Documents\\Assignments\\Ass73.txt", ios::in);
    string s;
    int lines = 0, chars = 0, words = 0;

    printf("File contents:\n");
    while (!f.eof()) {
        getline(f, s);
        lines ++;
        chars += s.length();
        words += count(s.begin(), s.end(), ' ') + 1;
        printf("> %s\n", s.c_str());
    }

    printf("\nNumber of lines read: %i\nMumber of characters: %i\nNumber of words: %i\n", lines, chars, words);
}

/*
Create a file which contains the multiple lines of text.  Create a program which reads the file, displays it and displays how many lines were read, the number of characters in the file and the number of words in the file. Name this application Ass73

File Contents:
This is an example of
a file which has multiple
lines to read from it

Number of lines read: 3
Number of characters: 67
Number of words: 15
*/
