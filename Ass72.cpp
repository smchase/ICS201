#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    fstream f("\\\\HS2\\C588 Students$\\schase9914\\Documents\\Assignments\\Ass71.txt", ios::in);
    string s;
    cout << "Content of Ass71.txt:\n";
    while (!f.eof()) {
        f >> s;
        cout << s <<endl;
    }
}
