#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char s[100];

    printf("Enter a sentence: ");
    scanf("%[^\n]100s", &s);

    for (int i = 0; i < strlen(s); i ++) {
        printf("%c = %i ", s[i], s[i]);
    }

    printf("\n");
}
