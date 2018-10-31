#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    fstream f("H:\\Documents\\Assignments\\Ass71.txt", ios::in);
    string s;
    cout << "Content of Ass71.txt:\n";
    while (!f.eof()) {
        f >> s;
        cout << s <<endl;
    }
}
