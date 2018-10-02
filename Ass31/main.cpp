#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number? ";
    cin >> n;

    if (n < 10) {
        cout << "This is a one digit number\n";
    } else if (n < 100) {
        cout << "This is a two digit number\n";
    } else if (n < 1000) {
        cout << "This is a three digit number\n";
    } else {
        cout << "This number is longer than three digits\n";
    }

    return 0;
}
