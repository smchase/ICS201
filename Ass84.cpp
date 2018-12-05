#include <iostream>

using namespace std;

int digSum (int n, int s = 0)
{
    if (n != 0) digSum((n-(n%10))/10, s+(n%10));
    else return s;
}

int main ()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << digSum(num) << endl;
}
