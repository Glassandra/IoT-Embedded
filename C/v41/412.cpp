#include <iostream>

using namespace std;

int textInText(string t1, string t2)
{
    int success = 0;
    for (int i = 0; i < t2.length(); i++)
    {
        if (t2[i] == t1[0])
        {
            success = i;
            for (int j = 1; j < t1.length(); j++)
            {
                if (t1[j] != t2[i + j])
                    success = -1;
            }
            if (success > 0)
                break;
        }
    }
    return success;
}

int main()
{
    string a = "hello";
    string b = "imtestinghello";
    int test = textInText(a, b);
    cout << "Test 1: " << test << endl;
    cout << "Test 2: " << textInText("hello", "theresno");
    return 0;
}