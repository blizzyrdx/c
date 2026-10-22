#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName;
    ifstream invFile; //two different ifstream
    ifstream bankFile;

    // inventory file
    do {
        cout << "Inventory File: ";
        cin >> fileName;
        invFile.clear();                 // reset the stream after a failed open
        invFile.open(fileName.c_str());
        if (!invFile.is_open()) {
            cout << "Error: Invalid inventory file name\n";
        }
    } while (!invFile.is_open());

    // bank file
    do {
        cout << "Bank File: ";
        cin >> fileName;
        bankFile.clear();
        bankFile.open(fileName.c_str());
        if (!bankFile.is_open()) {
            cout << "Error: Invalid bank file name\n";
        }
    } while (!bankFile.is_open());

    const int SIZE = 5;
    string inventory[SIZE];          // holds item names
    string headers;
    string name;
    int position = 0;

    getline(invFile, headers);       // skip the header line

    // read each "position name" row
    while (invFile >> position) {
        invFile >> ws;               // skip spaces before the name
        getline(invFile, name);      // read the full name, including spaces

        if (position >= 0 && position < SIZE) {
            inventory[position] = name;
        } else {
            cerr << "Warning: position " << position << " is out of range\n";
        }
    }

    // print the inventory array
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": " << inventory[i] << "\n";
    }

    invFile.close();
    bankFile.close();
    return 0;
}