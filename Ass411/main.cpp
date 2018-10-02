#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char s[20];
    bool palindrome = true;

    printf("Enter text: ");
    scanf("%[^\n]20s", &s);

    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] != s[strlen(s) - i - 1]) {
            palindrome = false;
        }
    }

    palindrome ? printf("%s is a palindrome\n", s) : printf("%s isn't a palindrome\n", s);
}
