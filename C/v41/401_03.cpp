#include <iostream>
#include <cmath>

using namespace std;

int sign(double d)
{
    if (d > 0)
        return 1;
    else if (d < 0)
        return -1;
    return 0;
}

bool isPrime(int number)
{
    if (number < 2)
    {
        cout << "Please insert an int higher than 1" << endl;
        return false;
    }
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isPerfect(int number)
{
    if (number < 2)
    {
        cout << "Please insert an int higher than 1" << endl;
        return false;
    }

    int sum = 1;
    int sqrtNumber = sqrt(number);

    for (int i = 2; i <= sqrtNumber; i++)
    {
        if (number % i == 0)
        {
            sum += i;
            if (i != number / i)
            {
                sum += number / i;
            }
        }
    }

    return sum == number;
}

int main()
{
    cout << "sign test (50, 0, -10): " << sign(50) << " " << sign(0) << " " << sign(-10) << endl;
    cout << "prime test (7, 9, 11): " << isPrime(7) << " " << isPrime(9) << " " << isPrime(11) << endl;
    cout << "perfect test (6,7,28): " << isPerfect(6) << " " << isPerfect(7) << " " << isPerfect(28);
    return 0;
}