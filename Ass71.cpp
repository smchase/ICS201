#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    fstream f("\\\\HS2\\C588 Students$\\schase9914\\Documents\\Assignments\\Ass71.txt", ios::out | ios::trunc);
    string s;
    cout << "Input: ";
    getline(cin, s);
    f << s;
}
