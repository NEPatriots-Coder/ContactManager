//
// Created by lamarwells on 7/22/2024.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

const int SIZE = 10;
const int WIDTH = 20;

void inputContacts(string names[], string phoneNumbers []);
void sortContacts(string names[], string phoneNumbers []);
void printContacts(const string names[], const string phoneNumbers []);
void searchContact(const string names[], const string phoneNumbers[]);

int main()
{
    string names[SIZE];
    string phoneNumbers[SIZE];

    inputContacts(names, phoneNumbers);
    sortContacts(names, phoneNumbers);
    printContacts(names, phoneNumbers);
    searchContact(names, phoneNumbers);

    return 0;
}

void inputContacts(string names[], string phoneNumbers[])
{
    cout << "\n--- Input Contacts ---\n";
    cin.ignore(); // Clears any newline character in the input buffer

    for (int i = 0; i < SIZE; ++i)
    {
        cout << "Enter the name of your contact " << i + 1 << ": ";
        getline(cin, names[i]);
        cout << "Enter the phone number for " << names[i] << ": ";
        getline(cin, phoneNumbers[i]);
    }
}

void printContacts(const string names[], const string phoneNumbers[])
{
    cout << "\n--- Sorted Contacts List ---\n";
    cout << left << setw(WIDTH) << "Name" << "Phone Number" << endl;
    cout << string(2 * WIDTH, '-') << endl;

    for (int i = 0; i < SIZE; ++i)
    {
        cout << left << setw(WIDTH) << names[i] << phoneNumbers[i] << endl;
    }
}

void sortContacts(string names[], string phoneNumbers[])
{
    for (int i = 0; i < SIZE - 1; ++i)
    {
        for (int j = 0; j < SIZE - 1; ++j)
        {
            if (phoneNumbers[j] < phoneNumbers[j + 1])
            {
                swap(phoneNumbers[j], phoneNumbers[j + 1]);
                swap (names[j], names[j + 1]);
            }
        }
    }
}

void searchContact(const string names[], const string phoneNumbers[]) {
    string searchName;
    bool keepSearching = true;

    while (keepSearching) {
        cout << "Enter the name to search for (or type 'exit' to quit): ";
        getline(cin, searchName);

        if (searchName == "exit") {
            keepSearching = false;
            cout << "Exiting search.\n";
            break;
        }

        bool found = false;
        for (int i = 0; i < SIZE; ++i)
        {
            if (names[i] == searchName)
            {
                cout << "Found " << searchName << ": " << phoneNumbers[i] << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "User not found.\n";
        }
    }
}
