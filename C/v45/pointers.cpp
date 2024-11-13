#include <iostream>

using namespace std;
int main() {
    int* pointer = nullptr;
    int x = 3;
    pointer = &x;
    cout << x <<endl;
    cout << pointer << endl;
    cout << *pointer << endl;

    x = 4;
    cout << *pointer << endl;

    return 0;
}