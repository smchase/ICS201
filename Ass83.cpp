#include <iostream>

using namespace std;

void tri (int n1, int n2) {
    if (n1 <= n2) {
        for (int i = 0; i < n1; i ++) {
            cout << "*";
        }
        cout << endl;
        tri(n1 + 1, n2);
    }
}

int main ()
{
    int num1, num2;
    cout << "Enter a smaller number: ";
    cin >> num1;
    cout << "Enter a larger number: ";
    cin >> num2;
    tri(num1, num2);
}
