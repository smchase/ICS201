#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void b16 (int n, string t) {
    string arr[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
    if (n%16 != n) b16(n/16, t+arr[n%16]);
    else {
        t += arr[n%16];
        reverse(t.begin(), t.end());
        cout << t << endl;
    }
}

int main ()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    b16(num, "");
}
