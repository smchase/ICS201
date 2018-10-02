#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char name[20];

    printf("Enter a first and last name: ");
    scanf("%[^\n]20s", &name);

    for (int i = 0; i < strlen(name); i ++) {
        if (isupper(name[i])) {
            printf("%c", name[i]);
        }
    }

    printf("\n");
}
