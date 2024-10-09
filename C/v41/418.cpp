#include <iostream>

using namespace std;

float salary(int year)
{
    if (year == 1)
        return 15000.0;
    else
        return 1.04 * salary(year - 1) + 400;
}

int main()
{
    int year = 10;
    cout << "Salary after " << year << " is: " << salary(year);
    return 0;
}