#include <iostream>

using namespace std;

int main()
{
    int c; //copies
    float p; //price

    cout << "Enter the number of copies: ";
    cin >> c;

    if ( c < 101) {
        p = c * 0.30;
    } else if (c < 201) {
        p = c * 0.35;
    } else if (c < 301) {
        p = c * 0.40;
    } else if (c < 401) {
        p = c * 0.50;
    } else {
        p = c * 0.60;
    }

    cout << "The price is $" << p << endl;

    return 0;
}
