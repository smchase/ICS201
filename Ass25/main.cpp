#include <iostream>

using namespace std;

int main()
{
    int m;
    cout << "Enter time in minutes: ";
    cin >> m;
    cout << "Seconds: " << m*60 << endl;
    int h = m/60;
    cout << "Hours:minutes: " << h << ":" << m % 60 << endl;
    return 0;
}
