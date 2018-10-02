#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

bool compLen (const string &i, const string &j)
{
    return i.length() < j.length();
}

int main()
{
    string str, wordlist = "", thes = "";
    int ups = 0, lows = 0;
    vector<string> words;

    printf("Enter a sentence:\n");
    getline(cin, str);

    string currWord = "";
    for (int i = 0; i < str.length(); i ++) {
        if (isalpha(str[i]))
            currWord += str[i];

        if ((!isalpha(str[i]) || i + 1 == str.length()) && currWord.length() != 0) {
            words.push_back(currWord);
            currWord.clear();
        }

        if (isupper(str[i]))
            ups++;

        if (islower(str[i]))
            lows++;
    }

    for (int i = 0; i < words.size(); i++) {
        wordlist += words[i];

        if (i + 1 != words.size())
            wordlist += "\n";

        if (words[i].find("the") != string::npos)
            thes += (words[i] + "\n");
    }

    if (thes.length() > 3)
        if (thes.substr(thes.length() - 2, thes.length() - 1) == "\\n")
            thes.erase(thes.length() - 2, thes.length() - 1);

    if (thes == "")
        thes = "None";

    string rev = str;
    reverse(rev.begin(), rev.end());

    int puncts = count(str.begin(), str.end(), '.') + count(str.begin(), str.end(), ',') + count(str.begin(), str.end(), '?') + count(str.begin(), str.end(), '!') + count(str.begin(), str.end(), ';');

    string middle;
    (words.size() % 2 == 1) ? (middle = words[words.size() / 2]) : (middle = words[words.size() / 2 - 1] + "\n" + words[words.size() / 2]);

    vector<string> ordered = words;
    sort(ordered.begin(), ordered.end(), compLen);

    printf("\nNumber of characters:\n%i\n\nNumber of words:\n%i\n\nWords entered:\n%s\n\nSentence reversed:\n%s\n\nNumber of uppercase letters:\n%i\n\nNumber of lowercase letters:\n%i\n\nNumber of punctuation:\n%i\n\nMiddle word(s):\n%s\n\nLongest word:\n%s\n\nShortest word:\n%s\n\nWords containing 'the':\n%s\n", str.length(), words.size(), wordlist.c_str(), rev.c_str(), ups, lows, puncts, middle.c_str(), ordered[ordered.size() - 1].c_str(), ordered[0].c_str(), thes.c_str());

    /*
    * Number of characters
    * Number of words
    * Words entered
    * Sentence reversed
    * Number of uppercase letters
    * Number of lowercase letters
    * Number of punctuation (!.,;?)
    * Middle word(s)
    * Longest word
    * Shortest word
    * Words containing 'the'
    */
}
