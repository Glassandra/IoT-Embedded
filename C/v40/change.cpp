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
        if (!cin.good()) {
            cout << "\nPlease use whole positive numbers. Try again" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else if (cost < payed && payed > 0 && cost >> 0) {
            break;
        }
        else {
            cout << "Invalid numbers, try again." << endl;
        }
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
    }

    return 0;
}