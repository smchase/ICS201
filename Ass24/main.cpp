#include <iostream>

using namespace std;

int main()
{
    int l, w;
    cout << "Enter length: ";
    cin >> l;
    cout << "Enter width: ";
    cin >> w;

    cout << "Area: " << l*w << endl << "Perimeter: " << 2*l + 2*w;
    return 0;
}
