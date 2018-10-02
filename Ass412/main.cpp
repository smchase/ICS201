#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char s[20];
    int g;

    printf("Enter a first and last name: ");
    scanf("%[^\n]20s", &s);

    char last;
    for (int i = strlen(s); i >= 0; i --) {
        if (s[i] == ' ') {
            break;
        }
        last = s[i];
    }

    if (int(last) >= 65 && int(last) <= 73) {
        g = 1;
    } else if (int(last) >= 74 && int(last) <= 83) {
        g = 2;
    } else if (int(last) >= 84 && int(last) <= 90) {
        g = 3;
    } else {
        printf("Couldn't find a last name");
        return 0;
    }

    printf("%s is in group %i\n", s, g);
}
