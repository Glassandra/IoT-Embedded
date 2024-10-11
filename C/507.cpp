#include <iostream>

using namespace std;

char *strcopy(char *source, char *destination, size_t destination_length) {
    if (destination_length == 0) return destination;
    size_t i;
    for (i = 0; source[i] != '\0' && i < destination_length - 1; i++) {
        destination[i] = source[i];
        if (i + 1 >= destination_length) {
            cout << "Error: too long source" << endl;
        }
    }
    destination[i] = '\0';
    return destination;
}

int main() {
    char test1[10] = "Hello";
    char test2[20] = "This is not hello";
    cout << strcopy(test1, test2, sizeof(test2)) << endl;
    char test4[10] = "Hello";
    char test3[3] = "";
    cout << strcopy(test4, test3, sizeof(test3));
}