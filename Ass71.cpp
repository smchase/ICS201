#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    fstream f("H:\\Documents\\Assignments\\Ass71.txt", ios::out | ios::trunc);
    string s;
    cout << "Input: ";
    getline(cin, s);
    f << s;
    f.close();
}
