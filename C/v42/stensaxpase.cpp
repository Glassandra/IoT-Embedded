#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

int newgame()
{
    cout << "Sten, Sax eller Pase?" << endl;

    string choice;

    while (true)
    {
        cin >> choice;
        transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
        if (choice == "sten" || choice == "sax" || choice == "pase")
        {
            break;
        }
        cout << "Error, please select one of the three: " << endl;
    }

    int randomNumber = rand() % 3;
    string computerChoice;
    if (randomNumber == 0)
    {
        computerChoice = "sten";
    }
    else if (randomNumber == 1)
    {
        computerChoice = "sax";
    }
    else
        computerChoice = "pase";

    cout << "Datorn väljer " << computerChoice << endl;

    if (choice == computerChoice)
    {
        cout << "Oavgjort" << endl;
        return 0;
    }
    else if ((choice == "sten" && computerChoice == "sax") ||
             (choice == "sax" && computerChoice == "pase") ||
             (choice == "pase" && computerChoice == "sten"))
    {
        cout << "Du vann!" << endl;
        return 1;
    }
    else
    {
        cout << "Du förlorade!" << endl;
        return 2;
    }
}

void statistics(int &playerScore, int &computerScore, int &roundsPlayed)
{
    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Total har " << roundsPlayed << " spelats" << endl;
    if (roundsPlayed > 0) {
        cout << "Spelaren har " << playerScore << " poäng. Spelaren har vunnit " << (double)playerScore/roundsPlayed*100 << "% av matcherna" << endl;
        cout << "Datorn har " << computerScore << " poäng. Datorn har vunnit " << (double)computerScore/roundsPlayed*100 << "% av matcherna" << endl;
    }
    cout << "--------------------------" << endl;
    cout << endl;
}

int main()
{
    int playerScore = 0;
    int computerScore = 0;
    int roundsPlayed = 0;
    bool continuePlaying = true;

    do
    {
        int menu;
        cout << endl;
        cout << "Välj ett av följande alternativ, välj med siffra: " << endl;
        cout << "1) Starta nytt spel (1)" << endl;
        cout << "2) Visa statistik   (2)" << endl;
        cout << "3) Avsluta spelet   (3)" << endl;
        cin >> menu;
        if (menu == 1)
        {

            int result = newgame();
            ++roundsPlayed;
            if (result == 1)
            {
                ++playerScore;
            }
            else if (result == 2)
            {
                ++computerScore;
            }
            cout << endl;
            cout << "Spelaren har: " << playerScore << " poäng." << endl;
            cout << "Datorn har: " << computerScore << " poäng." << endl;
            cout << "Ni har spelat " << roundsPlayed << " rundor" << endl;
        }
        else if (menu == 2) {
            statistics(playerScore, computerScore, roundsPlayed);
        }
        else if (menu == 3) {
            cout << "Tack för att du spelat, ha en bra dag!" << endl;
            continuePlaying = false;
        }

    } while (continuePlaying);
}
