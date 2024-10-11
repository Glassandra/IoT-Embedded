#include <iostream>
using namespace std;

char *strcat(char *destination, char *source) {
    size_t i,j;
    for (i = 0; destination[i] != '\0'; ++i) 
        ;
    for (j = 0; source[j] != '\0'; ++j)
        destination[i+j] = source[j];
    destination[i+j] = '\0';
    return destination;
}

int main() {
    char str[50] = "Hello";
    char str2[50] = "World";
    strcat(str, str2);
    cout << str;
}