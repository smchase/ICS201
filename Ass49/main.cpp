#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char s[100];
    int n = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]100s", &s);

    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            n++;
        }
    }

    printf("There are %i vowels\n", n);
}
