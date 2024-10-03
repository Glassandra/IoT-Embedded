#include <iostream>

using namespace std;

int main()
{
    int static denominators[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int cost;
    int payed;

    while (true)
    {
        cout << "Hur mycket betalade du? ";
        cin >> payed;
        cout << "Hur mycket kostade det? ";
        cin >> cost;
        break;
    }

    int difference = payed - cost;
    int length = size(denominators);
    int count[9] = {0};

    cout << "Du ska få tillbaka ";
    for (int i = 0; i < length; ++i)
    {
        if (difference >= denominators[i])
        {
            count[i] = difference/denominators[i];
            difference %= denominators[i];
            if (denominators[i] > 10) {
                cout << count[i] << " " << denominators[i] << "sedel, ";
            }
            else {
                cout << count[i] << " " << denominators[i] << "mynt, ";
            }
        }
        /* cout << "Denominator is: " << denominators[i] << endl;
        cout << "Number of bills is: " << count[i] << endl;
        cout << "Change left is: ";
        cout << difference << endl; */
    }

    return 0;
}

int countDenominators(int value)
{
    return value;
}