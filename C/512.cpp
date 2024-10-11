#include <iostream>
#include <vector>

using namespace std;

enum class roman_numerals { I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000 };

typedef const char *roman_txt;
roman_txt roman_table[] = {"I", "V", "X", "L", "C", "D", "M", nullptr};

int translate(roman_numerals num) {
    return static_cast<int>(num);
}

int get_value(char


int main() {
    vector<int> numbers;
    char c;
    while (cin.get(c)) {

    }

    return -1;
}