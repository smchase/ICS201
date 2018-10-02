#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << left <<

    setw(15) << "Name" <<
    setw(15) << "Adress" <<
    setw(15) << "Phone Number" <<
    endl <<

    setw(15) << "Mark Peterson" <<
    setw(15) << "123 Main St" <<
    setw(15) << "905-455-3212" <<
    endl <<

    setw(15) << "Cathy Harkin" <<
    setw(15) << "234 King St W" <<
    setw(15) << "905-756-1231" <<
    endl <<

    setw(15) << "Bob Linter" <<
    setw(15) << "34 Parkdale" <<
    setw(15) << "905-657-4321" <<
    endl;

    return 0;
}
