#include <iostream>
#include <string>

using namespace std;

int textInText(const string &t1, const string &t2)
{
    size_t result = t2.find(t1);
    return (int)result;
}

int main()
{
    const string a = "hello";
    const string b = "imtestinghello";
    int test = textInText(a, b);
    cout << "Test 1: " << test << endl;
    cout << "Test 2: " << textInText("hello", "theresno");
    return 0;
}