#include <iostream>
using namespace std;

std::string decimalToBinary(int n, int length)
{
    if (n == 0)
        return std::string(length, '0');

    std::string binary = "";
    while (n > 0)
    {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n = n / 2;
    }

    if (binary.length() < length)
    {
        binary = std::string(length - binary.length(), '0') + binary;
    }

    return binary;
}

int main() {
    for (int i = 1; i < 256; ++i) {
        cout << decimalToBinary(i,10) << endl;
    }
}