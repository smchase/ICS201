#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main ()
{
    ofstream f("Ass71.txt");
    string s;
    cout << "Input: ";
    getline(cin, s);
    f << s;
    f.close();
}
