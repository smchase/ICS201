#include <iostream>

using namespace std;

void tri (int n1, int n2, bool up, int n) {
    if (n == n2 && up) up = false;
    for (int i = 0; i < n; i ++) {
        cout << "*";
    }
    cout << endl;
    if (n == n1 && !up) return;
    tri(n1, n2, up, up ? n + 1 : n - 1);
}

int main ()
{
    int num1, num2;
    cout << "Enter a smaller number: ";
    cin >> num1;
    cout << "Enter a larger number: ";
    cin >> num2;
    cout << endl;
    tri(num1, num2, true, num1);
}
