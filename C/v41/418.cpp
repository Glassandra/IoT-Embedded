#include <iostream>

using namespace std;

float salary(int year) {
    float sal;
    if (year == 1) {
        sal = 15000.0;
    }
    else {
        sal = 1.04*salary(year-1)+400;
    }
    return sal;
}

int main() {
    int year = 10;
    cout << "Salary after " << year << " is: " <<  salary(year);
    return 0;
}