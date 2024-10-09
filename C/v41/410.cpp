#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

bool isAllowedVariable(string name)
{
    if (name.empty())
        return false;
    if (!isalpha(name[0]) && name[0] != '_')
        return false;
    for (char c : name)
    {
        if (!isalnum(c) && c != '_')
            return false;
    }

    return true;
}

int main()
{
    string text;
    cout << "Write a number of words separated by space: " << endl;
    getline(cin, text);

    istringstream splittedText(text);
    vector<string> words;
    string word;

    while (splittedText >> word)
    {
        words.push_back(word);
    }

    int count = 0;

    for (const string &s : words)
    {
        if (isAllowedVariable(s))
        {
            count++;
        }
    }

    cout << "The number of allowed words is: " << count;

    return 0;
}