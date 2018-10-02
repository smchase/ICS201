#include <iostream>

using namespace std;

int main()
{
    float t;

    cout << "Enter a temperature in Fahrenheit: ";
    cin >> t;

    t = 5 * (t - 32) / 9;
    int t2 = t;

    cout << "The temperature in Celsius is: ~" << t2 << " (" << t << ")" << endl;

    return 0;
}
