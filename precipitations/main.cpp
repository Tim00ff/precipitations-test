#include <iostream>

using namespace std;
#include "prepositions.h"
#include "file_reader.h"
#include "constants.h"
#include "manipulations.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory N8. GIT\n";
    cout << "Variant 3. Prepositions\n";
    cout << "Author: Timofei Fedorchenko\n\n";
    prp_stuff* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        for (int i = 0; i < size; i++)
        {
            cout << subscriptions[i]->prp_date.day << "  ";
            cout << subscriptions[i]->prp_date.month << "  ";
            cout << subscriptions[i]->prp_volume << "  ";
            cout << subscriptions[i]->prp_type << "  ";
            cout << '\n';
        }
        
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }
    bool rpts = true;
    int rpts_value = 0;
    while (rpts == true)
    {
        cout << "What do you want to do next?" << endl << "1. When it was raining?" << endl << "2. When Preposition Volume was < 1.5";
        cout << endl << "3. Do Shaker Sort and Print" << endl << "4. Do a Quick Sort and print" << endl << "5. Exit" << endl;
        cin >> rpts_value;
        switch (rpts_value)
        {
        case 1: only_rain(subscriptions, size); 
            break;
        case 2 :
            break;
        case 3 :
            break;
        case 4 : 
            break;
        case 5: rpts = false;
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        delete subscriptions[i];
    }
    return 0;
}