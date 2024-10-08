#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> numbers;
    int input;

    cout << "Enter numbers (type 'done' to finish):" << endl;
    while (true)
    {
        cout << "Enter a number: ";
        if (cin >> input)
        {
            numbers.push_back(input);
        }
        else
        {
            cin.clear();
            string invalidInput;
            cin >> invalidInput;
            if (invalidInput == "done")
            {
                break;
            }
            else
            {
                cout << "Invalid input. Please enter a valid number or type 'done' to finish." << endl;
            }
        }
    }

    int size = numbers.size();

    while (true)
    {
        bool hasChanged = false;
        for (int i = 0; i < size - 1; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                int temp = numbers[i + 1];
                numbers[i + 1] = numbers[i];
                numbers[i] = temp;
                hasChanged = true;
            }
        }
        if (hasChanged == false)
        {
            break;
        }
    }

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << numbers[i] << " ";
    }

    return 0;
}