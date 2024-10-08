#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int tal;
    int talLista[] = {10, 9, 11, 5, 3, 2, 1};
    int size = sizeof(talLista) / sizeof(talLista[0]);    

    while (true)
    {
        cout << "Vilket tal letar du efter? ";
        cin >> tal;
        if (!cin.good()) {
            cout << "\nPlease use whole positive numbers. Try again" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else if (tal > 0) {
            break;
        }
        else {
            cout << "Invalid numbers, try again." << endl;
        }
    }
    
    sort(talLista, talLista + size); // uppgiften är att avbryta innan slutet, så jag använder inbyggd sort

    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << talLista[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < size ; i++) {
        if (talLista[i] == tal) {
            cout << "Talet finns på plats nr " << i << endl;
            break;
        }
        if (talLista[i] > tal ) { // Break early
            cout << "Talet finns ej" << endl;
            break;
        }
    }

    return 0;
}
