#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    char x; //h = hi or l = lo
    float r;
    srand (time(NULL));

    r = rand() % 10 + 1;

    cout << "Type \'h\' to choose hi (6-10) or \'l\' to choose lo (1-5)\n";
    cin >> x;

    if ((r > 5 && x == 'h') || (r < 6 && x == 'l')) {
        cout << "The computer generated " << r << ", you win!" << endl;
    } else if (x == 'l' || x == 'h') {
        cout << "The computer generated " << r << ", you lose!" << endl;
    } else {
        cout << "You didn't enter \'l\' or \'h\'" << endl;
    }

    return 0;
}
