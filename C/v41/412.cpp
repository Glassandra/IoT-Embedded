#include <iostream>

using namespace std;

int textInText(char t1[], int t1length, char t2[], int t2length)
{
    int success = 0;
    for (int i = 0; i < t2length; i++)
    {
        if (t2[i] == t1[0])
        {
            success = i;
            for (int j = 1; j < t1length; j++)
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
    char a[] = "hello";
    char b[] = "imtestinghello";
    int test = textInText(a, sizeof(a), b, sizeof(b));
    cout << "Test 1: " << test << endl;
    cout << "Test 2: " << textInText("hello", sizeof("hello"), "theresno", sizeof("theresno"));
    return 0;
}