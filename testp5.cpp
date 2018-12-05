#include <iostream>

using namespace std;

float calcArea (float a, float b, float h)
{
    return (a+b)*h/2;
}

void goldenratio (float a, float h)
{
    cout << ">> " << (a/h == (float)1.618 ? "Is Golden Ratio" : "Is Not Golden Ratio") << endl;
}

int main ()
{
    float a, b, h;

    cout << "Calculate Area" << endl;
    cout << "> a: ";
    cin >> a;
    cout << "> b: ";
    cin >> b;
    cout << "> h: ";
    cin >> h;
    cout << ">> Area: " << calcArea(a, b, h) << endl << endl;

    cout << "Check For Golden Ratio" << endl;
    cout << "> a: ";
    cin >> a;
    cout << "> h: ";
    cin >> h;
    goldenratio(a, h);
}
