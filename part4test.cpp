#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
    string s;
    printf("Enter a sentence:\n");
    getline(cin, s);

    string rs = s.substr(0, s.find(" "));
    int fwascii[rs.length()];
    for (int i = 0; i < rs.length(); i ++) {
        fwascii[i] = (int)rs[i];
    }
    reverse(rs.begin(), rs.end());

    printf("\nCharacter count:\n%i\n\nWord count:\n%i\n\nFirst word reversed:\n%s\n\nASCII numbers of first word:\n", s.length(), count(s.begin(), s.end(), ' ') + 1, rs.c_str());

    for (int i = 0; i < rs.length(); i ++) {
        printf("%i ", fwascii[i]);
    }

    string lower = "";
    for (int i = 0; i < s.length(); i ++) {
        lower += tolower(s[i]);
    }

    printf("\n\nFirst two letters of second word:\n%s\n\nSentence in lowercase:\n%s\n\nContains 'this':\n%s\n", s.substr(s.find(" ") + 1, 2).c_str(), lower.c_str(), s.find("this") != -1 ? "Yes" : "No");
}
