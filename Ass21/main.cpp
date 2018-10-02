#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter an integer: ";
    cin >> n;

    n = 3 * n * (n + 1) / 2;
    cout << "Sum: " << n << endl;
}
