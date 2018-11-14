#include <iostream>

using namespace std;

void add (int n1, int n2, int t) {
    if (n1 <= n2) add (n1 + 1, n2, t + n1);
    else cout << t << endl;
}

int main ()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    add(1, n, 0);
}
