#include <iostream>
#include <array>

using namespace std;

array<int, 2> bigAndSmall(string text)
{
    int small = 0, big = 0;

    for (char c : text)
    {
        if (isupper(c))
        {
            big++;
        }
        else
        {
            small++;
        }
    }
    return {small, big};
}

int main()
{
    string text = "AaBbCcdeF";

    array<int, 2> result = bigAndSmall(text);

    cout << "Number of lowercase: " << result[0] << endl
         << "Number of capital: " << result[1];
}
