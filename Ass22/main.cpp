#include <iostream>

using namespace std;

int main()
{
    int x;

    cout << "Enter dollar amount: ";
    cin >> x;

    cout << "Twenties: " << x / 20 << endl;
    x = x % 20;

    cout << "Fives: " << x / 5 << endl;
    x = x % 5;

    cout << "Ones: " << x << endl;

    return 0;
}
